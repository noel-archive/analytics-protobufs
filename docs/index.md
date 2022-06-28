---
title: Protocol Buffers for Analytics Engine
description: Main page about the Protocol Buffers for Noelware Analytics.

---

# Protocol Buffers for Analytics Engine
This is the main documentation about the Protocol Buffers for the Analytics Engine which includes server and client types.

## Server
The analytics engine will need a seperate gRPC instance running as the product grows. So, you will need to provide a `/grpc` endpoint, this is supported in **Arisu** and **charted-server**, so, you can just register it and it'll just work.

To provide a server for it (if you do wish to use the Analytics engine), we have server libraries for:

- [Kotlin](https://github.com/Noelware/analytics-kotlin) [org.noelware.analytics.server]
- [Go](https://github.com/Noelware/analytics-go) [github.com/Noelware/analytics-go/server]

So you can just drop and place it and it'll run the service in the background with the rest of the HTTP endpoints you build.

To include the protobufs, you will need to create a submodule for it:

```ignore name=.gitmodules
[submodule "protos"]
    path = protos
    url = https://github.com/Noelware/analytics-protobufs.git
```

and then do `git submodule update` and you should have the protobufs available.

## Libraries
We have support for [Kotlin](https://github.com/Noelware/analytics-kotlin) and [Go](https://github.com/Noelware/analytics-go)

- **Kotlin**:
  - Protocol Buffers Package: `org.noelware.analytics.protobufs.v1`
  - Client Package: `org.noelware.analytics.client`
- **Go**
  - Protocol Buffers Package: `github.com/Noelware/analytics-go/protobufs/v1`
  - Client Package: `github.com/Noelware/analytics-go/client`
