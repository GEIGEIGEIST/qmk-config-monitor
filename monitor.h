#pragma once

#include "quantum.h"

#define LAYOUT_ortho_1x1( \
    k00 \
) { \
    { k00 } \
}

#ifdef QUANTUM_PAINTER_ENABLE
extern painter_device_t ssd1351;
#endif