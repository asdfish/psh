#include <config.hpp>
#include <main.hpp>
#include <process_list.hpp>

#include <iostream>
#include <string>
#include <vector>

static std::vector<std::string> string_separate(const std::string& string) {
  std::string string_copy = string;
  std::vector<std::string> output;
  size_t location = std::string::npos;

  while((location = string_copy.find(" ")) != std::string::npos) {
    size_t initial_location = location;

    while(string_copy[location] == ' ')
      location ++;

    output.push_back(string_copy.substr(0, initial_location));
    string_copy.erase(0, location);
  }

  output.push_back(string_copy);
  return output;
}

int main(void) {
  std::vector<std::unique_ptr<Command>> commands;
  config_commands(commands);

  ProcessList process_list = ProcessList();

  MainState state;
  while(state.running) {
    std::cout << ">>> ";
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> input_separated = string_separate(input);
    if(!input_separated.size())
      continue;

    std::string command = input_separated[0];
    bool valid_command = false;
    for(const auto& i : commands)
      if(command == i->name) {
        i->command->execute(input_separated, process_list, state);
        valid_command = true;
        break;
      }

    if(!valid_command)
      std::cout << "Command " << command << " not found\n";
  }
  return 0;
}
