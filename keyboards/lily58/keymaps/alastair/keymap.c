#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _NAV,
    _SYM,
    _OTH,
};

#define OSM_SFT OSM(MOD_LSFT)
#define OSL_SYM OSL(_SYM)
#define TT_NAV TT(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|  ADJ  |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | NAV  | LGUI | /  SYM  /       \LShft \  |Space |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_BASE] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  _______,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_TAB,  MT(MOD_LSFT, KC_A), MT(MOD_LCTL, KC_S), MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F),    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
  KC_GRV,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, MO(_OTH),  _______,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  _______,
                        KC_LALT, TT_NAV, KC_LGUI, OSL_SYM, OSM_SFT, KC_SPC, KC_BSPC, _______
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   ~  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | NAV  | LGUI | /SYM.   /       \LShft \  |Space |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______,  KC_GRV, KC_UNDS,   KC_LT,   KC_GT,  KC_DQT,                   KC_PIPE, KC_DLR, KC_LPRN, KC_RPRN, KC_AT, KC_PERC,
  _______, LSFT(KC_1),  KC_MINS,  LSFT(KC_EQL),  KC_EQL, KC_DOT,                   KC_AMPR, KC_COLN, KC_LCBR, KC_RCBR, KC_SCLN, _______,
  _______, KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, KC_QUOT, _______, _______, KC_TILD, KC_QUES, KC_LBRC, KC_RBRC, KC_HASH, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | NAV  | LGUI | /SYM.   /       \LShft \  |Space |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                     LSG(KC_LBRC), LGUI(KC_LBRC), LGUI(KC_RBRC), LSG(KC_RBRC), _______, _______,
  _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,                     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,  _______, _______,  _______, KC_PGDN, KC_PGUP, _______, _______, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_OTH] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, UG_NEXT, UG_PREV, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, UG_SATU, UG_SATD, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   UG_TOGG, UG_HUEU, UG_HUED, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______, UG_VALU, UG_VALD, _______, _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

// Setup KJ escape combo
enum combos { KJ_ESC };

const uint16_t PROGMEM kj_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    // For Vim, put Escape on the home row
    [KJ_ESC] = COMBO(kj_combo, KC_ESC)
};


// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _NAV, _SYM, _OTH);
// }

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
