//∫œ≤¢≈≈–Ú 
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    void merge(int * ,int ,int ,int );
    void Merge_Sort(int * ,int ,int );
    int n;
    int arr[100];
    
    cout << "Input a number: ";
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> arr[i];
        
    Merge_Sort(arr, 1, n);
    for(int i=1;i<=n;i++)
    
        cout << arr[i] << " ";
    cout << endl;
    
    system("pause");
    return 0;
}

//∫œ≤¢ 
void merge(int *A, int p, int q, int r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int *L,*R;
    
    L=new int[n1+2];
    R=new int[n2+2];
    
    for(i=1;i<=n1+1;i++)
        L[i]=A[p+i-1];
    for(j=1;j<=n2+1;j++)
        R[j]=A[q+j];
        
    L[n1+1]=9999;//…⁄±¯≈∆ 
    R[n2+1]=9999;//…⁄±¯≈∆ 
    
    i=j=1;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
    }
    
    delete []L;
    delete []R;
}

void Merge_Sort(int *A, int p, int r)
{
    int q;
    
    if(p<r)
    {
         q=(p+r)/2;
         Merge_Sort(A,p,q);
         Merge_Sort(A,q+1,r);
         merge(A,p,q,r);
    }    
}
