#ifndef EXCUTE_COMMAND_ 
#define EXCUTE_COMMAND_   
#include <vector>
#include <string>
#include <map>
class command{
    public:

    command();
    ~command()=default;
    std::string execute_command(std::string cmd);



    private:
        std::map<std::string, std::string>  commands;


};


#endif 