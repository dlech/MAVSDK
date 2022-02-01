#pragma once

#include "plugins/camera_server/camera_server.h"
#include "plugin_impl_base.h"

namespace mavsdk {

class CameraServerImpl : public PluginImplBase {
public:
    explicit CameraServerImpl(System& system);
    explicit CameraServerImpl(std::shared_ptr<System> system);
    ~CameraServerImpl();

    void init() override;
    void deinit() override;

    void enable() override;
    void disable() override;

    CameraServer::Result set_information(CameraServer::Information information);

    CameraServer::Result set_in_progress(bool in_progress);

    void
    subscribe_take_photo(bool can_capture_in_video_mode, CameraServer::TakePhotoCallback callback);

    void subscribe_set_camera_mode_image(CameraServer::SetCameraModeImageCallback callback);
    void subscribe_set_camera_mode_video(CameraServer::SetCameraModeVideoCallback callback);
    void subscribe_set_camera_mode_survey(CameraServer::SetCameraModeSurveyCallback callback);

    void subscribe_set_camera_zoom(
        float focal_length_min,
        float focal_length_max,
        CameraServer::SetCameraZoomCallback callback);
    void subscribe_set_camera_focus(CameraServer::SetCameraFocusCallback callback);

    CameraServer::Result publish_photo(CameraServer::CaptureInfo capture_info);

private:
    enum StatusFlags {
        IN_PROGRESS = 1 << 0,
        INTERVAL_SET = 1 << 1,
    };

    enum class TriggerControl {
        IGNORE = -1,
        DISABLE = 0,
        ENABLE = 1,
    };

    bool _is_information_set{};
    uint32_t _information_flags{0};
    CameraServer::Information _information{};
    bool _in_progress{};

    float _focal_length_min{};
    float _focal_length_max{};

    void check_modes_available();

    CameraServer::TakePhotoCallback take_photo_callback;
    CameraServer::SetCameraModeImageCallback set_camera_mode_image_callback;
    CameraServer::SetCameraModeVideoCallback set_camera_mode_video_callback;
    CameraServer::SetCameraModeSurveyCallback set_camera_mode_survey_callback;
    CameraServer::SetCameraZoomCallback set_camera_zoom_callback;
    CameraServer::SetCameraFocusCallback set_camera_focus_callback;

    std::optional<mavlink_message_t>
    process_camera_information_request(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_camera_settings_request(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_storage_information_request(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_storage_format(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_camera_capture_status_request(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_reset_camera_settings(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_set_camera_mode(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_set_camera_zoom(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_set_camera_focus(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_set_storage_usage(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_image_start_capture(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_image_stop_capture(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_camera_image_capture_request(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_do_trigger_control(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_video_start_capture(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_video_stop_capture(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_video_start_streaming(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_video_stop_streaming(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_video_stream_information_request(const MavlinkCommandReceiver::CommandLong& command);
    std::optional<mavlink_message_t>
    process_video_stream_status_request(const MavlinkCommandReceiver::CommandLong& command);
};

} // namespace mavsdk
