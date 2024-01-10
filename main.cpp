#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include <QTimeEdit>
#include <QFrame>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Cool Train");

    // Central widget and layout
    QWidget *centralWidget = new QWidget(&mainWindow);
    QGridLayout *gridLayout = new QGridLayout(centralWidget);

    // Style sheet for the buttons and labels
    QString buttonStyle = "QPushButton { background-color: #333; color: white; font-weight: bold; }";
    QString labelStyle = "QLabel { color: #666; font-weight: bold; }";

    // Header
    QLabel *headerLabel = new QLabel("Cool Train");
    headerLabel->setStyleSheet(labelStyle);
    // Help button
    QPushButton *helpButton = new QPushButton("Help");
    helpButton->setStyleSheet(buttonStyle);
    gridLayout->addWidget(headerLabel, 0, 3, 1, 4);
    gridLayout->addWidget(helpButton, 0, 8, 1, 2);

    for (int col = 0; i < 2; i++)
    {
        // Train i
        QLabel *trainLabel = new QLabel("Train " + QString::number(i + 1));
        trainLabel->setStyleSheet(labelStyle);
        gridLayout->addWidget(trainLabel, 1 + col * 4, 1, 1, 5);
        // Speed Slider
        QSlider *speedSlider = new QSlider(Qt::Horizontal);
        speedSlider1->setRange(0, 100);
        QLabel *speedLabel = new QLabel("Speed");
        speedLabel->setStyleSheet(labelStyle);

        gridLayout->addWidget(speedSlider, 2 + col * 4, 1, 1, 5);
        gridLayout->addWidget(speedLabel, 3 + col * 4, 1, 1, 5);

        // Start Button
        QPushButton *startButton = new QPushButton("START");
        startButton1->setStyleSheet(buttonStyle);
        // Play icon to startButton
        QIcon playIcon(":/icons/play_icon.png");
        startButton->setIcon(playIcon);
        startButton->setIconSize(QSize(16, 16));
        gridLayout->addWidget(startButton, 4 + col * 4, 1, 1, 5);
    }

    // Track selection buttons
    QPushButton *trackOneButton = new QPushButton("1.Track");
    QPushButton *trackTwoButton = new QPushButton("2.Track");
    trackOneButton->setStyleSheet(buttonStyle);
    trackTwoButton->setStyleSheet(buttonStyle);
    gridLayout->addWidget(trackOneButton, 5 + 2 * 4, 1, 2, 2);
    gridLayout->addWidget(trackTwoButton, 5 + 2 * 4, 4, 2, 2);

    // Working time display
    QLabel *workingTimeLabel = new QLabel("12:30");
    workingTimeLabel->setStyleSheet(labelStyle);
    gridLayout->addWidget(workingTimeLabel, 7, 2, 2, 3);
    QLabel *workingTimeTextLabel = new QLabel("Working Time");
    workingTimeTextLabel->setStyleSheet(labelStyle);
    gridLayout->addWidget(workingTimeTextLabel, 7, 4, 1, 3);

    // Additional buttons
    QPushButton *lightButton = new QPushButton("Light");
    lightButton->setStyleSheet(buttonStyle);
    // Light icon to lightButton
    QIcon lightIcon(":/icons/light_icon.png");
    lightButton->setIcon(lightIcon);
    lightButton->setIconSize(QSize(16, 16));
    gridLayout->addWidget(lightButton, 7, 7, 1, 3);

    QPushButton *moreSettingsButton = new QPushButton("More Settings");
    moreSettingsButton->setStyleSheet(buttonStyle);
    // Menu icon to moreSettingsButton
    QIcon moreSettingsIcon(":/icons/menu_icon.png");
    moreSettingsButton->setIcon(moreSettingsIcon);
    moreSettingsButton->setIconSize(QSize(16, 16));
    gridLayout->addWidget(moreSettingsButton, 7, 9, 1, 3);

    // Set central widget and show main window
    mainWindow.setCentralWidget(centralWidget);
    mainWindow.resize(500, 600);
    mainWindow.show();

    return app.exec();
}
