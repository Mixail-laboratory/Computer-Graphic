#pragma once

#include <memory>
#include <unordered_set>

#include <QKeyEvent>
#include <QVector3D>

class InputController {
public:
    void keyPressEvent(QKeyEvent *event);


    int state_diff = 0;
    int state_spec = 0;

    enum Shaders {
        Phong = 0
    };

    unsigned int currentShader = Phong;

private:
    int lastPressedKey = 0x00;
    bool isDpress = false;
    bool isSpress = false;
};