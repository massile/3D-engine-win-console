#include "window.h"
#include "rasterizer.h"

int main() {
	Window win(200, 4);
	Rasterizer raz(&win);
	
	while(true) {
		win.Clear(7);
		raz.DrawLine(30, 50, 40, 20);
		win.Render();
	}
	
	return 0;
}