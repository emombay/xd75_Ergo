#include "xd75.h"
#include <stdarg.h>
#include "action_layer.h"
#include "version.h"
#include "action_util.h"
#include "eeconfig.h"

#define _______ KC_TRNS

#define _WORK 0 // Workman layer
#define _QWERTY 1 // QWERTY layer
#define _SYMB 2 // symbols
#define _UTIL 3 // symbols
#define _NUM 4 // symbols
#define _ADJ 5 // adjust keys
#define _GAME 6 // game keys

enum ergodox_keycodes {
  WRKMN = SAFE_RANGE,
  QWERTY,
  SYMB,
  UTIL,
  NUM,
  ADJUST,
  GAME,
  VRSN,
  EPRM
};

#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_UNDO LCTL(KC_Z)
#define KC_REDO LCTL(KC_Y)
#define KC_CUT LCTL(KC_X)
#define KC_ALL LCTL(KC_A)
#define KC_SAVE LCTL(KC_S)

enum {
  TD_FUN = 0,
  TD_3EQ,
  TD_2EQ
};
#define ALTTAB 1
#define CTRLWIN 2
#define CTRLSHIFT 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Workman layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |   `    | 1      | 2      | 3      | 4      | 5      | UNDO   |PrintSc |  Redo  | 6      | 7      | 8      | 9      | 0      | NUM    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | D      | R      | W      | B      | DELETE | CAPS   |CRTL+Win| J      | F      | U      | P      | ;      | \      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | CODE   | A      | S      | H      | T      | G      | _      | Esc    | Meh    | Y      | N      | E      | O      | I      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z      | X      | M      | C      | V      | App    | COPY   | Enter  | K      | L      | ,      | .      | /      | RSHIFT |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRL  | AltTab |  LGui  |  Alt   | RCTRL  |  UTIL  | BackSp | PASTE  | Enter  | SPACE  |  Left  |  Down  |   Up   | Right  | TT(NUM)|
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_WORK] = { 
  { KC_GRV,  KC_1,     KC_2,    KC_3,    KC_4,   KC_5,   KC_UNDO, KC_PSCR, KC_REDO,      KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    TO(_NUM) },
  { KC_TAB,  KC_Q,     KC_D,    KC_R,    KC_W,   KC_B,   KC_DELT, KC_CAPS, M(CTRLWIN),   KC_J,   KC_F,   KC_U,    KC_P,    KC_SCLN, KC_BSLS, },
  { SYMB,    KC_A,     KC_S,    KC_H,    KC_T,   KC_G,   KC_UNDS, KC_ESC,  MEH_T(KC_NO), KC_Y,   KC_N,   KC_E,    KC_O,    KC_I,    KC_QUOT, },
  { KC_LSFT, KC_Z,     KC_X,    KC_M,    KC_C,   KC_V,   KC_APP,  KC_COPY, KC_ENT,       KC_K,   KC_L,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, },
  { KC_LCTL, M(ALTTAB),KC_LGUI, KC_LALT, KC_RCTL,UTIL,   KC_BSPC, KC_PASTE,KC_ENT,       KC_SPC, KC_LEFT,KC_DOWN, KC_UP,   KC_RGHT, NUM },
 },
/* Keymap 1: Basic layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | Q      | W      | E      | R      | T      |        |        |        | Y      | U      | I      | O      | P      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | A      | S      | D      | F      | G      |        |        |        | H      | J      | K      | L      | ;      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        | Z      | X      | C      | V      | B      |        |        |        | N      | M      | ,      | .      | /      |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_QWERTY] = { 
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______ },
  { _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______ },
  { _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______, _______, _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______ },
  { _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ },
 },

/* Keymap 3: Symbol Layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |  +     |  =     |  {     |  }     | |      |        |        |        |        | TD_2EQ |        |        |        | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | &      |  -     |  (     |  )     | `      |        |        |        |        | TD_3EQ | TD_FUN |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        | <      |  >     |  [     |  ]     |  ~     |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        | F8     | F9     | F10    | F11    |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
// SYMBOLS
 [_SYMB] = { /* QWERTY */
  { _______, KC_F1,        KC_F2,        KC_F3,  KC_F4,  KC_F5,   _______, _______, _______, KC_F6,   KC_F7,      KC_F8,      KC_F9,   KC_F10,  KC_F11 },
  { _______, LSFT(KC_EQL), KC_EQL,       KC_LCBR,KC_RCBR,KC_PIPE, _______, _______, _______, _______, TD(TD_2EQ), _______,    _______, _______, KC_F12 },
  { _______, LSFT(KC_7),   KC_MINS,      KC_LPRN,KC_RPRN,KC_GRV,  _______, _______, _______, _______, TD(TD_3EQ), TD(TD_FUN), _______, _______, _______ },
  { _______, LSFT(KC_COMM),LSFT(KC_DOT), KC_LBRC,KC_RBRC,KC_TILD, _______, _______, _______, _______, _______,    _______,    _______, _______, _______ },
  { _______, KC_F8,        KC_F9,        KC_F10, KC_F11, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______ },
 },

