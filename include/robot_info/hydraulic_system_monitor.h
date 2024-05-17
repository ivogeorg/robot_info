#ifndef HYDRAULIC_SYSTEM_MONITOR_H
#define HYDRAULIC_SYSTEM_MONITOR_H

#include <string>
#include <map>

class HydraulicSystemMonitor {
  std::string hydraulic_oil_temperature_{"45C"};
  std::string hydraulic_oil_tank_fill_level_{"100%"};
  std::string hydraulic_oil_pressure_{"250 bar"};

public:
  std::map<std::string, std::string> get_parameters();
};

#endif