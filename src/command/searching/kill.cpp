#include <command/searching/kill.hpp>

#include <iostream>

void CommandKill::default_callback(ProcessList& process_list, MainState& main_state) {
  std::cout << "No targetes provided\n";
}

void CommandKill::matching_callback(Process& process, MainState& main_state) {
  process.kill();
}
