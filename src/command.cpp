#include <command.hpp>

Command::Command(const std::string& name, const std::shared_ptr<CommandBase>& command) {
  this->name = name;
  this->command = command;
}
