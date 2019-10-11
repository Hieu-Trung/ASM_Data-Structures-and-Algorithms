#include<iostream>
#include<time.h>
using namespace std;
const int MAX = 100;

void nhap(int A[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<"nhap phan tu thu A["<<i<<"] = ";
		cin >> A[i];
	}
}

void xuat(int A[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<A[i]<<" ";
	}
}

void insertat(int A[], int &n, int x, int pos)
{
	if(n >= MAX)
		cout <<"full.";
	else
	{
		n = n + 1;
		for(int i = n; i > pos; i--)
			A[i] = A[i-1];
			A[pos] = x;
	}
}
void remove(int A[], int &n, int pos)
{
	if(n <= 0)
		cout <<"not.";
	else
	{
		n = n - 1;
		for(int i = pos; i < n; i++)
		A[i] = A[i+1];
	}
}
void swap( int &a, int &b)
{
	int x = a;
	a = b;
	b = x;
}
void selection(int A[], int n)
{
	int i, j, min;
	for( i = 0; i < n - 1; i++)
	{
		min = i;
		for( j = i + 1; j < n; j++)
		if (A[j] < A[min])
			min = j;
		if( min != i)
		swap(A[i], A[min]);
	}
}
void bubblesort(int A[], int n)
{
	int i, j;
	for ( int i = 0; i < n - 2; i++)
		for (int j = n - 1; j > i; j--)
			if ( A[j] < A[j - 1])
				swap(A[j], A[j - 1]);
}
void insertionsort(int A[], int n)
{
	int i, j, x;
	for (int i = 1; i < n; i++)
	{
		int x = A[i];
		int j = i;
		while (j > 0 && A[j - 1] > x)
		{
			A[j] = A[j - 1];
			j--;	
		}
		A[j] = x;
	}
}
int partition(int A[], int low, int high)
{
	int pivot = A[high];
	int l =  low;
	int r = high - 1;
	while(true)
	{
		while(l <= r && A[l] < pivot) l++;
		while(r >= l && A[r] > pivot) r--;
		if (l >= r) break;
		swap(A[l], A[r]);
		l++;
		r--;
	}
	swap(A[l], A[high]);
	return l;
}
void quicksort(int A[], int low, int high)
{
	if(low < high)
	{
		int pi = partition(A, low, high);
		quicksort(A, low, pi - 1);
		quicksort(A, pi + 1, high);
	}
}
int main(){
	int A[MAX];
	int x, f, n, pos;
	cout<<"Nhap so phan tu cua A: ";
	cin>>n;
	nhap(A, n);
	cout<<"\nPhan tu mang A sau khi nhap la: \n";
	xuat(A, n);
	cout<<"\nNhap gia tri can chen: \n";
	cin>>x;
	cout<<"\nNhap vi tri can chen: \n";
	cin>>pos;
	insertat(A, n, x, pos);
	cout<<"\nMang sau khi chen la: \n";
	xuat(A, n);
	cout<<"\nNhap vi tri can xoa: \n";
	cin>>pos;
	remove(A, n, pos);
	cout<<"mang sao khi xoa: ";
	xuat(A, n);
	
	cout<<"\n";
	clock_t start = clock();
	selection(A, n);
	cout<<"\nMang sau khi sap xep theo selection la: \n";
	xuat(A, n);
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<"\n";
	printf("Thoi gian thuc thi selection: %.5f", duration);
	
	cout<<"\n";
	start = clock();
	bubblesort(A, n);
	cout<<"\nMang sau khi sap xep theo bubble sort la: \n";
	xuat(A, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<"\n";
	printf("Thoi gian thuc thi bubble sort la: %.5f", duration);
	
	cout<<"\n";
	start = clock();
	insertionsort(A, n);
	cout<<"\nMang sau khi sap xep theo insertion sort la: \n";
	xuat(A, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<"\n";
	printf("\nThoi gian thuc thi insertion sort la: %.5f", duration);
	
	cout<<"\n";
	start =  clock();
	quicksort;
	cout<<"\nMang sau khi sap xep theo quicksort la: \n";
	xuat(A, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout<<"\n";
	printf("\nThoi gian thuc thi quicksort la: %.5f", duration);
	
}
