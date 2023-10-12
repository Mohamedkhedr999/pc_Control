#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "execute_command.hpp"

command::command() : commands{{"calculator","gnome-calculator"},
                              {"terminal","gnome-terminal"},
                              {"firefox","firefox"},
                              {"date","date"},
                              {"battery","upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep 'percentage'"},
                              {"shutdown","shutdown now"}}{

}


std::string command::execute_command(std::string cmd){
    auto it = commands.find(cmd);
    if (it != commands.end()) {
        std::string command = it->second + " &";
        int result = system(command.c_str());
        if (result == 0) {
            return "command executed";
        } else {
            return "command execution failed";
        }
    } else {
        return "wrong command";
    }
}