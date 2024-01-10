#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLabel>
#include <QGridLayout>
#include <QTimeEdit>
#include <QFrame>
#include <QPalette>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Cool Train");

    // Central widget and layout
    QWidget *centralWidget = new QWidget(&mainWindow);
    QGridLayout *gridLayout = new QGridLayout(centralWidget);

    // Style sheet for the buttons and labels
    QString buttonStyle = "QPushButton { background-color: #333; color: white; font-weight: bold; }";
    QString labelStyle = "QLabel { color: #666; font-weight: bold; }";
    
    // Train 1
    // Speed Slider
    QSlider *speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setRange(0, 100);
    QLabel *speedLabel = new QLabel("Speed");
    speedLabel->setStyleSheet(labelStyle);
    gridLayout->addWidget(speedLabel, 0, 0, 1, 1);
    gridLayout->addWidget(speedSlider, 0, 1, 1, 3);

    // Start Button
    QPushButton *startButton = new QPushButton("START");
    startButton->setStyleSheet(buttonStyle);
    gridLayout->addWidget(startButton, 1, 0, 1, 4);

    // Train 2
    // Speed Slider
    QSlider *speedSlider = new QSlider(Qt::Horizontal);
    speedSlider->setRange(0, 100);
    QLabel *speedLabel = new QLabel("Speed");
    speedLabel->setStyleSheet(labelStyle);
    gridLayout->addWidget(speedLabel, 0, 0, 1, 1);
    gridLayout->addWidget(speedSlider, 0, 1, 1, 3);

    // Start Button
    QPushButton *startButton = new QPushButton("START");
    startButton->setStyleSheet(buttonStyle);
    gridLayout->addWidget(startButton, 1, 0, 1, 4);

    // Track selection buttons
    QPushButton *trackOneButton = new QPushButton("1.Track");
    QPushButton *trackTwoButton = new QPushButton("2.Track");
    trackOneButton->setStyleSheet(buttonStyle);
    trackTwoButton->setStyleSheet(buttonStyle);
    gridLayout->addWidget(trackOneButton, 2, 0, 1, 2);
    gridLayout->addWidget(trackTwoButton, 2, 2, 1, 2);

    // Working time display
    QLabel *workingTimeLabel = new QLabel("12:30\nWorking Time");
    workingTimeLabel->setStyleSheet(labelStyle);
    gridLayout->addWidget(workingTimeLabel, 3, 0, 1, 2);

    // Laps display
    QLabel *lapsLabel = new QLabel("003\nLaps");
    lapsLabel->setStyleSheet(labelStyle);
    gridLayout->addWidget(lapsLabel, 3, 2, 1, 2);

    // Additional buttons
    QPushButton *lightButton = new QPushButton("Light");
    QPushButton *moreSettingsButton = new QPushButton("More Settings");
    lightButton->setStyleSheet(buttonStyle);
    moreSettingsButton->setStyleSheet(buttonStyle);
    gridLayout->addWidget(lightButton, 4, 0, 1, 2);
    gridLayout->addWidget(moreSettingsButton, 4, 2, 1, 2);

    // Set central widget and show main window
    mainWindow.setCentralWidget(centralWidget);
    mainWindow.resize(400, 300);
    mainWindow.show();

    return app.exec();
}
