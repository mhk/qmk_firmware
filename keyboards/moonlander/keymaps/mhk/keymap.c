#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"

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
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum mhk_keycodes {
  ST_MACRO_0 = SAFE_RANGE,
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
#define _QWERTY     (1)
#define _PROGKEYS   (2)
#define _MOVEMENT   (3)
#define _UMLAUTE    (4)
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

#include "kblayout.h"


#ifndef KEY_MACRO_0
#define KEY_MACRO_0     (ST_MACRO_0)
#endif // KEY_MACRO_0
#ifndef KEY_MACRO_1
#define KEY_MACRO_1     (ST_MACRO_1)
#endif // KEY_MACRO_1
#ifndef KEY_AE
#define KEY_AE          (CK_AE)
#endif // KEY_AE
#ifndef KEY_SZ
#define KEY_SZ          (CK_SZ)
#endif // KEY_SZ
#ifndef KEY_UE
#define KEY_UE          (CK_UE)
#endif // KEY_UE
#ifndef KEY_OE
#define KEY_OE          (CK_OE)
#endif // KEY_OE
#ifndef KEY_ON_PLOVER
#define KEY_ON_PLOVER   (ON_PLOVER)
#endif // KEY_ON_PLOVER
#ifndef KEY_OFF_PLOVER
#define KEY_OFF_PLOVER  (OFF_PLOVER)
#endif // KEY_OFF_PLOVER
#ifndef KEY_LPROG
#define KEY_LPROG       (CK_LPROG)
#endif // KEY_LPROG
#ifndef KEY_RPROG
#define KEY_RPROG       (CK_RPROG)
#endif // KEY_RPROG


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
  keymap_config.nkro = true;
}

static uint16_t key_timer = 0;
static uint16_t shift_active = 0;
static uint16_t on_plover = 0;
static uint16_t lock_prog = 0;

void matrix_scan_user(void) {
  if(shift_active && !IS_LAYER_ON(_UMLAUTE) && timer_elapsed(key_timer) > TAPPING_TERM) {
    register_code(shift_active);
    shift_active = 0;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CUSTOM_PROCESS_RECORD_USER
  int result = -1;
  if(-1 != (result = custom_process_record_user(keycode, record))) {
    return result;
  }
#endif

  switch (keycode) {
    case KEY_MACRO_0:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_Z)));
      }
      break;
    case KEY_MACRO_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_Y)));
      }
      break;
    case KEY_AE:
      if (record->event.pressed) {
        SEND_STRING("\"a");
      }
      break;
    case KEY_SZ:
      if (record->event.pressed) {
        SEND_STRING(SS_RALT(SS_TAP(X_S)));
      }
      break;
    case KEY_UE:
      if (record->event.pressed) {
        SEND_STRING("\"u");
      }
      break;
    case KEY_OE:
      if (record->event.pressed) {
        SEND_STRING("\"o");
      }
      break;
    case KEY_OFF_PLOVER:
      if (record->event.pressed) {
        deactivate_plover();
        layer_off(_ONETS);
      }
      return false;
    case KEY_LPROG:
    case KEY_RPROG:
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
  // to prevent accidental activation of the plover layer force the user to double tap it
  if(KEY_ON_PLOVER == keycode && record->event.pressed) {
    ++on_plover;
    if(!(on_plover & 0x01)) {
      activate_plover();
      layer_on(_ONETS);
      on_plover = 0;
      return false;
    }
  } else {
    on_plover = 0;
  }
  // If shift is tapped without any other keypress switch to the UMLAUTE layer
  // but only if the current layer is colemakdhm or qwerty. This allows double
  // shift press in other layers.
  if((KC_LSFT == keycode || KC_RSFT == keycode) && !IS_LAYER_ON(_UMLAUTE)
      && (IS_LAYER_ON(_COLEMAKDHM) || IS_LAYER_ON(_QWERTY))) {
    if(record->event.pressed) {
      shift_active = keycode;
      key_timer = timer_read();
      return false;
    } else if(shift_active == keycode && timer_elapsed(key_timer) < TAPPING_TERM) {
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
