#ifndef SEARCHING_BASE_HPP
#define SEARCHING_BASE_HPP

#include <command/command_base.hpp>

class SearchingBase : public CommandBase {
  public:
    using CommandBase::CommandBase;

    void execute(const std::vector<std::string>& arguments, ProcessList& process_list, MainState& main_state) override;

  private:
    virtual void default_callback(ProcessList& process_list, MainState& state) = 0;
    virtual void matching_callback(Process& process, MainState& state) = 0;
};

#endif
