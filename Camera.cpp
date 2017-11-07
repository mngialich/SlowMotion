#include "Camera.h"

#include<iostream>

Camera::Camera()
{
  Open();
}

void Camera::Open()
{
  if(!camera.open())
  {
    std::cerr << "Camera failed to open" << "\n";
  }
}
