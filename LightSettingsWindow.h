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
};

#endif // LIGHTSETTINGSWINDOW_H
