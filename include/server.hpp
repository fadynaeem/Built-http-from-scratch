#ifndef SERVER_HPP
#define SERVER_HPP
#include <string>
#include <functional>
#include <vector>
#include <cstddef>
#include "PlatformSockets.h"
#include "Router.h"
#include "Request.h"
#include "Response.h"
#include "ThreadPool.h"
class Server {
private:
	int port;
	int server_fd;
	struct sockaddr_in address;
	Router router;
	ThreadPool thread_pool;
	std::vector<std::function<void(Request&, Response&, std::function<void()>)>> middlewares;
	void handleRequest(int new_socket);
	void processMiddlewares(Request& request, Response& response, int index);
	void setupServer();
public:
	Server(int port, int num_threads);
	void start();
	void addRoute(const std::string& path, const std::string& method, void(*handler)(Request&, Response&));
	void use(std::function<void(Request&, Response&, std::function<void()>)> middleware);
	Router& getRouter();
};
#endif // SERVER_HPP
