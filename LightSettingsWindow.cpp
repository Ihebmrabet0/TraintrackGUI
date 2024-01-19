#include "LightSettingsWindow.h"

LightSettingsWindow::LightSettingsWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);


    QString labelTitelStyle = "QLabel { color: #0F172A; font-family : Inter; font-size : 44px; font-style : normal; font-weight : 800;}";
    QString labelStyle = "QLabel { color: gray; font-family : Inter; font-size : 40px; font-style : normal; font-weight : 600;}";
    QString lineEditStyle = "QLineEdit {"
                            "background-color: #FFF;"
                            "border: 2px solid #0F172A;"
                            "border-radius: 4px;"
                            "padding: 8px;"
                            "font-family: Inter;"
                            "font-size: 20px;"
                            "color: #333;"
                            "}";
    // Title
    QLabel *titleLabel = new QLabel("Lights Control Panel");
    titleLabel->setStyleSheet(labelTitelStyle);
    layout->addWidget(titleLabel, 0, 0, 1, 8);

    // Subtitle
    QLabel *subtitleLabel = new QLabel("Here you can run each LED separately.");
    subtitleLabel->setStyleSheet(labelStyle);
    layout->addWidget(subtitleLabel, 1, 0, 1, 8);

    // Create 24 light buttons
    for (int i = 0; i < 24; ++i)
    {
        QPushButton *lightButton = new QPushButton(QString::number(i + 1));
        lightButton->setStyleSheet(buttonStyle);
        connect(lightButton, &QPushButton::clicked, this, &LightSettingsWindow::onLightButtonClicked);
        layout->addWidget(lightButton, 2 + i / 4, (i % 4)*2, 1, 2);
    }

    // Label and edit field
    selectedLightLabel = new QLabel("Edit the last selected Light Name:");
    selectedLightLabel->setStyleSheet(labelStyle);
    layout->addWidget(selectedLightLabel, 8, 0, 1, 8);

    editNameField = new QLineEdit();
    editNameField->setPlaceholderText("Name...");
    editNameField->setStyleSheet(lineEditStyle);
    layout->addWidget(editNameField, 9, 0, 1, 6);

    // Edit button
    QPushButton *editButton = new QPushButton("Edit");
    editButton->setStyleSheet(buttonStyle);
    connect(editButton, &QPushButton::clicked, this, &LightSettingsWindow::onEditButtonClicked);
    layout->addWidget(editButton, 9, 6, 1, 2);
}

void LightSettingsWindow::onLightButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button)
    {
        if (selectedLightButton)
        {
            selectedLightButton->setStyleSheet(buttonStyle);
        }
        selectedLightButton = button;
        QString selectedButtonStyle = buttonStyle;
        selectedButtonStyle.replace("background-color: #333;", "background-color: gray;");
        selectedLightButton->setStyleSheet(selectedButtonStyle);

        lastSelectedLight = button->text();
        editNameField->setText(lastSelectedLight);
    }
}

void LightSettingsWindow::onEditButtonClicked()
{
    QString newName = editNameField->text();
    if (selectedLightButton)
    {
        selectedLightButton->setText(newName);
        selectedLightButton->setStyleSheet(buttonStyle);
        selectedLightButton = nullptr; //
    }
    editNameField->clear();
    lastSelectedLight.clear();
    editNameField->clearFocus();
}

