/////////////////////////////////////////////////////////////////////////////////////////////////////
// webcam capture and display program using OpenCV
// captures frames from default camera(id 0) and shows in window
// press 'q' to quit
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
  // initialize video capture from default camera (id 0)
  cv::VideoCapture cap(0);
  if (!cap.isOpened())
  {
    return -1;
  }

  // matrix to store video frame
  cv::Mat frame;

  /////////////////////////////////////////////////////////////////////////////////////////////////////
  // main capture loop - get and display frames until 'q' pressed
  /////////////////////////////////////////////////////////////////////////////////////////////////////

  while (true)
  {
    // capture frame from camera
    cap >> frame;
    if (frame.empty())
    {
      break;
    }

    // display frame in window
    cv::imshow("Webcam", frame);

    // wait 1ms for keypress
    if (cv::waitKey(1) == 'q')
    {
      break;
    }
  }

  // cleanup and release resources
  cap.release();
  cv::destroyAllWindows();
  return 0;
}
