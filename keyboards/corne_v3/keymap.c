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

#define ESCTL  CTL_T(KC_ESC)
#define ESLSFT SFT_T(KC_ESC)

enum {
    TD_ACCENT_E,
    TD_ACCENT_A,
    TD_ACCENT_U,
    TD_ACCENT_C,
};


void accent_e(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_E);
            unregister_code(KC_E);
            reset_tap_dance(state);
            break;
        case 2:
            register_code(KC_SLSH);
            unregister_code(KC_SLSH);
            reset_tap_dance(state);
            break;
        case 3:
            register_code(KC_QUOT);
            unregister_code(KC_QUOT);
            reset_tap_dance(state);
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_ACCENT_E] = ACTION_TAP_DANCE_FN(accent_e),
    [TD_ACCENT_A] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_BSLS),
    [TD_ACCENT_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_GRV),
    [TD_ACCENT_C] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_RBRC),
};

#define TD_E TD(TD_ACCENT_E)
#define TD_A TD(TD_ACCENT_A)
#define TD_U TD(TD_ACCENT_U)
#define TD_C TD(TD_ACCENT_C)

#define LWR_SPC LT(1, KC_SPC)
#define RSE_ENT LT(2, KC_ENT)

const uint16_t PROGMEM LY_LWR = MO(1);
const uint16_t PROGMEM LY_RSE = MO(2);

