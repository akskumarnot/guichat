#include"want.h"
#include<QStringListModel>
#include<QHBoxLayout>
#include<QVBoxLayout>


extern QString naam;bool press2;int startx2,starty2;extern QString baba;

want::want(QTcpSocket * soc,QWidget *parent):QWidget(parent)
{
        socket=soc;
	choose=new QPushButton("ok");
	update=new QPushButton("refresh");
	choose->setStyleSheet(QString("QPushButton{background:black;border:1px solid rgb(0,255,70);color:rgb(0,255,70);}"));
	update->setStyleSheet(QString("QPushButton{background:black;border:1px solid rgb(0,255,70);color:rgb(0,255,70)}"));
	connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
	connect(update,SIGNAL(clicked()),this,SLOT(clearAll()));
	connect(choose,SIGNAL(clicked()),this,SLOT(dothehonors()));
	setWindowFlags(Qt::SplashScreen);

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
view->setStyleSheet(QString("QListView{background:black;}"));
QPalette pal;
	pal.setColor(QPalette::Text,QColor(0,255,70));
	view->setPalette(pal);
	view->setStyleSheet(QString("QListView{border:1px solid rgb(0,255,70);background:black;}"));
//color of window
QPalette pal1;
pal1.setColor(QPalette::Window,QColor(0,0,0));
setPalette(pal1);
//color
setWindowOpacity(0.7);
 }

void want::clearAll()
{
onClose();
QAbstractItemModel *mod=view->model();
delete view;
ui ** b=bit;
for(int i=0;i<mod->rowCount();i++)
	{delete *b;b++;}
delete [] bit;
delete choose;
delete update;
choose=new QPushButton("ok");
choose->setStyleSheet(QString("QPushButton{background:black;border:1px solid rgb(0,255,70);color:rgb(0,255,70);}"));
update=new QPushButton("refresh");
update->setStyleSheet(QString("QPushButton{background:black;border:1px solid rgb(0,255,70);color:rgb(0,255,70);}"));
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
		if(mod->index(i,0).data(Qt::DisplayRole).toString()!=item.data(Qt::DisplayRole).toString())
			{b++;}
		else{break;}
		}
		
		if(*b==NULL)
		{	
			ui *u=new ui(item.data(Qt::DisplayRole).toString(),this);
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
		if(mod->index(i,0).data(Qt::DisplayRole).toString()!=topic)
			{b++;}
		else{break;}
		}  *b=NULL;
	
}

void want::closeEvent(QCloseEvent *e)
	{
		onClose();
	}

void want::onClose()
	{
	ui ** b=bit;
		QStringListModel *model=(QStringListModel*)view->model();
		int len=(model->stringList()).length();
		
		for(int i=0;i<len;i++)		
			{
				if(*b!=NULL)
				{(*b)->close();}
				b++;
			}
	}


//drag code



void want::mousePressEvent(QMouseEvent *e)
{
press2=true;
startx2=e->globalX();
starty2=e->globalY();
}

void want::mouseMoveEvent(QMouseEvent *e)
{
if(press2==true)
 {
int dx=e->globalX()-startx2;
int dy=e->globalY()-starty2;

startx2=e->globalX();
starty2=e->globalY();
move(x()+dx,y()+dy);
 }

}


void want::mouseReleaseEvent(QMouseEvent* e)
{
Q_UNUSED(e);
press2=false;
}

