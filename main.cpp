#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include <QTimeEdit>
#include <QFrame>
#include <QPalette>
#include <QIcon>
#include <QObject>
#include <QGraphicsDropShadowEffect>

#include "TrainWidget.h"
#include "HelpWindow.h"
#include "LightSettingsWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Cool Train");

    // Central widget and layout
    QWidget *centralWidget = new QWidget(&mainWindow);
    QGridLayout *mainLayout = new QGridLayout(centralWidget);

    // Container for the grid layout
    QFrame *container = new QFrame(centralWidget);
    container->setObjectName("container"); // Set an object name for styling

    // Grid layout for the main window
    QGridLayout *gridLayout = new QGridLayout(container);
    gridLayout->setSpacing(10); // Set the spacing between cells

    // Apply styling to the container
    QString containerStyle = "#container { background-color: #F5F7FA; border-radius: 8px; border: 1px solid #E5E7EB; padding: 20px;}";
    container->setStyleSheet(containerStyle);

    mainLayout->addWidget(container, 0, 0, 1, 1);

    // Style sheet for the buttons and labels
    QString buttonStyleAction = "QPushButton { background-color: #333; color: white; border: none; border-radius: 5px; padding: 10px; font-size: 92px; font-style: normal; font-weight: 800;}";
    QString buttonStyleTrack = "QPushButton { background-color: #333; color: white; border: none; border-radius: 5px; padding: 30px 10px 30px 10px; font-family: Inter; font-size: 44px; font-style: normal; font-weight: 800;}";
    QString buttonStyleNormal = "QPushButton { background-color: #333; color: white; border: none; border-radius: 5px; padding: 10px; font-family: Inter; font-size: 30px; font-style: normal; font-weight: 600;}";
    QString labelTitleStyle = "QLabel { color: #0F172A; text-align: center; font-family: Inter; font-size: 60px; font-style: normal; font-weight: 800;}";
    QString labelTimeStyle = "QLabel { color: #0F172A; text-align: center; font-family: Inter; font-size: 92px; font-style: normal; font-weight: 600; border-radius: 8px; border: 1px solid #E5E7EB; background: #FFF; qproperty-alignment: AlignCenter; }";
    QString labelStyle = "QLabel { color: #0F172A; font-family : Inter; font-size : 44px; font-style : normal; font-weight : 800;}";
    QString sliderStyle = R"(
QSlider::groove:horizontal {
    border: 1px solid #999999;
    height: 8px;
    background: #e1e1e1;
    margin: 2px 0;
    border-radius: 4px;
}

QSlider::handle:horizontal {
    background: #333333;
    border: 1px solid #5c5c5c;
    width: 18px;
    height: 18px;
    margin: -4px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */
    border-radius: 8px;
}

QSlider::handle:horizontal:hover {
    background: #555555;
    border-color: #666666;
}

QSlider::sub-page:horizontal {
    background: #666666;
    border: 1px solid #999999;
    height: 10px;
    border-radius: 4px;
}
)";


    // Header
    QLabel *headerLabel = new QLabel("Cool Train");
    headerLabel->setStyleSheet(labelTitleStyle);
    gridLayout->addWidget(headerLabel, 0, 4, 1, 4);

    // Help button
    QPushButton *helpButton = new QPushButton("Help");
    helpButton->setStyleSheet(buttonStyleNormal);
    gridLayout->addWidget(helpButton, 0, 8, 1, 2);

    // Help window
    HelpWindow *helpWindow = new HelpWindow();
    QObject::connect(helpButton, &QPushButton::clicked, helpWindow, &QWidget::show);

    // max train number
    int maxTrainNumber = 2;

    for (int col = 0; col < maxTrainNumber; col++)
    {
        // Train col
        QLabel *trainLabel = new QLabel("Train " + QString::number(col + 1));
        trainLabel->setStyleSheet(labelStyle);
        gridLayout->addWidget(trainLabel, 1 + col * 4, 1, 1, 5);
        // Speed Slider
        QSlider *speedSlider = new QSlider(Qt::Horizontal);
        speedSlider->setStyleSheet(sliderStyle);

        speedSlider->setRange(0, 100);
        QLabel *speedLabel = new QLabel("Speed");
        speedLabel->setStyleSheet(labelStyle);

        gridLayout->addWidget(speedSlider, 2 + col * 4, 1, 1, 5);
        gridLayout->addWidget(speedLabel, 3 + col * 4, 1, 1, 5);

        // Start Button
        QPushButton *startButton = new QPushButton("START");
        startButton->setStyleSheet(buttonStyleAction);
        // Play icon to startButton
        QIcon playIcon(":/icons/play_icon.png");
        startButton->setIcon(playIcon);
        startButton->setIconSize(QSize(92, 92));
        gridLayout->addWidget(startButton, 4 + col * 4, 1, 1, 5);
    }

    // Track selection buttons
    QPushButton *trackOneButton = new QPushButton("1.Track");
    QPushButton *trackTwoButton = new QPushButton("2.Track");
    trackOneButton->setStyleSheet(buttonStyleTrack);
    trackTwoButton->setStyleSheet(buttonStyleTrack);
    gridLayout->addWidget(trackOneButton, 1 + maxTrainNumber * 4, 1, 2, 2);
    gridLayout->addWidget(trackTwoButton, 1 + maxTrainNumber * 4, 4, 2, 2);

    // Working time display
    QLabel *workingTimeLabel = new QLabel("12:30");
    workingTimeLabel->setStyleSheet(labelTimeStyle);

    // Create a drop shadow effect
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
    shadowEffect->setBlurRadius(10);  // Adjust the blur radius
    shadowEffect->setXOffset(5);      // Horizontal offset of the shadow
    shadowEffect->setYOffset(5);      // Vertical offset of the shadow
    shadowEffect->setColor(Qt::gray); // Shadow color

    // Apply the shadow effect to the label
    workingTimeLabel->setGraphicsEffect(shadowEffect);
    gridLayout->addWidget(workingTimeLabel, 1, 7, 2, 3);
    QLabel *workingTimeTextLabel = new QLabel("Working Time");
    workingTimeTextLabel->setStyleSheet(labelStyle);
    gridLayout->addWidget(workingTimeTextLabel, 3, 7, 1, 3);

    // Additional buttons
    QPushButton *lightButton = new QPushButton("Light");
    lightButton->setStyleSheet(buttonStyleNormal);
    // Light icon to lightButton
    QIcon lightIcon(":/icons/light_icon.png");
    lightButton->setIcon(lightIcon);
    lightButton->setIconSize(QSize(30, 30));
    gridLayout->addWidget(lightButton, 5, 7, 1, 3);

    QPushButton *moreSettingsButton = new QPushButton("More Settings");
    moreSettingsButton->setStyleSheet(buttonStyleNormal);
    // Menu icon to moreSettingsButton
    QIcon moreSettingsIcon(":/icons/menu_icon.png");
    moreSettingsButton->setIcon(moreSettingsIcon);
    moreSettingsButton->setIconSize(QSize(30, 30));
    gridLayout->addWidget(moreSettingsButton, 7, 7, 1, 3);

    // Light settings window
    LightSettingsWindow *lightSettings = new LightSettingsWindow();
    QObject::connect(moreSettingsButton, &QPushButton::clicked, lightSettings, &QWidget::show);

    // Set central widget and show main window
    mainWindow.setCentralWidget(centralWidget);
    mainWindow.resize(600, 600);
    mainWindow.show();

    return app.exec();
}
