#ifndef QUIT_HPP
#define QUIT_HPP

#include <command/command_base.hpp>

class CommandQuit : public CommandBase {
  using CommandBase::CommandBase;

  void execute(const std::vector<std::string>& arguments, ProcessList& process_list, MainState& main_state) override;
};

#endif
