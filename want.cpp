#include"want.h"
#include<QStringListModel>
#include<QHBoxLayout>
#include<QVBoxLayout>


extern QString naam;

want::want(QTcpSocket * soc,QWidget *parent):QWidget(parent)
{
        socket=soc;
	choose=new QPushButton("ok");
	update=new QPushButton("refresh");
	connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
	connect(update,SIGNAL(clicked()),this,SLOT(clearAll()));
	connect(choose,SIGNAL(clicked()),this,SLOT(dothehonors()));
}

void want::request()
{	
	QByteArray arr;
	arr.append("$list$");
	 socket->write(arr);	
}

void want::readyRead()
{
	QByteArray arr=socket->readAll();
	QString str(arr);
       	arrange(str);	
}

void want::arrange(QString str)
 {
  QStringList pieces=str.split("$");
//filtering
for(int i=0;i<pieces.length();i++)
 	{
	 if(pieces.at(i)=="")
		{
		 pieces.removeAt(i);
		}
	}
//filtering
bit=new ui*[pieces.length()];

//initialize the flags
ui **b=bit;
	for(int i=0;i<pieces.length();i++){*b=NULL;++b;}
//done

QStringListModel *model=new QStringListModel();
	model->setStringList(pieces);
	view=new QListView();
	view->setModel(model);
 	view->setEditTriggers(QAbstractItemView::NoEditTriggers);
	view->setSpacing(10);
  QVBoxLayout *vlay=new QVBoxLayout();
  vlay->addWidget(view);
  	QHBoxLayout *hlay=new QHBoxLayout();
	hlay->addWidget(choose);
	hlay->addWidget(update);
 vlay->addLayout(hlay);
setFixedSize(300,400);
 setLayout(vlay);
setWindowTitle("Chat rooms");	  	
 }

void want::clearAll()
{
QAbstractItemModel *mod=view->model();
delete view;
ui ** b=bit;
for(int i=0;i<mod->rowCount();i++)
	{delete *b;b++;}
delete [] bit;
delete choose;
delete update;
choose=new QPushButton("ok");
update=new QPushButton("refresh");
connect(update,SIGNAL(clicked()),this,SLOT(clearAll()));
connect(choose,SIGNAL(clicked()),this,SLOT(dothehonors()));
QLayout *now=this->layout();
delete now;
request();
}


void want::dothehonors()
{ 
QModelIndex item=view->currentIndex();
QAbstractItemModel *mod=view->model();

  //index number
ui **b=bit;

int i=0;
	for(i=0;i<mod->rowCount();i++)
		{
		if(mod->index(i,0).data(Qt::DisplayRole).toString()==item.data(Qt::DisplayRole).toString())
			{b++;break;}
		}
		
		if(*b==NULL)	
		{	ui *u=new ui(item.data(Qt::DisplayRole).toString());
			connect(u,SIGNAL(closing()),this,SLOT(ui_closing()));
			u->show();
			*b=u;
		}
}

//need closing here
void want::ui_closing()
{      ui *u=(ui*)QObject::sender();
       QAbstractItemModel *mod=view->model();
QString topic=u->windowTitle();
ui**b=bit;
int i=0;
	for(i=0;i<mod->rowCount();i++)
		{
		if(mod->index(i,0).data(Qt::DisplayRole).toString()==topic)
			{b++;break;}
		}  *b=NULL;

}


