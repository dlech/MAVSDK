// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see
// https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/camera_server/camera_server.proto)

#include <iomanip>

#include "camera_server_impl.h"
#include "plugins/camera_server/camera_server.h"

namespace mavsdk {

using Information = CameraServer::Information;
using Position = CameraServer::Position;
using Quaternion = CameraServer::Quaternion;
using CaptureInfo = CameraServer::CaptureInfo;

CameraServer::CameraServer(System& system) :
    PluginBase(),
    _impl{std::make_unique<CameraServerImpl>(system)}
{}

CameraServer::CameraServer(std::shared_ptr<System> system) :
    PluginBase(),
    _impl{std::make_unique<CameraServerImpl>(system)}
{}

CameraServer::~CameraServer() {}

CameraServer::Result CameraServer::set_information(Information information) const
{
    return _impl->set_information(information);
}

CameraServer::Result CameraServer::set_in_progress(bool in_progress) const
{
    return _impl->set_in_progress(in_progress);
}

void CameraServer::subscribe_take_photo(bool can_capture_in_video_mode, TakePhotoCallback callback)
{
    _impl->subscribe_take_photo(can_capture_in_video_mode, callback);
}

void CameraServer::subscribe_set_camera_mode_image(SetCameraModeImageCallback callback)
{
    _impl->subscribe_set_camera_mode_image(callback);
}

void CameraServer::subscribe_set_camera_mode_video(SetCameraModeVideoCallback callback)
{
    _impl->subscribe_set_camera_mode_video(callback);
}

void CameraServer::subscribe_set_camera_mode_survey(SetCameraModeSurveyCallback callback)
{
    _impl->subscribe_set_camera_mode_survey(callback);
}

CameraServer::Result CameraServer::publish_photo(CaptureInfo capture_info) const
{
    return _impl->publish_photo(capture_info);
}

bool operator==(const CameraServer::Information& lhs, const CameraServer::Information& rhs)
{
    return (rhs.vendor_name == lhs.vendor_name) && (rhs.model_name == lhs.model_name) &&
           (rhs.firmware_version == lhs.firmware_version) &&
           ((std::isnan(rhs.focal_length_mm) && std::isnan(lhs.focal_length_mm)) ||
            rhs.focal_length_mm == lhs.focal_length_mm) &&
           ((std::isnan(rhs.sensor_size_h_mm) && std::isnan(lhs.sensor_size_h_mm)) ||
            rhs.sensor_size_h_mm == lhs.sensor_size_h_mm) &&
           ((std::isnan(rhs.sensor_size_v_mm) && std::isnan(lhs.sensor_size_v_mm)) ||
            rhs.sensor_size_v_mm == lhs.sensor_size_v_mm) &&
           (rhs.resolution_h_px == lhs.resolution_h_px) &&
           (rhs.resolution_v_px == lhs.resolution_v_px) && (rhs.lens_id == lhs.lens_id) &&
           (rhs.cam_definition_version == lhs.cam_definition_version) &&
           (rhs.cam_definition_uri == lhs.cam_definition_uri);
}

std::ostream& operator<<(std::ostream& str, CameraServer::Information const& information)
{
    str << std::setprecision(15);
    str << "information:" << '\n' << "{\n";
    str << "    vendor_name: " << information.vendor_name << '\n';
    str << "    model_name: " << information.model_name << '\n';
    str << "    firmware_version: " << information.firmware_version << '\n';
    str << "    focal_length_mm: " << information.focal_length_mm << '\n';
    str << "    sensor_size_h_mm: " << information.sensor_size_h_mm << '\n';
    str << "    sensor_size_v_mm: " << information.sensor_size_v_mm << '\n';
    str << "    resolution_h_px: " << information.resolution_h_px << '\n';
    str << "    resolution_v_px: " << information.resolution_v_px << '\n';
    str << "    lens_id: " << information.lens_id << '\n';
    str << "    cam_definition_version: " << information.cam_definition_version << '\n';
    str << "    cam_definition_uri: " << information.cam_definition_uri << '\n';
    str << '}';
    return str;
}

bool operator==(const CameraServer::Position& lhs, const CameraServer::Position& rhs)
{
    return ((std::isnan(rhs.latitude_deg) && std::isnan(lhs.latitude_deg)) ||
            rhs.latitude_deg == lhs.latitude_deg) &&
           ((std::isnan(rhs.longitude_deg) && std::isnan(lhs.longitude_deg)) ||
            rhs.longitude_deg == lhs.longitude_deg) &&
           ((std::isnan(rhs.absolute_altitude_m) && std::isnan(lhs.absolute_altitude_m)) ||
            rhs.absolute_altitude_m == lhs.absolute_altitude_m) &&
           ((std::isnan(rhs.relative_altitude_m) && std::isnan(lhs.relative_altitude_m)) ||
            rhs.relative_altitude_m == lhs.relative_altitude_m);
}

std::ostream& operator<<(std::ostream& str, CameraServer::Position const& position)
{
    str << std::setprecision(15);
    str << "position:" << '\n' << "{\n";
    str << "    latitude_deg: " << position.latitude_deg << '\n';
    str << "    longitude_deg: " << position.longitude_deg << '\n';
    str << "    absolute_altitude_m: " << position.absolute_altitude_m << '\n';
    str << "    relative_altitude_m: " << position.relative_altitude_m << '\n';
    str << '}';
    return str;
}

bool operator==(const CameraServer::Quaternion& lhs, const CameraServer::Quaternion& rhs)
{
    return ((std::isnan(rhs.w) && std::isnan(lhs.w)) || rhs.w == lhs.w) &&
           ((std::isnan(rhs.x) && std::isnan(lhs.x)) || rhs.x == lhs.x) &&
           ((std::isnan(rhs.y) && std::isnan(lhs.y)) || rhs.y == lhs.y) &&
           ((std::isnan(rhs.z) && std::isnan(lhs.z)) || rhs.z == lhs.z);
}

std::ostream& operator<<(std::ostream& str, CameraServer::Quaternion const& quaternion)
{
    str << std::setprecision(15);
    str << "quaternion:" << '\n' << "{\n";
    str << "    w: " << quaternion.w << '\n';
    str << "    x: " << quaternion.x << '\n';
    str << "    y: " << quaternion.y << '\n';
    str << "    z: " << quaternion.z << '\n';
    str << '}';
    return str;
}

bool operator==(const CameraServer::CaptureInfo& lhs, const CameraServer::CaptureInfo& rhs)
{
    return (rhs.position == lhs.position) && (rhs.attitude_quaternion == lhs.attitude_quaternion) &&
           (rhs.time_utc_us == lhs.time_utc_us) && (rhs.is_success == lhs.is_success) &&
           (rhs.index == lhs.index) && (rhs.file_url == lhs.file_url);
}

std::ostream& operator<<(std::ostream& str, CameraServer::CaptureInfo const& capture_info)
{
    str << std::setprecision(15);
    str << "capture_info:" << '\n' << "{\n";
    str << "    position: " << capture_info.position << '\n';
    str << "    attitude_quaternion: " << capture_info.attitude_quaternion << '\n';
    str << "    time_utc_us: " << capture_info.time_utc_us << '\n';
    str << "    is_success: " << capture_info.is_success << '\n';
    str << "    index: " << capture_info.index << '\n';
    str << "    file_url: " << capture_info.file_url << '\n';
    str << '}';
    return str;
}

std::ostream& operator<<(std::ostream& str, CameraServer::Result const& result)
{
    switch (result) {
        case CameraServer::Result::Unknown:
            return str << "Unknown";
        case CameraServer::Result::Success:
            return str << "Success";
        case CameraServer::Result::InProgress:
            return str << "In Progress";
        case CameraServer::Result::Busy:
            return str << "Busy";
        case CameraServer::Result::Denied:
            return str << "Denied";
        case CameraServer::Result::Error:
            return str << "Error";
        case CameraServer::Result::Timeout:
            return str << "Timeout";
        case CameraServer::Result::WrongArgument:
            return str << "Wrong Argument";
        case CameraServer::Result::NoSystem:
            return str << "No System";
        default:
            return str << "Unknown";
    }
}

std::ostream& operator<<(std::ostream& str, CameraServer::CameraMode const& camera_mode)
{
    switch (camera_mode) {
        case CameraServer::CameraMode::Unknown:
            return str << "Unknown";
        case CameraServer::CameraMode::Image:
            return str << "Image";
        case CameraServer::CameraMode::Video:
            return str << "Video";
        case CameraServer::CameraMode::Survey:
            return str << "Survey";
        default:
            return str << "Unknown";
    }
}

} // namespace mavsdk