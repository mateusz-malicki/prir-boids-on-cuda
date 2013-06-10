
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Structures.h"
#include "Boid.h"
#include "Frame.h"
#include "Parser.h"

using namespace std; 

const float FPS = 30;
const int xRes = 800;
const int yRes = 800;


void drawTriangle(Boid boid, ALLEGRO_COLOR color, float scale, bool range)
{
  float xc = boid.position.x*scale;
  float yc = boid.position.y*scale;

  float vx = boid.velocityForce.x;
  float vy = boid.velocityForce.y;

  float s = sqrt(vx*vx + vy*vy);

  float vxNorm = vx/s;
  float vyNorm = vy/s;

  int len = 8;
  
  int x1 = xc+vxNorm*len;
  int y1 = yc+vyNorm*len;

  int midx = xc-vxNorm*len*0.5;
  int midy = yc-vyNorm*len*0.5;

  int x2 = midx-vyNorm*len*0.5;
  int y2 = midy+vxNorm*len*0.5;

  int x3 = midx+vyNorm*len*0.5;
  int y3 = midy-vxNorm*len*0.5;

           al_draw_filled_triangle(x1,y1, x2,y2, x3, y3, color);

  ALLEGRO_COLOR blue_color = al_map_rgb(22,22,184);
  if(range) al_draw_circle(xc,yc, 32, blue_color, 2);
  
}

int initAllegro(ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* event_queue, ALLEGRO_TIMER* timer)
{
   //ALLEGRO_DISPLAY *display = NULL;
   //ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   //ALLEGRO_TIMER *timer = NULL;


   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }

   display = al_create_display(xRes, yRes);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }

   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }

   //al_register_event_source(event_queue, al_get_display_event_source(display));

   //al_register_event_source(event_queue, al_get_timer_event_source(timer));

   al_clear_to_color(al_map_rgb(0,0,0));

   al_flip_display();

   al_init_primitives_addon();
   
   return 0;
}
 
int main(int argc, char** argv)
{
 
   bool redraw = true;
   
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;
   //bool redraw = true;
   
   //int width, height;
   //float scale = 1.0;

   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }
 
   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }
 
   display = al_create_display(xRes, yRes);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }
 
   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
 
   al_register_event_source(event_queue, al_get_display_event_source(display));
 
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
 
   al_clear_to_color(al_map_rgb(0,0,0));
 
   al_flip_display();

   al_init_primitives_addon();
   al_start_timer(timer);
 /*
   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;

   initAllegro(display, event_queue, timer);
   al_register_event_source(event_queue, al_get_display_event_source(display));

   al_register_event_source(event_queue, al_get_timer_event_source(timer));
*/

   cout <<"start\n";
   string filename(argv[1]);
   bool debug = false;
   int  debugIndex = 0;

   vector<string> arguments;
   for(int i = 2; i < argc; i++)
   {
     arguments.push_back(string(argv[i]));
     if(arguments.back() =="-debug") 
     {
       debug = true;
     }
   }

   for(int i = 0; i < arguments.size(); i++)  
   {
     if(arguments[i] == "-debug")
     {
       debugIndex = atoi(arguments[i+1].c_str());
     }
   }


   int  width, height;
   vector<Frame> frames = Parser::GetInstance().Deserialize(filename, width, height);
   float scale = (1.0*xRes)/width;
   //cout << "dziwne"<<frames.size()<<endl;
   int index = 0;

   while(1)
   {
      ALLEGRO_EVENT ev;
      al_wait_for_event(event_queue, &ev);
 
      if(ev.type == ALLEGRO_EVENT_TIMER) {
         //cout << "redraw\n";
         redraw = true;
      }
      else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
         break;
      }
 
      if(redraw && al_is_event_queue_empty(event_queue)) {
         redraw = false;
         al_clear_to_color(al_map_rgb(0,0,0));     

         for(int i = 0; i < frames[index].boids.size(); i++)
         {
           ALLEGRO_COLOR color = al_map_rgb(184,22,22);
           if(debug && i==debugIndex)
           { 
             color = al_map_rgb(22,184,22);
             drawTriangle(frames[index].boids[i], color, scale, true);
           }
           else if(debug)
           {
             bool found = false;
             for(int j = 0; j < frames[index].boids[debugIndex].neighbours.size(); j++)
             {
               if(j == i)
               {
                 color = al_map_rgb(184,184,22);
                 drawTriangle(frames[index].boids[i], color, scale, false);
                 found = true;
                 break;
               }
             }
             if(!found) drawTriangle(frames[index].boids[i], color, scale, false);
           }
           else drawTriangle(frames[index].boids[i], color, scale, false);
         }
         if(index<frames.size()-1)index++;
         else
         {
           cout << "finito!!!\n";
           break;
         }
         al_flip_display();
      }
   }
 
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
 
   return 0;
}