/* Keymap 3: UTIL Layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | F7     | F8     | F9     | F10    | F11    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |Ctrl+Tab|        | Ctrl+D | Ctrl+R | Ctrl+W |        |        |        |        |        | Ctrl+F |        | Ctrl+P |        | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        | All    | Save   |        |Ctrl+T  |        |        |        |        |        | Home   | PgDown | PgUp   | End    | Insert |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        | Cut    |        | Copy   | Paste  |        |        |        | Prev   | Next   | Vol-   | Vol+   | Play   |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        | Undo   | Redo   |        |        |        |        |        | Ctrl+< | Ctrl+^ | Ctrl+v | Ctrl+> |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
// SYMBOLS
 [_UTIL] = { /* QWERTY */
  { _______,      KC_F1,   KC_F2,     KC_F3,     KC_F4,      KC_F5,   _______, _______, _______, KC_F6,   KC_F7,        KC_F8,        KC_F9,      KC_F10,       KC_F11 },
  { LCTL(KC_TAB), _______, LCTL(KC_D),LCTL(KC_R),LCTL(KC_W), _______, _______, _______, _______, _______, LCTL(KC_F),   _______,      LCTL(KC_P), _______,      KC_F12 },
  { _______,      KC_ALL,  KC_SAVE,   _______,   LCTL(KC_T), _______, _______, _______, _______, _______, KC_HOME,      KC_PGDN,      KC_PGUP,    KC_END,       KC_INS },
  { _______,      _______, KC_CUT,    _______,   KC_COPY,    KC_PASTE,_______, _______, _______, KC_MPRV, KC_MNXT,      KC_VOLD,      KC_VOLU,    KC_MPLY,      _______ },
  { _______,      _______, _______,   KC_UNDO,   KC_REDO,    _______, _______, _______, _______, _______, LCTL(KC_LEFT),LCTL(KC_DOWN),LCTL(KC_UP),LCTL(KC_RGHT),_______ },
 },
/* Keymap 4: Numpad Layer
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        | NumLk  | /      | *      | -      | ADJUST |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        | Lclk   | MsUp   | Rclk   |        |        |        |        |        | 7      | 8      | 9      | +      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        | MsLeft | MsDown | MsRght |        |        |        |        |        | 4      | 5      | 6      | +      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        | App    |        |        |        |        |        | 1      | 2      | 3      | Enter  |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | 0      | 0      | .      | =      |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NUM] = { 
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, TO(_ADJ) },
  { _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, _______ },
  { _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, _______ },
  { _______, _______, _______, _______, KC_APP,  _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, _______ },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_KP_0, KC_PDOT, KC_EQL,  _______ },
 },
/* Keymap 5: Adjust
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        | Bright-| WRKM   | Hue-   | Version| EPRM   |        | AGnorm | AGswap | Wrkmn  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        | Bright+| QWRTY  | Hue+   |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |        |        |        |        |        |        |        | Animat |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[_ADJ] = {

   { _______,  _______,  _______,  _______,  _______,  _______,       RGB_VAD, WRKMN,   RGB_HUD, VRSN,     EPRM,     _______,  AG_NORM,  AG_SWAP,  TO(_GAME) },
   { _______  ,_______,  _______,  _______,  _______,  _______,       RGB_VAI ,QWERTY,  RGB_HUI, _______,  _______,  _______,  _______,  _______,  _______ },
   { _______  ,_______,  _______,  _______,  _______,  _______,       _______ ,RGB_MOD, _______, _______,  _______,  _______,  _______,  _______,  _______ },
   { _______  ,_______,  _______,  _______,  _______,  _______,       _______ ,_______, _______, _______,  _______,  _______,  _______,  _______,  _______ },
   { _______  ,_______,  _______,  _______,  _______,  _______,       _______ ,_______, _______, _______,  _______,  _______,  _______,  _______,  _______ }

  },

  /* Keymap 6: Game
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | Wrkmn  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * |    ;   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        | Space  |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */
[_GAME] = {

   { _______,  _______,  _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  TO(_WORK) },
   { _______  ,_______,  _______,  _______,  _______,  _______, _______ ,_______, _______, _______, _______, _______,  _______,  _______,  _______ },
   { KC_SCLN  ,_______,  _______,  _______,  _______,  _______, _______ ,_______, _______, _______, _______, _______,  _______,  _______,  _______ },
   { _______  ,_______,  _______,  _______,  _______,  _______, _______ ,_______, _______, _______, _______, _______,  _______,  _______,  _______ },
   { _______  ,_______,  _______,  _______,  _______,  KC_SPC,  _______ ,_______, _______, _______, _______, _______,  _______,  _______,  _______ }

  },
}; 

