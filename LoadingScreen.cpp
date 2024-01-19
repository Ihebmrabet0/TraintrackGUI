#include "LoadingScreen.h"

LoadingScreen::LoadingScreen(QWidget *parent) : QWidget(parent) {
    // Set the size of the loading screen
    setFixedSize(800, 600);

    // Set the background to black
    setStyleSheet("background-color: black;");

    animationLabel = new QLabel(this);
    loadingMovie = new QMovie(":/gif/loading1.gif");
    animationLabel->setMovie(loadingMovie);
    loadingMovie->start();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addStretch(); // Add a spacer at the top
    layout->addWidget(animationLabel, 0, Qt::AlignCenter); // Center the label
    layout->addStretch(); // Add a spacer at the bottom
    setLayout(layout);

    connectionTimer = new QTimer(this);
    connect(connectionTimer, &QTimer::timeout, this, &LoadingScreen::onConnectionSimulated);
    connectionTimer->start(10000); // 10 seconds
}

void LoadingScreen::onConnectionSimulated() {
    connectionTimer->stop();
    emit connectionComplete();
}
