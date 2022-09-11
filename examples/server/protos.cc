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

#include "protos.h"

using noelware::analytics::protobufs::ConnectionAckResponse;
using noelware::analytics::protobufs::ReceiveStatsResponse;
using noelware::analytics::protobufs::ConnectionAckRequest;
using noelware::analytics::protobufs::ReceiveStatsRequest;
using noelware::analytics::protobufs::BuildFlavour;
using noelware::analytics::protobufs::Analytics;
using google::protobuf::Timestamp;
using google::protobuf::Struct;
using grpc::ServerContext;
using grpc::Status;
using std::string;

namespace examples {
  Status AnalyticsImpl::ConnectionAck(ServerContext* context, const ConnectionAckRequest* request, ConnectionAckResponse* res) {
    // We're only using the stub UUID that is present in the documentation https://analytics.noelware.org/docs
    string uuid("0e2a7451-2b50-46c3-8481-8c7bd26de7cc");

    res->set_connected(true);
    res->set_instanceuuid(uuid);

    return Status::OK;
  }

  Status AnalyticsImpl::RetrieveStats(ServerContext* context, const ReceiveStatsRequest* request, ReceiveStatsResponse* res) {
    string example_build_date("2022-09-11T07:30:25.052Z");
    string example_version("1.2.3-nightly.0");
    string example_commit_sha("abcdefgh");
    string example_product("charted-server");

    // TODO: make this accessible with windows
    struct timeval tv;
    gettimeofday(&tv, NULL);

    Timestamp timestamp;
    timestamp.set_seconds(tv.tv_sec);
    timestamp.set_nanos(tv.tv_usec * 1000);

    res->set_builddate(example_build_date);
    res->set_commitsha(example_commit_sha);
    res->set_version(example_version);
    res->set_product(example_product);
    res->set_allocated_snapshotdate(&timestamp);
    res->set_buildflavour(BuildFlavour::GIT);
    res->set_allocated_data(NULL);

    return Status::OK;
  }
}
