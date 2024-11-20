#include <command/quit.hpp>

void CommandQuit::execute(const std::vector<std::string>& arguments, ProcessList& process_list, MainState& main_state) {
  main_state.running = false;
}
