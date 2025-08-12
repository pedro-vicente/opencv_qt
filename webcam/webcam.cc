#include <QGuiApplication>
#include <QVBoxLayout>
#include <QLabel>

#include "webcam.h"

///////////////////////////////////////////////////////////////////////////////////////
//MainWindow
///////////////////////////////////////////////////////////////////////////////////////

MainWindow::MainWindow()
{
  // central widget
  QWidget* container = new QWidget(this);
  setCentralWidget(container);

  QVBoxLayout* layout = new QVBoxLayout(container);

  // create label to display video
  label = new QLabel(this);
  label->setMinimumSize(640, 480);
  label->setStyleSheet("border: 1px solid gray");
  layout->addWidget(label);

  // open webcam
  cap.open(0);
  if (!cap.isOpened())
  {
    label->setText("Error: Cannot open webcam");
    return;
  }

  // set up timer for frame updates
  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &MainWindow::update_frame);
  timer->start(30);

  setWindowTitle("OpenCV Webcam");
  resize(660, 500);
}

///////////////////////////////////////////////////////////////////////////////////////
// ~MainWindow
///////////////////////////////////////////////////////////////////////////////////////

MainWindow::~MainWindow()
{
  if (cap.isOpened())
  {
    cap.release();
  }
}

///////////////////////////////////////////////////////////////////////////////////////
// update_frame()
///////////////////////////////////////////////////////////////////////////////////////

void MainWindow::update_frame()
{
  cv::Mat frame;
  cap >> frame;

  if (frame.empty())
  {
    return;
  }

  // convert BGR to RGB
  cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

  // convert to QImage
  QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

  // scale to fit label while keeping aspect ratio
  QPixmap pixmap = QPixmap::fromImage(qimg);
  pixmap = pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

  label->setPixmap(pixmap);
}
