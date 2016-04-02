#if defined(PBL_ROUND)
#include <pebble.h>
#include "./ui.h"
void drawDirection(GContext *ctx, uint16_t direction, Layer *layer) {
    printf("we in draw arc");
    uint16_t startAngle = direction - 22;
    uint16_t endAngle = direction + 22;
    graphics_fill_radial(ctx, grect_inset(layer_get_bounds(layer),GEdgeInsets(0)), GOvalScaleModeFitCircle, 20, DEG_TO_TRIGANGLE(startAngle), DEG_TO_TRIGANGLE(endAngle));
}
#endif