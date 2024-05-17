#include "robot_info/hydraulic_system_monitor.h"
#include <string>
#include <map>

// default constructor and destructor are automatically generated

std::map<std::string, std::string> HydraulicSystemMonitor::get_parameters() {
  std::map<std::string, std::string> hyd_params;
  
  hyd_params["hydraulic_oil_temperature"] = hydraulic_oil_temperature_;
  hyd_params["hydraulic_oil_tank_fill_level"] = hydraulic_oil_tank_fill_level_;
  hyd_params["hydraulic_oil_pressure"] = hydraulic_oil_pressure_;

  return std::move(hyd_params);
}
