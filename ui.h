#ifndef UI_H
#define UI_H

#include<QWidget>
#include<QTimer>
#include<QTextEdit>
#include<QLineEdit>
#include"client.h"
#include<QPushButton>

class ui:public QWidget
{
Q_OBJECT

public:
ui(QString str,QWidget *parent=0);
ui(QWidget * parent=0);
void arrange();
void policy();

signals:
void takethis(QString);
void closing();
public slots:
void rAtMain(QString);
void bye();
void newavatar();
private:
QTextEdit *te;
QLineEdit *le;
QString ip;
client *sender;
QPushButton *ref;
QPushButton *close1;
QTcpSocket *soc;
protected:
void mousePressEvent(QMouseEvent *);
void mouseReleaseEvent(QMouseEvent *);
void mouseMoveEvent(QMouseEvent *);
void keyPressEvent(QKeyEvent *);
void closeEvent(QCloseEvent *e);
};
#endif


