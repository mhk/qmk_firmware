/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)

// Tap Dance declarations
enum {
    TD_LSFT_RSFT,
    TD_LCTL_RCTL,
    TD_LALT_RALT,
    TD_CLY_BRCKT,
    TD_RND_BRCKT,
    TD_SQR_BRCKT,
    TD_CRNCY_SGN,
    TD_HASH_CIRC,
    TD_LCTL_LCMD,
    TD_RCTL_RCMD,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for left shift/ctrl/alt, twice for right shift/ctrl/alt
    [TD_LSFT_RSFT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_RSFT),
    [TD_LCTL_RCTL] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_RCTL),
    [TD_LALT_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
    // Tap once for open round/curly/square braket, twice for close round/curly/square braket
    [TD_CLY_BRCKT] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_RND_BRCKT] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_SQR_BRCKT] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    // Tap once for dollar sign, twice for euro sign
    [TD_CRNCY_SGN] = ACTION_TAP_DANCE_DOUBLE(KC_DLR , RALT(KC_5)),
    [TD_HASH_CIRC] = ACTION_TAP_DANCE_DOUBLE(KC_HASH ,KC_CIRC),
    // Tap once for left/right ctrl, twice for left/right alt
    [TD_LCTL_LCMD] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL ,KC_LCMD),
    [TD_RCTL_RCMD] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL ,KC_RCMD),
};

#define _COLEMAKDHM (0)
#define _PROGKEYS   (1)
#define _MOVEMENT   (2)
#define _UMLAUTE    (3)
#define _QWERTY     (4)
#define _ONETS      (5)
#define KC_UMLT     KC_LSFT
#define TD_DALT     TD(TD_LALT_RALT)
#define TD_DCTL     TD(TD_LCTL_RCTL)
#define TD_DSFT     TD(TD_LSFT_RSFT)
#define TD_SPC      LSFT_T(KC_SPC)
#define TD_CBRC     TD(TD_CLY_BRCKT)
#define TD_RBRC     TD(TD_RND_BRCKT)
#define TD_SBRC     TD(TD_SQR_BRCKT)
#define TD_CRNCY    TD(TD_CRNCY_SGN)
#define TD_KHCIR    TD(TD_HASH_CIRC)
#define TD_LCTCM    TD(TD_LCTL_LCMD)
#define TD_RCTCM    TD(TD_RCTL_RCMD)

enum custom_keycodes {
  ST_MACRO_0  = SAFE_RANGE,
  ST_MACRO_1,
  CK_AE,
  CK_SZ,
  CK_UE,
  CK_OE,
  ON_PLOVER,
  OFF_PLOVER,
  CK_LPROG,
  CK_RPROG,
};


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
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       ON_PLOVER,
    KC_ESCAPE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           TG(4),                                          TG(2),          KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_SLASH,
    KC_BSPACE,      KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           KC_LALT,                                        KC_RALT,        KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SCOLON,      KC_DELETE,
                                                                    CK_LPROG,       KC_ENTER,       KC_LSHIFT,      TD_LCTCM,       TD_RCTCM,       KC_RSHIFT,      KC_SPACE,       CK_RPROG
    ),

[_PROGKEYS] = LAYOUT(
    KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_AMPR,        TD_CBRC,        KC_BSLASH,                                                                      KC_ASTR,        KC_5,           KC_6,           KC_7,           KC_8,           KC_TRANSPARENT,
    TO(0),          KC_DQUO,        KC_UNDS,        KC_EQUAL,       TD_RBRC,        KC_AT,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PLUS,        KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_PIPE,        TD_CRNCY,       TD_SBRC,        TD_KHCIR,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PERC,        KC_9,           KC_COMMA,       KC_DOT,         KC_MINUS,       KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_TRANSPARENT, KC_TRANSPARENT
    ),

[_MOVEMENT] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_MS_ACCEL1,                                                                   KC_TRANSPARENT, KC_PGUP,        KC_UP,          KC_PGDOWN,      KC_HOME,        KC_TRANSPARENT,
    TO(0),          KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_ACCEL2,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_0,     KC_PC_CUT,      KC_PC_COPY,     ST_MACRO_1,     KC_PC_PASTE,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2
    ),

