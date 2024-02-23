#include "Logger.h"

#include <QFormLayout>
#include <QTextStream>




Logger* Logger::_logger = 0;


Logger::Logger() : QWidget(nullptr)
{

    QFormLayout * layout = new QFormLayout(this);



    logger_text = new QTextEdit;
    configureSize();
    layout->addWidget(logger_text);

    setLayout(layout);

    setWindowFlags(Qt::WindowStaysOnTopHint);

    connect(this, SIGNAL(printToLog(const QString&)), logger_text, SLOT(append(const QString&)));



}


void Logger::configureSize()
{
    logger_text->setMinimumSize(MIN_LOGGER_WIDTH, MIN_LOGGER_HEIGHT);
    logger_text->setReadOnly(true);

    
}


void Logger::print(const QString &msg,const QString& file, int line)
{
    QString tmp;
    QTextStream(&tmp) << file <<"::Line "<<line<<": "<<msg;


    emit printToLog(tmp);

    show();

}