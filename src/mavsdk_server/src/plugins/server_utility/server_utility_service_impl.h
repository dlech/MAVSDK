// WARNING: THIS FILE IS AUTOGENERATED! As such, it should not be edited.
// Edits need to be made to the proto files
// (see
// https://github.com/mavlink/MAVSDK-Proto/blob/master/protos/server_utility/server_utility.proto)

#include "server_utility/server_utility.grpc.pb.h"
#include "plugins/server_utility/server_utility.h"

#include "mavsdk.h"
#include "lazy_plugin.h"
#include "log.h"
#include <atomic>
#include <cmath>
#include <future>
#include <limits>
#include <memory>
#include <sstream>
#include <vector>

namespace mavsdk {
namespace mavsdk_server {

template<typename ServerUtility = ServerUtility, typename LazyPlugin = LazyPlugin<ServerUtility>>
class ServerUtilityServiceImpl final : public rpc::server_utility::ServerUtilityService::Service {
public:
    ServerUtilityServiceImpl(LazyPlugin& lazy_plugin) : _lazy_plugin(lazy_plugin) {}

    template<typename ResponseType>
    void fillResponseWithResult(ResponseType* response, mavsdk::ServerUtility::Result& result) const
    {
        auto rpc_result = translateToRpcResult(result);

        auto* rpc_server_utility_result = new rpc::server_utility::ServerUtilityResult();
        rpc_server_utility_result->set_result(rpc_result);
        std::stringstream ss;
        ss << result;
        rpc_server_utility_result->set_result_str(ss.str());

        response->set_allocated_server_utility_result(rpc_server_utility_result);
    }

    static rpc::server_utility::StatusTextType
    translateToRpcStatusTextType(const mavsdk::ServerUtility::StatusTextType& status_text_type)
    {
        switch (status_text_type) {
            default:
                LogErr() << "Unknown status_text_type enum value: "
                         << static_cast<int>(status_text_type);
            // FALLTHROUGH
            case mavsdk::ServerUtility::StatusTextType::Debug:
                return rpc::server_utility::STATUS_TEXT_TYPE_DEBUG;
            case mavsdk::ServerUtility::StatusTextType::Info:
                return rpc::server_utility::STATUS_TEXT_TYPE_INFO;
            case mavsdk::ServerUtility::StatusTextType::Notice:
                return rpc::server_utility::STATUS_TEXT_TYPE_NOTICE;
            case mavsdk::ServerUtility::StatusTextType::Warning:
                return rpc::server_utility::STATUS_TEXT_TYPE_WARNING;
            case mavsdk::ServerUtility::StatusTextType::Error:
                return rpc::server_utility::STATUS_TEXT_TYPE_ERROR;
            case mavsdk::ServerUtility::StatusTextType::Critical:
                return rpc::server_utility::STATUS_TEXT_TYPE_CRITICAL;
            case mavsdk::ServerUtility::StatusTextType::Alert:
                return rpc::server_utility::STATUS_TEXT_TYPE_ALERT;
            case mavsdk::ServerUtility::StatusTextType::Emergency:
                return rpc::server_utility::STATUS_TEXT_TYPE_EMERGENCY;
        }
    }

    static mavsdk::ServerUtility::StatusTextType
    translateFromRpcStatusTextType(const rpc::server_utility::StatusTextType status_text_type)
    {
        switch (status_text_type) {
            default:
                LogErr() << "Unknown status_text_type enum value: "
                         << static_cast<int>(status_text_type);
            // FALLTHROUGH
            case rpc::server_utility::STATUS_TEXT_TYPE_DEBUG:
                return mavsdk::ServerUtility::StatusTextType::Debug;
            case rpc::server_utility::STATUS_TEXT_TYPE_INFO:
                return mavsdk::ServerUtility::StatusTextType::Info;
            case rpc::server_utility::STATUS_TEXT_TYPE_NOTICE:
                return mavsdk::ServerUtility::StatusTextType::Notice;
            case rpc::server_utility::STATUS_TEXT_TYPE_WARNING:
                return mavsdk::ServerUtility::StatusTextType::Warning;
            case rpc::server_utility::STATUS_TEXT_TYPE_ERROR:
                return mavsdk::ServerUtility::StatusTextType::Error;
            case rpc::server_utility::STATUS_TEXT_TYPE_CRITICAL:
                return mavsdk::ServerUtility::StatusTextType::Critical;
            case rpc::server_utility::STATUS_TEXT_TYPE_ALERT:
                return mavsdk::ServerUtility::StatusTextType::Alert;
            case rpc::server_utility::STATUS_TEXT_TYPE_EMERGENCY:
                return mavsdk::ServerUtility::StatusTextType::Emergency;
        }
    }

