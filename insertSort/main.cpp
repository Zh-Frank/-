/************************************************
* write a fun --- bool insertSort(int a[], int maxnum, int n, int x);
* maxnum ---- the size of the array
* n ---- the number of elements that have been inserted into the array
* x ---- the element will be inserted into the array
* after insert element, keep the array from small to large
************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
bool insertSort(int a[], int maxnum, int n, int x)
{
	if (n >= maxnum)
		return false;
	if (n == 0)
		a[0] = x;
	else	//when the array is not empty
	{
		for (int pos = n - 1; pos >= 0; --pos)	//compare the element and x
		{
			if (a[pos] > x)
			{
				a[pos + 1] = a[pos];	//move the element to next
				if (0 == pos)		//if the element is the first, the fun is over
					a[0] = x;
			}
			else		//if the element is larger than x, insert x into the array at [pos + 1]
			{
				a[pos + 1] = x;
				break;
			}
		}
	}
	return true;
}
//print an array that have n elements;
void printArr(int a[], int n)
{
	for (int i = 0; i != n; ++i)
		cout << a[i] << ' ';
	cout << endl;
}
int main()
{
	int maxnum;
	cout << "please input the size of array : ";
	cin >> maxnum;
	int *arr = new int[maxnum];
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; insertSort(arr, maxnum, i, rand() & 100); ++i)
		;
	printArr(arr, maxnum);
	delete[]arr;
	system("pause");
	return 0;
}