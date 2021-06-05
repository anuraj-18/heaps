#include <iostream>

using namespace std;

#define MAX_SIZE 3000

int maxHeap[MAX_SIZE];
int pos;

void init()
{
	pos = 0;
}

int pow(int x, int n)
{
	int res = 1;
	while(n > 0)
	{
		res *= x;
		n--;
	}
	return res;
}

int ceilLog2(int n)
{
	int res = 0;
	while(n > 0)
	{
		n = n /2;
		res++;		
	}
	return res;
}

void swap(int i, int j)
{
	int temp = maxHeap[i];
	maxHeap[i] = maxHeap[j];
	maxHeap[j] = temp;
}

int getRight(int i)
{
	return 2 * (i+1);
}

int getLeft(int i)
{
	return 2*i + 1;
}

int parent(int i)
{
	return (i-1)/2;
}

void maxHeapify(int i)
{
	int ind = i;

	while(ind>0)
	{
		if(maxHeap[ind] > maxHeap[parent(ind)])
		{
			swap(ind, parent(ind));
			ind = parent(ind);
		}
		else
			break;
	}
}

bool insert(int n)
{
	if (pos >= MAX_SIZE)
		return false;

	maxHeap[pos] = n;
	maxHeapify(pos);
	pos++;

	return true;
}

void removeUtil(int i)
{
	int l = getLeft(i);
	int r = getRight(i);
	int largest = i;

	if(l < pos && maxHeap[l] > maxHeap[largest])
		largest = l;
	if(r < pos && maxHeap[r] > maxHeap[largest])
		largest = r;
	if(largest != i)
	{
		swap(i, largest);
		removeUtil(largest);
	}
}

bool remove(int i)
{
	if(i >= pos)
		return false;

	swap(i, pos-1);
	pos--;
	removeUtil(i);

	return true;
}

int getMax()
{
	if(pos == 0)
		return -1000;
	return maxHeap[0];
}

void showHeap()
{
	if(pos == 0)
	{
		cout << "-" << endl;
		return;
	}
	int n = ceilLog2(pos);
	int k = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = k; j < k + pow(2, i) && j < pos; j++)
		{
			cout << maxHeap[j] << " ";
		}
		cout << endl;
		k = pow(2, i + 1) - 1;
	}
}

int main()
{
	insert(1);
	insert(3);
	insert(5);
	insert(7);
	showHeap();

	remove(0);
	showHeap();
	return 0;
}