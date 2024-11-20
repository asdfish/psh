#include <command/searching/print.hpp>

void CommandPrint::default_callback(ProcessList& process_list, MainState& main_state) {
  for(Process& process : process_list.processes)
    process.print();
}

void CommandPrint::matching_callback(Process& process, MainState& main_state) {
  process.print();
}
