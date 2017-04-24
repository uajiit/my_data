#include <linux/fb.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ()
{
	int framebuffer_device;
	int line_size, buffer_size, i;
	char *screen_memory;
	struct fb_var_screeninfo var_info;

	framebuffer_device = open ("/dev/fb0", O_RDWR);
	ioctl (framebuffer_device, FBIOGET_VSCREENINFO, &var_info);

	line_size = var_info.xres * var_info.bits_per_pixel/8;
	buffer_size = line_size * var_info.yres;

	var_info.xoffset = 0;
	var_info.yoffset = 0;
	 ioctl (framebuffer_device, FBIOPAN_DISPLAY, &var_info);
	
	screen_memory = (char *) mmap (0, buffer_size, PROT_READ | PROT_WRITE, MAP_SHARED, framebuffer_device, 0);

	for (i=0; i < buffer_size ; i++ ) {
		*(screen_memory+i) = i;
	}
	sleep(2);
	return 0;
}
