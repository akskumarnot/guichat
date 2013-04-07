#ifndef UI_H
#define UI_H

#include<QWidget>
#include<QTimer>
#include<QTextEdit>
#include<QLineEdit>
#include"client.h"
#include<QPushButton>
#include<QSplitter>
#include<QListView>

class ui:public QWidget
{
Q_OBJECT

public:
ui(QString str,QWidget *parent=0);
ui(QWidget * parent=0);
void arrange();
void policy();
QListView *men;

signals:

void takethis(QString);
void closing();

public slots:
void rAtMain(QString);
void bye();
void newavatar();
void arrangelistview(QString);
void rearrangelistview(QString);
void newbox();
private:
QTextEdit *te;
QLineEdit *le;
QString ip;
client *sender;
QPushButton *ref;
QPushButton *close1;
QPushButton *pmme;
QTcpSocket *soc;
QString old[50];
int old_count,top;
QSplitter *spli;
protected:
void mousePressEvent(QMouseEvent *);
void mouseReleaseEvent(QMouseEvent *);
void mouseMoveEvent(QMouseEvent *);
void keyPressEvent(QKeyEvent *);
void closeEvent(QCloseEvent *e);
};
#endif


