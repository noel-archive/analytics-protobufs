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
using noelware::analytics::protobufs::Analytics;
using grpc::ServerContext;
using grpc::Status;

namespace examples {
  class AnalyticsImpl final : public Analytics::Service {
    Status ConnectionAck(ServerContext* context, const ConnectionAckRequest* request, ConnectionAckResponse* res) override;
    Status RetrieveStats(ServerContext* context, const ReceiveStatsRequest* request, ReceiveStatsResponse* res) override;
  };
}
