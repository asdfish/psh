#ifndef PROCESS_LIST_HPP
#define PROCESS_LIST_HPP

#include <process.hpp>

#include <vector>

class ProcessList {
  public:
    std::vector<Process> processes;
    size_t max_processes;

    ProcessList(size_t max_processes = 1024);
    void update(void);
};

#endif
