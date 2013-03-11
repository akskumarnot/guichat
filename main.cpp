#include<QApplication>
#include"login.h"

int main(int argc,char * argv[])
{
QApplication app(argc,argv);
login *l=new login();
l->show();
return app.exec();
}
