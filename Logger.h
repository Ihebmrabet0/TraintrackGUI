#ifndef LOGGER_H
#define LOGGER_H


#include <QString>
#include <QWidget>
#include <QTextEdit>

#define MIN_LOGGER_WIDTH 400
#define MIN_LOGGER_HEIGHT 400

#define DEBUG(X) Logger::N() -> print(X,tr(__FILE_NAME__),__LINE__)

class Logger : public QWidget
{
    Q_OBJECT

    public:
    static Logger* N()
    {
        if(!_logger)
        {
            _logger = new Logger();
        }
        
        return _logger;
    }

    void print(const QString &msg, const QString &file, int line);

    signals:
        void printToLog(const QString& text);


    private:

        static Logger* _logger;



        Logger();
        //Logger(const Logger&){};
        //~Logger();

       void configureSize();

       QTextEdit * logger_text; 
       
};


#endif