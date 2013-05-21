//≤Â»Î≈≈–Ú
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n;
    int arr[20];
    void Insertion_Sort(int *,int );
    
    cout << "Input a number: ";
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
        
    Insertion_Sort(arr,n);
    
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    
    system("pause");
    return 0;
}

void Insertion_Sort(int *A,int n)
{
    int i,j,k,key;
    
    for(j=1;j<n;j++)
    {
        key = A[j];
        i = j - 1;
        while(i>=0 && A[i]>key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}
