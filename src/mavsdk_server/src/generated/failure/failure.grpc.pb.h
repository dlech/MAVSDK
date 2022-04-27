// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: failure/failure.proto
#ifndef GRPC_failure_2ffailure_2eproto__INCLUDED
#define GRPC_failure_2ffailure_2eproto__INCLUDED

#include "failure/failure.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace mavsdk {
namespace rpc {
namespace failure {

// Inject failures into system to test failsafes.
class FailureService final {
public:
    static constexpr char const* service_full_name() { return "mavsdk.rpc.failure.FailureService"; }
    class StubInterface {
    public:
        virtual ~StubInterface() {}
        // Injects a failure.
        virtual ::grpc::Status Inject(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::mavsdk::rpc::failure::InjectResponse* response) = 0;
        std::unique_ptr<
            ::grpc::ClientAsyncResponseReaderInterface<::mavsdk::rpc::failure::InjectResponse>>
        AsyncInject(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::grpc::CompletionQueue* cq)
        {
            return std::unique_ptr<
                ::grpc::ClientAsyncResponseReaderInterface<::mavsdk::rpc::failure::InjectResponse>>(
                AsyncInjectRaw(context, request, cq));
        }
        std::unique_ptr<
            ::grpc::ClientAsyncResponseReaderInterface<::mavsdk::rpc::failure::InjectResponse>>
        PrepareAsyncInject(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::grpc::CompletionQueue* cq)
        {
            return std::unique_ptr<
                ::grpc::ClientAsyncResponseReaderInterface<::mavsdk::rpc::failure::InjectResponse>>(
                PrepareAsyncInjectRaw(context, request, cq));
        }
        class experimental_async_interface {
        public:
            virtual ~experimental_async_interface() {}
            // Injects a failure.
            virtual void Inject(
                ::grpc::ClientContext* context,
                const ::mavsdk::rpc::failure::InjectRequest* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                std::function<void(::grpc::Status)>) = 0;
            virtual void Inject(
                ::grpc::ClientContext* context,
                const ::grpc::ByteBuffer* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                std::function<void(::grpc::Status)>) = 0;
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
            virtual void Inject(
                ::grpc::ClientContext* context,
                const ::mavsdk::rpc::failure::InjectRequest* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                ::grpc::ClientUnaryReactor* reactor) = 0;
#else
            virtual void Inject(
                ::grpc::ClientContext* context,
                const ::mavsdk::rpc::failure::InjectRequest* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
#endif
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
            virtual void Inject(
                ::grpc::ClientContext* context,
                const ::grpc::ByteBuffer* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                ::grpc::ClientUnaryReactor* reactor) = 0;
#else
            virtual void Inject(
                ::grpc::ClientContext* context,
                const ::grpc::ByteBuffer* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
#endif
        };
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
        typedef class experimental_async_interface async_interface;
#endif
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
        async_interface* async() { return experimental_async(); }
#endif
        virtual class experimental_async_interface* experimental_async() { return nullptr; }

    private:
        virtual ::grpc::ClientAsyncResponseReaderInterface<::mavsdk::rpc::failure::InjectResponse>*
        AsyncInjectRaw(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::grpc::CompletionQueue* cq) = 0;
        virtual ::grpc::ClientAsyncResponseReaderInterface<::mavsdk::rpc::failure::InjectResponse>*
        PrepareAsyncInjectRaw(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::grpc::CompletionQueue* cq) = 0;
    };
    class Stub final : public StubInterface {
    public:
        Stub(const std::shared_ptr<::grpc::ChannelInterface>& channel);
        ::grpc::Status Inject(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::mavsdk::rpc::failure::InjectResponse* response) override;
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::mavsdk::rpc::failure::InjectResponse>>
        AsyncInject(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::grpc::CompletionQueue* cq)
        {
            return std::unique_ptr<
                ::grpc::ClientAsyncResponseReader<::mavsdk::rpc::failure::InjectResponse>>(
                AsyncInjectRaw(context, request, cq));
        }
        std::unique_ptr<::grpc::ClientAsyncResponseReader<::mavsdk::rpc::failure::InjectResponse>>
        PrepareAsyncInject(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::grpc::CompletionQueue* cq)
        {
            return std::unique_ptr<
                ::grpc::ClientAsyncResponseReader<::mavsdk::rpc::failure::InjectResponse>>(
                PrepareAsyncInjectRaw(context, request, cq));
        }
        class experimental_async final : public StubInterface::experimental_async_interface {
        public:
            void Inject(
                ::grpc::ClientContext* context,
                const ::mavsdk::rpc::failure::InjectRequest* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                std::function<void(::grpc::Status)>) override;
            void Inject(
                ::grpc::ClientContext* context,
                const ::grpc::ByteBuffer* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                std::function<void(::grpc::Status)>) override;
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
            void Inject(
                ::grpc::ClientContext* context,
                const ::mavsdk::rpc::failure::InjectRequest* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                ::grpc::ClientUnaryReactor* reactor) override;
#else
            void Inject(
                ::grpc::ClientContext* context,
                const ::mavsdk::rpc::failure::InjectRequest* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                ::grpc::experimental::ClientUnaryReactor* reactor) override;
#endif
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
            void Inject(
                ::grpc::ClientContext* context,
                const ::grpc::ByteBuffer* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                ::grpc::ClientUnaryReactor* reactor) override;
#else
            void Inject(
                ::grpc::ClientContext* context,
                const ::grpc::ByteBuffer* request,
                ::mavsdk::rpc::failure::InjectResponse* response,
                ::grpc::experimental::ClientUnaryReactor* reactor) override;
#endif
        private:
            friend class Stub;
            explicit experimental_async(Stub* stub) : stub_(stub) {}
            Stub* stub() { return stub_; }
            Stub* stub_;
        };
        class experimental_async_interface* experimental_async() override { return &async_stub_; }

