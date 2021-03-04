#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
    if (origin.size() > 1){
        // initialisation
        Array& first = w->newArray(origin.size()/2);
        Array& second = w->newArray(origin.size()-first.size());

        // split
        for(int i =0; i < first.size(); i++){
            first[i] = origin[i];
        }
        for (int j = 0; j< second.size(); j++) {
            second[j] = origin[j+ first.size()];
        }
        // recursiv splitAndMerge of lowerArray and greaterArray
        splitAndMerge(first);
        splitAndMerge(second);
        // merge
        merge(first, second,origin);
    }
}

void merge(Array& first, Array& second, Array& result)
{
    int i = 0;
    int j = 0;
    int size = 0;
    while( i< first.size()  && j< second.size()){
        if (first[i] < second[j]){
            result.insert(size, first[i]);
            i++;
            size++;
        }
            else{
                result.insert(size, second[j]);
                j++;
                size++;
            }
        }
    while( i< first.size()){
        result.insert(size, first[i]);
        i++;
        size++;
    }
    while ( j< second.size()){
        result.insert(size, second[j]);
        j++;
        size++;
    }
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
