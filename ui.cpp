#include"ui.h"
#include<QScrollArea>
#include<QVBoxLayout>
#include<QSizePolicy>
#include<QKeyEvent>
#include<QDebug>
#include<QStringListModel>
#include"pm.h"
#include"want.h"
#include<QTime>
extern QString naam;extern QString baba;
int startx,starty;bool press=false;

ui::ui(QWidget *parent):QWidget(parent){}

ui::ui(QString str,QWidget *parent):QWidget(parent)
{
old_count=0;
top=0;
pmme=new QPushButton();
QIcon icon(":pm.png");
pmme->setIcon(icon);
pmme->setStyleSheet(QString("QPushButton{border-radius:5px;width:30px;height:30px;}"));
connect(pmme,SIGNAL(clicked()),this,SLOT(newbox()));
close1=new QPushButton();
QIcon *ic=new QIcon(":close.png");
close1->setIconSize(QSize(60,60));
close1->setIcon(*ic);
close1->setStyleSheet("border-radius:10px");
connect(close1,SIGNAL(clicked()),this,SLOT(bye()));

ic=new QIcon(":ref.png");
ref=new QPushButton();
ref->setIconSize(QSize(60,60));
ref->setIcon(*ic);
ref->setStyleSheet("border-radius:10px");
connect(ref,SIGNAL(clicked()),this,SLOT(newavatar()));
te=new QTextEdit(this);
te->setReadOnly(true);
le=new QLineEdit("default");
spli=new QSplitter();
men=new QListView();
men->setMaximumWidth(150);
sender=NULL;
arrange();
policy();
setFixedSize(600,400);
setWindowTitle(str);
setWindowFlags(Qt::SplashScreen);
setWindowOpacity(0.7);
setWindowTitle(str);
//connect
sender=new client(windowTitle(),baba,this);
connect(sender,SIGNAL(sendtomain(QString)),this,SLOT(rAtMain(QString)));
connect(this,SIGNAL(takethis(QString)),sender,SLOT(tookthis(QString)));
connect(sender,SIGNAL(peoplenames(QString)),this,SLOT(arrangelistview(QString)));
connect(sender,SIGNAL(peoplenamesedit(QString)),this,SLOT(rearrangelistview(QString)));

//color of mainwindow

QPalette pal=palette();	
	pal.setColor(QPalette::Window,QColor(0,0,0));
	pal.setColor(QPalette::WindowText,QColor(0,255,70));
	setPalette(pal);
//

//color of textedit

	
	QPalette pal_te(QColor(0,0,0));
	te->setPalette(pal_te);
	te->setStyleSheet(QString("QTextEdit{border:2px solid green;border-radius:5px;} QScrollBar:vertical {  background:black;} QScrollBar:horizontal { background:black;}"));
//color

//color of le
	QPalette pal_le(QColor(0,0,0));
	pal_le.setColor(QPalette::Text,QColor(0,255,70));
	le->setPalette(pal_le);
	le->setStyleSheet(QString("QLineEdit{border:2px solid green;border-radius:5px;background:black;}"));
//color
//color of listview
	QPalette pal_men(QColor(0,0,0));
	pal_men.setColor(QPalette::Text,QColor(0,255,70));
	men->setPalette(pal_men);
	men->setStyleSheet(QString("QListView{border:2px solid green;border-radius:5px;} QScrollBar:vertical {  background:black;} QScrollBar:horizontal {background:black;}"));
//color

}

void ui::arrange()
{
QHBoxLayout *outer=new QHBoxLayout(this);
QVBoxLayout *lay=new QVBoxLayout();
QHBoxLayout *hlay=new QHBoxLayout();
hlay->addWidget(pmme);
hlay->addWidget(ref);
ref->setFixedSize(40,30);
hlay->addWidget(close1);
close1->setFixedSize(40,30);
hlay->setAlignment(Qt::AlignRight);
QVBoxLayout *vlay=new QVBoxLayout();
te->zoomOut(2);
vlay->addWidget(te);
vlay->addWidget(le);
vlay->setAlignment(le,Qt::AlignHCenter);
lay->addLayout(hlay);
lay->addLayout(vlay);
//making a temp widget
QWidget *temp_wid=new QWidget();
temp_wid->setLayout(lay);
//over
//putting stuff to splitter
	spli->addWidget(men);
	spli->addWidget(temp_wid);
//over
outer->addWidget(spli);
setLayout(outer);
}

void ui::policy()
{
le->setFixedSize(450,30);
}

