#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QWidget>
#include <QPixmap>
#include <opencv2/opencv.hpp>

///////////////////////////////////////////////////////////////////////////////////////
//MainWindow
///////////////////////////////////////////////////////////////////////////////////////

class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  MainWindow();
  ~MainWindow();

  QLabel* label;
  QTimer* timer;
  cv::VideoCapture cap;

  void update_frame();
};

#endif
