#include <future>

#include <iostream>
#include <thread>
#include <mavsdk/mavsdk.h>
#include <mavsdk/plugins/camera/camera.h>
#include <mavsdk/plugins/camera_server/camera_server.h>

/*
 This example runs a MAVLink "camera" utilizing the MAVSDK server plugins
 on a separate thread. This uses two MAVSDK instances, one GCS, one camera.

 The main thread acts as a GCS and reads telemetry, parameters, transmits across
 a mission, clears the mission, arms the vehicle and then triggers a vehicle takeoff.

 The camera thread handles all the servers and triggers callbacks, publishes telemetry,
 handles and stores parameters, prints received missions and sets the vehicle height to 10m on
 successful takeoff request.
*/

using namespace mavsdk;

using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::system_clock;
using std::this_thread::sleep_for;

int main(int argc, char** argv)
{
    mavsdk::Mavsdk mavsdk;
    mavsdk::Mavsdk::Configuration configuration(mavsdk::Mavsdk::Configuration::UsageType::Camera);
    mavsdk.set_configuration(configuration);

    // 14030 is the default camera port for PX4 SITL
    auto result = mavsdk.add_any_connection("udp://:24547");
    if (result == mavsdk::ConnectionResult::Success) {
        std::cout << "Created camera server connection" << std::endl;
    }

    auto prom = std::promise<std::shared_ptr<mavsdk::System>>{};
    auto fut = prom.get_future();

    mavsdk.subscribe_on_new_system([&mavsdk, &prom]() {
        auto system = mavsdk.systems().back();

        if (!system->is_standalone()) {
            return;
        }

        std::cout << "Discovered GCS" << std::endl;
        mavsdk.subscribe_on_new_system(nullptr);
        prom.set_value(system);
    });

    if (fut.wait_for(seconds(10)) == std::future_status::timeout) {
        std::cerr << "No GCS found, exiting." << std::endl;
        return 1;
    }

    auto system = fut.get();

    // Create server plugin
    auto camera_server = mavsdk::CameraServer{system};

    camera_server.set_information(
        {.vendor_name = "Foo Industries",
         .model_name = "T100",
         .firmware_version = 1,
         .focal_length_mm = 16.0,
         .sensor_size_h_mm = 15.4,
         .sensor_size_v_mm = 23.2,
         .resolution_h_px = 5456,
         .resolution_v_px = 2464,
         .lens_id = 0,
         .cam_definition_version = 0,
         .cam_definition_uri =
             "https://gist.githubusercontent.com/dayjaby/a448be3670fbbcf05a5360421c92c27f/raw/b0e75b84f1fad69c5598bac2d96a25f96686c436/camera_info.xml"});

    camera_server.set_in_progress(false);

    bool can_capture_in_video_mode = true;
    camera_server.subscribe_take_photo(
        can_capture_in_video_mode, [&camera_server](CameraServer::Result result, int32_t index) {
            camera_server.set_in_progress(true);

            std::cout << "taking a picture..." << std::endl;

            // TODO : actually capture image here
            // simulating with delay
            sleep_for(seconds(1));

            // TODO: populate with telemetry data
            auto position = CameraServer::Position{};
            auto attitude = CameraServer::Quaternion{};

            auto timestamp =
                duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
            auto success = true;

            camera_server.set_in_progress(false);

            camera_server.publish_photo({
                .position = position,
                .attitude_quaternion = attitude,
                .time_utc_us = static_cast<uint64_t>(timestamp),
                .is_success = success,
                .index = index,
                .file_url = {},
            });
        });

    while (true) {
        // TODO: better way to wait forever?
        sleep_for(seconds(1));
    }

    return 0;
}
