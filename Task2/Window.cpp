#include "Window.hpp"
#include <QtWidgets>

#include "SlidersGroup.hpp"


//! [0]
Window::Window() {
    horizontalSliders = new SlidersGroup(Qt::Horizontal, tr("Horizontal"));
    verticalSliders = new SlidersGroup(Qt::Vertical, tr("Vertical"));

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(horizontalSliders);
    stackedWidget->addWidget(verticalSliders);

    createControls(tr("Controls"));
//! [0]

//! [1]
    connect(horizontalSliders, SIGNAL(valueChanged(int)),
//! [1] //! [2]
            verticalSliders, SLOT(setValue(int)));
    connect(verticalSliders, SIGNAL(valueChanged(int)),
            valueSpinBox, SLOT(setValue(int)));
    connect(valueSpinBox, SIGNAL(valueChanged(int)),
            horizontalSliders, SLOT(setValue(int)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(controlsGroup);
    layout->addWidget(stackedWidget);
    setLayout(layout);

    minimumSpinBox->setValue(1);
    maximumSpinBox->setValue(30);
    valueSpinBox->setValue(5);

    setWindowTitle(tr("Sliders"));
}
//! [2]

//! [3]
void Window::createControls(const QString &title)
//! [3] //! [4]
{
    controlsGroup = new QGroupBox(title);

    minimumLabel = new QLabel(tr("Minimum value:"));
    maximumLabel = new QLabel(tr("Maximum value:"));
    valueLabel = new QLabel(tr("Current value:"));

    invertedAppearance = new QCheckBox(tr("Inverted appearance"));
    invertedKeyBindings = new QCheckBox(tr("Inverted key bindings"));

//! [4] //! [5]
    minimumSpinBox = new QSpinBox;
//! [5] //! [6]
    minimumSpinBox->setRange(-10000, 10000);
    minimumSpinBox->setSingleStep(1);

    maximumSpinBox = new QSpinBox;
    maximumSpinBox->setRange(-10000, 10000);
    maximumSpinBox->setSingleStep(1);

    valueSpinBox = new QSpinBox;
    valueSpinBox->setRange(-10000, 10000);
    valueSpinBox->setSingleStep(1);

    orientationCombo = new QComboBox;
    orientationCombo->addItem(tr("Horizontal slider-like widgets"));
    orientationCombo->addItem(tr("Vertical slider-like widgets"));

//! [6] //! [7]
    connect(orientationCombo, SIGNAL(activated(int)),
//! [7] //! [8]
            stackedWidget, SLOT(setCurrentIndex(int)));
    connect(minimumSpinBox, SIGNAL(valueChanged(int)),
            horizontalSliders, SLOT(setMinimum(int)));
    connect(minimumSpinBox, SIGNAL(valueChanged(int)),
            verticalSliders, SLOT(setMinimum(int)));
    connect(maximumSpinBox, SIGNAL(valueChanged(int)),
            horizontalSliders, SLOT(setMaximum(int)));
    connect(maximumSpinBox, SIGNAL(valueChanged(int)),
            verticalSliders, SLOT(setMaximum(int)));
    connect(invertedAppearance, SIGNAL(toggled(bool)),
            horizontalSliders, SLOT(invertAppearance(bool)));
    connect(invertedAppearance, SIGNAL(toggled(bool)),
            verticalSliders, SLOT(invertAppearance(bool)));
    connect(invertedKeyBindings, SIGNAL(toggled(bool)),
            horizontalSliders, SLOT(invertKeyBindings(bool)));
    connect(invertedKeyBindings, SIGNAL(toggled(bool)),
            verticalSliders, SLOT(invertKeyBindings(bool)));

    QGridLayout *controlsLayout = new QGridLayout;
    controlsLayout->addWidget(minimumLabel, 0, 0);
    controlsLayout->addWidget(maximumLabel, 1, 0);
    controlsLayout->addWidget(valueLabel, 2, 0);
    controlsLayout->addWidget(minimumSpinBox, 0, 1);
    controlsLayout->addWidget(maximumSpinBox, 1, 1);
    controlsLayout->addWidget(valueSpinBox, 2, 1);
    controlsLayout->addWidget(invertedAppearance, 0, 2);
    controlsLayout->addWidget(invertedKeyBindings, 1, 2);
    controlsLayout->addWidget(orientationCombo, 3, 0, 1, 3);
    controlsGroup->setLayout(controlsLayout);
}

int Window::getVal() {
    return horizontalSliders->getValue();
}

int Window::getMorphVal() {
    return verticalSliders->getValue();
}

Window::Window(double min, double max, double step) {
    horizontalSliders = new SlidersGroup(Qt::Horizontal, tr("Horizontal"));
    verticalSliders = new SlidersGroup(Qt::Vertical, tr("Vertical"));

    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(horizontalSliders);
    stackedWidget->addWidget(verticalSliders);

    createControls(tr("Controls"));
//! [0]

//! [1]
    connect(horizontalSliders, SIGNAL(valueChanged(int)),
//! [1] //! [2]
            verticalSliders, SLOT(setValue(int)));
    connect(verticalSliders, SIGNAL(valueChanged(int)),
            valueSpinBox, SLOT(setValue(int)));
    connect(valueSpinBox, SIGNAL(valueChanged(int)),
            horizontalSliders, SLOT(setValue(int)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(controlsGroup);
    layout->addWidget(stackedWidget);
    setLayout(layout);

    minimumSpinBox->setValue(min);
    maximumSpinBox->setValue(max);
    valueSpinBox->setValue(step);

    setWindowTitle(tr("Sliders"));

}
