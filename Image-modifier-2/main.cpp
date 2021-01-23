#include "ImageTransform.h"
#include "uiuc/PNG.h"

int main() {
  uiuc::PNG png, png2, result;

  png.readFromFile("pic.png");
  result = grayscale(png);
  result.writeToFile("out-grayscale.png");
  
  result = createSpotlight(png, 450, 150);
  result.writeToFile("out-spotlight.png");

  result = illinify(png);
  result.writeToFile("out-illinify.png");

  png2.readFromFile("pic2o.png");
  result = watermark(png, png2);
  result.writeToFile("out-watermark.png");
  
  return 0;
}