void ui::keyPressEvent(QKeyEvent *e)
{
if((le->hasFocus()==true) && (e->key()==Qt::Key_Return))
 { QString str=le->text();

		if(str=="")
		{return;}
//putting text in self made cache
if(old_count<49)
{old[++old_count]=le->text();
top=old_count;}
else{old_count=0;}
//over
   if(str.left(8)=="$connect") 
    {int i;
    	 for(i=8;(i<str.length()) && (str[i]==' ');i++);
      		ip=str.mid(i,str.length());
    		 if(ip=="")
      			 {te->append("\nthere dosent seem to be anything");
    			 le->setText("");
                         }
     		 else 
    		 {
       			/*if(sender==NULL)
        			 { sender=new client(ip);
				   connect(sender,SIGNAL(sendtomain(QString)),this,SLOT(rAtMain(QString)));
                                   connect(this,SIGNAL(takethis(QString)),sender,SLOT(tookthis(QString)));
                                  }
      			 else
         			{te->append("\nalready connected to server");}*/
                 }

       le->setText("");
    }



  else{
   QColor color(te->textColor());
   QColor c(0,255,70);
   te->setTextColor(c);
   te->append(QTime::currentTime().toString("h:m:s ap")+" Me : "+le->text()+"\n");
   te ->setTextColor(color);
    if(sender!=NULL)
     {
     QString str=le->text();
      str.prepend("$"+windowTitle()+"$"+naam+"$");
      str.append("$");	
	qDebug()<<str;
      emit takethis(str);
     } 
   le->setText(""); 
  }     
 }


if((le->hasFocus()==true) && (e->key()==Qt::Key_Up))
	{	
		if(top==0)
		{top=old_count;}
		le->setText(old[top--]);
	}

}

void ui::rAtMain(QString str)
{
qDebug()<<"reached here wow my name is Khan and i am not a terrorist";
QColor color(te->textColor());
QColor c(255,46,0);
te->setTextColor(c);
te->setAlignment(Qt::AlignRight);
te->append(QTime::currentTime().toString("h:m:s ap")+" "+ str +"\n");
te->setAlignment(Qt::AlignLeft);
te->setTextColor(color);
}



void ui::mousePressEvent(QMouseEvent *e)
{
press=true;
startx=e->globalX();
starty=e->globalY();
}

void ui::mouseMoveEvent(QMouseEvent *e)
{
if(press==true)
 {
int dx=e->globalX()-startx;
int dy=e->globalY()-starty;
startx=e->globalX();
starty=e->globalY();
move(x()+dx,y()+dy);
 }

}


void ui::mouseReleaseEvent(QMouseEvent* e)
{
Q_UNUSED(e);
press=false;
}

void ui::bye()
{
this->close();
}

void ui::closeEvent(QCloseEvent *e){

emit closing();
qDebug()<<"request for delete";
QByteArray c;
c.append("$bye$" + windowTitle()+"$"+ naam+"$");
qDebug()<<"$bye$"+ windowTitle()+"$"+ naam+"$";
sender->cli->write(c);
sender->cli->flush();
sender->cli->waitForBytesWritten();
}


void ui::newavatar()
{
want * w=(want*)(this->parent());
QAbstractItemModel *mod=w->view->model();
  //index number
ui **b=w->bit;

int i=0;
	for(i=0;i<mod->rowCount();i++)
		{
		if(mod->index(i,0).data(Qt::DisplayRole).toString()!=windowTitle())
			{b++;}
		else{break;}
		}

	this->close();
ui *u=new ui(windowTitle(),(want*)this->parent());
*b=u;
connect(u,SIGNAL(closing()),(want*)this->parent(),SLOT(ui_closing()));
u->show();

/*sender->quit();
sender=NULL;
te->append("reconnecting..");
sender=new client(windowTitle(),"localhost",this);
connect(sender,SIGNAL(sendtomain(QString)),this,SLOT(rAtMain(QString)));
connect(this,SIGNAL(takethis(QString)),sender,SLOT(tookthis(QString)));
connect(sender,SIGNAL(peoplenames(QString)),this,SLOT(arrangelistview(QString)));
connect(sender,SIGNAL(peoplenamesedit(QString)),this,SLOT(rearrangelistview(QString)));*/

}


void ui::arrangelistview(QString str)
	{
		QStringList pieces=str.split("$");
		for(int i=0;i<pieces.length();i++)
			{
			if(pieces.at(i)=="")
			{pieces.removeAt(i);}
			}
		pieces.removeAt(0);//removing substring 'names'
			
		QStringListModel *model=new QStringListModel();
		model->setStringList(pieces);
		men->setModel(model);
		men->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}

void ui::rearrangelistview(QString str)
	{
	QStringList abc=str.split(" ");
	qDebug()<<abc.at(0);
	QStringListModel *model=(QStringListModel *)men->model();
	QStringList pieces=model->stringList();
	if(str.indexOf("joined the room")!=-1)
	{pieces<<abc.at(0);}
	else if(str.indexOf("said buh-bye")!=-1)
	{
		for(int i=0;i<pieces.length();i++)
			{if(pieces.at(i)==abc.at(0))
			 pieces.removeAt(i);
			}
	}	
	model->setStringList(pieces);
	men->setModel(model);
	}

void ui::newbox()
	{
		QModelIndex index=men->currentIndex();
		if(naam!=index.data(Qt::DisplayRole).toString() && naam!="")		
		{pm *m=new pm(windowTitle(),index.data(Qt::DisplayRole).toString(),0,"",this);
		m->show();}
	}

