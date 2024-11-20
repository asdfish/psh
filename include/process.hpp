#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <windows.h>
#include <psapi.h>

#include <string>

class Process {
  public:
    DWORD id;
    std::string name;

    void print(void) const;
    void kill(void);

    Process(DWORD id);
    ~Process(void);

  private:
    HANDLE handle;
};

#endif
