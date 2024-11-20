#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <command/command_base.hpp>

#include <memory>

class Command {
  public:
    std::string name;
    std::shared_ptr<CommandBase> command;

    Command(const std::string& name, const std::shared_ptr<CommandBase>& command);
};

#endif
