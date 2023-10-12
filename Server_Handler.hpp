#ifndef SERVER_HANDLER_
#define SERVER_HANDLER_   

#include <netinet/in.h>
#include <string>

class server_handler{


    public:
    server_handler();
    bool server_intit();
    bool server_listen();
    bool server_acceptClient();
    void server_SendMsg( std::string msg);
    std::string server_Read();
    void server_closeConnection();
    ~server_handler();





    private:
    char buffer[256];
    bool has_client = false;

    int socket_fd;
    int ClientSocket_fd;
    struct sockaddr_in address;





};

#endif // !SERVER_HANDLER_
