# Noelware Analytics Protobuf Examples
This directory tests the **connection.proto** file that is used. It uses Bazel and C++ as an example, because why not?

## Server
> At the moment, the RetrieveStats method will segfault. At the time of writing this (11.09.22 @ 01:11 AM MST), I don't feel like
> fixing it right now.

```sh
$ bazel run //server:analytics_server
# INFO: Build option --features has changed, discarding analysis cache.
# INFO: Analyzed target //server:analytics_server (0 packages loaded, 4225 targets configured).
# INFO: Found 1 target...
# Target //server:analytics_server up-to-date:
#   bazel-bin/server/analytics_server
# INFO: Elapsed time: 3.430s, Critical Path: 2.66s
# INFO: 4 processes: 1 internal, 3 linux-sandbox.
# INFO: Build completed successfully, 4 total actions
# INFO: Build completed successfully, 4 total actions
```

## Client
```sh
$ bazel run //client:analytics_client
```
