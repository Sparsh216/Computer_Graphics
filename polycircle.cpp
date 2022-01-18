#include <graphics.h>
// driver code
int main()
{
  // gm is Graphics mode which is
  // a computer display mode that
  // generates image using pixels.
  // DETECT is a macro defined in
  // "graphics.h" header file
  int gd = DETECT, gm;
  // coordinates of polygon
  int arr[] = {145,120,180,180,260,180,280,120,260,60,180,60,145,120};
  // initgraph initializes the

  // graphics system by loading a

  // graphics driver from disk

  initgraph(&gd, &gm, "");
  // drawpoly function
  drawpoly(7, arr);
  circle(216,120,60);
  getch();
  // closegraph function closes the
  // graphics mode and deallocates
  // all memory allocated by
  // graphics system .
  closegraph();
  return 0;
}
