#include "Camera.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
Camera::Camera():
  stabalization_time{3}
{
  Open();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Camera::SaveImage(void)
{
  unsigned char *data = new unsigned char
    [camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)];

  camera.retrieve(data,raspicam::RASPICAM_FORMAT_RGB);

  std::ofstream outFile("raspicam_image.ppm",std::ios::binary );
  outFile<<"P6\n"<<camera.getWidth() <<" "<<camera.getHeight() <<" 255\n";
  outFile.write((char*) data, camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB));

  delete data;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Camera::Open()
{
  if(!camera.open())
  {
    std::cerr << "Camera failed to open" << "\n";
  }
  else
  {
    std::cout << "Initializing camera, waiting " << stabalization_time
      << "seconds\n";

    std::this_thread::sleep_for(std::chrono::seconds(stabalization_time));
  }
}