    private:
        std::shared_ptr<::grpc::ChannelInterface> channel_;
        class experimental_async async_stub_ {
            this
        };
        ::grpc::ClientAsyncResponseReader<::mavsdk::rpc::failure::InjectResponse>* AsyncInjectRaw(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::grpc::CompletionQueue* cq) override;
        ::grpc::ClientAsyncResponseReader<::mavsdk::rpc::failure::InjectResponse>*
        PrepareAsyncInjectRaw(
            ::grpc::ClientContext* context,
            const ::mavsdk::rpc::failure::InjectRequest& request,
            ::grpc::CompletionQueue* cq) override;
        const ::grpc::internal::RpcMethod rpcmethod_Inject_;
    };
    static std::unique_ptr<Stub> NewStub(
        const std::shared_ptr<::grpc::ChannelInterface>& channel,
        const ::grpc::StubOptions& options = ::grpc::StubOptions());

    class Service : public ::grpc::Service {
    public:
        Service();
        virtual ~Service();
        // Injects a failure.
        virtual ::grpc::Status Inject(
            ::grpc::ServerContext* context,
            const ::mavsdk::rpc::failure::InjectRequest* request,
            ::mavsdk::rpc::failure::InjectResponse* response);
    };
    template<class BaseClass> class WithAsyncMethod_Inject : public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}