enum layers {
    LAYER_DEFAULT, // QWERTY layer
    LAYER_LOWER,   // symbols layer
    LAYER_RAISE,   // movement & numbers layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    /* Default layer: http://www.keyboard-layout-editor.com/##@_name=Split%203x6%20+%203%20thumb%20keys%20layout,%20lower%20layer&author=https%2F:%2F%2F%2F%2Fgithub.com%2F%2Fbcat&plate:false%3B&@_x:3%3B&=%23&_x:7%3B&=i%3B&@_y:-0.9&x:2%3B&=%2F@%3B&@_y:-1&x:4%3B&=$&_x:5%3B&=u&_x:1%3B&=o%3B&@_y:-0.9000000000000001&x:5%3B&=%25&_x:3%3B&=y%3B&@_y:-0.8999999999999999%3B&=Tab&=!&_x:11%3B&=p&=Back%0A%0A%0A%0A%0A%0Aspace%3B&@_y:-0.30000000000000004&x:3%3B&=d&_x:7%3B&=k%3B&@_y:-0.8999999999999999&x:2%3B&=s&_x:1%3B&=f&_x:5%3B&=j&_x:1%3B&=l%3B&@_y:-0.9000000000000001&x:5%3B&=g&_x:3%3B&=h%3B&@_y:-0.9000000000000001%3B&=Left%0A%0A%0A%0A%0A%0AShift&=a&_x:11%3B&=%2F%3B%0A%0A%0A%0A%0A%0A%2F:&='%0A%0A%0A%0A%0A%0A%22%3B&@_y:-0.2999999999999998&x:3%3B&=c&_x:7%3B&=,%0A%0A%0A%0A%0A%0A%3C%3B&@_y:-0.8999999999999999&x:2%3B&=x&_x:1%3B&=v&_x:5%3B&=m&_x:1%3B&=.%0A%0A%0A%0A%0A%0A%3E%3B&@_y:-0.8999999999999999&x:5%3B&=b&_x:3%3B&=n%3B&@_y:-0.9000000000000004%3B&=Left%0A%0A%0A%0A%0A%0ACtrl&=z&_x:11%3B&=%2F%2F%0A%0A%0A%0A%0A%0A%3F&=Left%0A%0A%0A%0A%0A%0AAlt%3B&@_y:-0.19999999999999973&x:3.5%3B&=Super&_x:6%3B&=Esc%3B&@_r:15&rx:4.5&ry:4.1&y:-0.9999999999999996%3B&=LWR%3B&@_r:30&rx:5.4&ry:4.3&y:-1.5&x:0.09999999999999964&h:1.5%3B&=Space%3B&@_r:-30&rx:9.6&y:-1.5&x:-1.0999999999999996&h:1.5%3B&=Enter%3B&@_r:-15&rx:10.5&ry:4.1&y:-0.9999999999999996&x:-1%3B&=RSE*/
    [LAYER_DEFAULT] = LAYOUT_split_3x6_3(
        KC_TAB,   KC_Q,     KC_W,     TD_E,     KC_R,     KC_T,                         KC_Y,     TD_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        ESLSFT,   TD_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LCTL,  KC_Z,     KC_X,     TD_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_LALT,
                                             KC_LGUI,   LY_LWR,   LWR_SPC,   RSE_ENT,   LY_RSE,   KC_LGUI
    ),
    /* Lower layer: http://www.keyboard-layout-editor.com/##@_name=Split%203x6%20+%203%20thumb%20keys%20layout,%20lower%20layer&author=https%2F:%2F%2F%2F%2Fgithub.com%2F%2Fbcat&plate:false%3B&@_x:3%3B&=%23&_x:7%3B&=*%3B&@_y:-0.9&x:2%3B&=%2F@%3B&@_y:-1&x:4%3B&=$&_x:5%3B&=%2F&&_x:1%3B&=(%3B&@_y:-0.9000000000000001&x:5%3B&=%25&_x:3%3B&=%5E%3B&@_y:-0.8999999999999999&g:true&a:7%3B&=&_g:false&a:4%3B&=!&_x:11%3B&=)&=Del%3B&@_y:-0.30000000000000004&x:3&g:true&a:7%3B&=&_x:7&g:false&a:4%3B&=+%3B&@_y:-0.8999999999999999&x:2&g:true&a:7%3B&=&_x:1%3B&=&_x:5&g:false&a:4%3B&=%2F_&_x:1%3B&=%7B%3B&@_y:-0.9000000000000001&x:5&g:true&a:7%3B&=&_x:3&g:false&a:4%3B&=%7C%3B&@_y:-0.9000000000000001&g:true&a:7%3B&=&=&_x:11&g:false&a:4%3B&=%7D&=~%3B&@_y:-0.2999999999999998&x:3&g:true&a:7%3B&=&_x:7&g:false&a:4%3B&=%2F=%3B&@_y:-0.8999999999999999&x:2&g:true&a:7%3B&=&_x:1%3B&=&_x:5&g:false&a:4%3B&=-&_x:1%3B&=%5B%3B&@_y:-0.8999999999999999&x:5%3B&=Super&_x:3%3B&=%5C%3B&@_y:-0.9000000000000004&g:true&a:7%3B&=&=&_x:11&g:false&a:4%3B&=%5D&=%60%3B&@_y:-0.19999999999999973&x:3.5&g:true&a:7%3B&=&_x:6%3B&=%3B&@_r:15&rx:4.5&ry:4.1&y:-0.9999999999999996%3B&=%3B&@_r:30&rx:5.4&ry:4.3&y:-1.5&x:0.09999999999999964&h:1.5%3B&=%3B&@_r:-30&rx:9.6&y:-1.5&x:-1.0999999999999996&h:1.5%3B&=%3B&@_r:-15&rx:10.5&ry:4.1&y:-0.9999999999999996&x:-1%3B&= */
    [LAYER_LOWER] = LAYOUT_split_3x6_3(
        _______,  KC_EXLM,     KC_AT,       KC_HASH,    KC_DLR,      KC_PERC,           KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL,
        _______,  _______,     _______,     _______,    _______,     _______,           KC_PIPE,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_TILD,
        _______,  LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C), LCTL(KC_V),  KC_LGUI,           KC_BSLS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_GRV,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),
    /* Raise layer: http://www.keyboard-layout-editor.com/##@_name=Split%203x6%20+%203%20thumb%20keys%20layout,%20lower%20layer&author=https%2F:%2F%2F%2F%2Fgithub.com%2F%2Fbcat&plate:false%3B&@_x:3%3B&=3&_x:7%3B&=8%3B&@_y:-0.9&x:2%3B&=2%3B&@_y:-1&x:4%3B&=4&_x:5%3B&=7&_x:1%3B&=9%3B&@_y:-0.9000000000000001&x:5%3B&=5&_x:3%3B&=6%3B&@_y:-0.8999999999999999&g:true%3B&=Tab&_g:false%3B&=1&_x:11%3B&=0&=Del%3B&@_y:-0.30000000000000004&x:3%3B&=Media%0A%0A%0A%0A%0A%0APrev&_x:7%3B&=Up%3B&@_y:-0.8999999999999999&x:2%3B&=Vol%0A%0A%0A%0A%0A%0ADown&_x:1%3B&=Play%0A%0A%0A%0A%0A%0APause&_x:5%3B&=Down&_x:1%3B&=Right%3B&@_y:-0.9000000000000001&x:5%3B&=Media%0A%0A%0A%0A%0A%0ANext&_x:3%3B&=Left%3B&@_y:-0.9000000000000001&g:true%3B&=Left%0A%0A%0A%0A%0A%0AShift&_g:false%3B&=Vol%0A%0A%0A%0A%0A%0AUp&_x:11%3B&=F11&=Del%3B&@_y:-0.2999999999999998&x:3%3B&=F3&_x:7%3B&=Page%0A%0A%0A%0A%0A%0AUp%3B&@_y:-0.8999999999999999&x:2%3B&=F2&_x:1%3B&=F5&_x:5%3B&=Page%0A%0A%0A%0A%0A%0ADown&_x:1%3B&=End%3B&@_y:-0.8999999999999999&x:5%3B&=F5&_x:3%3B&=Home%3B&@_y:-0.9000000000000004&g:true%3B&=Left%0A%0A%0A%0A%0A%0ACtrl&_g:false%3B&=BL%0A%0A%0A%0A%0A%0AToggle&_x:11%3B&=F12&=Insert%3B&@_y:-0.19999999999999973&x:3.5%3B&=Super&_x:6%3B&=Esc%3B&@_r:15&rx:4.5&ry:4.1&y:-0.9999999999999996%3B&=LWR%3B&@_r:30&rx:5.4&ry:4.3&y:-1.5&x:0.09999999999999964&h:1.5%3B&=Space%3B&@_r:-30&rx:9.6&y:-1.5&x:-1.0999999999999996&h:1.5%3B&=Enter%3B&@_r:-15&rx:10.5&ry:4.1&y:-0.9999999999999996&x:-1%3B&=RSE*/
    [LAYER_RAISE] = LAYOUT_split_3x6_3(
        KC_TAB,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_BSPC,
        KC_LSFT,  KC_VOLU,  KC_VOLD,  KC_MPRV,  KC_MPLY,  KC_MNXT,                      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_DEL,
        KC_LCTL,  CG_SWAP,  CG_LNRM,  KC_F3,    KC_F5,    KC_F5,                        _______,  _______,  _______,  _______,  KC_F12,   _______,
                                                _______,  _______,  _______,  _______,  _______,  _______
    ),/* Adjust layer: http://www.keyboard-layout-editor.com/#/gists/77e7572e077b36a23eb2086017e16fee */
    //
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
    KL_GTE,
    JH_LTE,
    JK_ARROW,
    WQ_VIM_SAVE_EXIT,
    TY_PAREN,
    GH_CRLY,
    BN_BRACKETS
};

const uint16_t PROGMEM gte_combo[]           = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM jk_combo[]            = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM lte_combo[]           = {KC_J, KC_H, COMBO_END};
const uint16_t PROGMEM vim_save_exit_combo[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM ty_paren_combo[]      = {KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM gh_crly_combo[]       = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM bn_brackets_combo[]   = {KC_B, KC_N, COMBO_END};

combo_t key_combos[] = {
    [KL_GTE]           = COMBO_ACTION(gte_combo),
    [JH_LTE]           = COMBO_ACTION(lte_combo),
    [JK_ARROW]         = COMBO_ACTION(jk_combo),
    [WQ_VIM_SAVE_EXIT] = COMBO_ACTION(vim_save_exit_combo),
    [TY_PAREN]         = COMBO_ACTION(ty_paren_combo),
    [GH_CRLY]          = COMBO_ACTION(gh_crly_combo),
    [BN_BRACKETS]      = COMBO_ACTION(bn_brackets_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case JH_LTE:
            if (pressed) {
                SEND_STRING(">=");
            }
            break;
        case KL_GTE:
            if (pressed) {
                SEND_STRING("=<");
            }
            break;
        case JK_ARROW:
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
    }
}

