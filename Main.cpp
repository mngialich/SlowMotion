#include "Camera.h"

#include<iostream>

int main()
{
  std::cout << "trying to create object and open camera" << "\n";
  Camera camera;

  for(int i = 0; i<10; i++)
  {
    camera.SaveImage();
  }
}
