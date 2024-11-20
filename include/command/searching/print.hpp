#ifndef PRINT_HPP
#define PRINT_HPP

#include <command/searching/searching_base.hpp>

class CommandPrint : public SearchingBase {
  public:
    using SearchingBase::SearchingBase;

  private:
    void default_callback(ProcessList& process_list, MainState& main_state) override;
    void matching_callback(Process& process, MainState& main_state) override;
};

#endif
