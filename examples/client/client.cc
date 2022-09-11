// 🧭🐃 analytics-protobufs: Protocol Buffers for Noelware Analytics
// Copyright (c) 2022 Noelware
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <string>
#include <google/protobuf/timestamp.pb.h>
#include <google/protobuf/struct.pb.h>
#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "protobufs/connection.grpc.pb.h"
#else
#include "protobufs/connection.grpc.pb.h"
#endif

using noelware::analytics::protobufs::ConnectionAckResponse;
using noelware::analytics::protobufs::ReceiveStatsResponse;
using noelware::analytics::protobufs::ConnectionAckRequest;
using noelware::analytics::protobufs::ReceiveStatsRequest;
using noelware::analytics::protobufs::BuildFlavour;
using noelware::analytics::protobufs::Analytics;
using google::protobuf::Timestamp;
using google::protobuf::Struct;
using grpc::ClientContext;
using grpc::Channel;
using grpc::Status;
using std::string;

class AnalyticsClient {
  public:
    AnalyticsClient(std::shared_ptr<Channel> channel)
      : stub_(Analytics::NewStub(channel)) {}

    bool ConnectionAck() {
      ConnectionAckRequest request;
      ConnectionAckResponse res;
      ClientContext context;

      Status status = stub_->ConnectionAck(&context, request, &res);
      if (status.ok()) {
        std::cout << "was a success!" << std::endl;
        return true;
      } else {
        std::cout << "was a failure! :(" << std::endl;
        return false;
      }
    }
    
    bool RetrieveStats() {
      ClientContext context;
      ReceiveStatsRequest request;
      ReceiveStatsResponse res;

      Status status = stub_->RetrieveStats(&context, request, &res);
      if (status.ok()) {
        std::cout << "was a success!" << std::endl;
        return true;
      } else {
        auto code = status.error_code();

        std::cout << "code [" << code << "]" << std::endl;
        std::cout << "was a failure! :(" << std::endl;
        return false;
      }
    }

  private:
    std::unique_ptr<Analytics::Stub> stub_;
};

int main(int argc, char** argv) {
  std::cout << "connecting to server..." << std::endl;

  AnalyticsClient client(grpc::CreateChannel("0.0.0.0:50051", grpc::InsecureChannelCredentials()));
  bool res1 = client.ConnectionAck();
  bool res2 = client.RetrieveStats();

  return 0;
}
