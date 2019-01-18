#include "window.h"

Window::Window(short dimension, short fontSize):
	dimension(dimension),
	console(GetStdHandle(STD_OUTPUT_HANDLE)),
	buffer(new CHAR_INFO[dimension * dimension])
{
	SetFontSize(fontSize);	
	SetWindowDimension(dimension);
}

void Window::SetFontSize(short size) {
	CONSOLE_FONT_INFOEX consoleInfo = {};
	consoleInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	consoleInfo.dwFontSize.X = size;
	consoleInfo.dwFontSize.Y = size;
	SetCurrentConsoleFontEx(console, false, &consoleInfo);
}

void Window::SetWindowDimension(short dimension) {
	bufferSize = { dimension, dimension };
	winRect = { 0, 0, short(dimension - 1), short(dimension - 1) };
	SetConsoleScreenBufferSize(console, bufferSize);
	SetConsoleWindowInfo(console, true, &winRect); 
}

void Window::Clear(short color) {
	for(int x=0; x < dimension; x++) {
		for(int y=0; y < dimension; y++) {
			DrawPixel(x, y, color);
		}
	}
}

void Window::DrawPixel(short x, short y, short color) {
	CHAR_INFO& pixel = buffer[y * dimension + x];
	pixel.Char.UnicodeChar = 0xFF;
	pixel.Attributes = color * 17;
}

void Window::Render() {
	WriteConsoleOutput(console, buffer, bufferSize, { 0, 0 }, &winRect);
}
