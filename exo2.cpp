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

void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{

    int n = binarySearch(array, toSearch);
    if (n==-1){
        indexMax = -1;
        indexMin = -1;
    }
    else {
        indexMax = n;
        indexMin = n;
        while (indexMax < array.size()-1 && array[indexMax+1]== toSearch){
            indexMax++;
        }
        while (indexMin > 0 && array[indexMin-1]== toSearch ) {
            indexMax--;
        }
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
