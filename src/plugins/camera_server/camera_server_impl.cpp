#include "camera_server_impl.h"

namespace mavsdk {

CameraServerImpl::CameraServerImpl(System& system) : PluginImplBase(system)
{
    _parent->register_plugin(this);
}

CameraServerImpl::CameraServerImpl(std::shared_ptr<System> system) : PluginImplBase(system)
{
    _parent->register_plugin(this);
}

CameraServerImpl::~CameraServerImpl()
{
    _parent->unregister_plugin(this);
}

void CameraServerImpl::init()
{
    _parent->register_mavlink_command_handler(
        MAV_CMD_REQUEST_CAMERA_INFORMATION,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_camera_information_request(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_REQUEST_CAMERA_SETTINGS,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_camera_settings_request(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_REQUEST_STORAGE_INFORMATION,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_storage_information_request(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_STORAGE_FORMAT,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_storage_format(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_REQUEST_CAMERA_CAPTURE_STATUS,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_camera_capture_status_request(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_RESET_CAMERA_SETTINGS,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_reset_camera_settings(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_SET_CAMERA_MODE,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_set_camera_mode(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_SET_CAMERA_ZOOM,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_set_camera_zoom(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_SET_CAMERA_FOCUS,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_set_camera_focus(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_SET_STORAGE_USAGE,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_set_storage_usage(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_IMAGE_START_CAPTURE,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_image_start_capture(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_IMAGE_STOP_CAPTURE,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_image_stop_capture(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_REQUEST_CAMERA_IMAGE_CAPTURE,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_camera_image_capture_request(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_DO_TRIGGER_CONTROL,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_do_trigger_control(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_VIDEO_START_CAPTURE,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_video_start_capture(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_VIDEO_STOP_CAPTURE,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_video_stop_capture(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_VIDEO_START_STREAMING,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_video_start_streaming(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_VIDEO_STOP_STREAMING,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_video_stop_streaming(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_REQUEST_VIDEO_STREAM_INFORMATION,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_video_stream_information_request(command);
        },
        this);
    _parent->register_mavlink_command_handler(
        MAV_CMD_REQUEST_VIDEO_STREAM_STATUS,
        [this](const MavlinkCommandReceiver::CommandLong& command) {
            return process_video_stream_status_request(command);
        },
        this);
}

void CameraServerImpl::deinit() {}

void CameraServerImpl::enable() {}

void CameraServerImpl::disable() {}

CameraServer::Result CameraServerImpl::set_information(CameraServer::Information information)
{
    _is_information_set = true;
    _information = information;
    return CameraServer::Result::Success;
}

CameraServer::Result CameraServerImpl::set_in_progress(bool in_progress)
{
    _in_progress = in_progress;
    return CameraServer::Result::Success;
}

void CameraServerImpl::check_modes_available()
{
    uint8_t modes = 0;
    if (_information_flags & CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_CAPTURE_IMAGE)
        modes++;
    if (_information_flags & CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_CAPTURE_VIDEO)
        modes++;
    if (_information_flags & CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_HAS_IMAGE_SURVEY_MODE)
        modes++;

    if (modes > 1) {
        _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_HAS_MODES;
    }
}

void CameraServerImpl::subscribe_take_photo(
    bool can_capture_in_video_mode, CameraServer::TakePhotoCallback callback)
{
    _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_CAPTURE_IMAGE;
    if (can_capture_in_video_mode) {
        _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_CAPTURE_VIDEO;
        _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_CAN_CAPTURE_IMAGE_IN_VIDEO_MODE;
    }
    check_modes_available();

    take_photo_callback = callback;
}

void CameraServerImpl::subscribe_set_camera_mode_image(
    CameraServer::SetCameraModeImageCallback callback)
{
    _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_CAPTURE_IMAGE;
    check_modes_available();

    set_camera_mode_image_callback = callback;
}

void CameraServerImpl::subscribe_set_camera_mode_video(
    CameraServer::SetCameraModeVideoCallback callback)
{
    _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_CAPTURE_VIDEO;
    check_modes_available();

    set_camera_mode_video_callback = callback;
}

void CameraServerImpl::subscribe_set_camera_mode_survey(
    CameraServer::SetCameraModeSurveyCallback callback)
{
    _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_HAS_IMAGE_SURVEY_MODE;
    check_modes_available();

    set_camera_mode_survey_callback = callback;
}

void CameraServerImpl::subscribe_set_camera_zoom(
    float focal_length_min, float focal_length_max, CameraServer::SetCameraZoomCallback callback)
{
    _focal_length_min = focal_length_min;
    _focal_length_max = focal_length_max;
    _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_HAS_BASIC_ZOOM;

    set_camera_zoom_callback = callback;
}

void CameraServerImpl::subscribe_set_camera_focus(CameraServer::SetCameraFocusCallback callback)
{
    _information_flags |= CAMERA_CAP_FLAGS::CAMERA_CAP_FLAGS_HAS_BASIC_FOCUS;

    set_camera_focus_callback = callback;
}

CameraServer::Result CameraServerImpl::publish_photo(CameraServer::CaptureInfo capture_info)
{
    UNUSED(capture_info);

    // TODO :)
    return {};
}

std::optional<mavlink_message_t> CameraServerImpl::process_camera_information_request(
    const MavlinkCommandReceiver::CommandLong& command)
{
    auto capabilities = static_cast<bool>(command.params.param1);

    if (!capabilities) {
        LogDebug() << "early info return";
        return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
    }

    if (!_is_information_set) {
        return _parent->make_command_ack_message(
            command, MAV_RESULT::MAV_RESULT_TEMPORARILY_REJECTED);
    }

    // ack needs to be sent before camera information message
    auto ack_msg = _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
    _parent->send_message(ack_msg);
    LogDebug() << "sent info ack";

    // FIXME: why is this needed to prevent dropping messages? - comment from dayjaby: guess it's
    // not? commenting it for now std::this_thread::sleep_for(std::chrono::milliseconds(100));

    mavlink_message_t msg{};
    mavlink_msg_camera_information_pack(
        _parent->get_own_system_id(),
        _parent->get_own_component_id(),
        &msg,
        static_cast<uint32_t>(_parent->get_time().elapsed_s() * 1e3),
        reinterpret_cast<const uint8_t*>(_information.vendor_name.c_str()),
        reinterpret_cast<const uint8_t*>(_information.model_name.c_str()),
        _information.firmware_version,
        _information.focal_length_mm,
        _information.sensor_size_h_mm,
        _information.sensor_size_v_mm,
        _information.resolution_h_px,
        _information.resolution_v_px,
        _information.lens_id,
        _information_flags,
        _information.cam_definition_version,
        reinterpret_cast<const char*>(_information.cam_definition_uri.c_str()));

    _parent->send_message(msg);
    LogDebug() << "sent info msg";

    // ack was already sent
    return std::nullopt;
}

std::optional<mavlink_message_t> CameraServerImpl::process_camera_settings_request(
    const MavlinkCommandReceiver::CommandLong& command)
{
    auto settings = static_cast<bool>(command.params.param1);

    if (!settings) {
        LogDebug() << "early settings return";
        return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
    }

    // ack needs to be sent before camera information message
    auto ack_msg = _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
    _parent->send_message(ack_msg);
    LogDebug() << "sent settings ack";

    // FIXME: why is this needed to prevent dropping messages?
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // unsupported
    const auto mode_id = CAMERA_MODE::CAMERA_MODE_IMAGE;
    const float zoom_level = 0;
    const float focus_level = 0;

    mavlink_message_t msg{};
    mavlink_msg_camera_settings_pack(
        _parent->get_own_system_id(),
        _parent->get_own_component_id(),
        &msg,
        static_cast<uint32_t>(_parent->get_time().elapsed_s() * 1e3),
        mode_id,
        zoom_level,
        focus_level);

    _parent->send_message(msg);
    LogDebug() << "sent settings msg";

    // ack was already sent
    return std::nullopt;
}

std::optional<mavlink_message_t> CameraServerImpl::process_storage_information_request(
    const MavlinkCommandReceiver::CommandLong& command)
{
    auto storage_id = static_cast<uint8_t>(command.params.param1);
    auto information = static_cast<bool>(command.params.param2);

    if (!information) {
        LogDebug() << "early storage return";
        return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
    }

    // ack needs to be sent before camera information message
    auto ack_msg = _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
    _parent->send_message(ack_msg);
    LogDebug() << "sent storage ack";

    // FIXME: why is this needed to prevent dropping messages?
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // unsupported
    const uint8_t storage_count = 0;
    const auto status = STORAGE_STATUS::STORAGE_STATUS_NOT_SUPPORTED;
    const float total_capacity = 0;
    const float used_capacity = 0;
    const float available_capacity = 0;
    const float read_speed = 0;
    const float write_speed = 0;
    const uint8_t type = STORAGE_TYPE::STORAGE_TYPE_UNKNOWN;
    auto name = "";
    const uint8_t storage_usage = 0;

    mavlink_message_t msg{};
    mavlink_msg_storage_information_pack(
        _parent->get_own_system_id(),
        _parent->get_own_component_id(),
        &msg,
        static_cast<uint32_t>(_parent->get_time().elapsed_s() * 1e3),
        storage_id,
        storage_count,
        status,
        total_capacity,
        used_capacity,
        available_capacity,
        read_speed,
        write_speed,
        type,
        name,
        storage_usage);

    _parent->send_message(msg);
    LogDebug() << "sent storage msg";

    // ack was already sent
    return std::nullopt;
}

std::optional<mavlink_message_t>
CameraServerImpl::process_storage_format(const MavlinkCommandReceiver::CommandLong& command)
{
    auto storage_id = static_cast<uint8_t>(command.params.param1);
    auto format = static_cast<bool>(command.params.param2);
    auto reset_image_log = static_cast<bool>(command.params.param3);

    UNUSED(storage_id);
    UNUSED(format);
    UNUSED(reset_image_log);

    LogDebug() << "unsupported storage format request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t> CameraServerImpl::process_camera_capture_status_request(
    const MavlinkCommandReceiver::CommandLong& command)
{
    auto capture_status = static_cast<bool>(command.params.param1);

    if (!capture_status) {
        return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
    }

    // ack needs to be sent before camera information message
    auto ack_msg = _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
    _parent->send_message(ack_msg);

    // FIXME: why is this needed to prevent dropping messages?
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    uint8_t image_status{};
    if (_in_progress) {
        image_status |= StatusFlags::IN_PROGRESS;
    }

    int32_t image_count = 0; // TODO: get image capture vector length

    // unsupported
    const uint8_t video_status = 0;
    const float image_interval = 0;
    const uint32_t recording_time_ms = 0;
    const float available_capacity = 0;

    mavlink_message_t msg{};
    mavlink_msg_camera_capture_status_pack(
        _parent->get_own_system_id(),
        _parent->get_own_component_id(),
        &msg,
        static_cast<uint32_t>(_parent->get_time().elapsed_s() * 1e3),
        image_status,
        video_status,
        image_interval,
        recording_time_ms,
        available_capacity,
        image_count);

    _parent->send_message(msg);

    // ack was already sent
    return std::nullopt;
}

std::optional<mavlink_message_t>
CameraServerImpl::process_reset_camera_settings(const MavlinkCommandReceiver::CommandLong& command)
{
    auto reset = static_cast<bool>(command.params.param1);

    UNUSED(reset);

    LogDebug() << "unsupported reset camera settings request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_set_camera_mode(const MavlinkCommandReceiver::CommandLong& command)
{
    auto camera_mode = static_cast<CAMERA_MODE>(command.params.param2);

    UNUSED(camera_mode);

    LogDebug() << "unsupported set camera mode request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_set_camera_zoom(const MavlinkCommandReceiver::CommandLong& command)
{
    auto zoom_type = static_cast<CAMERA_ZOOM_TYPE>(command.params.param1);
    auto zoom_value = command.params.param2;

    CameraServer::CameraZoomFocalLength zoom;

    switch (zoom_type) {
        case CAMERA_ZOOM_TYPE::ZOOM_TYPE_RANGE:
            zoom.normalized = zoom_value / 100.0f;
            zoom.length =
                zoom.normalized * (_focal_length_max - _focal_length_min) + _focal_length_min;
            break;
        case CAMERA_ZOOM_TYPE::ZOOM_TYPE_FOCAL_LENGTH:
            zoom.length = zoom_value;
            if (_focal_length_min > 0.0f || _focal_length_max > _focal_length_min) {
                zoom.normalized =
                    (zoom_value - _focal_length_min) / (_focal_length_max - _focal_length_min);
            }
            break;
        default:
            return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_DENIED);
    }

    auto ack_msg = _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_IN_PROGRESS);
    _parent->send_message(ack_msg);
    set_camera_zoom_callback(CameraServer::Result::Success, zoom);

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_set_camera_focus(const MavlinkCommandReceiver::CommandLong& command)
{
    auto focus_type = static_cast<SET_FOCUS_TYPE>(command.params.param1);
    auto focus_value = command.params.param2;

    CameraServer::CameraFocus focus;

    switch (focus_type) {
        case SET_FOCUS_TYPE::FOCUS_TYPE_STEP:
            focus.type = CameraServer::CameraFocusType::Step;
            if (focus_value < 0.0f) {
                focus.step_direction = CameraServer::CameraFocusStepDirection::In;
            } else {
                focus.step_direction = CameraServer::CameraFocusStepDirection::Out;
            }
            break;
        case SET_FOCUS_TYPE::FOCUS_TYPE_CONTINUOUS:
            focus.type = CameraServer::CameraFocusType::Continuous;
            focus.continuous = focus_value;
            break;
        case SET_FOCUS_TYPE::FOCUS_TYPE_RANGE:
            focus.type = CameraServer::CameraFocusType::Range;
            focus.normalized = focus_value / 100.0f;
            break;
        case SET_FOCUS_TYPE::FOCUS_TYPE_METERS:
            focus.type = CameraServer::CameraFocusType::Meters;
            focus.meters = focus_value;
            break;
        case SET_FOCUS_TYPE::FOCUS_TYPE_AUTO:
            focus.type = CameraServer::CameraFocusType::Auto;
            break;
        case SET_FOCUS_TYPE::FOCUS_TYPE_AUTO_SINGLE:
            focus.type = CameraServer::CameraFocusType::AutoSingle;
            break;
        case SET_FOCUS_TYPE::FOCUS_TYPE_AUTO_CONTINUOUS:
            focus.type = CameraServer::CameraFocusType::AutoContinuous;
            break;
        default:
            return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_DENIED);
    }

    auto ack_msg = _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_IN_PROGRESS);
    _parent->send_message(ack_msg);
    set_camera_focus_callback(CameraServer::Result::Success, focus);

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_set_storage_usage(const MavlinkCommandReceiver::CommandLong& command)
{
    auto storage_id = static_cast<uint8_t>(command.params.param1);
    auto usage = static_cast<STORAGE_USAGE_FLAG>(command.params.param2);

    UNUSED(storage_id);
    UNUSED(usage);

    LogDebug() << "unsupported set storage usage request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_image_start_capture(const MavlinkCommandReceiver::CommandLong& command)
{
    auto interval = command.params.param2;
    auto total_images = static_cast<uint32_t>(command.params.param3);
    auto seq_number = static_cast<uint32_t>(command.params.param4);

    UNUSED(interval);
    UNUSED(total_images);
    UNUSED(seq_number);

    // ack needs to be sent before camera information message
    auto ack_msg = _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_IN_PROGRESS);
    _parent->send_message(ack_msg);

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_ACCEPTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_image_stop_capture(const MavlinkCommandReceiver::CommandLong& command)
{
    LogDebug() << "unsupported image stop capture request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t> CameraServerImpl::process_camera_image_capture_request(
    const MavlinkCommandReceiver::CommandLong& command)
{
    auto seq_number = static_cast<uint32_t>(command.params.param1);

    UNUSED(seq_number);

    LogDebug() << "unsupported image capture request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_do_trigger_control(const MavlinkCommandReceiver::CommandLong& command)
{
    auto enable = static_cast<TriggerControl>(command.params.param1);
    auto reset = static_cast<TriggerControl>(command.params.param2);
    auto pause = static_cast<TriggerControl>(command.params.param3);

    UNUSED(enable);
    UNUSED(reset);
    UNUSED(pause);

    LogDebug() << "unsupported do trigger control request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_video_start_capture(const MavlinkCommandReceiver::CommandLong& command)
{
    auto stream_id = static_cast<uint8_t>(command.params.param1);
    auto status_frequency = command.params.param2;

    UNUSED(stream_id);
    UNUSED(status_frequency);

    LogDebug() << "unsupported video start capture request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_video_stop_capture(const MavlinkCommandReceiver::CommandLong& command)
{
    auto stream_id = static_cast<uint8_t>(command.params.param1);

    UNUSED(stream_id);

    LogDebug() << "unsupported video stop capture request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_video_start_streaming(const MavlinkCommandReceiver::CommandLong& command)
{
    auto stream_id = static_cast<uint8_t>(command.params.param1);

    UNUSED(stream_id);

    LogDebug() << "unsupported video start streaming request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t>
CameraServerImpl::process_video_stop_streaming(const MavlinkCommandReceiver::CommandLong& command)
{
    auto stream_id = static_cast<uint8_t>(command.params.param1);

    UNUSED(stream_id);

    LogDebug() << "unsupported video stop streaming request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t> CameraServerImpl::process_video_stream_information_request(
    const MavlinkCommandReceiver::CommandLong& command)
{
    auto stream_id = static_cast<uint8_t>(command.params.param1);

    UNUSED(stream_id);

    LogDebug() << "unsupported video stream information request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

std::optional<mavlink_message_t> CameraServerImpl::process_video_stream_status_request(
    const MavlinkCommandReceiver::CommandLong& command)
{
    auto stream_id = static_cast<uint8_t>(command.params.param1);

    UNUSED(stream_id);

    LogDebug() << "unsupported video stream status request";

    return _parent->make_command_ack_message(command, MAV_RESULT::MAV_RESULT_UNSUPPORTED);
}

} // namespace mavsdk
