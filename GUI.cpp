#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

class CoolTrainUI : public QWidget {
public:
    CoolTrainUI(QWidget *parent = nullptr) : QWidget(parent) {
        // Initialize UI components
        QSlider *speedSlider = new QSlider(Qt::Horizontal, this);
        speedSlider->setRange(0, 100); // Assuming 0 to 100 is the speed range

        QPushButton *startButton = new QPushButton("START", this);
        
        QPushButton *trackButton1 = new QPushButton("1.Track", this);
        QPushButton *trackButton2 = new QPushButton("2.Track", this);
        
        QLabel *workingTimeLabel = new QLabel("12:30\nWorking Time", this);
        QLabel *lapsLabel = new QLabel("003\nLaps", this);
        
        QPushButton *lightButton = new QPushButton("Light", this);
        QPushButton *moreSettingsButton = new QPushButton("More Settings", this);
        
        // Layout the UI components
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        
        // Add components to the layout...
        // You'll need to use QHBoxLayout, QVBoxLayout, and maybe QGridLayout
        // for proper arrangement.

        // For example, to layout the speed slider and the start button horizontally:
        QHBoxLayout *topLayout = new QHBoxLayout();
        topLayout->addWidget(speedSlider);
        topLayout->addWidget(startButton);
        
        // Similarly, create and arrange other layouts for the rest of the UI components

        // Finally, set the main layout
        this->setLayout(mainLayout);
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    CoolTrainUI coolTrainUI;
    coolTrainUI.show();
    
    return app.exec();
}
