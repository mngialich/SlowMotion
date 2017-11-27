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
  image_counter{0},
  height{0},
  width{0}
{
  Open();
  set_width();
  set_height();
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

  write_file(file_name.str(),data);

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

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void Camera::write_file(std::string file_name,unsigned char* data)
{
  std::ofstream outFile(file_name,std::ios::binary );
  outFile<<"P6\n"<<width <<" "<<height <<" 255\n";
  outFile.write((char*) data, get_image_size());
}
