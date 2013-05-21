#include<iostream>
using namespace std;
int binary_search(int p[],int n,int tar)
{
    int r,l,mid;
    r=n-1;l=0;
    while(l<=r)
    {
        mid = (r+l)/2;
        if(tar==p[mid])
            return mid;
        else if(p[mid]<tar)
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}
int main()
{
    int n,*p,i,tar,mid;
    while(cin >> n)
    {
        cout << "Input the number: ";
        p = new int[n];
        for(i=0;i<n;i++)
            cin >> p[i];
        cout << "Input the target: ";
        cin >> tar;
        mid=binary_search(p, n, tar);
        if(mid>=0)
            printf("%d\n",p[mid]);
        else
            printf("Can't find target.\n");
    }
    return 0;
}
