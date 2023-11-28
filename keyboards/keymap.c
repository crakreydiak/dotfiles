/* Copyright 2020 Jonathan Rascher
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


#define LWR_SPC LT(1, KC_SPC)
#define RSE_ENT LT(2, KC_ENT)

#define GUI_A  MT(MOD_LGUI, KC_A)
#define ALT_S  MT(MOD_LALT, KC_S)
#define LSFT_D MT(MOD_LSFT, KC_D)
#define LCTL_F MT(MOD_LCTL, KC_F)

#define LCTL_J    MT(MOD_LCTL, KC_J)
#define LSFT_K    MT(MOD_LSFT, KC_K)
#define ALT_L     MT(MOD_LALT, KC_L)
#define GUI_SCLN  MT(MOD_LGUI, KC_SCLN)

const uint16_t PROGMEM LY_LWR = MO(1);
const uint16_t PROGMEM LY_RSE = MO(2);

enum layers {
    LAYER_DEFAULT, // QWERTY layer
    LAYER_LOWER,   // symbols layer
    LAYER_RAISE,   // movement & numbers layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    // DEFAULT LAYER
    [LAYER_DEFAULT] = LAYOUT_split_3x6_3(
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_ESC,   GUI_A,    ALT_S,    LSFT_D,   LCTL_F,   KC_G,                         KC_H,     LCTL_J,   LSFT_K,   ALT_L,    GUI_SCLN, KC_QUOT,
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_LALT,
                                             KC_LGUI,  KC_LSFT,   LWR_SPC,   RSE_ENT,   KC_BSPC,  KC_ESC
    ),
    // LAYER LOWER
    [LAYER_LOWER] = LAYOUT_split_3x6_3(
        _______,  KC_EXLM,     KC_AT,       KC_HASH,    KC_DLR,      KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
        _______,  _______,     _______,     _______,    _______,     _______,           KC_PIPE,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_TILD,
        _______,  LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C), LCTL(KC_V),  KC_LGUI,           KC_BSLS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_GRV,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),
    // LAYER RAISE
    [LAYER_RAISE] = LAYOUT_split_3x6_3(
        _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
        _______,  _______,  _______,  _______,  _______,  _______,                      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_DEL,
        _______,  KC_VOLD,  KC_VOLU,  KC_MPRV,  KC_MPLY,  KC_MNXT,                      CG_SWAP,  _______,  _______,  _______,  KC_F12,   _______,
                                                _______,  _______,  _______,  _______,  _______,  _______
   ),
};

#ifdef OLED_ENABLE

/* KEYBOARD PET START */

/* settings */
#    define MIN_WALK_SPEED      10

/* advanced settings */
#    define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#    define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int   current_wpm = 0;
led_t led_usb_state;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {/* 'sit1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'sit2', 32x22px */
                                                   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28, 0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {/* 'run1', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01, 0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   },

                                                   /* 'run2', 32x22px */
                                                   {
                                                       0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                   }};

    /* animation */
    void animate_luna(void) {
        /* clear */
        oled_set_cursor(LUNA_X, LUNA_Y - 1);
        oled_write("     ", false);

        oled_set_cursor(LUNA_X, LUNA_Y);

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[current_frame], ANIM_SIZE);
       } else {
            oled_write_raw_P(run[current_frame], ANIM_SIZE);
        }
    }

#    if OLED_TIMEOUT > 0
    /* the animation prevents the normal timeout from occuring */
    if (last_input_activity_elapsed() > OLED_TIMEOUT && last_led_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
        return;
    } else {
        oled_on();
    }
#    endif

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    /* wpm counter */
    uint8_t n = get_current_wpm();
    char    wpm_str[4];
    oled_set_cursor(0, 14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0, 15);
    oled_write(" wpm", false);
}

static void print_status_narrow(void) {
    oled_set_cursor(0, 5);
    /* KEYBOARD PET RENDER START */
    render_luna(0, 13);
    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
    return false;
}

#endif


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

