#ifndef COMMAND_BASE_HPP
#define COMMAND_BASE_HPP

#include <main.hpp>
#include <process_list.hpp>

#include <string>
#include <vector>

class CommandBase {
  public:
    CommandBase(void);
    virtual void execute(const std::vector<std::string>& arguments, ProcessList& process_list, MainState& main_state) = 0;
};

#endif
