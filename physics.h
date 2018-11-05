#ifndef __PHYSICS_H__
#define __PHYSICS_H__
#include <cstdlib>

void calculate_new_velocity(float & vx, float & vy, float x_pos, float y_pos, float click_x, float click_y){
  float x = click_x - x_pos;
  float y = click_y - y_pos;

  vx -= x;
  vy -= y;
}

void wall_hit(float & v, float & x_pos, float new_position){
  v = -v;
  x_pos = new_position;
}

#endif
