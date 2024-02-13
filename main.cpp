#include <QApplication>
#include "MainScreen.h"
#include "LoadingScreen.h"

#include <iostream>

int main(int argc, char *argv[]) {

    std::cout<<"Programm"<<std::endl;
    QApplication app(argc, argv);


    LoadingScreen loadingScreen;
    MainScreen *mainScreen = new MainScreen(); // Create but don't show yet

    // Connect the loading screen's signal to show the main screen
/*
    QObject::connect(&loadingScreen, &LoadingScreen::connectionComplete, [&]() {
        loadingScreen.close();
        mainScreen->show();
    });
*/
    mainScreen->show();
    //loadingScreen.show(); // Show loading screen first

    return app.exec();
}