    static rpc::server_utility::ServerUtilityResult::Result
    translateToRpcResult(const mavsdk::ServerUtility::Result& result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case mavsdk::ServerUtility::Result::Unknown:
                return rpc::server_utility::ServerUtilityResult_Result_RESULT_UNKNOWN;
            case mavsdk::ServerUtility::Result::Success:
                return rpc::server_utility::ServerUtilityResult_Result_RESULT_SUCCESS;
            case mavsdk::ServerUtility::Result::NoSystem:
                return rpc::server_utility::ServerUtilityResult_Result_RESULT_NO_SYSTEM;
            case mavsdk::ServerUtility::Result::ConnectionError:
                return rpc::server_utility::ServerUtilityResult_Result_RESULT_CONNECTION_ERROR;
            case mavsdk::ServerUtility::Result::InvalidArgument:
                return rpc::server_utility::ServerUtilityResult_Result_RESULT_INVALID_ARGUMENT;
        }
    }

    static mavsdk::ServerUtility::Result
    translateFromRpcResult(const rpc::server_utility::ServerUtilityResult::Result result)
    {
        switch (result) {
            default:
                LogErr() << "Unknown result enum value: " << static_cast<int>(result);
            // FALLTHROUGH
            case rpc::server_utility::ServerUtilityResult_Result_RESULT_UNKNOWN:
                return mavsdk::ServerUtility::Result::Unknown;
            case rpc::server_utility::ServerUtilityResult_Result_RESULT_SUCCESS:
                return mavsdk::ServerUtility::Result::Success;
            case rpc::server_utility::ServerUtilityResult_Result_RESULT_NO_SYSTEM:
                return mavsdk::ServerUtility::Result::NoSystem;
            case rpc::server_utility::ServerUtilityResult_Result_RESULT_CONNECTION_ERROR:
                return mavsdk::ServerUtility::Result::ConnectionError;
            case rpc::server_utility::ServerUtilityResult_Result_RESULT_INVALID_ARGUMENT:
                return mavsdk::ServerUtility::Result::InvalidArgument;
        }
    }

    grpc::Status SendStatusText(
        grpc::ServerContext* /* context */,
        const rpc::server_utility::SendStatusTextRequest* request,
        rpc::server_utility::SendStatusTextResponse* response) override
    {
        if (_lazy_plugin.maybe_plugin() == nullptr) {
            if (response != nullptr) {
                auto result = mavsdk::ServerUtility::Result::NoSystem;
                fillResponseWithResult(response, result);
            }

            return grpc::Status::OK;
        }

        if (request == nullptr) {
            LogWarn() << "SendStatusText sent with a null request! Ignoring...";
            return grpc::Status::OK;
        }

        auto result = _lazy_plugin.maybe_plugin()->send_status_text(
            translateFromRpcStatusTextType(request->type()), request->text());

        if (response != nullptr) {
            fillResponseWithResult(response, result);
        }

        return grpc::Status::OK;
    }

    void stop()
    {
        _stopped.store(true);
        for (auto& prom : _stream_stop_promises) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        }
    }

private:
    void register_stream_stop_promise(std::weak_ptr<std::promise<void>> prom)
    {
        // If we have already stopped, set promise immediately and don't add it to list.
        if (_stopped.load()) {
            if (auto handle = prom.lock()) {
                handle->set_value();
            }
        } else {
            _stream_stop_promises.push_back(prom);
        }
    }

    void unregister_stream_stop_promise(std::shared_ptr<std::promise<void>> prom)
    {
        for (auto it = _stream_stop_promises.begin(); it != _stream_stop_promises.end();
             /* ++it */) {
            if (it->lock() == prom) {
                it = _stream_stop_promises.erase(it);
            } else {
                ++it;
            }
        }
    }

    LazyPlugin& _lazy_plugin;
    std::atomic<bool> _stopped{false};
    std::vector<std::weak_ptr<std::promise<void>>> _stream_stop_promises{};
};

} // namespace mavsdk_server
} // namespace mavsdk