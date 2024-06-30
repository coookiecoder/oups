#include <X11/Xlib.h>
#include <iostream>
#include <unistd.h>

int main(void) {
    Display* dpy = XOpenDisplay(0);
    int scr = XDefaultScreen(dpy);
    Window root_window = XRootWindow(dpy, scr);

	unsigned long long int time = 0;

    while (true) {
		XWarpPointer(dpy, None, root_window, 0, 0, 0, 0, (time % 4 == 2 || time % 4 == 3) * 100 + 3000, (time % 4 == 1 || time % 4 == 2) * 100 + 1500);
		XFlush(dpy);
		//system("xset dmps force off");
		//system("xinput disable 11");
        sleep(1);
		time++;
    }
}
