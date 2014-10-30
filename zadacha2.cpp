#include<iostream>
#include<vector>
#include"stdlib.h"
using namespace std;
void merge(int* arr, int leftSize,int size)
{
	vector<int> tmp;
	int left=0;
	int right=leftSize;
	while(left<leftSize || right<size)
	{
		if(left<leftSize && right<size)
		{
			if(arr[left]<arr[right])
			{
				tmp.push_back(arr[left]);
				left++;
			}
			else
			
				tmp.push_back(arr[right]);
				right++;
			}
		}
		else if(left<leftSize)
		{
			tmp.push_back(arr[left]);
			left++;
		}
		else
			{tmp.push_back(arr[right]);right++;}

	}
	for(int i =0;i<size;i++)
		arr[i]=tmp[i];
}
void mergeSort(int* arr, int size)
{
	if(size==1) return;
	if(size==2)
	{
		if(arr[0]>arr[1]) 
			{swap(arr[0],arr[1]);
				return;}
		else return;
	}
	mergeSort(arr,size/2);
	mergeSort(arr+size/2, (size+1)/2);
	merge(arr,size/2,size);
}
int minVal(int* arr,int size)
{
mergeSort(arr,size);
int maxCnt=0;
int minVal=0;
	int tmpCnt=1;
int tmpVal=0;
	for(int i=0;i<6;i++)
	{
	if(arr[i]==arr[i+1]) {tmpVal=arr[i];tmpCnt++;}
	else
	{
	if(tmpCnt>maxCnt) {maxCnt=tmpCnt; minVal=tmpVal;tmpCnt=1;}
	}
	}
return minVal;
}
int main()
{
	int arr[20];
	for(int i=0;i<7;i++)
		arr[i]=rand()%5;
	for(int i=0;i<7;i++)
		cout<<arr[i]<<"  ";
	cout<<"\n";
	mergeSort(arr,7);
	for(int i=0;i<7;i++)
		cout<<arr[i]<<"  ";
	cout<<minVal(arr,7)<<"\n";

}
