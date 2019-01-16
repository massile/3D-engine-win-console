#pragma once
#include <windows.h>

class Window {
private:
	HANDLE console;
	CHAR_INFO* buffer;
	short dimension;
	COORD bufferSize;
	SMALL_RECT winRect;
public:
	Window(short dimension, short fontSize);
	void DrawPixel(short x, short y, short color = 255);
	void Clear(short color = 0);
	void Render();
private:
	void SetFontSize(short size);
	void SetWindowDimension(short dimension);
};

extern "C" {
	struct CONSOLE_FONT_INFOEX {
	  ULONG cbSize;
	  DWORD nFont;
	  COORD dwFontSize;
	  UINT  FontFamily;
	  UINT  FontWeight;
	  WCHAR FaceName[LF_FACESIZE];
	};

	BOOL WINAPI SetCurrentConsoleFontEx(
	  HANDLE               hConsoleOutput,
	  BOOL                 bMaximumWindow,
	  CONSOLE_FONT_INFOEX* lpConsoleCurrentFontEx
	);
}