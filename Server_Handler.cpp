#include <array>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstddef>
#include <string>
#include <unistd.h>
#include <iostream>

#include "Server_Handler.hpp"

server_handler::server_handler():socket_fd(-1)
{}

bool server_handler::server_intit()
{
    int opt = 1;
    sockaddr_in address;
    socket_fd = socket(AF_INET,  SOCK_STREAM, 0);
    if(socket_fd < 0)
    {
        return false;
    }
    if (setsockopt(socket_fd, SOL_SOCKET, 
                   SO_REUSEADDR | SO_REUSEPORT, &opt, 
                   sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET;
    address.sin_addr.s_addr =inet_addr("192.168.1.108");//inet_addr("192.168.1.108");//INADDR_ANY; ;;    //inet_addr("192.168.1.255");
    address.sin_port = htons(8888);
    if (bind(socket_fd, (struct sockaddr*)&address, sizeof(address) ) < 0)
    {
        return false;
    }  
    return true;
}

bool server_handler::server_listen(){
    if(listen(socket_fd, 5) < 0)
    {
        return false;
    }



    return true;
}
bool server_handler::server_acceptClient(){
    if(!has_client)
    {
        ClientSocket_fd = accept(socket_fd, NULL, NULL);
    }
    if(ClientSocket_fd < 0)
    {
        has_client = false;
        return false;
    }
    has_client = true;
    return true;

}
void server_handler::server_SendMsg(const std::string msg){
     send(ClientSocket_fd,msg.c_str(), msg.size(), 0);
}
std::string server_handler::server_Read(){
    std::array<char, 256> msg;
    ssize_t bytesRead = recv(ClientSocket_fd,static_cast<void*>(msg.data()), sizeof(msg) - 1, 0);
   if (bytesRead == -1) {
     // Error occurred during recv()
    return "error happend during recv()";
}  else if (bytesRead == 0) {
     // Client closed the connection
    has_client = false;
    return "Client closed the connection";
}  else
    {
        std::string buffer(msg.data(), bytesRead);
        return buffer;
    }
    
    

}
void server_handler::server_closeConnection()
{
    close(ClientSocket_fd);
    ClientSocket_fd = -1;
}
 server_handler:: ~server_handler()
 {
    close(socket_fd);
 }