#include <process_list.hpp>

ProcessList::ProcessList(size_t max_processes) {
  this->max_processes = max_processes;

  update();
}

void ProcessList::update(void) {
  DWORD cb_needed = 0;

  DWORD* pid_buffer = new DWORD[max_processes];
  if(!pid_buffer)
    return;
  if(!EnumProcesses(pid_buffer, max_processes * sizeof(DWORD), &cb_needed)) {
    delete[] pid_buffer;
    return;
  }

  if(!cb_needed) {
    delete[] pid_buffer;
    return;
  }

  processes.clear();

  size_t pids_length = cb_needed / sizeof(DWORD);
  for(size_t i = 0; i < pids_length; i ++)
    processes.push_back(Process(pid_buffer[i]));

  delete[] pid_buffer;
}
