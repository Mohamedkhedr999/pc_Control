#include <iostream>
#include "Server_Handler.hpp"
#include "execute_command.hpp"


int main() {

    server_handler myserver;
    command executor;
    std::string buffer;
    bool has_client = false;

    while(!(myserver.server_intit()));
    while(!(myserver.server_listen()));
    std::cout<<"server created"<<std::endl;

    while(true)
    {
        
           
           

        

        if(myserver.server_acceptClient())
        {
            myserver.server_SendMsg("------------------------------------------\n");
            myserver.server_SendMsg("menu\n");
            myserver.server_SendMsg("enter one command\n");
            myserver.server_SendMsg("1-calculator\n");
            myserver.server_SendMsg("2-terminal\n");
            myserver.server_SendMsg("3-date\n");
            myserver.server_SendMsg("4-battery\n");
            myserver.server_SendMsg("5-shutdown\n");
            myserver.server_SendMsg("6-firefox\n");

            
            buffer = myserver.server_Read();
            std::cout<<buffer<<std::endl;
            buffer = executor.execute_command(buffer);
            std::cout<<buffer<<std::endl;
            myserver.server_SendMsg(buffer);
            

            
            


        }
               


    }








    return 0;
}
