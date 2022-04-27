// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: core/core.proto

#include "core/core.pb.h"
#include "core/core.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace mavsdk {
namespace rpc {
namespace core {

static const char* CoreService_method_names[] = {
  "/mavsdk.rpc.core.CoreService/SubscribeConnectionState",
  "/mavsdk.rpc.core.CoreService/SetMavlinkTimeout",
};

std::unique_ptr< CoreService::Stub> CoreService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< CoreService::Stub> stub(new CoreService::Stub(channel));
  return stub;
}

CoreService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_SubscribeConnectionState_(CoreService_method_names[0], ::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_SetMavlinkTimeout_(CoreService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::ClientReader< ::mavsdk::rpc::core::ConnectionStateResponse>* CoreService::Stub::SubscribeConnectionStateRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::core::SubscribeConnectionStateRequest& request) {
  return ::grpc_impl::internal::ClientReaderFactory< ::mavsdk::rpc::core::ConnectionStateResponse>::Create(channel_.get(), rpcmethod_SubscribeConnectionState_, context, request);
}

void CoreService::Stub::experimental_async::SubscribeConnectionState(::grpc::ClientContext* context, ::mavsdk::rpc::core::SubscribeConnectionStateRequest* request, ::grpc::experimental::ClientReadReactor< ::mavsdk::rpc::core::ConnectionStateResponse>* reactor) {
  ::grpc_impl::internal::ClientCallbackReaderFactory< ::mavsdk::rpc::core::ConnectionStateResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_SubscribeConnectionState_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::mavsdk::rpc::core::ConnectionStateResponse>* CoreService::Stub::AsyncSubscribeConnectionStateRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::core::SubscribeConnectionStateRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc_impl::internal::ClientAsyncReaderFactory< ::mavsdk::rpc::core::ConnectionStateResponse>::Create(channel_.get(), cq, rpcmethod_SubscribeConnectionState_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::mavsdk::rpc::core::ConnectionStateResponse>* CoreService::Stub::PrepareAsyncSubscribeConnectionStateRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::core::SubscribeConnectionStateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncReaderFactory< ::mavsdk::rpc::core::ConnectionStateResponse>::Create(channel_.get(), cq, rpcmethod_SubscribeConnectionState_, context, request, false, nullptr);
}

::grpc::Status CoreService::Stub::SetMavlinkTimeout(::grpc::ClientContext* context, const ::mavsdk::rpc::core::SetMavlinkTimeoutRequest& request, ::mavsdk::rpc::core::SetMavlinkTimeoutResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_SetMavlinkTimeout_, context, request, response);
}

void CoreService::Stub::experimental_async::SetMavlinkTimeout(::grpc::ClientContext* context, const ::mavsdk::rpc::core::SetMavlinkTimeoutRequest* request, ::mavsdk::rpc::core::SetMavlinkTimeoutResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SetMavlinkTimeout_, context, request, response, std::move(f));
}

void CoreService::Stub::experimental_async::SetMavlinkTimeout(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::core::SetMavlinkTimeoutResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_SetMavlinkTimeout_, context, request, response, std::move(f));
}

void CoreService::Stub::experimental_async::SetMavlinkTimeout(::grpc::ClientContext* context, const ::mavsdk::rpc::core::SetMavlinkTimeoutRequest* request, ::mavsdk::rpc::core::SetMavlinkTimeoutResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SetMavlinkTimeout_, context, request, response, reactor);
}

void CoreService::Stub::experimental_async::SetMavlinkTimeout(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::mavsdk::rpc::core::SetMavlinkTimeoutResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_SetMavlinkTimeout_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::core::SetMavlinkTimeoutResponse>* CoreService::Stub::AsyncSetMavlinkTimeoutRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::core::SetMavlinkTimeoutRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::core::SetMavlinkTimeoutResponse>::Create(channel_.get(), cq, rpcmethod_SetMavlinkTimeout_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::mavsdk::rpc::core::SetMavlinkTimeoutResponse>* CoreService::Stub::PrepareAsyncSetMavlinkTimeoutRaw(::grpc::ClientContext* context, const ::mavsdk::rpc::core::SetMavlinkTimeoutRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::mavsdk::rpc::core::SetMavlinkTimeoutResponse>::Create(channel_.get(), cq, rpcmethod_SetMavlinkTimeout_, context, request, false);
}

CoreService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      CoreService_method_names[0],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< CoreService::Service, ::mavsdk::rpc::core::SubscribeConnectionStateRequest, ::mavsdk::rpc::core::ConnectionStateResponse>(
          [](CoreService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::mavsdk::rpc::core::SubscribeConnectionStateRequest* req,
             ::grpc_impl::ServerWriter<::mavsdk::rpc::core::ConnectionStateResponse>* writer) {
               return service->SubscribeConnectionState(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      CoreService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< CoreService::Service, ::mavsdk::rpc::core::SetMavlinkTimeoutRequest, ::mavsdk::rpc::core::SetMavlinkTimeoutResponse>(
          [](CoreService::Service* service,
             ::grpc_impl::ServerContext* ctx,
             const ::mavsdk::rpc::core::SetMavlinkTimeoutRequest* req,
             ::mavsdk::rpc::core::SetMavlinkTimeoutResponse* resp) {
               return service->SetMavlinkTimeout(ctx, req, resp);
             }, this)));
}

CoreService::Service::~Service() {
}

::grpc::Status CoreService::Service::SubscribeConnectionState(::grpc::ServerContext* context, const ::mavsdk::rpc::core::SubscribeConnectionStateRequest* request, ::grpc::ServerWriter< ::mavsdk::rpc::core::ConnectionStateResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status CoreService::Service::SetMavlinkTimeout(::grpc::ServerContext* context, const ::mavsdk::rpc::core::SetMavlinkTimeoutRequest* request, ::mavsdk::rpc::core::SetMavlinkTimeoutResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace mavsdk
}  // namespace rpc
}  // namespace core

