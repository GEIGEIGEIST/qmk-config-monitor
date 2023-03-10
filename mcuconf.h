#pragma once

#include_next <mcuconf.h>

#undef RP_SIO_USE_UART0
#define RP_SIO_USE_UART0 FALSE
#undef RP_SIO_USE_UART1
#define RP_SIO_USE_UART1 FALSE
#undef RP_SIO_I2C_USE_I20
#define RP_SIO_I2C_USE_I20 FALSE
#undef RP_SPI_USE_SPI0
#define RP_SPI_USE_SPI0 TRUE
#undef RP_USB_USE_ERROR_DATA_SEQ_INTR
#define RP_USB_USE_ERROR_DATA_SEQ_INTR FALSE

//audio
#undef RP_PWM_USE_PWM4
#define RP_PWM_USE_PWM4 TRUE
#undef RP_PWM_USE_TIM1
#define RP_PWM_USE_TIM1 TRUE

//backlight
#undef RP_PWM_USE_PWM6
#define RP_PWM_USE_PWM6 TRUE
