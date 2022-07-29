#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // [0] = LAYOUT_65_ansi(
    //     KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
    //     KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    //     CTL_T(KC_CAPS), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
    //     KC_LSFT,                 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
    //     KC_LCTL,        KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    // ),

    [_LAYER0] = LAYOUT_65_ansi( /* Base */
        KC_GESC, KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_LSFT, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,              MO(1),   KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // [1] = LAYOUT_65_ansi(
    //     KC_GESC,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_HOME,
    //     _______,        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET,   KC_PGUP,
    //     CTL_T(KC_CAPS), RGB_SPI, RGB_SPD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          EEP_RST, KC_PGDN,
    //     KC_LSFT,                 _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______, _______, KC_VOLU, KC_MUTE,
    //     _______,        _______, _______,                            _______,                   _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    // )

    [_LAYER1] = LAYOUT_65_ansi( /* FN */
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_MPLY,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______,
        KC_LSFT, RGB_SPI, RGB_SPD, DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LSFT, _______, _______, _______, _______, _______, _______, _______, KC_BRID, KC_BRIU, _______, _______, KC_VOLU, KC_MUTE,
        _______, _______, _______,          _______,                            _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

    // [_LAYER2] = LAYOUT_65_ansi( /* MOUSE => TG(_LAYER2) */
    //   _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_D,
    //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_WH_U,
    //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2,
    //   _______, _______, _______,          _______,                            _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R
    // ),

};

void rgb_matrix_indicators_user(void)
{
  if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK))
  {
    rgb_matrix_set_color(8, 0xFF, 0xFF, 0xFF);
  }
}

void matrix_init_user(void)
{
  //user initialization
}

void matrix_scan_user(void)
{
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // If console is enabled, it will print the matrix position and status of each key pressed
  #ifdef CONSOLE_ENABLE
  uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
  #endif
  return true;
}
