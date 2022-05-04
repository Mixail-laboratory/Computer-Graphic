#include <QApplication>
#include <QPushButton>
#include <QSurfaceFormat>

#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    format.setSamples(16);
    QSurfaceFormat::setDefaultFormat(format);

    QApplication::setApplicationName("Task3");

    MainWindow widget;
    widget.show();

    return QApplication::exec();
}
