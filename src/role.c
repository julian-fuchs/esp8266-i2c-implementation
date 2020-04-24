#include <stdbool.h>
#include <osapi.h>

#include "gpio_util.h"
#include "pins.h"

bool i2c_is_master;

void role_init() {
    pin_set_input(PIN_ROLE_SELECT);
    PIN_PULLUP_EN(io_mux_address[PIN_ROLE_SELECT]);

    if (pin_read_value(PIN_ROLE_SELECT)) {
        os_printf("role_init: A\n");
        i2c_is_master = true;
    } else {
        os_printf("role_init: B\n");
        i2c_is_master = false;
    }
}