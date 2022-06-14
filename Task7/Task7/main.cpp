#include <QGuiApplication>
#include <QApplication>
/*#include <QMatrix4x4>
#include <QtMath>*/
#include "CubeWindow.h"
#include "cubesettingswindow.h"
#include "Params.h"
#include <iostream>
#include <fstream>

//! [2]
int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QApplication qapp(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);

    std::fstream fs;
    fs.open("Models/MeshSphere.obj");
    auto v = Parser().parse(fs);
    fs.close();

    Params params{v, QVector3D{0, 0, 10}};

    CubeWindow window{params};
    window.setFormat(format);
    window.resize(800, 640);
    window.setPosition(0, 0);
    window.show();

    window.setAnimating(true);

    CubeSettingsWindow settings(params);
    settings.move(window.x() + window.width(), window.y());
    settings.show();
    app.exec();
    return qapp.exec();
}
//! [2]
