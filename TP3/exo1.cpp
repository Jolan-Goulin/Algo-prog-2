#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

int binarySearch(Array& array, int toSearch)
{
    int size = array.size();
    int left = 0;
    int right = size;
    while(left < right){
        int mid = (left + right)/2;
        if (array[mid] == toSearch){
            return mid;
        }
        else if (array[mid]<toSearch) {
            left = mid+1;
        }
        else if (array[mid]>toSearch) {
            right = mid;
        }
    }
	return -1;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchWindow(binarySearch);
	w->show();

	return a.exec();
}
