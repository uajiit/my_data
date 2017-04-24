#include<linux/fb.h>
#include<stdio.h>
#include<stdint.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/ioctl.h>
#include<graphics.h>
void draw_line(int x1, int y1, int x2, int y2, uint32_t pixel)
{
int i,dx,dy,sdx,sdy,dxabs,dyabs,x,y,px,py;
dx=x2-x1;
//Delta x
dy=y2-y1;
//Delta y
dxabs=abs(dx);
//Absolute delta
dyabs=abs(dy);
//Absolute delta
sdx=(dx>0)?1:-1; //signum function
sdy=(dy>0)?1:-1; //signum function
x=dyabs>>1;
y=dxabs>>1;
px=x1;

py=y1;
if (dxabs>=dyabs)
{
for(i=0;i<dxabs;i++)
{
y+=dyabs;
if (y>=dxabs)
{
y-=dxabs;
py+=sdy;
}
px+=sdx;
draw(px,py,pixel);
}
}
else
{
for(i=0;i<dyabs;i++)
{
x+=dxabs;
if (x>=dyabs)
{
x-=dyabs;
px+=sdx;
}
py+=sdy;
draw(px,py,pixel);
}
}
}


uint32_t pixel_color(uint8_t r, uint8_t g, uint8_t b, struct fb_var_screeninfo *vinfo)
{
return (r<<vinfo->red.offset) | (g<<vinfo->green.offset) | (b<<vinfo->blue.offset);
}
int main()
{
struct fb_fix_screeninfo finfo;
struct fb_var_screeninfo vinfo;
int fb_fd = open("/dev/fb0",O_RDWR);
//Get variable screen information
ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
vinfo.grayscale=0;
vinfo.bits_per_pixel=32;
ioctl(fb_fd, FBIOPUT_VSCREENINFO, &vinfo);
ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo);
long screensize = vinfo.yres_virtual * finfo.line_length;
uint8_t *fbp = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, (off_t)0);
int x,y;

draw_line(20,30, 10, 40, pixel_color(0xFF,0x00,0xFF, &vinfo));


#if 0
for (x=200;x<400;x++)
for (y=200;y<300;y++)
{
long location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
*((uint32_t*)(fbp + location)) = pixel_color(0xFF,0x00,0xFF, &vinfo);
}
#endif
return 0;
}
