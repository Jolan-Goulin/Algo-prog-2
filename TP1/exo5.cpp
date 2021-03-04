#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot
    Point fz;
    fz.x = z.x*z.x - z.y*z.y +point.x;
    fz.y = 2*z.x*z.y + point.y;
    float ModFz = sqrt(z.x*z.x + z.y*z.y);
    if (ModFz >2){
        return n;
    }
    else if (n>0){
        return isMandelbrot(fz, n-1, point);
    }
    else{
        return 0;

    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