    public:
        WithAsyncMethod_Inject() { ::grpc::Service::MarkMethodAsync(0); }
        ~WithAsyncMethod_Inject() override { BaseClassMustBeDerivedFromService(this); }
        // disable synchronous version of this method
        ::grpc::Status Inject(
            ::grpc::ServerContext* /*context*/,
            const ::mavsdk::rpc::failure::InjectRequest* /*request*/,
            ::mavsdk::rpc::failure::InjectResponse* /*response*/) override
        {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestInject(
            ::grpc::ServerContext* context,
            ::mavsdk::rpc::failure::InjectRequest* request,
            ::grpc::ServerAsyncResponseWriter<::mavsdk::rpc::failure::InjectResponse>* response,
            ::grpc::CompletionQueue* new_call_cq,
            ::grpc::ServerCompletionQueue* notification_cq,
            void* tag)
        {
            ::grpc::Service::RequestAsyncUnary(
                0, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    typedef WithAsyncMethod_Inject<Service> AsyncService;
    template<class BaseClass> class ExperimentalWithCallbackMethod_Inject : public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}

    public:
        ExperimentalWithCallbackMethod_Inject()
        {
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
            ::grpc::Service::
#else
            ::grpc::Service::experimental().
#endif
                MarkMethodCallback(
                    0,
                    new ::grpc_impl::internal::CallbackUnaryHandler<
                        ::mavsdk::rpc::failure::InjectRequest,
                        ::mavsdk::rpc::failure::InjectResponse>(
                        [this](
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                            ::grpc::CallbackServerContext*
#else
                            ::grpc::experimental::CallbackServerContext*
#endif
                                context,
                            const ::mavsdk::rpc::failure::InjectRequest* request,
                            ::mavsdk::rpc::failure::InjectResponse* response) {
                            return this->Inject(context, request, response);
                        }));
        }
        void SetMessageAllocatorFor_Inject(::grpc::experimental::MessageAllocator<
                                           ::mavsdk::rpc::failure::InjectRequest,
                                           ::mavsdk::rpc::failure::InjectResponse>* allocator)
        {
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
            ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
#else
            ::grpc::internal::MethodHandler* const handler =
                ::grpc::Service::experimental().GetHandler(0);
#endif
            static_cast<::grpc_impl::internal::CallbackUnaryHandler<
                ::mavsdk::rpc::failure::InjectRequest,
                ::mavsdk::rpc::failure::InjectResponse>*>(handler)
                ->SetMessageAllocator(allocator);
        }
        ~ExperimentalWithCallbackMethod_Inject() override
        {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status Inject(
            ::grpc::ServerContext* /*context*/,
            const ::mavsdk::rpc::failure::InjectRequest* /*request*/,
            ::mavsdk::rpc::failure::InjectResponse* /*response*/) override
        {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
        virtual ::grpc::ServerUnaryReactor* Inject(
            ::grpc::CallbackServerContext* /*context*/,
            const ::mavsdk::rpc::failure::InjectRequest* /*request*/,
            ::mavsdk::rpc::failure::InjectResponse* /*response*/)
#else
        virtual ::grpc::experimental::ServerUnaryReactor* Inject(
            ::grpc::experimental::CallbackServerContext* /*context*/,
            const ::mavsdk::rpc::failure::InjectRequest* /*request*/,
            ::mavsdk::rpc::failure::InjectResponse* /*response*/)
#endif
        {
            return nullptr;
        }
    };
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef ExperimentalWithCallbackMethod_Inject<Service> CallbackService;
#endif

    typedef ExperimentalWithCallbackMethod_Inject<Service> ExperimentalCallbackService;
    template<class BaseClass> class WithGenericMethod_Inject : public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}

    public:
        WithGenericMethod_Inject() { ::grpc::Service::MarkMethodGeneric(0); }
        ~WithGenericMethod_Inject() override { BaseClassMustBeDerivedFromService(this); }
        // disable synchronous version of this method
        ::grpc::Status Inject(
            ::grpc::ServerContext* /*context*/,
            const ::mavsdk::rpc::failure::InjectRequest* /*request*/,
            ::mavsdk::rpc::failure::InjectResponse* /*response*/) override
        {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
    };
    template<class BaseClass> class WithRawMethod_Inject : public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}

    public:
        WithRawMethod_Inject() { ::grpc::Service::MarkMethodRaw(0); }
        ~WithRawMethod_Inject() override { BaseClassMustBeDerivedFromService(this); }
        // disable synchronous version of this method
        ::grpc::Status Inject(
            ::grpc::ServerContext* /*context*/,
            const ::mavsdk::rpc::failure::InjectRequest* /*request*/,
            ::mavsdk::rpc::failure::InjectResponse* /*response*/) override
        {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        void RequestInject(
            ::grpc::ServerContext* context,
            ::grpc::ByteBuffer* request,
            ::grpc::ServerAsyncResponseWriter<::grpc::ByteBuffer>* response,
            ::grpc::CompletionQueue* new_call_cq,
            ::grpc::ServerCompletionQueue* notification_cq,
            void* tag)
        {
            ::grpc::Service::RequestAsyncUnary(
                0, context, request, response, new_call_cq, notification_cq, tag);
        }
    };
    template<class BaseClass> class ExperimentalWithRawCallbackMethod_Inject : public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}

