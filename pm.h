#ifndef PM_H
#define PM_H
#include<QTcpSocket>
#include<QWidget>
#include<QLineEdit>
#include<QTextEdit>
#include<QVBoxLayout>
#include<QLabel>
class pm:public QWidget
{
Q_OBJECT
private:
QTcpSocket *socket;
QString person;
QLineEdit *le;
QTextEdit *te;
QVBoxLayout *mainLayout;
QLabel *title;
QString gpname;
int mode;
public:
pm(QString gp,QString per,int mode,QString id,QWidget * parent=0);
void arrange();
public slots:
void readyRead();
void setUp();
void sendData(QString str);
protected:
void mouseMoveEvent(QMouseEvent *e);
void mousePressEvent(QMouseEvent *e);
void mouseReleaseEvent(QMouseEvent *e);
void keyPressEvent(QKeyEvent *e);
};

#endif
