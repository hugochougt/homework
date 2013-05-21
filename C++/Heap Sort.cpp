#include<iostream>
#include<cstdio>
using namespace std;

int heap_size;
int len;

inline int Left(int i)
{
    return 2*i;
}

inline int Right(int i)
{
    return 2*i+1;
}

void Max_Heapity(int *A, int i)
{
    int l = Left(i);
    int r = Right(i);
    int largest;
    
    if(l<=heap_size && A[l]>A[i])
        largest = l;
    else
        largest = i;
    
    if(r<=heap_size && A[r]>A[largest])
        largest = r;
    
    if(largest != i)
    {
        int t = A[i];
        A[i] = A[largest];
        A[largest] = t;
        Max_Heapity(A,largest);
    }
}

void Built_Max_Heap(int *A)
{
    heap_size=len;
    for(int i=len/2;i>0;i--)
    {
        Max_Heapity(A,i);
    }
}

void Heap_Sort(int *A)
{
    int tmp;
    Built_Max_Heap(A);
    for(int i=len;i>1;i--)
    {
        tmp = A[1];
        A[1]=A[i];
        A[i]=tmp;
        heap_size--;
        Max_Heapity(A,1);
    }
}

int main()
{
    int i;
    int arr[20];
    
    cout << "Input a number: ";
    cin >> len;
    
    for(i=1;i<=len;i++)
        cin >> arr[i];
    
    Heap_Sort(arr);
    
    for(i=1;i<=len;i++)
        cout << arr[i] << " ";
    cout << endl;
    
    system("pause");
    return 0;
}
