#ifndef HYDRAULIC_SYSTEM_MONITOR_H
#define HYDRAULIC_SYSTEM_MONITOR_H

#include <string>
#include <vector>

class HydraulicSystemMonitor {
public:
  std::string hydraulic_oil_temperature{"45C"};
  std::string hydraulic_oil_tank_fill_level{"100%"};
  std::string hydraulic_oil_pressure{"250 bar"};

  std::vector<std::string> pack_hydraulic_parameters();
};

#endif