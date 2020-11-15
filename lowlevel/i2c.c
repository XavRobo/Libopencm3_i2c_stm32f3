#include "i2c.h"

/**********************/
/* I2C initialization */
/**********************/
void i2c_setup()
{
    // I2C1
    i2c_peripheral_disable(I2C1);
    i2c_enable_analog_filter(I2C1); // filters up to 50 ns pulses
    i2c_set_speed(I2C1, i2c_speed_fm_400k, I2C1_CLK_MHZ);
    
    // set_speed fix : 125ns @8MHz, see RM0316 §28.4.9 Table 147
    i2c_set_data_hold_time(I2C1, 1);
    
    i2c_set_7bit_addr_mode(I2C1);
    i2c_enable_stretching(I2C1); // required for master mode (default)
}
