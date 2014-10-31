#include<iostream>
using namespace std;
template<typename V>
class HeapSort
{
public:
	V* elem;
	int size;
public:
	HeapSort();
	HeapSort(V* arr);
	~HeapSort();
	void sizeIncr();
	void addItem(V item);
	void removeItem();
	void recurse(int ind);
	void swapEles(int p, int q);
	void print();
	void maxHeap();
};
template<typename V>
void HeapSort<V>::sizeIncr()
{
	
	
}
template<typename V>
HeapSort<V>::HeapSort()
{
	
	elem=NULL;
	size=0;
}
template<typename V>
HeapSort<V>::~HeapSort()
{
	delete[] elem;
}
template<typename V>
HeapSort<V>::HeapSort(V* arr)
{
	elem=arr;
	int i=0;
	size=0;
	while(elem[i]) {size++; i++;}
	V* newArr=new V[size-1];
	size--;
	for(int i=0;i<size;i++)
		newArr[i]=arr[i];
	elem=newArr;


	//Nachalo na 
	/*int tmp;
	int curr=0;
	while(size>=0)
	{
		maxHeap();
		//Smenqme posledniq s purviq element
		tmp=elem[size-1];
		elem[size-1]=elem[0];
		elem[0]=tmp;
		//
		size--;
	}*/
}
template<typename V>
void HeapSort<V>::maxHeap()
{
	int maxIndex=size/2;
	for(int i=maxIndex;i>=0;i--)
	{
		recurse(i);
	}

}
template<typename V>
void HeapSort<V>::recurse(int ind)
{ 	if(2*ind<size || 2*ind+1 < size)
	{
	if((2*ind+1 < size)&&(elem[ind]<elem[2*ind+1]))
	{
		swap(elem[ind],elem[2*ind+1]);
		recurse(2*ind+1);
	}
	if((2*ind+1 < size) && (elem[ind]<elem[2*ind+2]))
	{
		swap(elem[ind],elem[2*ind+2]);
		recurse(2*ind+2);
	}
	}
	else return;
}
template<typename V>
void HeapSort<V>::print()
{
	int i=0;
	while(elem[i]) 
	{
		cout<<elem[i]<<"\n";
		i++;
	}
}

int main()
{
	int arr1[] = {2,7,26,25,19,17,1,90,3,36};
	/*while(i<10)
	{
		cout<<"Vuvedete chislo"<<i<<"  "; cin>>arr1[i];
		i++;
	}*/

	HeapSort<int> hs(arr1);
	cout<<hs.size<<"\n";
	for(int i=0;i<hs.size;i++)
	{
		cout<<hs.elem[i]<<"\n";
	}
	hs.maxHeap();
	hs.print();
	cout<<hs.elem[0]<<"  "<<hs.size<<"\n";
	//hs.print();

}