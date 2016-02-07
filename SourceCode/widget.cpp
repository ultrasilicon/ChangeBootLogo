#include "widget.h"

Widget::Widget(QWidget *parent)
  : QWidget(parent)
{

  logo_label = new QLabel(this);

  logo_layout = new QVBoxLayout(this);
  logo_layout->addWidget(logo_label);

  logo_group_box = new QGroupBox(this);
  logo_group_box->setTitle("Drag image into me to load && preview!");
  logo_group_box->setLayout(logo_layout);

  start_btn = new QPushButton("Apply", this);
  main_layout = new QVBoxLayout(this);
  main_layout->addWidget(logo_group_box);
  main_layout->addWidget(start_btn);

  connect(start_btn, SIGNAL(clicked()), this, SLOT(changeBootImg()));

  loadLogoPixmap(object_path);

  this->setLayout(main_layout);
  this->setWindowOpacity(1);
  this->setWindowTitle("Change Boot Logo!");
  this->setAcceptDrops(true);
}

Widget::~Widget()
{

}

void Widget::dragEnterEvent(QDragEnterEvent *event)
{
  event->accept();
}

void Widget::dropEvent(QDropEvent *event)
{
  QList<QUrl> urls = event->mimeData()->urls();
  if (urls.isEmpty())
    {
      return;
    }
  QString fileName = urls.first().toLocalFile();
  if (fileName.isEmpty())
    {
      return;
    }
  loadLogoPixmap(fileName);
  subject_path = fileName;
}

void Widget::loadLogoPixmap(QString path)
{
  logo_pixmap.load(path);
  logo_pixmap = logo_pixmap.scaled(this->width(),this->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
  logo_label->setPixmap(logo_pixmap);
}

void Widget::changeBootImg()
{
  if(subject_path == "")
    {
      return;
    }
  QProcess::execute(QString("sudo cp %1 %2").arg(subject_path).arg(object_path));
  subject_path == "";
}
