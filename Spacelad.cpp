#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
constexpr auto pi = 3.1459;
using namespace std;

double gravity = 9.8;

int main() {
	al_init();
	al_init_image_addon();
	 
	ALLEGRO_BITMAP* planet = al_load_bitmap("test-planet.png");
	ALLEGRO_DISPLAY* display = al_create_display(1080, 720);
	ALLEGRO_BITMAP* player = al_load_bitmap("astronautImageSheet.png");
	ALLEGRO_TIMER* timer = al_create_timer(60.0);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();


	float x = (al_get_bitmap_width(planet)/2), y = (al_get_bitmap_height(planet)/2);
	float angle = 0;
	float radians = 0;
	int frames = 0;

	bool isRunning = true;
	while (isRunning == true) {
		ALLEGRO_EVENT event;
		al_clear_to_color(al_map_rgb(23, 23, 23));
		al_draw_bitmap_region(player, 0, 0, 36, 63, 383, 117, 0);
		al_draw_rotated_bitmap(planet, x, y, 500, 300, radians, 0);
		if (frames == 60) {
			angle += 0.1;
			radians = (angle * pi / 180);
			frames = 0;
		}
		al_flip_display();
		frames++;
	}
	al_destroy_bitmap(planet);
	al_destroy_display(display);
}