[_UMLAUTE] = LAYOUT(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, CK_UE,          CK_UE,          CK_OE,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, CK_AE,          CK_SZ,          CK_SZ,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, CK_OE,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_RSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

[_QWERTY] = LAYOUT(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRACKET,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_BSPACE,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_LALT,                                        KC_RALT, KC_N,  KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_DELETE,
                                                                    KC_LALT,        KC_ENTER,       KC_LSHIFT,      TD_LCTCM,       TD_RCTCM,       KC_RSHIFT,      KC_SPACE,       KC_RALT
    ),

[_ONETS] = LAYOUT(
    KC_NO,          KC_EQUAL,       KC_MINUS,       KC_9,           KC_8,           KC_7,                                                                           KC_4,           KC_3,           KC_2,           KC_1,           KC_NO,          OFF_PLOVER,
    KC_NO,          KC_LBRACKET,    KC_P,           KC_O,           KC_I,           KC_U,           KC_Y,                                           KC_T,           KC_R,           KC_E,           KC_W,           KC_Q,           KC_NO,          KC_NO,
    KC_NO,          KC_QUOTE,       KC_SCOLON,      KC_L,           KC_K,           KC_J,           KC_H,                                           KC_G,           KC_F,           KC_D,           KC_S,           KC_A,           KC_NO,          KC_NO,
                                                                    KC_NO,          KC_NO,          KC_M,           KC_N,           KC_V,           KC_C,           KC_NO,          KC_NO
    )
};

#ifdef COMBO_ENABLE
enum combo_events {
  TO_MOVEMENT,
};

const uint16_t PROGMEM switch_to_movement[] = {KC_ENT, KC_SPC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  [TO_MOVEMENT] = COMBO_ACTION(switch_to_movement),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case TO_MOVEMENT:
      if(pressed) {
        layer_invert(_MOVEMENT);
      }
      break;
  }
}
#endif

extern keymap_config_t keymap_config;
// static bool nkro = true;

static void activate_plover(void) {
  // PHROPB -> ERFVIK
  register_code(KC_E);
  register_code(KC_R);
  register_code(KC_F);
  register_code(KC_V);
  register_code(KC_I);
  register_code(KC_K);
  wait_ms(3);
  clear_keyboard();
  // nkro = keymap_config.nkro;
  keymap_config.nkro = true;
}

static void deactivate_plover(void) {
  // PHRO*F -> ERFVYU
  register_code(KC_E);
  register_code(KC_R);
  register_code(KC_F);
  register_code(KC_V);
  register_code(KC_Y);
  register_code(KC_U);
  wait_ms(3);
  clear_keyboard();
  // keymap_config.nkro = nkro;
  keymap_config.nkro = true;
}

static uint16_t key_timer = 0;
static uint16_t shift_active = 0;
static uint16_t lock_prog = 0;

void matrix_scan_user(void) {
  if(shift_active && !IS_LAYER_ON(_UMLAUTE) && timer_elapsed(key_timer) > TAPPING_TERM) {
    register_code(shift_active);
    shift_active = 0;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_Z)));
      }
      break;
    case ST_MACRO_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_Y)));
      }
      break;
    case CK_AE:
      if (record->event.pressed) {
        SEND_STRING("\"a");
      }
      break;
    case CK_SZ:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT(SS_TAP(X_S)));
      }
      break;
    case CK_UE:
      if (record->event.pressed) {
        SEND_STRING("\"u");
      }
      break;
    case CK_OE:
      if (record->event.pressed) {
        SEND_STRING("\"o");
      }
      break;
    case ON_PLOVER:
      if (record->event.pressed) {
        activate_plover();
        layer_on(_ONETS);
      }
      return false;
    case OFF_PLOVER:
      if (record->event.pressed) {
        deactivate_plover();
        layer_off(_ONETS);
      }
      return false;
    case CK_LPROG:
    case CK_RPROG:
      if (record->event.pressed && IS_LAYER_ON(_PROGKEYS) && lock_prog) {
        lock_prog = 0;
      } else if (record->event.pressed && IS_LAYER_ON(_PROGKEYS) && !lock_prog) {
        lock_prog = 1;
      } else if (record->event.pressed && !IS_LAYER_ON(_PROGKEYS)) {
        layer_on(_PROGKEYS);
      } else if(!lock_prog) {
        layer_off(_PROGKEYS);
      }
      break;
  }
  // If shift is tapped without any other keypress switch to the UMLAUTE layer
  // TODO: Ignore double shift
  if((KC_LSFT == keycode || KC_RSFT == keycode) && !IS_LAYER_ON(_UMLAUTE)) {
    if(record->event.pressed) {
      shift_active = keycode;
      key_timer = timer_read();
      return false;
    } else if(shift_active && timer_elapsed(key_timer) < TAPPING_TERM) {
      shift_active = 0;
      layer_on(_UMLAUTE);
      return false;
    }
  }
  if(shift_active) {
    register_code(shift_active);
    shift_active = 0;
  }
  if(IS_LAYER_ON(_UMLAUTE) && !record->event.pressed) {
    layer_off(_UMLAUTE);
  }
  return true;
}
