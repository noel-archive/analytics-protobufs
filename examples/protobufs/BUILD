# 🧭🐃 analytics-protobufs: Protocol Buffers for Noelware Analytics
# Copyright (c) 2022 Noelware
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library", "cpp_grpc_library")

cpp_proto_library(
  name = "connection_proto_cc",
  protos = [":connection_proto"]
)

proto_library(
  name = "connection_proto",
  srcs = ["connection.proto"],
  deps = [
    "@com_google_protobuf//:timestamp_proto",
    "@com_google_protobuf//:struct_proto"
  ]
)

cpp_grpc_library(
  name = "connection_proto_grpc",
  protos = [":connection_proto"],
  deps = [":connection_proto_cc"],
  visibility = ["//visibility:public"]
)
