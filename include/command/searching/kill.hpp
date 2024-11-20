#ifndef KILL_HPP
#define KILL_HPP

#include <command/searching/searching_base.hpp>

class CommandKill : public SearchingBase {
  public:
    using SearchingBase::SearchingBase;

  private:
    void default_callback(ProcessList& process_list, MainState& main_state) override;
    void matching_callback(Process& process, MainState& main_state) override;
};

#endif
