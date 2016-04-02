#include <pebble.h>
#include <stdio.h>
#include "./ui.h"

static Window *window;
static TextLayer *text_layer;
static Layer *s_layer;

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Select");
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Up");
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Down");
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void update_display(Layer *layer, GContext *ctx) {
  printf("we in update display");
  graphics_context_set_fill_color(ctx,GColorTiffanyBlue);
  drawDirection(ctx, 320, layer);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect windowBounds = layer_get_bounds(window_layer);

  int distance = 1500;
  static char text [20];
  text_layer = text_layer_create(GRect(0, 72, windowBounds.size.w, 20));
  if(distance < 1000){
    snprintf(text,sizeof(text), "%d M",distance);
  }else{
    snprintf(text,sizeof(text), "%d.%d KM",distance/1000 , (distance%1000)/10); // divide by 10 to use only two decimal digits
  }
  text_layer_set_text(text_layer, text);
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
  
  s_layer = layer_create(windowBounds);
  layer_set_update_proc(s_layer, update_display);
  layer_add_child(window_layer, s_layer);
  
  layer_mark_dirty(s_layer);
}

static void window_unload(Window *window) {
  text_layer_destroy(text_layer);
}

static void init(void) {
  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}