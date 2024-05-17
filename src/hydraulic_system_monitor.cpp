#include "robot_info/hydraulic_system_monitor.h"
#include <string>
#include <vector>

// default constructor and destructor are automatically generated

std::vector<std::string> HydraulicSystemMonitor::pack_hydraulic_parameters() {
  std::vector<std::string> hyd_params{hydraulic_oil_temperature,
                                      hydraulic_oil_tank_fill_level,
                                      hydraulic_oil_pressure};

  return std::move(hyd_params);
}
