#ifndef TASK2_SLIDERSGROUP_HPP
#define TASK2_SLIDERSGROUP_HPP


#include <QGroupBox>

QT_BEGIN_NAMESPACE
class QDial;

class QScrollBar;

class QSlider;

QT_END_NAMESPACE

//! [0]
class SlidersGroup : public QGroupBox {
Q_OBJECT

public:
    SlidersGroup(Qt::Orientation orientation, const QString &title,
                 QWidget *parent = 0);

signals:

    void valueChanged(int value);

public slots:

    void setValue(int value);

    void setMinimum(int value);

    void setMaximum(int value);

    void invertAppearance(bool invert);

    void invertKeyBindings(bool invert);

    int getValue() const;
private:
    QSlider *slider;
    QScrollBar *scrollBar;
    QDial *dial;
    int val{};
};


#endif //TASK2_SLIDERSGROUP_HPP
