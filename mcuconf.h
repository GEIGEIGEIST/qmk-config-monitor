#pragma once

#include_next <mcuconf.h>

#undef RP_SIO_I2C_USE_I20
#define RP_SIO_I2C_USE_I20 FALSE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 FALSE

#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE

#undef RP_PWM_USE_PWM6
#define RP_PWM_USE_PWM6 TRUE


//audio
#undef RP_PWM_USE_PWM4
#define RP_PWM_USE_PWM4 TRUE
#undef RP_PWM_USE_TIM1
#define RP_PWM_USE_TIM1 TRUE