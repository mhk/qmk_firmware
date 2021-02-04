/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#if 0
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Blank template at the bottom

enum customKeycodes {
	URL  = 1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * | L1/ESC |   Q  |   W  |   E  |   R  |   T  |                         |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |Ctrl/BS |   A  |   S  |  D   |   F  |   G  | RMB  |           |      |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LMB  |           |      |   N  |   M  | ,  < | . >  | /  ? |  - _   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .-----.
 *                    | Super/Del|   |Ent/ALT|                                 | Tab  |   |BKSP |
 *                    '----------'   '-------'                                 `------.   '-----'
 *                                        ,-------.                      ,-------.
 *                                        | MMB   |                      | PgDn  |
 *                                 ,------|-------|                      |-------|------.
 *                                 | SYMB | NUMB  |                      | SYMB  | NUMB |
 *                                 | Space| Escape|                      | Mod   |Space |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[BASE] = LAYOUT_gergo(
    LT(NUMB, KC_ESC),       KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                          KC_Y,    KC_U, KC_I, KC_O,   KC_P,    KC_PIPE,
    MT(MOD_LCTL, KC_BSPC),  KC_A,  KC_S,   KC_D,   KC_F, KC_G, KC_BTN2,                       KC_TRNS,  KC_H,    KC_J, KC_K, KC_L,   KC_SCLN, KC_QUOT,
    KC_RSFT,                KC_Z,  KC_X,   KC_C,   KC_V, KC_B, KC_BTN1, KC_BTN3,     KC_PGDN, KC_BSPC,  KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_MINS,
  MT(MOD_LGUI, KC_DEL), MT(MOD_LALT, KC_ENT), LT(SYMB, KC_SPC), LT(NUMB, KC_ESC),    LT(SYMB, KC_ENT), LT(NUMB, KC_SPC), KC_TAB, KC_BSPC
    ),
/* Keymap 1: Symbols layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  @   |  {   |  }   |  |   |                         |      |      |      |      |      |  \ |   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  #   |  $   |  (   |  )   |  `   |      |           |      |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |           |      |   &  |  =   |  ,   |  .   |  / ? | - _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   | DEL |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |   ;  |   =   |                     |   =   |   ;  |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[SYMB] = LAYOUT_gergo(
    KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS,
    KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS,                          KC_TRNS, KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_PERC, KC_QUOT,
    KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_AMPR, KC_EQL,  KC_COMM, KC_DOT,  KC_SLSH, KC_MINS,
                                        KC_TRNS, KC_TRNS, KC_SCLN, KC_EQL,         KC_EQL,  KC_SCLN, KC_PGUP, KC_DEL
    ),
/* Keymap 2: Pad/Function layer
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                         |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |  F1    |  F2  | F3   | F4   | F5   | F6   | BTN1 |           |      | LEFT | DOWN |  UP  | RIGHT|VolDn | VolUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |  F7    |  F8  | F9   | F10  | F11  | F12  | BTN2 |           |      | MLFT | MDWN | MUP  | MRGHT|Ply/Pa|  Skip  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_TRNS, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                         KC_TRNS,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_VOLD, KC_VOLU,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,     KC_TRNS, KC_TRNS,  KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MPLY, KC_MNXT,
                                        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
#endif

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
    TD_LCTL_LALT,
    TD_RCTL_RALT,
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
    [TD_LCTL_LALT] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL ,KC_LALT),
    [TD_RCTL_RALT] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL ,KC_RALT),
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
#define TD_LCTAL    TD(TD_LCTL_LALT)
#define TD_RCTAL    TD(TD_RCTL_RALT)

enum custom_keycodes {
  ST_MACRO_0  = SAFE_RANGE,
  ST_MACRO_1,
  CK_AE,
  CK_SZ,
  CK_UE,
  CK_OE,
  ON_PLOVER,
  OFF_PLOVER,
};


/* Keymap template
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAKDHM] = LAYOUT_gergo(
    KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                                                           KC_J,           KC_L,           KC_U,           KC_Y,           KC_QUOTE,       KC_NO,
    KC_ESCAPE,      KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_LALT,                                        KC_RALT,        KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_SLASH,
    KC_BSPACE,      KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,           TG(2),          TG(4),          ON_PLOVER,      TG(2),          KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SCOLON,      KC_DELETE,
                                                                    TT(1),          KC_ENTER,       KC_LSHIFT,      TD_LCTAL,       TD_RCTAL,       KC_RSHIFT,      KC_SPACE,       TT(1)
    ),

[_PROGKEYS] = LAYOUT_gergo(
    KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_AMPR,        TD_CBRC,        KC_BSLASH,                                                                      KC_ASTR,        KC_5,           KC_6,           KC_7,           KC_8,           KC_TRANSPARENT,
    TO(0),          KC_DQUO,        KC_UNDS,        KC_EQUAL,       TD_RBRC,        KC_AT,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PLUS,        KC_1,           KC_2,           KC_3,           KC_4,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_PIPE,        TD_CRNCY,       TD_SBRC,        TD_KHCIR,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PERC,        KC_9,           KC_COMMA,       KC_DOT,         KC_MINUS,       KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_TRANSPARENT, KC_TRANSPARENT
    ),

[_MOVEMENT] = LAYOUT_gergo(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_MS_ACCEL1,                                                                   KC_TRANSPARENT, KC_PGUP,        KC_UP,          KC_PGDOWN,      KC_HOME,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_ACCEL2,   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_END,         KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_0,     KC_PC_CUT,      KC_PC_COPY,     ST_MACRO_1,     KC_PC_PASTE,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_ACCEL2,   KC_MS_ACCEL1,   KC_MS_ACCEL0,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2
    ),

[_UMLAUTE] = LAYOUT_gergo(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, CK_UE,          CK_UE,          CK_OE,          KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, CK_AE,          CK_SZ,          CK_SZ,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, CK_OE,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_RSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

[_QWERTY] = LAYOUT_gergo(
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_LBRACKET,
    KC_ESCAPE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_LALT,                                        KC_RALT,        KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,
    KC_BSPACE,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_DELETE,
                                                                    KC_LALT,        KC_ENTER,       KC_LSHIFT,      TD_LCTAL,       TD_RCTAL,       KC_RSHIFT,      KC_SPACE,       KC_RALT
    ),

[_ONETS] = LAYOUT_gergo(
    KC_NO,          KC_EQUAL,       KC_MINUS,       KC_9,           KC_8,           KC_7,                                                                           KC_4,           KC_3,           KC_2,           KC_1,           KC_NO,          KC_NO,
    KC_NO,          KC_LBRACKET,    KC_P,           KC_O,           KC_I,           KC_U,           KC_Y,                                           KC_T,           KC_R,           KC_E,           KC_W,           KC_Q,           KC_NO,          KC_NO,
    KC_NO,          KC_QUOTE,       KC_SCOLON,      KC_L,           KC_K,           KC_J,           KC_H,           KC_TRANSPARENT, OFF_PLOVER,     KC_G,           KC_F,           KC_D,           KC_S,           KC_A,           KC_NO,          KC_NO,
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
#if 0
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
#endif
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
  }
  // If shift is tapped without any other keypress switch to the UMLAUTE layer
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
