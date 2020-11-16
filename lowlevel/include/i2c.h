#ifndef I2C_H
#define I2C_H

// From Antonin

#include <libopencm3/stm32/i2c.h>
#include <libopencm3/stm32/rcc.h>

#define I2C1_CLK_MHZ    8
#define I2C_MAX_NBYTES 255

typedef enum I2C_Status_E{
    I2C_OK,
    I2C_ETIME, // timeout for unknown reason
    I2C_ENACK, // NACK
}I2C_Status;

/**
 * @brief Set the application-specific I2C configuration
 * @warning GPIOs must be initialized
 */
void i2c_setup();

#endif /* I2C_H */
