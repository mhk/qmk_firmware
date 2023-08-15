#pragma once

/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      + ------.          .------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|       |          |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      + ------|          |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|       |          |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      + ------'          `------|      |      |      |      |      |        |
 * `--------+------+------+------+------+------'                         `------+------+------+------+------+--------'
 *                        ,---------------------------.           ,---------------------------.
 *                        |      |      |      |      |           |      |      |      |      |
 *                        `---------------------------'           `---------------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAKDHM] = LAYOUT(
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       ON_PLOVER2,
    KC_ESCAPE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           TG(_QWERTY),                                    TG(_MOVEMENT),  KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_SLASH,
    KC_BSPACE,      KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_LALT,                                        KC_RALT,        KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SCOLON,      KC_DELETE,
                                                                    CK_LPROG,       KC_ENTER,       KC_LSHIFT,      TD_LCTCM,       TD_RCTCM,       KC_RSHIFT,      KC_SPACE,       CK_RPROG
    ),

[_QWERTY] = LAYOUT(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           ON_PLOVER2,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           TG(_QWERTY),                                    TG(_MOVEMENT),  KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_BSPACE,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LALT,                                        KC_RALT,        KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_DELETE,
                                                                    CK_LPROG,       KC_ENTER,       KC_LSHIFT,      TD_LCTCM,       TD_RCTCM,       KC_RSHIFT,      KC_SPACE,       CK_RPROG
    ),

[_PROGKEYS] = LAYOUT(
    KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_AMPR,        TD_CBRC,        KC_BSLASH,                                                                      KC_ASTR,        KC_5,           KC_6,           KC_7,           KC_8,           KC_TRANSPARENT,
    TO(0),          KC_DQUO,        KC_UNDS,        KC_EQUAL,       TD_RBRC,        KC_AT,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PLUS,        KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_PIPE,        TD_CRNCY,       TD_SBRC,        TD_KHCIR,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PERC,        KC_9,           KC_COMMA,       KC_DOT,         KC_MINUS,       KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_TRANSPARENT, KC_TRANSPARENT
    ),

[_MOVEMENT] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PGUP,        KC_UP,          KC_PGDOWN,      KC_HOME,        KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_TRANSPARENT, KC_PC_PASTE,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2
    ),

[_UMLAUTE] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, CK_UE,          CK_UE,          CK_OE,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, CK_AE,          CK_SZ,          CK_SZ,          KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,                                        QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, CK_OE,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MAC_UNDO,    KC_MAC_CUT,     KC_MAC_COPY,    KC_TRANSPARENT, KC_MAC_PASTE,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_RSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

[_ONETS] = LAYOUT(
    KC_NO,          KC_EQUAL,       KC_MINUS,       KC_9,           KC_8,           KC_7,                                                                           KC_4,           KC_3,           KC_2,           KC_1,           KC_NO,          OFF_PLOVER,
    KC_NO,          KC_LBRACKET,    KC_P,           KC_O,           KC_I,           KC_U,           KC_Y,                                           KC_T,           KC_R,           KC_E,           KC_W,           KC_Q,           KC_NO,          KC_NO,
    KC_NO,          KC_QUOTE,       KC_SCOLON,      KC_L,           KC_K,           KC_J,           KC_H,                                           KC_G,           KC_F,           KC_D,           KC_S,           KC_A,           KC_NO,          KC_NO,
                                                                    KC_NO,          KC_NO,          KC_M,           KC_N,           KC_V,           KC_C,           KC_NO,          KC_NO
    )
};
