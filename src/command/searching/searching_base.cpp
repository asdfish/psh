#include <command/searching/searching_base.hpp>

#include <cstring>
#include <iostream>

void SearchingBase::execute(const std::vector<std::string>& arguments, ProcessList& process_list, MainState& main_state) {
  if(arguments.size() == 1) {
    this->default_callback(process_list, main_state);
    return;
  }

  for(size_t i = 1; i < arguments.size(); i ++) {
    const char* argument = arguments[i].c_str();
    char* end_pointer = NULL;

    long argument_l = std::strtol(argument, &end_pointer, 10);
    if(std::strcmp(end_pointer, argument) == 0) {
      for(Process& process : process_list.processes)
        if(process.name.find(arguments[i]) != std::string::npos)
          this->matching_callback(process, main_state);
    } else {
      for(Process& process : process_list.processes)
        if((DWORD) argument_l == process.id)
          this->matching_callback(process, main_state);
    }
  }
}
