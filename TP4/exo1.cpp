#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChild(int nodeIndex)
{
    return nodeIndex*2+1;
}

int Heap::rightChild(int nodeIndex)
{
    return nodeIndex*2+2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
    int i = heapSize;
    (*this)[i]= value;
    while(i>=0 && this->get(i)>this->get((i-1)/2)){
        this->swap(i, (i-1)/2);
    }
}

void Heap::heapify(int heapSize, int nodeIndex)
{
    int inRig = this->rightChild(nodeIndex);
    int inLef = this->leftChild(nodeIndex);
    int largest = nodeIndex;

    if (inLef < heapSize && this->get(inLef) > this->get(largest)){
        largest = inLef;
    }
    if (inRig < heapSize && this->get(inRig) > this->get(largest)){
        largest = inRig;
    }
    if (largest != nodeIndex){
        this->swap(largest, nodeIndex);
        heapify(heapSize,largest);
    }
}

void Heap::buildHeap(Array& numbers)
{
    for(int i= 0; i < numbers.size(); i++){
        this->insertHeapNode(this->size(), numbers[i]);
    }
}

void Heap::heapSort()
{
    for (int i = this->size()-1; i<=0; i--) {
        this->swap(0,i);
        this->heapify(i,0);
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
