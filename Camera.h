#include <raspicam/raspicam.h>

class Camera
{
public:
  Camera();

private:
  void Open();

  raspicam::RaspiCam camera;
};
