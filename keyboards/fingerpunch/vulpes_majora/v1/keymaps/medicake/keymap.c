#include <stdint.h>
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE
};

#define LOWER MO(_LOWER)
#define RAISE OSL(_RAISE)

const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM ctrl_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM right_ctrl_combo[] = {KC_DOT, KC_SLASH, COMBO_END};
const uint16_t PROGMEM right_gui_combo[] = {KC_COMM, KC_M, COMBO_END};
const uint16_t PROGMEM gui_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM alt_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM dash_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM semi_combo[] = {KC_L, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM app_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM word_del_combo[] = {MOD_LSFT, KC_BSPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(ctrl_combo, KC_LCTL),
    COMBO(right_ctrl_combo, KC_LCTL),
    COMBO(gui_combo, KC_LGUI),
    COMBO(right_gui_combo, KC_LGUI),
    COMBO(dash_combo, KC_MINUS),
    COMBO(semi_combo, KC_COLON),
    COMBO(app_combo, KC_APPLICATION),
    COMBO(word_del_combo, LCTL(KC_BSPC))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 *  Key layout visual aid
 *
 * ,-----------------------------------------.                                          ,-----------------------------------------.
 * |  ESC |   Q  |   W  |   E  |   R  |   T  |                                          |   Y  |   U  |   I  |   O  |   P  |BckSpc|
 * |------+------+------+------+------+------|                                          |------+------+------+------+------+------|
 * |  TAB |   A  |   S  |   D  |   F  |   G  |                                          |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|                                          |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |                                          |   N  |   M  |   ,  |   .  |   /  | SFT  |
 * `-----------------------------------------'                                          `-----------------------------------------'
 *                          ,--------------------.      ,--------------------.      ,--------------------.
 *                          |   \  | Enter| LOWER|      | RAISE| Space| Del  |      | RAISE| Space| Del  |
 *                          `--------------------'      `--------------------'      `--------------------'
 *          ,------.        ,--------------------.                                  ,--------------------.        ,------.
 *          |Vol Up|        |Mouse1|Mouse3|Mouse2|                                  |Vol Up| Mute |Vol Dn|        |Vol Up|
 *   ,------+------+------. `--------------------'                                  `--------------------' ,------+------+------.
 *   | Prev | Play | Next |   3 way thumb rocker                                      3 way thumb rocker   | Prev | Play | Next |  5 way switch
 *   `------+------+------'                                                                                `------+------+------'
 *          |Vol Dn|                                                                                              |Vol Dn|
 *          `------'                                                                                              `------'
 */

[_QWERTY] = LAYOUT_vulpes_majora(
  KC_NO,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                                                      KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,          KC_NO,
  KC_NO,  KC_A,         KC_S,         KC_D,         KC_F,         KC_G,                                                      KC_H,    KC_J,         KC_K,         KC_L,         KC_QUOTE,      KC_NO,
  KC_NO,  KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,                                                      KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLASH,       KC_NO,
                                      LT(LOWER, KC_TAB),      KC_SPC,        OSM(MOD_LSFT), KC_MS_BTN2,     KC_MS_BTN1,   KC_APPLICATION,   OSL(RAISE),   KC_BSPC,      KC_ENT,
           OSM(MOD_LCTL),              OSL(RAISE),     KC_MS_BTN3,   OSL(LOWER),                                          KC_VOLD, KC_MUTE,      KC_VOLU,                              KC_UP,
  KC_APPLICATION,  KC_PSCR, OSM(MOD_LALT),                                                                                                                                            KC_LEFT, KC_UNDO, KC_RGHT,
           OSM(MOD_LGUI),                                                                                                                                                              KC_DOWN
),

[_RAISE] = LAYOUT_vulpes_majora(
  KC_NO,  KC_EXLM, KC_AT,   KC_HASH, KC_DOLLAR, KC_PERCENT,                        KC_CIRCUMFLEX,    KC_AMPERSAND,    KC_ASTERISK,    KC_LEFT_PAREN,    KC_RIGHT_PAREN, KC_NO,
  KC_NO,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_NO,
  KC_NO,  KC_TILD, KC_GRAVE, KC_PIPE, KC_EQUAL, KC_SEMICOLON,                     KC_COLON, KC_GRAVE, KC_LBRC, KC_RBRC, KC_BACKSLASH, KC_NO,
                             _______, _______, _______,  _______, _______, _______, _______, _______, _______,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
),

[_LOWER] = LAYOUT_vulpes_majora(
  KC_NO, KC_ESC, KC_F1, KC_F4, KC_F7, KC_F10,                            KC_APP, KC_HOME,   KC_UP,   KC_END, KC_DEL,  KC_NO,
  KC_NO, KC_TAB, KC_F2, KC_F5, KC_F8, KC_F11,                            KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,  KC_NO,
  KC_NO, QK_BOOTLOADER,   KC_F3,   KC_F6,   KC_F9,   KC_F12,             _______, _______, _______, _______, _______, KC_NO,
                             _______, _______, _______,  _______, _______, _______, _______, _______, _______,
           _______,          _______, _______, _______,                             _______, _______, _______,          _______,
  _______, _______, _______,                                                                                   _______, _______, _______,
           _______,                                                                                                     _______
)
};
