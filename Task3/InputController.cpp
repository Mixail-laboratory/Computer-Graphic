#include "InputController.hpp"

void InputController::keyPressEvent(QKeyEvent *event) {
    int pressedKey = event->key();

    if (pressedKey == Qt::Key::Key_S) {
        if (isSpress) {
            state_spec = 0;
            isSpress = false;
            lastPressedKey = 0x00;
            return;
        } else {
            isSpress = true;
            state_spec = 1;
            return;
        }
    }

    if (pressedKey == Qt::Key::Key_D) {
        if (isDpress) {
            state_diff = 0;
            lastPressedKey = 0x00;
            isDpress = false;
            return;
        } else {
            isDpress = true;
            state_diff = 1;
            return;
        }
    }

    lastPressedKey = pressedKey;
}
