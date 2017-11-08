#include <raspicam/raspicam.h>

class Camera
{
public:
  Camera();

  void SaveImage(void);

private:
  void Open();

  raspicam::RaspiCam camera;

  int stabalization_time;
  int image_counter;
};
