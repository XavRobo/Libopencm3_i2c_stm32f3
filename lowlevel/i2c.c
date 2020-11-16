#include "i2c.h"

/**********************/
/* I2C initialization */
/**********************/
void i2c_setup()
{
    rcc_periph_clock_enable(RCC_I2C1);
    rcc_set_i2c_clock_hsi(I2C1);

    // I2C1
    i2c_reset(I2C1);
    i2c_peripheral_disable(I2C1);
    i2c_enable_analog_filter(I2C1); // filters up to 50 ns pulses
    i2c_set_digital_filter(I2C1, 0);
    i2c_set_speed(I2C1, i2c_speed_fm_400k, I2C1_CLK_MHZ );
    
    i2c_set_7bit_addr_mode(I2C1);
    i2c_enable_stretching(I2C1); // required for master mode (default)

    i2c_peripheral_enable(I2C1);
}
