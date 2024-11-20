#include <command/update.hpp>

void CommandUpdate::execute(const std::vector<std::string>& arguments, ProcessList& process_list, MainState& main_state) {
  process_list.update();
}
