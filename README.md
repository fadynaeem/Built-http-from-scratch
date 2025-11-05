## Built-HTTP (1.1 & 2.0) From Scratch
This repository contains a from-scratch, multi-threaded HTTP server written in C++ with middleware support. The goal is to provide a clear, modular architecture for understanding how HTTP works at a low level, from socket management to protocol parsing and request routing. This README first explains the server & client architecture, then clarifies the differences between sending messages and handling requests in HTTP/1.1 vs HTTP/2.

## File quick reference

- `include/server.hpp` — Declares the Server interface: configuration (host/port/backlog/thread-count), socket setup & lifecycle (socket/bind/listen, non-blocking)
- `include/Router.h` / `src/Router.cpp` — route registration and dispatch.
- `include/Request.h`, `include/Response.h` — request/response data types.
- `include/ThreadPool.h` / `include/ThreadPool.inl` / `src/ThreadPool.cpp` — thread pool implementation.
- `src/main.cpp` — program entrypoint.
- `core/App.h` / `core/App.cpp` — probable application wiring (registering routes, middleware).
