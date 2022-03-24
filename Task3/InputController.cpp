#include "InputController.hpp"
void InputController::keyPressEvent(QKeyEvent *event) {
    int pressedKey = event->key();
    if (lastPressedKey != pressedKey) {
        if (pressedKey >= Qt::Key::Key_0 && pressedKey <= Qt::Key::Key_9) {
            vertexFactor = pressedKey - Qt::Key::Key_0;
        }
        swapKeyFlag = true;
    }
    lastPressedKey = pressedKey;
}
