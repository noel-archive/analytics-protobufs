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

load("@com_github_grpc_grpc//bazel:cc_grpc_library.bzl", "cc_grpc_library")
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

licenses(["notice"])
package(default_visibility = ["//visibility:public"])

proto_library(
  name = "analytics_proto",
  srcs = ["connection.proto"]
)

cc_proto_library(
  name = "analytics_cc_proto",
  deps = [":analytics_proto"]
)

cc_grpc_library(
  name = "analytics_cc_grpc",
  srcs = [":analytics_proto"],
  grpc_only = True,
  deps = [":analytics_cc_proto"]
)

cc_binary(
  name = "analytics_client",
  srcs = ["client.cc"],
  defines = ["BAZEL_BUILD"],
  deps = [
    ":analytics_cc_grpc",
    "@com_github_grpc_grpc//:grpc++"
  ]
)

cc_binary(
  name = "analytics_server",
  srcs = ["server.cc"],
  defines = ["BAZEL_BUILD"],
  deps = [
    ":analytics_cc_grpc",
    "@com_github_grpc_grpc//:grpc++"
  ]
)
