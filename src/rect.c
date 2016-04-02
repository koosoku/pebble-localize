#if defined(PBL_RECT)
#include <pebble.h>
#include "./ui.h"

void drawDirection(GContext *ctx, uint16_t direction, Layer *layer) {
  double eighthPi = 22.5;
  GRect bounds = layer_get_bounds(layer);
  int maxWidth = bounds.size.w;
  int maxHeight = bounds.size.h;
                                                                            
  if (direction >= 15*eighthPi || direction <= 1*eighthPi){
    graphics_fill_rect(ctx,  GRect(maxWidth/4,0,maxWidth/2,20),0,0);
  }else if (direction>= 1*eighthPi && direction <= 3*eighthPi){
    graphics_fill_rect(ctx,  GRect(maxWidth/2,0,maxWidth/2,20),0,0);
    graphics_fill_rect(ctx,  GRect(maxWidth-20,0,20,maxHeight/2),0,0);
  }else  if (direction >= 3*eighthPi && direction <= 5*eighthPi){
    graphics_fill_rect(ctx,  GRect(maxWidth-20,maxHeight/4,20,maxHeight/2),0,0);
  }else if (direction>= 5*eighthPi && direction <= 7*eighthPi){
    graphics_fill_rect(ctx,  GRect(maxWidth-20,maxHeight/2,20,maxHeight/2),0,0);
    graphics_fill_rect(ctx,  GRect(maxWidth/2,maxHeight-20,maxWidth/2,20),0,0);
  }else  if (direction >= 7*eighthPi && direction <= 9*eighthPi){
    graphics_fill_rect(ctx,  GRect(maxWidth/4,maxHeight-20,maxWidth/2,20),0,0);
  }else if (direction>= 9*eighthPi && direction <= 11*eighthPi){
    graphics_fill_rect(ctx,  GRect(0,maxHeight/2,20,maxHeight/2),0,0);
    graphics_fill_rect(ctx,  GRect(0,maxHeight-20,maxWidth/2,20),0,0);
  }else  if (direction >= 11*eighthPi && direction <= 13*eighthPi){
    graphics_fill_rect(ctx,  GRect(0,maxHeight/4,20,maxHeight/2),0,0);
  }else if (direction>= 13*eighthPi && direction <= 15*eighthPi){
    graphics_fill_rect(ctx,  GRect(0,0,20,maxHeight/2),0,0);
    graphics_fill_rect(ctx,  GRect(0,0,maxWidth/2,20),0,0);
  }    
}

#endif
