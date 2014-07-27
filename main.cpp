#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
#define MAX 1000

void bubbleSort(int[],int);
void selectionSort(int [],int);
void insertionSort(int [],int);
void qSort(int [],int);
void qSort_inplace(int [],int,int);
void swap(int &,int &);


int main()
{
	int input[MAX];
	int inNum = 0;
	cout<<"How many point will enter?"<<endl;
	cin>>inNum;
	for(int i=0;i<inNum;i++)
		cin>>input[i];
	
	//bubbleSort(input,inNum);
	//selectionSort(input,inNum);
	//insertionSort(input,inNum);
	//qSort(input,inNum);
	qSort_inplace(input,0,inNum-1);
	
	for(int i=0;i<inNum;i++)
		cout<<" "<<input[i];
	cout<<endl;

	system("pause");
		
	return 0;
}

void bubbleSort(int inArr[],int num)
{
	for(int i =num-1;i>=0;i--)
	{
		for(int j=0;j<i;j++)
		if(inArr[j]>inArr[j+1])
			swap(inArr[j],inArr[j+1]);
	}
}
void selectionSort(int inArr[],int num)
{
	for(int i=0;i<num;i++)
	{
		int min = inArr[i];
		int index = i;
		for(int j=i+1;j<num;j++)
		{
			if(min>inArr[j])
			{
				min = inArr[j];
				index = j;
			}
		}
		swap(inArr[i],inArr[index]);
	}
}

void insertionSort(int inArr[],int num)
{
	for(int i=0;i<num;i++)
	{
		for(int j=i;j>0;j--)
		{
			if(inArr[j] < inArr[j-1])
				swap(inArr[j],inArr[j-1]);
			else break;
		}
	}
}

void qSort (int inArr[],int num)
{
	int pivot =num/2,lNum=0,rNum = 0;
	int left[MAX],right[MAX];
	
	if(num <=1 )
		return;
	for(int i=0;i<num;i++)
	{
		if(i!=pivot)
		{
			if(inArr[i]<= inArr[pivot])
				left[lNum++] = inArr[i];
			else 
				right[rNum++] = inArr[i];
		}
	}

	qSort(left,lNum);
	qSort(right,rNum);

	for(int i=0;i<num;i++)
	{
		if(i<lNum)
			inArr[i] = left[i];
		else if( i == lNum)
			inArr[i] = inArr[pivot];
		else
			inArr[i] = right[i-lNum-1];
	}
}

void qSort_inplace(int inArr[],int left,int right)
{
	if(right<= left)
		return;
 	int pivotIndex = (left+right)/2;
	int pivot = inArr[pivotIndex];
	int swapIndex = left;
	swap(inArr[pivotIndex],inArr[right]);

	for(int i=left;i<right;i++)
	{
		if(inArr[i] <= pivot )
		{
			swap(inArr[i],inArr[swapIndex]);
			swapIndex++;
		}
	}

	swap(inArr[swapIndex],inArr[right]);
	qSort_inplace(inArr,left,pivotIndex-1);
	qSort_inplace(inArr,pivotIndex+1,right);
}

void swap(int &a,int &b)
{
	int tmp = a;
	a=b;
	b=tmp;
}