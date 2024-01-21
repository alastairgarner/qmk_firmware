// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
    _BASE,
    _NAV,
    _NUM,
    _SYM,
};

enum combos { KJ_ESC };

const uint16_t PROGMEM kj_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    // For Vim, put Escape on the home row
    [KJ_ESC] = COMBO(kj_combo, KC_ESC)};

// For _QWERTY layer
#define OSM_SFT OSM(MOD_LSFT)
#define OSL_SYM OSL(_SYM)
#define OSL_NAV OSL(_NAV)
#define MO_NUM MO(_NUM)

#define GUI_ENT GUI_T(KC_ENT)
#define LOW_TAB LT(_LOWER, KC_TAB)
#define RSE_BSP LT(_RAISE, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ - │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ' │Ent│
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * |NUM│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │ ` │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               |Nav|                   |   |
     *               └───├───┐           ┌───┤───┘
     *                   |Cmd├───┐   ┌───┤Spc|
     *                   └───┤SYM│   │Sft├───┘
     *                       └───┘   └───┘
     */
    [_BASE] = LAYOUT_split_3x6_3(
        // Top left
        KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T,
        // Top right
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
        // Middle left
        KC_TAB, MT(MOD_LSFT, KC_A), MT(MOD_LCTL, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F), KC_G,
        // Middle right
        KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT,
        // Bottom left
        MO_NUM, KC_Z, KC_X, KC_C, KC_V, KC_B,
        // Bottom right
        KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_GRV,
        // Thumb left
        OSL_NAV, KC_LGUI, OSL_SYM,
        // Thumb right
        OSM_SFT, KC_SPC, KC_BSPC),

    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │   │BLD│   │   │   │   │       │ { │ [ │ ] │ } │   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │SFT│CTL│ALT│GUI│   │       │Lft│Dwn│Up │Rig│   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * |   │   │   │   │   │   │       │   │PDn│PUp│   │   │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤   │
     *               └───┤   ├───┐   ┌───┤   ├───┘
     *                   └───┤   │   │   ├───┘
     *                       └───┘   └───┘
     */
    [_NAV] = LAYOUT_split_3x6_3(
        // Top left
        KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Top right
        LSG(KC_LBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), LSG(KC_RBRC), KC_TRNS, KC_TRNS,
        // Middle left
        KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,
        // Middle right
        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS,
        // Bottom left
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Bottom right
        KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS,
        // Thumb left
        KC_TRNS, KC_TRNS, KC_TRNS,
        // Thumb right
        KC_TRNS, KC_TRNS, KC_TRNS),

    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │       │   │ 7 │ 8 │ 9 │   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │       │   │ 4 │ 5 │ 6 │   │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * |   │   │   │   │   │   │       │ 0 │ 1 │ 2 │ 3 │   │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤   │
     *               └───┤   ├───┐   ┌───┤   ├───┘
     *                   └───┤   │   │   ├───┘
     *                       └───┘   └───┘
     */
    [_NUM] = LAYOUT_split_3x6_3(
        // Top left
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Top right
        KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
        // Middle left
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Middle right
        KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS,
        // Bottom left
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        // Bottom right
        KC_0, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
        // Thumb left
        KC_TRNS, KC_TRNS, KC_TRNS,
        // Thumb right
        KC_TRNS, KC_TRNS, KC_TRNS),

    /*
     * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
     * │   │ ` │ _ │ < │ > │ " │       │ | │ $ │ ( │ ) │ @ │ % │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * │   │ ! │ - │ + │ = │ . │       │ & │ : │ { │ } │ ; │   │
     * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
     * |   │ ^ │ / │ * │ \ │ ' │       │ ~ │ ? │ [ │ ] │ # │   │
     * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
     *               ┌───┐                   ┌───┐
     *               │   ├───┐           ┌───┤Del│
     *               └───┤   ├───┐   ┌───┤   ├───┘
     *                   └───┤   │   │Esc├───┘
     *                       └───┘   └───┘
     */
    [_SYM] = LAYOUT_split_3x6_3(
        // Top left
        KC_TRNS, KC_GRV, KC_UNDS, KC_LT, KC_GT, KC_DQT,
        // Top right
        KC_PIPE, KC_DLR, KC_LPRN, KC_RPRN, KC_AT, KC_PERC,
        // Middle left
        KC_TRNS, LSFT(KC_1),  KC_MINS,  LSFT(KC_EQL),  KC_EQL, KC_DOT,
        // Middle right
        KC_AMPR, KC_COLN, KC_LCBR, KC_RCBR, KC_SCLN, KC_TRNS,
        // Bottom left
        KC_TRNS, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_QUOT,
        // Bottom right
        KC_TILD, KC_QUES, KC_LBRC, KC_RBRC, KC_HASH, KC_TRNS,
        // Thumb left
        KC_TRNS, KC_TRNS, KC_TRNS,
        // Thumb right
        KC_ESC, KC_TRNS, KC_DEL),
};

// Send function key when layer is changed
// Shouldn't use F14, F15 or F20, as these are used by the OS
// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _BASE:
//         SEND_STRING(SS_TAP(X_F20));
//         break;
//     case _NAV:
//         SEND_STRING(SS_TAP(X_F17));
//         break;
//     case _NUM:
//         SEND_STRING(SS_TAP(X_F18));
//         break;
//     case _SYM:
//         SEND_STRING(SS_TAP(X_F19));
//         break;
//     default: //  for any other layers, or the default layer
//         SEND_STRING(SS_TAP(X_F20));
//         break;
//     }
//   return state;
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _SYM, _NAV, _NUM);
// }

