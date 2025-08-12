#include <QGuiApplication>
#include <QVBoxLayout>
#include <QLabel>

#include "window.h"

///////////////////////////////////////////////////////////////////////////////////////
//MainWindow
///////////////////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow()
{
  // central widget
  QWidget* container = new QWidget;

  // create horizontal layout 
  QVBoxLayout* layout = new QVBoxLayout;
  container->setLayout(layout);

  // add a fame to the layout
  QFrame* frame = new QFrame();
  frame->setStyleSheet("background-color: olive;");
  frame->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  layout->addWidget(frame);

  setCentralWidget(container);
}
