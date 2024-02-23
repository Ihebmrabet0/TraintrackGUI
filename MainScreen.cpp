#include "MainScreen.h"
#include <QApplication>


MainScreen::MainScreen(QWidget *parent) : QMainWindow(parent) {


    API_Connector = new Connector();

    // Central widget & layout
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *mainLayout = new QGridLayout(centralWidget);

    // Container for the grid layout
    QFrame *container = new QFrame(centralWidget);
    this->setCentralWidget(centralWidget);

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
    QString buttonStyleDanger = "QPushButton { background-color: #CA0B00; color: white; border: none; border-radius: 5px; padding: 10px; font-family: Inter; font-size: 92px; font-style: normal; font-weight: 800;}";
    QString statusDisLabelStyle = "QLabel { background-color: red; color: white; border: none; border-radius: 5px; padding: 8px; font-family: Inter; font-size: 30px; font-style: normal; font-weight: 600;}";
    QString statusConLabelStyle = "QLabel { background-color: green; color: white;  border: none; border-radius: 5px; padding: 8px; font-family: Inter; font-size: 30px; font-style: normal; font-weight: 600;}";
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

    // Status Label
    QLabel *statusLabel = new QLabel("Disconnected");
    statusLabel->setStyleSheet(statusDisLabelStyle);
    gridLayout->addWidget(statusLabel, 0, 1, 1, 2);


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
        QPushButton *startButton = new QPushButton(" START");
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



    // Additional buttons
    QPushButton *lightButton = new QPushButton(" All Lights");
    lightButton->setStyleSheet(buttonStyleNormal);
    // Light icon to lightButton
    QIcon lightIcon(":/icons/light_icon.png");
    lightButton->setIcon(lightIcon);
    lightButton->setIconSize(QSize(30, 30));
    gridLayout->addWidget(lightButton, 2, 7, 1, 3);

    QPushButton *moreSettingsButton = new QPushButton(" Light Settings");
    moreSettingsButton->setStyleSheet(buttonStyleNormal);
    // Menu icon to moreSettingsButton
    QIcon moreSettingsIcon(":/icons/menu_icon.png");
    moreSettingsButton->setIcon(moreSettingsIcon);
    moreSettingsButton->setIconSize(QSize(30, 30));
    gridLayout->addWidget(moreSettingsButton, 3, 7, 1, 3);

    // Light settings window
    LightSettingsWindow *lightSettings = new LightSettingsWindow();
    LedController * lightController = new LedController(lightSettings, API_Connector);
    QObject::connect(moreSettingsButton, &QPushButton::clicked, lightSettings, &QWidget::show);


    // Train direction buttons
    QPushButton *forwardButton = new QPushButton("");
    QPushButton *backwardButton = new QPushButton("");
    // Forward icon to forwardButton
    QIcon forwardIcon(":/icons/forward.png");
    forwardButton->setIcon(forwardIcon);
    forwardButton->setIconSize(QSize(40, 40));
    // Backward icon to backwardButton
    QIcon backwardIcon(":/icons/backward.png");
    backwardButton->setIcon(backwardIcon);
    backwardButton->setIconSize(QSize(40, 40));
    forwardButton->setStyleSheet(buttonStyleNormal);
    backwardButton->setStyleSheet(buttonStyleNormal);
    gridLayout->addWidget(backwardButton, 4, 7, 1, 1);
    gridLayout->addWidget(forwardButton, 4, 9, 1, 1);


    QPushButton *stopButton = new QPushButton(" STOP");
    stopButton->setStyleSheet(buttonStyleDanger);
    // Stop icon to stopButton
    QIcon stopIcon(":/icons/stop.png");
    stopButton->setIcon(stopIcon);
    stopButton->setIconSize(QSize(80, 80));
    gridLayout->addWidget(stopButton, 6, 7, 3, 3);

    centralWidget->setLayout(mainLayout);

}


void MainScreen::updateConnectionStatus(bool isConnected) {
    QString statusDisLabelStyle = "QLabel { background-color: red; color: white; border: none; border-radius: 5px; padding: 8px; font-family: Inter; font-size: 30px; font-style: normal; font-weight: 600;}";
    QString statusConLabelStyle = "QLabel { background-color: green; color: white;  border: none; border-radius: 5px; padding: 8px; font-family: Inter; font-size: 30px; font-style: normal; font-weight: 600;}";

    if (isConnected) {
        statusLabel->setText("Verbinden");
        statusLabel->setStyleSheet(statusDisLabelStyle);
    } else {
        statusLabel->setText("Kein Signal");
        statusLabel->setStyleSheet(statusConLabelStyle);
    }
}
