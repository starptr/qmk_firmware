#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    BASE = 0,
    NO_TAP_HOLD,
    //KEYPAD,
    DIR,
    //DEV,
    FN,
};

#define TG_NOHT TG(NO_TAP_HOLD)     // alias

#define KC_TASK LGUI(KC_TAB)        // Task viewer
#define KC_FLXP LGUI(KC_E)          // Windows file explorer

#define KC_MSSN LGUI(KC_F3)         // Mission Control
#define KC_FIND LALT(LGUI(KC_SPC))  // Finder
#define KC_MSCR LSFT(LGUI(KC_3))    // Mac screenshot
#define KC_MSNP LSFT(LGUI(KC_4))    // Mac snip tool

// Home-row mods
#define H_SFTA LSFT_T(KC_A)
#define H_CTLS LCTL_T(KC_S)
#define H_CTLF LCTL_T(KC_F)
#define H_DIRD LT(DIR, KC_D)
#define H_ALTZ LALT_T(KC_Z)
#define H_ALTS LALT_T(KC_S)
#define H_SFTF LSFT_T(KC_F)
#define H_CTLA LCTL_T(KC_A)

#define H_SFTSCLN RSFT_T(KC_SCLN)
#define H_CTLL RCTL_T(KC_L)
#define H_CTLJ RCTL_T(KC_J)
#define H_DIRK LT(DIR, KC_K)
#define H_ALTSLSH RALT_T(KC_SLSH)
#define H_ALTL RALT_T(KC_L)
#define H_SFTJ RSFT_T(KC_J)
#define H_CTLSCLN RCTL_T(KC_SCLN)

#define ALTRIGHT LALT(KC_RIGHT)
#define ALTLEFT  LALT(KC_LEFT)

enum custom_keys {
  WINMAC = SAFE_RANGE, // swap win & mac layers
  VALAFK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    **********************************************************************************************************
    * ESC  * F1   * F2   * F3   * F4   * F5   * F6   * F7   * F8   * F9   * F10  * F11  * F12  * PSCR * DEL  *
    **********************************************************************************************************
    * ~    * 1    * 2    * 3    * 4    * 5    * 6    * 7    * 8    * 9    * 0    * *    * =    * BSPC * _    *
    **********************************************************************************************************
    * TAB  * Q    * W    * E    * R    * T    * Y    * U    * I    * O    * P    * [    * ]    * \    * PGDN *
    **********************************************************************************************************
    * CAPS * A    * S    * D    * F    * G    * H    * J    * K    * L    * ;    * '    * ENT  * HOME * _    *
    **********************************************************************************************************
    * LSFT * Z    * X    * C    * V    * B    * N    * M    * ,    * .    * /    * RSFT * UP   * END  * _    *
    **********************************************************************************************************
    * LCTL * LALT * LGUI * SPC  * LGUI * FN   * RCTL * LEFT * DOWN * RGHT * _    * _    * _    * _    * _    *
    **********************************************************************************************************
    */

	[BASE] = LAYOUT_ortho_5x15(
    /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14      */
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    _______ ,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    _______ ,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,     _______,    _______ ,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    _______,     KC_UP,     _______ ,
        KC_LCTL,    KC_ESC,     KC_LALT,    KC_LGUI,    KC_SPC,     KC_SPC,     KC_SPC,     KC_SPC,     KC_RGUI,    KC_RALT,    KC_RCTL,    MO(FN),     KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),
	[NO_TAP_HOLD] = LAYOUT_ortho_5x15(
    /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14      */
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    _______ ,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    _______ ,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_ENT,     _______,    _______ ,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,    _______,     KC_UP,     _______ ,
        KC_LCTL,    KC_ESC,     KC_LALT,    KC_LGUI,    KC_SPC,     KC_SPC,     KC_SPC,     KC_SPC,     KC_RGUI,    KC_RALT,    KC_RCTL,    MO(FN),     KC_LEFT,    KC_DOWN,    KC_RIGHT
    ),
	[FN] = LAYOUT_ortho_5x15(
    /*  0           1           2           3           4           5           6           7           8           9           10          11          12          13          14      */
        QK_BOOT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ ,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ ,
        _______,    _______,    _______,    _______,    _______,    _______,    TG_NOHT,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ ,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______ ,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)




