
 /**
 * USB Power Delivery integration in ESPHome
 *	
 * Authors: groothuisss & IMMRMKW
 */
  

#pragma once

#include <Arduino.h>
#include "esphome/core/gpio.h"
#include "esphome/core/component.h"
#include "esphome/core/log.h"
#include "PD_UFP.h"
#include "PD_UFP_Protocol.h"


namespace esphome {
namespace fusb302 {

enum MaximumSupplyVoltage {PD5V, PD9V, PD12V, PD15V, PD20V};

class FUSB302 : public Component {
  public:
    void set_maximum_supply_voltage(MaximumSupplyVoltage maximum_supply_voltage) { maximum_supply_voltage_ = maximum_supply_voltage; }
    void set_interrupt_pin(InternalGPIOPin *pin) { this->interrupt_pin_ = pin; }

    void setup() override;
    void loop() override;
    void dump_config() override;

  protected:
    MaximumSupplyVoltage maximum_supply_voltage_{PD5V};
    InternalGPIOPin *interrupt_pin_;
};
}  // namespace fusb302
}  // namespace esphome