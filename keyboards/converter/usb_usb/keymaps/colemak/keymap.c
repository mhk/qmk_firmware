/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H


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
};

#define _COLEMAKDHM (0)
#define _PROGKEYS   (1)
#define _MOVEMENT   (2)
#define _UMLAUTE    (3)
#define _QWERTY     (4)
#define KC_UMLT     KC_LSFT
#define TD_DALT     TD(TD_LALT_RALT)
#define TD_DCTL     TD(TD_LCTL_RCTL)
#define TD_DSFT     TD(TD_LSFT_RSFT)
#define TD_SPC      LSFT_T(KC_SPC)
#define TD_CBRC     TD(TD_CLY_BRCKT)
#define TD_RBRC     TD(TD_RND_BRCKT)
#define TD_SBRC     TD(TD_SQR_BRCKT)
#define TT_PROG     TT(_PROGKEYS)
#define TO_MOV      TO(_MOVEMENT)
#define TO_COLM     TO(_COLEMAKDHM)
#define DF_QWRT     DF(_QWERTY)
#define DF_COLM     DF(_COLEMAKDHM)
#define LC_ESC      LCTL_T(KC_ESC)
#define RC_SLSH     RCTL_T(KC_SLSH)
#define LS_Z        LSFT_T(KC_Z)
#define RS_SCLN     RSFT_T(KC_SCLN)
#define KC_AE       RALT(KC_Q)
#define KC_OE       RALT(KC_P)
#define KC_UE       RALT(KC_Y)
#define TD_CRNCY    TD(TD_CRNCY_SGN)
#define TD_KHCIR    TD(TD_HASH_CIRC)
#define KC_SZ       RALT(KC_S)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
  [_COLEMAKDHM] = LAYOUT_all(
                      KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,
  KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                  KC_PSCR,  KC_SLCK,  KC_PAUS,       KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_PWR,        KC_HELP,
  TO_MOV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_JYEN,  KC_BSPC,       KC_INS,   KC_HOME,  KC_PGUP,       KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,       KC_STOP,  KC_AGIN,
  KC_TAB,             KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_QUOT,  KC_LBRC,  KC_RBRC,  KC_DEL,        KC_DEL,   KC_END,   KC_PGDN,       KC_P7,    KC_P8,    KC_P9,    KC_PPLS,       KC_MENU,  KC_UNDO,
  KC_CAPS,            KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_SLSH,  KC_NUHS,  KC_ENT,                                           KC_P4,    KC_P5,    KC_P6,    KC_PCMM,       KC_SLCT,  KC_COPY,
  KC_UMLT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SCLN,  DF_COLM,            KC_BSLS,                 KC_UP,                   KC_P1,    KC_P2,    KC_P3,    KC_PEQL,       KC_EXEC,  KC_PSTE,
  TD_DCTL,  KC_LGUI,  TT_PROG,  KC_MHEN,  KC_HANJ,             KC_SPC,            KC_HAEN,  KC_HENK,  DF_QWRT,  TT_PROG,  KC_RGUI,  KC_APP,   TD_DALT,       KC_LEFT,  KC_DOWN,  KC_RGHT,       KC_P0,              KC_PDOT,  KC_PENT,       KC_FIND,  KC_CUT
  ),
  [_PROGKEYS] = LAYOUT_all(
                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                 KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,
  RESET,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,
  KC_TRNS,            KC_GRV,   KC_TILD,  KC_AMPR,  TD_CBRC,  KC_BSLS,  KC_ASTR,  KC_5,     KC_6,     KC_7,     KC_8,     KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,
  KC_TRNS,            KC_DQUO,  KC_UNDS,  KC_EQL,   TD_RBRC,  KC_AT,    KC_PLUS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_TRNS,  KC_TRNS,  KC_TRNS,                                          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,
  KC_0,     KC_TRNS,  KC_EXLM,  KC_PIPE,  TD_CRNCY, TD_SBRC,  TD_KHCIR, KC_PERC,  KC_9,     KC_COMM,  KC_DOT,   KC_MINS,  KC_TRNS,            KC_TRNS,                 KC_TRNS,                 KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,            KC_TRNS,  KC_TRNS,       KC_TRNS,  KC_TRNS
  ),
  [_UMLAUTE] = LAYOUT_all(
                      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                   KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,
  KC_NO,              KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_UE,    KC_UE,    KC_OE,    KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,
  KC_NO,              KC_AE,    KC_SZ,    KC_SZ,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_OE,    KC_NO,    KC_NO,    KC_NO,                                            KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,
  KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_NO,                   KC_NO,                   KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,         KC_NO,              KC_NO,    KC_NO,         KC_NO,    KC_NO
  ),
  [_MOVEMENT] = LAYOUT_all(
                      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_ESC,             KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                   KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,
  TO_COLM,  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_BSPC,       KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,
  KC_TAB,             KC_NO,    KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_NO,    KC_NO,    KC_PGUP,  KC_UP,    KC_PGDN,  KC_HOME,  KC_NO,    KC_NO,    KC_DEL,        KC_DEL,   KC_NO,    KC_NO,         KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,
  KC_NO,              KC_NO,    KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_NO,    KC_BTN3,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_END,   KC_NO,    KC_NO,    KC_BTN1,                                          KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,
  KC_LSFT,  KC_NO,    KC_UNDO,  KC_CUT,   KC_COPY,  KC_PSTE,  KC_AGIN,  KC_NO,    KC_ACL2,  KC_ACL1,  KC_ACL0,  KC_NO,    KC_NO,              KC_RSFT,                 KC_NO,                   KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,    KC_NO,
  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_NO,    KC_NO,    KC_BTN2,                      KC_NO,    KC_NO,    KC_NO,    KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL,       KC_NO,    KC_NO,    KC_NO,         KC_NO,              KC_NO,    KC_NO,         KC_NO,    KC_NO
  ),
  [_QWERTY] = LAYOUT_all(
                      KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,
  KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,                  KC_PSCR,  KC_SLCK,  KC_PAUS,       KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_PWR,        KC_HELP,
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_JYEN,  KC_BSPC,       KC_INS,   KC_HOME,  KC_PGUP,       KC_NLCK,  KC_PSLS,  KC_PAST,  KC_PMNS,       KC_STOP,  KC_AGIN,
  KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,       KC_DEL,   KC_END,   KC_PGDN,       KC_P7,    KC_P8,    KC_P9,    KC_PPLS,       KC_MENU,  KC_UNDO,
  KC_CAPS,            KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                                           KC_P4,    KC_P5,    KC_P6,    KC_PCMM,       KC_SLCT,  KC_COPY,
  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  DF_COLM,            KC_RSFT,                 KC_UP,                   KC_P1,    KC_P2,    KC_P3,    KC_PEQL,       KC_EXEC,  KC_PSTE,
  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_MHEN,  KC_HANJ,             KC_SPC,            KC_HAEN,  KC_HENK,  DF_QWRT,  KC_RALT,  KC_RGUI,  KC_APP,   KC_RCTL,       KC_LEFT,  KC_DOWN,  KC_RGHT,       KC_P0,              KC_PDOT,  KC_PENT,       KC_FIND,  KC_CUT
  ),
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
        layer_on(_MOVEMENT);
      }
      break;
  }
}
#endif


static uint16_t key_timer = 0;
static uint8_t shift_active = 0;

void matrix_scan_user(void) {
  if(shift_active && !IS_LAYER_ON(_UMLAUTE) && timer_elapsed(key_timer) > TAPPING_TERM) {
    register_code(KC_LSFT);
    shift_active = 0;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If shift is tapped without any other keypress switch to the UMLAUTE layer
  if(KC_UMLT == keycode && !IS_LAYER_ON(_UMLAUTE)) {
    if(record->event.pressed) {
      shift_active = 1;
      key_timer = timer_read();
      return false;
    } else if(shift_active && timer_elapsed(key_timer) < TAPPING_TERM) {
      shift_active = 0;
      layer_on(_UMLAUTE);
      return false;
    }
  }
  if(shift_active) {
    register_code(KC_LSFT);
    shift_active = 0;
  }
  if(IS_LAYER_ON(_UMLAUTE) && !record->event.pressed) {
    layer_off(_UMLAUTE);
  }
  return true;
}

