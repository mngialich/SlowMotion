#include "Camera.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <sstream>
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
Camera::Camera():
  stabalization_time{3},
  image_counter{0}
{
  Open();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Camera::SaveImage(void)
{
 camera.grab();
       
  unsigned char *data = new unsigned char
    [camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)];

  camera.retrieve(data,raspicam::RASPICAM_FORMAT_RGB);

  std::ostringstream file_name;
  file_name << "Image" << image_counter << ".ppm";
  
  image_counter++;
  
  std::ofstream outFile(file_name.str(),std::ios::binary );
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
