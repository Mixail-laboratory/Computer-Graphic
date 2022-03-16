#ifndef TASK2_WINDOW_HPP
#define TASK2_WINDOW_HPP


#include <QWidget>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QSpinBox;
class QStackedWidget;
QT_END_NAMESPACE
class SlidersGroup;

//! [0]
class Window : public QWidget
{
Q_OBJECT

public:
    Window();
    Window(double min, double max, double step);
    int getVal();
    int getMorphVal();
private:
    void createControls(const QString &title);

    SlidersGroup *horizontalSliders;
    SlidersGroup *verticalSliders;
    QStackedWidget *stackedWidget;

    QGroupBox *controlsGroup;
    QLabel *minimumLabel;
    QLabel *maximumLabel;
    QLabel *valueLabel;
    QCheckBox *invertedAppearance;
    QCheckBox *invertedKeyBindings;
    QSpinBox *minimumSpinBox;
    QSpinBox *maximumSpinBox;
    QSpinBox *valueSpinBox;
    QComboBox *orientationCombo;


};

#endif //TASK2_WINDOW_HPP
