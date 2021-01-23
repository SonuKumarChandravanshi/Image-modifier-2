#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* 

Name: Sonu Kumar
Email: iamsonukumarchandravanshi@gmail.com

 */

using uiuc::PNG;
using uiuc::HSLAPixel;

PNG grayscale(PNG image) {
  
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      pixel.s = 0;
    }
  }

  return image;
}



PNG createSpotlight(PNG image, int centerX, int centerY) {
	
	for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

    int a= sqrt((x*x) + (y*y));
	if( a>160)
	{
		image.l=(0.2*(image.l));
	}
	else
	{
		image.l=((1-0.05)*a*(image.l));
	}
	 
    }
  }

  return image;
  
}
 

PNG illinify(PNG image) {
	
	for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
		if(abs((pixel.h-11.0))<abs((pixel.h-216.0)))
		{
			pixel.h=11.0;
		}
		else
		pixel.h=216.0;
    }
  }

  return image;
}
 


PNG watermark(PNG firstImage, PNG secondImage) {
	
	for (unsigned x = 0; x < firstImage.width(); x++) {
    for (unsigned y = 0; y < firstImage.height(); y++) {
      HSLAPixel & pixel = firstImage.getPixel(x, y);
      HSLAPixel & pixel2 = secondImage.getPixel(x, y);
		
		if(pixel2.l==1.0)
		{
			if((1-pixel.l)<2.0)
			{
				pixel.l=1.0;
			}
			
			else
			{
				pixel.l=pixel.l+0.2;
			}
		}
		
    }
  }
  return firstImage;
}
