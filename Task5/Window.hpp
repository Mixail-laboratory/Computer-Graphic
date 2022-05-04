#ifndef TASK3_WINDOW_HPP
#define TASK3_WINDOW_HPP

#include <QWidget>
#include <QSlider>
#include <QPushButton>


class Window : public QWidget {
Q_OBJECT

public:
    Window();

    Window(double min, double max, double step);

    int getFactorVal();

    int getSunValX();
    int getSunValY();
    int getSunValZ();

    int getSpotValX();
    int getSpotValY();
    int getSpotValZ();

    float pointLight();

    float dirLight();

    float spotLight();

    void tapOnButton(QPushButton* button, bool& type);

private:
    QSlider *sliderForFactor;
    QSlider *sliderForSunX;
    QSlider* sliderForSunY;
    QSlider* sliderForSunZ;

    QSlider *sliderForSpotX;
    QSlider* sliderForSpotY;
    QSlider* sliderForSpotZ;

    QPushButton* PointLightButton;
    QPushButton* DirectionalLightButton;
    QPushButton* SpotLightButton;

    bool isPoint = false;
    bool isDir = false;
    bool isSpot = false;


};

#endif
