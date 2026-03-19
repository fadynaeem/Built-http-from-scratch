#include "../include/server.hpp"
void Server::processMiddlewares(Request& request, Response& response,int index) {
    if (index < middlewares.size()) {
        middlewares[index](request, response, [this, &request, &response, index] {
            processMiddlewares(request, response, index + 1);
        });
    } else {
        if (!router.handle(request, response)) {
            response.setStatus(404, "Not Found");
            response.text("404 Not Found");
        }
    }
}
