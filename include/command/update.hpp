#ifndef UPDATE_HPP
#define UPDATE_HPP

#include <command/command_base.hpp>

class CommandUpdate : public CommandBase {
  using CommandBase::CommandBase;

  void execute(const std::vector<std::string>& arguments, ProcessList& process_list, MainState& main_state) override;
};

#endif
