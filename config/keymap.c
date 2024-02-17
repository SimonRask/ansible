// Copyright 2022 Diego Palacios (@diepala)

// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_danish.h"

#define BASE 0
#define SYMBOL 1
#define LEFT 2
#define RIGHT 3
#define MISC 4
#define FUNCTION 5
#define ARROWS 6


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │ P │ Å │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │ESC│ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ Æ │ Ø │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │ - │Sft│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *          ┌───┐                               ┌───────┐
      *          │Alt├─────┐                   ┌─────┤GUI/Bsp│
      *          └───┤ SPC ├────┐      ┌───────┤TO(1)├───────┘
      *              └─────┤LCTL│      │ALT/ENT├─────┘
      *                    └────┘      └───────┘
      */
    [BASE] = LAYOUT_split_3x6_3(
        KC_TAB,    DK_Q,    DK_W,    DK_E,    DK_R,    DK_T,                                 DK_Y,    DK_U,    DK_I,    DK_O,    DK_P,    DK_ARNG,
        KC_LSFT, DK_A,    DK_S,    DK_D,    DK_F,    DK_G,                                 DK_H,    DK_J,    DK_K,    DK_L,    DK_AE, DK_OSTR,
        KC_ESCAPE,   DK_Z,    DK_X,    DK_C,    DK_V,    DK_B,                                 DK_N,    DK_M,    DK_COMM, DK_DOT,  DK_MINS, KC_LGUI,
                                        KC_LALT, KC_SPC, KC_LCTL,                    KC_ENT, LT(ARROWS, KC_BSPC), OSL(SYMBOL) 
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐           ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │           │ Y │ U │ I │ O │ P │ Å │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │ESC│ A │ S │ D │ F │ G │           │ H │ J │ K │ L │ Æ │ Ø │
      * ├───┼───┼───┼───┼───┼───┤           ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │           │ N │ M │ , │ . │ - │Sft│
      * └───┴───┴───┴───┴───┴───┘           └───┴───┴───┴───┴───┴───┘
      *          ┌───┐                               ┌───────┐
      *          │Alt├─────┐                   ┌─────┤GUI/Bsp│
      *          └───┤ SPC ├────┐      ┌───────┤TO(1)├───────┘
      *              └─────┤LCTL│      │ALT/ENT├─────┘
      *                    └────┘      └───────┘
      */
    [ARROWS] = LAYOUT_split_3x6_3(
        _______, _______, _______,  _______, _______, _______,                                 _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                 KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______,  _______, _______,
                                        _______, _______, _______,                     _______,  _______, _______ 
    ),
     /*
      * ┌───┬───┬───┬───┬─────┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ 1 │ 2 │ 3 │ 4   │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │   │
      * ├───┼───┼───┼───┼─────┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ @ │ = │ ! │LEFT │ ~ │       │ # │ & │ " │ | │ ' │   │
      * ├───┼───┼───┼───┼─────┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ? │ % │ ^ │RIGHT│ * │       │ + │ $ │ ; │ : │   │   │
      * └───┴───┴───┴───┴─────┴───┘       └───┴───┴───┴───┴───┴───┘
      *           ┌────┐                        ┌────┐
      *           │    ├────┐              ┌────┤MISC│
      *           └────┤BASE├────┐   ┌─────┤BSPC├────┘
      *                └────┤    │   │     ├────┘
      *                     └────┘   └─────┘
      */
    [SYMBOL] = LAYOUT_split_3x6_3(
        XXXXXXX,  DK_1,     DK_2,     DK_3,     DK_4,    DK_5,                     DK_6, DK_7,    DK_8,    DK_9,    DK_0,    XXXXXXX,
        XXXXXXX, DK_AT,  DK_EQL,  DK_EXLM,  OSL(LEFT),   DK_TILD,                  DK_HASH, DK_AMPR, DK_DQUO, DK_PIPE, DK_QUOT, XXXXXXX,
        XXXXXXX, DK_QUES,  DK_PERC,  DK_CIRC,  OSL(RIGHT),  DK_ASTR,                DK_PLUS, DK_DLR, DK_SCLN, DK_COLN, XXXXXXX, XXXXXXX,
                                        TO(SYMBOL), TO(BASE), XXXXXXX,         XXXXXXX, KC_BSPC, TO(MISC)
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │ ( │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ < │ \ │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │ { │   │ [ │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
                  ┌────┐                        ┌────┐
      *           │    ├────┐              ┌────┤    │
      *           └────┤BASE├────┐   ┌─────┤    ├────┘
      *                └────┤    │   │     ├────┘
      *                     └────┘   └─────┘
      */
    [LEFT] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_LPRN, XXXXXXX,
        XXXXXXX, DK_LABK,  DK_BSLS,  XXXXXXX,  XXXXXXX,  XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX,  DK_LCBR,  XXXXXXX,  DK_LBRC,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                           XXXXXXX, TO(BASE), XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │ ) │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ > │ / │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │ } │   │ ] │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *           ┌────┐                        ┌────┐
      *           │    ├────┐              ┌────┤    │
      *           └────┤BASE├────┐   ┌─────┤    ├────┘
      *                └────┤    │   │     ├────┘
      *                     └────┘   └─────┘
      */
    [RIGHT] = LAYOUT_split_3x6_3(
        XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DK_RPRN, XXXXXXX,
        XXXXXXX, DK_RABK,  DK_SLSH,  XXXXXXX,  XXXXXXX,  XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX,  DK_RCBR,  XXXXXXX,  DK_RBRC,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX, TO(BASE), XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX
    ),
     /*
      * ┌────┬──────┬──────┬────────┬────────┬──────┐       ┌──────┬──────┬──────┬───────┬──────┬───┐
      * │MSTP│ Play │ PRVS │ Next   │        │ CAPS │       │ PgDn │ PgUp │ INS  │ Print │      │Bsp│
      * ├────┼──────┼──────┼────────┼────────┼──────┤       ├──────┼──────┼──────┼───────┼──────┼───┤
      * │    │ HOME │ END  │ LCTRL+C│ LCTRL+V│      │       │ Left │ Down │ Up   │ Right │ Del  │   │
      * ├────┼──────┼──────┼────────┼────────┼──────┤       ├──────┼──────┼──────┼───────┼──────┼───┤
      * │Sft │ UNDO │ CUT  │ COPY   │ PASTE  │ RApp │       │ Vol- │ Vol+ │ Mute │       │ RGui │   │
      * └────┴──────┴──────┴────────┴────────┴──────┘       └──────┴──────┴──────┴───────┴──────┴───┘
      *                                ┌─────┐                       ┌─────┐
      *                                │LCTRL├─────┐           ┌─────┤TO(3)│
      *                                └─────┤TO(0)├───┐   ┌───┤TO(2)├─────┘
      *                                      └─────┤ALT│   │SPC├─────┘
      *                                            └───┘   └───┘
      */
    [MISC] = LAYOUT_split_3x6_3(
        KC_MSTP, KC_MPLY,    KC_MPRV,   KC_MNXT,  XXXXXXX,  KC_CAPS,         KC_PGDN,   KC_PGUP,   KC_INS,   KC_PSCR,    XXXXXXX,    KC_BSPC,
        XXXXXXX, KC_HOME,    KC_END,    C(KC_C),  C(KC_V),  XXXXXXX,         KC_LEFT,   KC_DOWN,   KC_UP,    KC_RGHT,    KC_DEL,   XXXXXXX,
        KC_TAB,  KC_UNDO,    KC_CUT,    KC_COPY,  KC_PASTE, KC_APP,          KC_VOLD,   KC_VOLU,   KC_MUTE,    XXXXXXX,      XXXXXXX,  KC_RSFT,
                                        KC_LCTL, TO(BASE), KC_LALT,        XXXXXXX, XXXXXXX, TO(FUNCTION)
    ),
     /*
      * ┌──┬────┬────┬────┬────┬────┐       ┌────┬────┬────┬────┬─────┬─────┐
      * │  │ F1 │ F2 │ F3 │ F4 │ F5 │       │ F6 │ F7 │ F8 │ F9 │ F10 │ F11 │
      * ├──┼────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼─────┼─────┤
      * │  │    │    │    │    │    │       │    │    │    │    │     │ F12 │
      * ├──┼────┼────┼────┼────┼────┤       ├────┼────┼────┼────┼─────┼─────┤
      * │  │    │    │    │    │    │       │    │    │    │    │     │     │
      * └──┴────┴────┴────┴────┴────┘       └────┴────┴────┴────┴─────┴─────┘
      *                   ┌───┐                       ┌───┐
      *                   │   ├─────┐           ┌─────┤   │
      *                   └───┤TO(0)├───┐   ┌───┤     ├───┘
      *                       └─────┤ENT│   │   ├─────┘
      *                             └───┘   └───┘
      */
    [FUNCTION] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                     KC_F6,     KC_F7,      KC_F8,      KC_F9,      KC_F10,      KC_F11,
        XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     KC_F12,
        XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                   XXXXXXX,   XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,     XXXXXXX,
                                              XXXXXXX, TO(BASE), XXXXXXX,              XXXXXXX, XXXXXXX, XXXXXXX
    )
};
