#include QMK_KEYBOARD_H

#define _MAIN 0
#define _FN 1

enum custom_keycodes {
    P_MACRO = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0: Main Layer
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │PRSCR│ INS │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
     * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │HOME │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
     * │  TAB   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │   \    │PG_UP│
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
     * │  CAPS   │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │    RETURN   │PG_DN│
     * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
     * │   LSHIFT   │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  RSHIFT  │ UP  │ END │
     * ├──────┬─────┴┬────┴─┬───┴─────┴─────┴─────┴─────┴─────┴────┬┴─────┴─┬───┴────┬─────┼─────┼─────┤
     * │LCTRL │L_GUI │L_ALT │                SPACE                 │ R_ALT  │   FN   │LEFT │DOWN │RIGHT│
     * └──────┴──────┴──────┴──────────────────────────────────────┴────────┴────────┴─────┴─────┴─────┘
     */
    [_MAIN] = LAYOUT(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_PSCR, KC_INSERT, KC_DEL,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,      KC_BSPC,        KC_HOME,
        KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,       KC_PGUP,
        KC_CAPS,     KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN  ,KC_QUOT,        KC_ENT,             KC_PGDOWN,
        KC_LSFT,       KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT,              KC_UP,    KC_END,
        KC_LCTL,  KC_LGUI,  KC_LALT,                  KC_SPC,                                    KC_RALT,  KC_RGUI,  MO(_FN),          KC_LEFT,   KC_DOWN,   KC_RGHT
    ),

    /* 1: Function Layer
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │R_TOG│R_MOD│R_HUI│R_SAI│R_VAI│R_HUD│R_SAD│R_VAD│     │     │     │VOL- │VOL+ │     │ RES │     │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
     * │BLTOG│BLINC│BLDEC│  £  │     │     │     │     │     │     │     │     │     │           │     │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
     * │        │     │     │     │     │     │     │     │     │     │     │     │     │        │     │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
     * │         │     │     │     │     │     │     │     │     │     │     │     │             │     │
     * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
     * │            │     │     │     │     │     │     │     │     │     │     │          │     │     │
     * ├──────┬─────┴┬────┴─┬───┴─────┴─────┴─────┴─────┴─────┴────┬┴─────┴─┬───┴────┬─────┼─────┼─────┤
     * │      │      │      │                                      │        │        │     │     │     │
     * └──────┴──────┴──────┴──────────────────────────────────────┴────────┴────────┴─────┴─────┴─────┘
     */
    [_FN] = LAYOUT(
        RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_HUD,  RGB_SAD,  RGB_VAD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_TRNS,  RESET,    KC_TRNS,
        BL_TOGG,  BL_INC,   BL_DEC,   P_MACRO,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
        BL_STEP,   KC_TRNS,  KC_TRNS,  KC_TRNS  ,KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,           KC_TRNS,  KC_TRNS,
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                KC_TRNS,      KC_TRNS,
        KC_TRNS,     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,               KC_TRNS,      KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
};


// GBP £ Macro (sends alt 156 - windows users only)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case P_MACRO:
                register_code(KC_LALT);
                tap_code(KC_KP_1);
                tap_code(KC_KP_5);
                tap_code(KC_KP_6);
                unregister_code(KC_LALT);
                return false;
        }
    }
    return true;
};
