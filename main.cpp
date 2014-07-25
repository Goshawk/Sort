#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
#define MAX 1000

void bubbleSort(int[],int);
void swap(int &,int &);
int main()
{
	int input[MAX];
	int inNum = 0;
	cout<<"How many point will enter?"<<endl;
	cin>>inNum;
	for(int i=0;i<inNum;i++)
		cin>>input[i];
	
	bubbleSort(input,inNum);
	
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

void swap(int &a,int &b)
{
	int tmp = a;
	a=b;
	b=tmp;
}