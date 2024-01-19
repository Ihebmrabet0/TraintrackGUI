#ifndef LIGHTSETTINGSWINDOW_H
#define LIGHTSETTINGSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>

class LightSettingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LightSettingsWindow(QWidget *parent = nullptr);

private slots:
    void onLightButtonClicked();
    void onEditButtonClicked();

private:
    QLineEdit *editNameField;
    QLabel *selectedLightLabel;
    QString lastSelectedLight;
    QPushButton* selectedLightButton = nullptr;
    QString buttonStyle = "QPushButton { background-color: #333; color: white; border: none; border-radius: 5px; padding: 10px; font-family: Inter; font-size: 30px; font-style: normal; font-weight: 600;}";

};

#endif // LIGHTSETTINGSWINDOW_H