// TAP DANCE SETTINGS

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

static void m_tapn (uint8_t code, ...) {
  uint8_t kc = code;
  va_list ap;

  va_start(ap, code);
  do {
    register_code(kc);
    unregister_code(kc);
    wait_ms(50);
    kc = va_arg(ap, int);
  } while (kc != 0);
  va_end(ap);
}

void dance_eq (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1: // ===
      m_tapn(KC_EQL, KC_EQL, KC_EQL, 0);
      break;
    case 2: // !==
      register_code(KC_LSHIFT);
      m_tapn(KC_1, 0);
      unregister_code(KC_LSHIFT);
      m_tapn(KC_EQL, KC_EQL, 0);
      break;
    default:
      reset_tap_dance(state);
  }
}

void dance_two_eq (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1: // ==
      m_tapn(KC_EQL, KC_EQL, 0);
      break;
    case 2: // !=
      register_code(KC_LSHIFT);
      m_tapn(KC_1, 0);
      unregister_code(KC_LSHIFT);
      m_tapn(KC_EQL, 0);
      break;
    default:
      reset_tap_dance(state);
  }
}

void dance_fun (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1: // =>    
      m_tapn(KC_EQL, 0);
      register_code(KC_LSFT);
      m_tapn(KC_DOT, 0);
      unregister_code(KC_LSFT);
      break;
    case 2: // () => {}
      register_code(KC_LSFT);
      m_tapn(KC_9, KC_0, KC_SPC, 0);
      unregister_code(KC_LSFT);
      m_tapn(KC_EQL, 0);
      register_code(KC_LSFT);
      m_tapn(KC_DOT, KC_SPC, KC_LBRC, KC_RBRC, 0);
      unregister_code(KC_LSFT);
      break;
    default:
      reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_FUN] = ACTION_TAP_DANCE_FN (dance_fun)
 ,[TD_3EQ] = ACTION_TAP_DANCE_FN (dance_eq)
 ,[TD_2EQ] = ACTION_TAP_DANCE_FN (dance_two_eq)
};

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  //Cancle one-shot mods.
  switch (keycode) {
        case WRKMN:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_WORK);
          }
          return false;
          break;
        case QWERTY:
          if (record->event.pressed) {
            persistant_default_layer_set(1UL<<_QWERTY);
          }
          return false;
          break;
        case SYMB:
          if (record->event.pressed) {
            layer_on(_SYMB);
          } else {
            layer_off(_SYMB);
          }
          return false;
          break;
        case NUM:
          if (record->event.pressed) {
            layer_on(_NUM);
          } else {
            layer_off(_NUM);
          }
          return false;
          break;
        case UTIL:
          if (record->event.pressed) {
            layer_on(_UTIL);
          } else {
            layer_off(_UTIL);
          }
          return false;
          break;
        case VRSN:
          if (record->event.pressed) {
            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
          }
          return false;
          break;
        case EPRM:
          if (record->event.pressed) {
            eeconfig_init();
          }
          return false;
          break;
      }
    return true;
}


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
		case ALTTAB: 
		if (record->event.pressed) {
			return MACRO( D(LALT), D(TAB), W(200), U(TAB), END );
		} else {
			return MACRO( U(LALT), END );
		}
		break;
		case CTRLWIN: 
		if (record->event.pressed) {
			return MACRO( D(LCTL), D(LGUI), END );
		} else {
			return MACRO( U(LGUI), U(LCTL), END );
		}
		break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  rgblight_init();
  #ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
  #endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
};

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);
  switch (layer) {
      case _WORK:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
          rgblight_init();
        #endif
        break;
      case _QWERTY:
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case _SYMB:
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case _UTIL:
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case _NUM:
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case _ADJ:
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case _GAME:
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 7:
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
