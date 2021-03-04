#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split
    if (size > 1){
        int pivot = toSort[0];
        for (int i =1 ;i < size; i++) {
            if (toSort[i]>pivot){
                greaterArray.insert(greaterSize, toSort[i]);
                greaterSize++;
            }
            else {
                lowerArray.insert(lowerSize, toSort[i]);
                lowerSize++;
            }
        }
        // recursiv sort of lowerArray and greaterArray
        recursivQuickSort(lowerArray, lowerSize);
        recursivQuickSort(greaterArray, greaterSize);
        // merge
        int i =0;
        while (i < lowerSize){
            toSort[i]= lowerArray[i];
            i++;
        }
        toSort[i] = pivot;
        i++;
        int j =0;
        while (j < greaterSize) {
            toSort[j+i]= greaterArray[j];
            j++;
        }
    }
}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
