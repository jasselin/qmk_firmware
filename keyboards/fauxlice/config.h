#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Jason Asselin
#define PRODUCT         fAuxLICE
#define DESCRIPTION     fAuxLICE

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 14

/* key matrix pins */
#define MATRIX_ROW_PINS { D1, F6, F5, F4, D5 }
#define MATRIX_COL_PINS { D3, D2, D0, D4, C6, D7, E6, B4, B5, B6, B2, B3, B1, F7 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#endif
