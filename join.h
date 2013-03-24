#ifndef JOIN_H
#define JOIN_H
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QTcpSocket>

class join:public QWidget
{
Q_OBJECT
public:
join(QTcpSocket *soc,QWidget *parent=0);
void make_nick();
void make_fname();
void make_pass();
void make_congo();
bool validator(QString);
void reg(QString);
public slots:
void redraw();
void constructString(QString);
void emitter();
void readyRead();
signals:
void adder(QString);
private:
QVBoxLayout *mainLayout;
QPushButton *nextb;
QLabel *lab1;
QLabel *l;
QLineEdit *le1;
QLineEdit *le;
QHBoxLayout *lay1;
QTcpSocket *socket;
protected:
void paintEvent(QPaintEvent *e);
void mousePressEvent(QMouseEvent *e);
void mouseReleaseEvent(QMouseEvent *e);
void mouseMoveEvent(QMouseEvent *e);
};

#endif
