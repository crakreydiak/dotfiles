/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀
                                                           ▀  ▀  ▀  D E F A U L T

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "totem.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘

enum totem_layers {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    LOWER,
    RAISE,
    ADJUST,
    OS_SWAP,
    MAKE_H,
    SNAP
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS QWERTY ├──────────────────┐

#define GUI_A MT(MOD_LGUI, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define CTL_D MT(MOD_LCTL, KC_D)
#define SHT_F MT(MOD_LSFT, KC_F)

// RIGHT HAND HOME ROW MODS QWERTY ├─────────────────┐

#define SHT_J MT(MOD_RSFT, KC_J)
#define CTL_K MT(MOD_LCTL, KC_K)
#define ALT_L MT(MOD_LALT, KC_L)
#define GUI_S MT(MOD_LGUI, KC_SCLN)

#define LOWER LT(_LOWER, KC_TAB)
#define RAISE LT(_RAISE, KC_ESC)
#define ADJUST MO(_ADJUST)

#define LWR_SPC LT(_LOWER, KC_SPC)
#define RSE_ENT LT(_RAISE, KC_ENT)

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ┌─────────────────────────────────────────────────┐
   │ q w e r t y                                     │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    P    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    A    │    S    │    D    │    F    │    G    ││    H    │    J    │    K    │    L    │    ;    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │  SHIFT  │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,    │    .    │    /    │    '    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │   ESC   │   TAB   │  SPACE  ││  ENTER  │   DEL   │  BSPC   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/

   [_QWERTY] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
              GUI_A,    ALT_S,    CTL_D,    SHT_F,    KC_G,      KC_H,     SHT_J,    CTL_K,    ALT_L,    GUI_S,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,      KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_QUOT,
                                  KC_ESC,   KC_TAB,   LWR_SPC,   RSE_ENT,  KC_DEL,   KC_BSPC
 ),

 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ l o w e r                                       │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    !    │    @    │    #    │    $    │    %    ││    ^    │    &    │    *    │    (    │    )    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    ▼    │    ▼    │    ▼    │    ▼    │         ││    |    │    _    │    =    │    {    │    }    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    ▼    │    `    │    ~    │  SAVE   │   PG↓   │   PG↑   ││    \    │    -    │    +    │    [    │    ]    │    ▼    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    ▼    │    ▼    │    ▼    ││  ADJUST │    ▼    │    ▼    │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_LOWER] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,   KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
              _______,  _______,  _______,  _______,  KC_LBRC,   KC_PIPE,  KC_UNDS,  KC_EQL,   KC_LCBR,  KC_RCBR,
    _______,   KC_GRV,  KC_TILD,  C(KC_S),  KC_PGDN,  KC_PGUP,   KC_BSLS,  KC_MINS,  KC_PLUS,  KC_LBRC,  KC_RBRC,  _______,
                                  _______,  _______,  _______,   ADJUST,   _______,  _______
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ r a i s e                                       │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    1    │    2    │    3    │    4    │    5    ││    6    │    7    │    8    │    9    │    0    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    ▼    │    ▼    │    ▼    │    ▼    │    ▼    ││    ←    │    ↓    │    ↑    │    →    │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │    Ä    │    è    │    SZ   │    é    │  SNAP   ││   VOL↓  │   VOL↑  │ ← MEDIA │  PLAY   │ MEDIA → │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    ▼    │ ADJUST  │    ▼    ││    ▼    │    ▼    │    ▼    │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_RAISE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷        ╷         ╷         ╷         ╷         ╷         ╷
              KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,    KC_7,     KC_8,     KC_9,     KC_0,
              _______,  _______,  _______,  _______,  XXXXXXX,   KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT, XXXXXXX,
    XXXXXXX,  RALT(KC_A),RALT(KC_F),RALT(KC_S),RALT(KC_G),SNAP,  KC_VOLD, KC_VOLU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  XXXXXXX,
                                  _______,  _______,  ADJUST,    _______,  _______,  _______
 ),
 /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ a d j u s t                                     │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡  RESET  │         │         │         │         ││         │   F7    │   F8    │   F9    │   F12   │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │ DEBUG   │         │         │         │         ││         │   F4    │   F5    │   F6    │   F11   │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │  MAKE   │ OS SWAP │         │         │         │         ││         │   F1    │   F2    │   F3    │   F10   │   F13   │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │    ▼    │    ▼    │    ▼    ││    ▼    │    ▼    │    ▼    │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */

   [_ADJUST] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              QK_BOOT,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_F7,    KC_F8,    KC_F9,    KC_F12,
              DB_TOGG,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_F4,    KC_F5,    KC_F6,    KC_F11,
    MAKE_H,   OS_SWAP,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F10,   KC_F13,
                                  _______,  _______,  _______,   _______,  _______,  _______
 )
