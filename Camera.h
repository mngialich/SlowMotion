#include <raspicam/raspicam.h>

class Camera
{
public:
  Camera();

  void SaveImage(void);

private:
  void Open();

  void set_height();
  {
    height = camera.getHeight()
  }

  void set_width()
  {
    width = camera.getWidth();
  }

  int get_image_size()
  {
    return(camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB)))
  }

  raspicam::RaspiCam camera;

  int stabalization_time;
  int image_counter;
  int width, height;
};
