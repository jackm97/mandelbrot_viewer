#include "mandelbrot.h"
#include <cmath>
#include <vector>
#include <string>

mandelbrot::mandelbrot(int H, int W, std::string center[], float zoom, int max_iter): 
	height(H), width(W), 
  zoom(zoom), max_iter(max_iter), 
  GPU_object(applyIterGPU(height,width,max_iter))
{
  centerx = center[0];
  centery = center[1];
	resetValues();
}

void mandelbrot::changeCenter(std::string new_center[]){
	centerx = new_center[0];
  centery = new_center[1];
	isCalc = false;
}

void mandelbrot::changeZoom(float new_zoom){
	zoom = new_zoom;
	isCalc = false;
}

void mandelbrot::changeMaxIter(size_t new_max_iter){
	max_iter = new_max_iter;
  GPU_object.setMaxIter(max_iter);
	isCalc = false;
}

cudaGraphicsResource_t* mandelbrot::getReferencePointer(){
	return GPU_object.getReferencePointer();
}

void mandelbrot::registerTexture(GLuint image){
	GPU_object.registerTextureResource(image);
}

void mandelbrot::getImage(){
	if (!isCalc){
		resetValues();
		GPU_object.GPU_PAR_FOR();
		isCalc=true;
	}
}

void mandelbrot::resetValues(){	
  GPU_object.SET_COORD_VALS(centerx,centery,zoom);	
}
