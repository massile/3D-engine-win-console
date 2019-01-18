#include "window.h"
#include "math.h"
#include "rasterizer.h"

int main() {
	int dim = 200;

	Window win(dim, 4);
	Rasterizer raz(&win);
	
	while(true) {
		win.Clear();

		for(int x=0; x < dim; x++) {
			int color = float(x) / float(dim) * 15;
			for (int y = 0; y < dim; y++) {
				win.DrawPixel(x, y, color);		
			}
		}
		
		win.Render();
	}
	
	return 0;
}