#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0]= LAYOUT_ortho_5x4(
		KC_TRNS,            	   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [1]= LAYOUT_ortho_5x4(
		KC_TRNS,            	   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [2]= LAYOUT_ortho_5x4(
		KC_TRNS,            	   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [3]= LAYOUT_ortho_5x4(
		KC_TRNS,                   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [4]= LAYOUT_ortho_5x4(
		KC_TRNS,                   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [5]= LAYOUT_ortho_5x4(
		KC_TRNS,                   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    oled_set_cursor(7,3);
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:

            oled_write_P(PSTR("  FN1\n"), false);
            break;
        case 2:

            oled_write_P(PSTR("  FN2\n"), false);
            break;
        case 3:

            oled_write_P(PSTR("  FN3\n"), false);
            break;
        case 4:

            oled_write_P(PSTR("  FN4\n"), false);
            break;
        case 5:

            oled_write_P(PSTR("  FN5\n"), false);
            break;
        default:
            oled_set_cursor(10, 3);
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("X"), false);
    }
    oled_set_cursor(0,3);
     led_t led_state = host_keyboard_led_state();
     oled_write_P(led_state.caps_lock ? PSTR("A") : PSTR("a"), false);
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // First encoder (E1)
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_F17);
        } else {
            tap_code(KC_F18);
        }
        // Second encoder (E2)
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_F19);
        } else {
            tap_code(KC_F20);
        }
        // Third encoder (E3)
    }
    return true;
}
#endif

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {ENCODER_CCW_CW(TO(5), TO(1)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}, [1] = {ENCODER_CCW_CW(TO(0), TO(2)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}, [2] = {ENCODER_CCW_CW(TO(1), TO(3)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}, [3] = {ENCODER_CCW_CW(TO(2), TO(4)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}, [4] = {ENCODER_CCW_CW(TO(3), TO(5)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)}, [5] = {ENCODER_CCW_CW(TO(4), TO(0)), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
};
