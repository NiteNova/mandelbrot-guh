#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>
#include <complex>
using namespace std;


const int WIDTH = 800;
const int HEIGHT = 800;

int mandelbrot(complex<double> c);


int main() {
	al_init();
	al_init_primitives_addon();
	ALLEGRO_DISPLAY* display = al_create_display(WIDTH, HEIGHT);

	double zoom = 2600;

	complex <double> c;
	int num;

	al_lock_bitmap(al_get_target_bitmap(), al_get_display_format(display), al_get_display_flags(display));

	for (double i = -2; i < 2; i += (1 / zoom))
		for (double j = -2; j < 2; j += (1 / zoom)) {
			if (i * zoom + 2300 > 0 && j * zoom - 100 > 0 && i * zoom + 2300 < WIDTH && j * zoom - 710 < HEIGHT) {
				c = complex<double>(i, j);
				num = mandelbrot(c);

				al_put_pixel(i * zoom + 2300, j * zoom - 710, al_map_rgb(num * 2, num / 5, num));
			}
		}
	al_unlock_bitmap(al_get_target_bitmap());
	al_flip_display();
	system("pause");
	al_destroy_display(display);
};

int mandelbrot(complex<double> c) {
	complex<double> z = 0;
	double counter = 0;
	while (abs(z) < 2 and counter < 80) {
		z = z * z + c;
		counter++;
		
	}
	return counter;
};
