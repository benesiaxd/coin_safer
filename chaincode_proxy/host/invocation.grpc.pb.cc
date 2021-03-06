// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: invocation.proto

#include "invocation.pb.h"
#include "invocation.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace invocation {

static const char* Invocation_method_names[] = {
  "/invocation.Invocation/TransactionInvocation",
};

std::unique_ptr< Invocation::Stub> Invocation::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Invocation::Stub> stub(new Invocation::Stub(channel));
  return stub;
}

Invocation::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_TransactionInvocation_(Invocation_method_names[0], ::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::ClientReaderWriter< ::invocation::ChaincodeWrapperMessage, ::invocation::ChaincodeProxyMessage>* Invocation::Stub::TransactionInvocationRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::invocation::ChaincodeWrapperMessage, ::invocation::ChaincodeProxyMessage>::Create(channel_.get(), rpcmethod_TransactionInvocation_, context);
}

void Invocation::Stub::experimental_async::TransactionInvocation(::grpc::ClientContext* context, ::grpc::experimental::ClientBidiReactor< ::invocation::ChaincodeWrapperMessage,::invocation::ChaincodeProxyMessage>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::invocation::ChaincodeWrapperMessage,::invocation::ChaincodeProxyMessage>::Create(stub_->channel_.get(), stub_->rpcmethod_TransactionInvocation_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::invocation::ChaincodeWrapperMessage, ::invocation::ChaincodeProxyMessage>* Invocation::Stub::AsyncTransactionInvocationRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::invocation::ChaincodeWrapperMessage, ::invocation::ChaincodeProxyMessage>::Create(channel_.get(), cq, rpcmethod_TransactionInvocation_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::invocation::ChaincodeWrapperMessage, ::invocation::ChaincodeProxyMessage>* Invocation::Stub::PrepareAsyncTransactionInvocationRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::invocation::ChaincodeWrapperMessage, ::invocation::ChaincodeProxyMessage>::Create(channel_.get(), cq, rpcmethod_TransactionInvocation_, context, false, nullptr);
}

Invocation::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Invocation_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< Invocation::Service, ::invocation::ChaincodeWrapperMessage, ::invocation::ChaincodeProxyMessage>(
          std::mem_fn(&Invocation::Service::TransactionInvocation), this)));
}

Invocation::Service::~Service() {
}

::grpc::Status Invocation::Service::TransactionInvocation(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::invocation::ChaincodeProxyMessage, ::invocation::ChaincodeWrapperMessage>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace invocation

