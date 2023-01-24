#include QMK_KEYBOARD_H

#define _MAIN 0
#define _FN 1

enum custom_keycodes {
    P_MACRO = SAFE_RANGE,
    //MY_CAPS = SAFE_RANGE,
};

enum unicode_names {
    EMDASH,
    ZWSP,
};

const uint32_t PROGMEM unicode_map[] = {
    [EMDASH] = 0x2014,  // —
    [ZWSP] = 0x200B,  // '​'
};

// Keycodes: https://docs.qmk.fm/#/keycodes_basic
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layers: https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
    /* 0: Main Layer
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ ESC │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │PRSCR│ INS │ DEL │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
     * │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │ BACKSPACE │HOME │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
     * │  TAB   │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │   \    │PG_UP│
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
     * │BACKSPACE│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │    RETURN   │PG_DN│
     * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
     * │   LSHIFT   │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  RSHIFT  │ UP  │ END │
     * ├──────┬─────┴┬────┴─┬───┴─────┴─────┴─────┴─────┴─────┴────┬┴─────┴─┬───┴────┬─────┼─────┼─────┤
     * │LCTRL │L_GUI │L_ALT │                SPACE                 │ R_ALT  │  MOD   │LEFT │DOWN │RIGHT│
     * └──────┴──────┴──────┴──────────────────────────────────────┴────────┴────────┴─────┴─────┴─────┘
     */
    [_MAIN] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_INSERT, KC_DEL, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_HOME, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, KC_BSPC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGDN, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_END, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RGUI, MO(_FN), KC_LEFT, KC_DOWN, KC_RGHT),

    /* 1: Function Layer
     * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
     * │ PWR │     │     │     │     │BRID │BRIU │MPRV │MNXT │MPLY │MUTE │VOL- │VOL+ │     │ RES │ EEP │
     * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┼─────┤
     * │MACRO│     │R SAD│R SAI│R VAD│R VAI│R HUD│R HUI│R MOD│RGB~ │ BL~ │ BL- │ BL+ │ BL BREATH │     │
     * ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
     * │        │     │     │     │     │     │     │     │     │     │     │     │     │        │     │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴────────┼─────┤
     * │  CAPS   │     │     │     │     │     │LEFT │DOWN │ UP  │RIGHT│     │     │             │     │
     * ├─────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────┬─────┼─────┤
     * │            │     │     │     │     │     │     │     │     │     │     │          │     │     │
     * ├──────┬─────┴┬────┴─┬───┴─────┴─────┴─────┴─────┴─────┴────┬┴─────┴─┬───┴────┬─────┼─────┼─────┤
     * │      │      │      │                                      │        │        │     │     │     │
     * └──────┴──────┴──────┴──────────────────────────────────────┴────────┴────────┴─────┴─────┴─────┘
     */
    // RESET,    EEP_RST,
    // backlight, media buttons; , , , ,
    [_FN]     = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BRID, KC_BRIU, KC_MPRV, KC_MNXT, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, RESET, EEP_RST, P_MACRO, KC_TRNS, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_MOD, RGB_TOG, BL_TOGG, BL_DEC, BL_INC, BL_BRTG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_FN + 1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RCTRL, KC_TRNS, KC_TRNS, X(ZWSP), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_FN + 1] = LAYOUT(  // X(EMDASH)
        KC_PWR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, X(EMDASH), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    // TODO: MacOS Layer toggle
    /** TODO: auto clicker,
     * dynamic macros(https://docs.qmk.fm/#/feature_dynamic_macros), https://docs.qmk.fm/#/feature_macros
     * modifier shortcuts, https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
     * poweroff shotcut? https://docs.qmk.fm/#/feature_mouse_keys,
     * leader keys https://docs.qmk.fm/#/feature_leader_key
     * mod tap FN https://docs.qmk.fm/#/mod_tap
     */
};

// enum combos {
//     CAPS_DEL,
// };

// const uint16_t PROGMEM caps_combo[] = {KC_LSFT, MY_CAPS, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//     [CAPS_DEL] = COMBO(caps_combo, KC_DEL),
// };

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();                           // enables Rgb, without saving settings
    rgblight_sethsv_noeeprom(214, 169, 252);              // sets the color to #d6a9fc without saving
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 1);  // sets mode to Fast breathing without saving

    set_unicode_input_mode(UC_LNX);
}

#ifdef AUDIO_ENABLE
float caps_on[][2]  = SONG(CAPS_LOCK_ON_SOUND);
float caps_off[][2] = SONG(CAPS_LOCK_OFF_SOUND);
#endif

// void suspend_power_down_user(void) {
// rgb_matrix_set_suspend_state(true);
// }

// void suspend_wakeup_init_user(void) {
// rgb_matrix_set_suspend_state(false);
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//    if (record->event.pressed) {
//        switch (keycode) {
//            case MY_CAPS:
//                tap_code(KC_BSPC);
//                return false;
//
//                //             case P_MACRO:
//                //                 register_code(KC_LALT);
//                //                 tap_code(KC_KP_1);
//                //                 tap_code(KC_KP_5);
//                //                 tap_code(KC_KP_6);
//                //                 unregister_code(KC_LALT);
//                //                 return false;
//        }
//    }
//    return true;
// };
