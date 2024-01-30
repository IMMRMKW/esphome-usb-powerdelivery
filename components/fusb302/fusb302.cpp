
 /**
 * USB Power Delivery integration in ESPHome
 *	
 * Authors: groothuisss & IMMRMKW
 */

#include "esphome/core/log.h"
#include "fusb302.h"
#include "PD_UFP.h"
#include "PD_UFP_Protocol.h"
#include <Arduino.h>

namespace esphome {
namespace fusb302 {

static const char *TAG = "fusb302.component";

class PD_UFP_c PD_UFP;


void FUSB302::setup() {
    Wire.begin();
    
    auto maxPowerSettingPDProtocol = PD_POWER_OPTION_MAX_5V;

    switch (maximum_supply_voltage_) {
        case PD5V:
            maxPowerSettingPDProtocol = PD_POWER_OPTION_MAX_5V;
            break;
        case PD9V:
            maxPowerSettingPDProtocol = PD_POWER_OPTION_MAX_9V;
            break;
        case PD12V:
            maxPowerSettingPDProtocol = PD_POWER_OPTION_MAX_12V;
            break;
        case PD15V:
            maxPowerSettingPDProtocol = PD_POWER_OPTION_MAX_15V;
            break;
        case PD20V:
            maxPowerSettingPDProtocol = PD_POWER_OPTION_MAX_20V;
            break;
    }

    PD_UFP.init(maxPowerSettingPDProtocol, this->interrupt_pin_->get_pin());
}

void FUSB302::loop() {
    PD_UFP.run();
}

void FUSB302::dump_config(){
    ESP_LOGCONFIG(TAG, "FUSB302:");

    switch (maximum_supply_voltage_) {
    case PD5V:
        ESP_LOGCONFIG(TAG, "  Maximum supply voltage: 5V");
        break;
    case PD9V:
        ESP_LOGCONFIG(TAG, "  Maximum supply voltage: 9V");
        break;
    case PD12V:
        ESP_LOGCONFIG(TAG, "  Maximum supply voltage: 12V");
        break;
    case PD15V:
        ESP_LOGCONFIG(TAG, "  Maximum supply voltage: 15V");
        break;
    case PD20V:
        ESP_LOGCONFIG(TAG, "  Maximum supply voltage: 20V");
        break;
    }

    LOG_PIN("  Interrupt pin: ", this->interrupt_pin_);
}


}  // namespace fusb302
}  // namespace esphome