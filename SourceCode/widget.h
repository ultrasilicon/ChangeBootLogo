#ifndef WIDGET_H
#define WIDGET_H

#include <QDropEvent>
#include <QMimeData>
#include <QProcess>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QLabel>

class Widget : public QWidget
{
  Q_OBJECT

public:
  Widget(QWidget *parent = 0);
  ~Widget();

protected:
  void dragEnterEvent(QDragEnterEvent *event);
  void dropEvent(QDropEvent *event);

private:
  QPixmap logo_pixmap;
  QLabel *logo_label;

  QVBoxLayout *logo_layout;
  QGroupBox *logo_group_box;

  QPushButton *start_btn;
  QVBoxLayout *main_layout;

  QString subject_path;
  QString object_path = "/System/Library/CoreServices/BootLogo.png";

  void loadLogoPixmap(QString path);

private slots:
  void changeBootImg();


};

#endif // WIDGET_H
