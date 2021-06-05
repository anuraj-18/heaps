#include <iostream>

using namespace std;

#define MAX_SIZE 2999

int minHeap[MAX_SIZE];
int pos = 0;

int ceilLog2(int n)
{
	int k = 0 ;
	while(n > 0)
	{
		n = n / 2;
		k++;
	}
	return k;
}

int pow(int x, int n)
{
	int res = 1;
	while(n > 0)
	{
		res = res * x;
		n--;
	}
	return res;
}

int getLeft(int i)
{
	return 2*i + 1;
}

int getRight(int i)
{
	return 2*i + 2;
}

int parent(int i)
{
	return (i-1)/2;
}

void swap(int a, int b)
{
	int temp = minHeap[a];
	minHeap[a] = minHeap[b];
	minHeap[b] = temp;
}

void minHeapify(int i)
{
	int ind = i;
	while(ind > 0)
	{
		if(minHeap[ind] < minHeap[parent(ind)])
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
	if(pos >= MAX_SIZE)
		return false;
	
	minHeap[pos] = n;
	minHeapify(pos);
	pos++;

	return true;
}

void removeUtil(int i)
{
	int l = getLeft(i); 
    int r = getRight(i); 
    int smallest = i; 

    if (l < pos && minHeap[l] < minHeap[i]) 
        smallest = l; 
    if (r < pos && minHeap[r] < minHeap[smallest]) 
        smallest = r; 

    if (smallest != i) 
    { 
        swap(i, smallest); 
        removeUtil(smallest); 
    } 
}

void remove(int i)
{
	swap(i, pos-1);
	pos--;
	removeUtil(i);
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
			cout << minHeap[j] << " ";
		}
		cout << endl;
		k = pow(2, i + 1) - 1;
	}
}

int main()
{
	insert(1);
	insert(4);
	insert(3);
	insert(2);
	insert(7);
	showHeap();

	remove(2);
	showHeap();

	return 0;
}