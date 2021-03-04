#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
	// bubbleSort
    for (int j =0; j <toSort.size()-1; j++) {

        for (int i =0; i<toSort.size()-j-1; i++){
            if (toSort[i+1]<toSort[i]){
                toSort.swap(i, i+1);
            }
        }
    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
