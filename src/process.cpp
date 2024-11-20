#include <process.hpp>

#include <tchar.h>

#include <iostream>

static std::string path_file(const std::string& path) {
  for(ssize_t i = path.length(); i > 0; i --)
    if(path[i] == '\\' && (size_t) i != path.length())
      return path.substr(i + 1, path.length());
  return "";
}

Process::Process(DWORD id) {
  this->id = id;

  handle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_TERMINATE, FALSE, id);

  if(handle) {
    TCHAR pid_name[MAX_PATH];
    if(GetModuleFileNameEx(handle, 0, pid_name, MAX_PATH))
      name = std::string((char*) pid_name);
    else
      name = "";
  } else
    name = "";
}
Process::~Process(void) {
  if(handle)
    CloseHandle(handle);
}

void Process::kill(void) {
//  if(handle)
//    TerminateProcess(handle, 1);
  if(name.length()) {
    std::string executable = path_file(name);
    if(executable.length())
      system(std::string("taskkill /F /T /IM " + executable).c_str());
  }
}

void Process::print(void) const {
  std::cout << "PID: " << id << " PATH: " << name << '\n';
}
