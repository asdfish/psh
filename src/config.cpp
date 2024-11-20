#include <config.hpp>
#include <command/searching/kill.hpp>
#include <command/searching/print.hpp>
#include <command/quit.hpp>
#include <command/update.hpp>

#include <memory>

void config_commands(std::vector<std::unique_ptr<Command>>& commands) {
  commands.push_back(std::make_unique<Command>("kill", std::make_shared<CommandKill>()));
  commands.push_back(std::make_unique<Command>("print", std::make_shared<CommandPrint>()));
  commands.push_back(std::make_unique<Command>("quit", std::make_shared<CommandQuit>()));
  commands.push_back(std::make_unique<Command>("update", std::make_shared<CommandUpdate>()));
}