/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ t e m p l a t e                                 │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡         │         │         │         │         ││         │         │         │         │         │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │         │         │         │         │         ││         │         │         │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││         │         │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘

   [_TEMPLATE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______, _______,
                                  _______,  _______,   _______,  _______,  _______,  _______,
 ),
*/
};



// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                }
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
          }


// ┌─────────────────────────────────────────────────┐
// │ q m k                                           │
// └─────────────────────────────────────────────────┘

        case MAKE_H:
          if (record->event.pressed) {
            SEND_STRING ("qmk compile -kb totem -km default");
            tap_code(KC_ENTER);
          }
          break;

// ┌─────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                         │
// └─────────────────────────────────────────────────┘

      case SNAP:
          if (record->event.pressed) {
            if (keymap_config.swap_lctl_lgui) {
              SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4"))));  //MAC
            } else {
              SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
            }
          }
          break;
    }
    return true;
}

///┌─────────────────────────────────────────────────┐
// │ c o m b o s                                     │
// └─────────────────────────────────────────────────┘

enum combos {
    GTE_COMBO,
    LTE_COMBO,
    ARROW_COMBO,
    TY_PAREN,
    GH_CRLY,
    BN_BRACKETS,
    VIM_Y2CB,
    WQ_VIM_SAVE_EXIT,
};

const uint16_t PROGMEM lte_combo[]           = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM arrow_combo[]         = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM gte_combo[]           = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM vim_save_exit_combo[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM ty_paren_combo[]      = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM gh_crly_combo[]       = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM bn_brackets_combo[]   = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM vim_y2cb[]            = {KC_Y, KC_U, COMBO_END};

combo_t key_combos[] = {
    [GTE_COMBO]           = COMBO_ACTION(gte_combo),
    [LTE_COMBO]           = COMBO_ACTION(lte_combo),
    [ARROW_COMBO]         = COMBO_ACTION(arrow_combo),
    [TY_PAREN]            = COMBO_ACTION(ty_paren_combo),
    [GH_CRLY]             = COMBO_ACTION(gh_crly_combo),
    [BN_BRACKETS]         = COMBO_ACTION(bn_brackets_combo),
    [VIM_Y2CB]            = COMBO_ACTION(vim_y2cb),
    [WQ_VIM_SAVE_EXIT]    = COMBO_ACTION(vim_save_exit_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case LTE_COMBO:
            if (pressed) {
                SEND_STRING(">=");
            }
            break;
        case GTE_COMBO:
            if (pressed) {
                SEND_STRING("=<");
            }
            break;
        case ARROW_COMBO:
            if (pressed) {
                SEND_STRING("=>");
            }
            break;
        case TY_PAREN:
            if (pressed) {
                SEND_STRING("()");
                tap_code16(KC_LEFT);
            }
            break;
        case GH_CRLY:
            if (pressed) {
                SEND_STRING("{}");
                tap_code16(KC_LEFT);
            }
            break;
        case BN_BRACKETS:
            if (pressed) {
                SEND_STRING("[]");
                tap_code16(KC_LEFT);
            }
            break;
        case WQ_VIM_SAVE_EXIT:
            if (pressed) {
                tap_code16(KC_ESC);
                tap_code16(KC_COLON);
                tap_code16(KC_W);
                tap_code16(KC_Q);
            }
            break;
        case VIM_Y2CB:
            if (pressed) {
                tap_code16(KC_COLON);
                tap_code16(KC_LSFT);
                tap_code16(KC_QUOT);
                tap_code16(KC_Y);

            }
    }
}

/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
                                                            ██ ██▀▀██
                                                            ▀▀ ██▄▄██
                                                        ██████  ▀▀▀▀
                                                          ██ ▄▄▄▄▄▄
                                                          ██ ██▀▀▀▀
                                                          ██ ██████
                                                             ██▄▄▄▄
                                                             ▀▀▀▀▀▀
                                                           ████████
                                                           ██ ██ ██
                                                           ██ ██ ██
                                                           ▀▀ ▀▀ ▀▀
                                                          ████████

*/