    public:
        ExperimentalWithRawCallbackMethod_Inject()
        {
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
            ::grpc::Service::
#else
            ::grpc::Service::experimental().
#endif
                MarkMethodRawCallback(
                    0,
                    new ::grpc_impl::internal::
                        CallbackUnaryHandler<::grpc::ByteBuffer, ::grpc::ByteBuffer>(
                            [this](
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                                ::grpc::CallbackServerContext*
#else
                                ::grpc::experimental::CallbackServerContext*
#endif
                                    context,
                                const ::grpc::ByteBuffer* request,
                                ::grpc::ByteBuffer* response) {
                                return this->Inject(context, request, response);
                            }));
        }
        ~ExperimentalWithRawCallbackMethod_Inject() override
        {
            BaseClassMustBeDerivedFromService(this);
        }
        // disable synchronous version of this method
        ::grpc::Status Inject(
            ::grpc::ServerContext* /*context*/,
            const ::mavsdk::rpc::failure::InjectRequest* /*request*/,
            ::mavsdk::rpc::failure::InjectResponse* /*response*/) override
        {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
#ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
        virtual ::grpc::ServerUnaryReactor* Inject(
            ::grpc::CallbackServerContext* /*context*/,
            const ::grpc::ByteBuffer* /*request*/,
            ::grpc::ByteBuffer* /*response*/)
#else
        virtual ::grpc::experimental::ServerUnaryReactor* Inject(
            ::grpc::experimental::CallbackServerContext* /*context*/,
            const ::grpc::ByteBuffer* /*request*/,
            ::grpc::ByteBuffer* /*response*/)
#endif
        {
            return nullptr;
        }
    };
    template<class BaseClass> class WithStreamedUnaryMethod_Inject : public BaseClass {
    private:
        void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}

    public:
        WithStreamedUnaryMethod_Inject()
        {
            ::grpc::Service::MarkMethodStreamed(
                0,
                new ::grpc::internal::StreamedUnaryHandler<
                    ::mavsdk::rpc::failure::InjectRequest,
                    ::mavsdk::rpc::failure::InjectResponse>(
                    [this](
                        ::grpc_impl::ServerContext* context,
                        ::grpc_impl::ServerUnaryStreamer<
                            ::mavsdk::rpc::failure::InjectRequest,
                            ::mavsdk::rpc::failure::InjectResponse>* streamer) {
                        return this->StreamedInject(context, streamer);
                    }));
        }
        ~WithStreamedUnaryMethod_Inject() override { BaseClassMustBeDerivedFromService(this); }
        // disable regular version of this method
        ::grpc::Status Inject(
            ::grpc::ServerContext* /*context*/,
            const ::mavsdk::rpc::failure::InjectRequest* /*request*/,
            ::mavsdk::rpc::failure::InjectResponse* /*response*/) override
        {
            abort();
            return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
        }
        // replace default version of method with streamed unary
        virtual ::grpc::Status StreamedInject(
            ::grpc::ServerContext* context,
            ::grpc::ServerUnaryStreamer<
                ::mavsdk::rpc::failure::InjectRequest,
                ::mavsdk::rpc::failure::InjectResponse>* server_unary_streamer) = 0;
    };
    typedef WithStreamedUnaryMethod_Inject<Service> StreamedUnaryService;
    typedef Service SplitStreamedService;
    typedef WithStreamedUnaryMethod_Inject<Service> StreamedService;
};

} // namespace failure
} // namespace rpc
} // namespace mavsdk

#endif // GRPC_failure_2ffailure_2eproto__INCLUDED
