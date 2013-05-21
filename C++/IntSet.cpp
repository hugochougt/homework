#include<iostream>
using namespace std;

class IntSet
{
    int element[100];
    int count;
public:
    IntSet(int *a, int size)
    {
        count = size;
        for(int i = 0; i<size; i++)
             element[i] = a[i];
    }
    IntSet()
    {count = 0;}
    void Empty()
    {count = 0;}
    bool IsEmpty()
    {
        if(count == 0)
            return true;
        else
            return false;    
    }
    bool IsMemberOf(int tar)
    {
        for(int i = 0; i<count; i++)
            if(tar == element[i])
                return true;
        return false;
    }
    void Add(int a)
    {
        if(IsMemberOf(a))
            return ;
        element[count] = a;
        count++;    
    }
    void Sub(int a)
    {
        if(IsMemberOf(a))
        {
            int index;
            for(int i = 0; i<count; i++)
            {
                if(a == element[i])
                {
                    index = i;
                    break;    
                }
            }
            element[index] = element[count-1];
            count--;
        }
    }
    bool IsEqual(IntSet A)
    {
        if(count == A.count)
        {
            for(int i = 0; i<count; i++)
                if(!IsMemberOf(A.element[i]))
                    return false;
            return true;
        }
        else 
            return false;
    }
    IntSet Intersection(IntSet A)
    {
        IntSet temp;
        for(int i = 0; i<A.count; i++)
        {
            if(IsMemberOf(A.element[i]))
                temp.Add(A.element[i]);
        }
        
        return temp;
    }
    IntSet Union(IntSet A)
    {
        IntSet temp;
        for(int i = 0; i<count; i++)
            temp.Add(element[i]);
            
        for(int i = 0; i<A.count; i++)
            if(!temp.IsMemberOf(A.element[i]))
                temp.Add(A.element[i]);
                
        return temp;
    }
    void print()
    {
        cout << "( " ;
        for(int i = 0; i<count-1; i++)
            cout << element[i] << ", ";
        if(0 == count)
            cout << " )";
        else
            cout << element[count-1] << " )";
        cout << endl;
    }
};
int main()
{
    int a[4] = {12, 83, 9, 0},b[3] = {84, 12, 0};
    IntSet A(a, 4), B(b, 3);
    IntSet C;
    
    A.print();
    B.print();
    C.print();
    
    C=A.Intersection(B);
	C.print();

	C=A.Union(B);
	C.print();
    
    C.Sub(9);
    C.print();
    
    C.Add(1);
	C.Add(2);
	C.Add(3);
	C.print();
    system("pause");
    return 0;    
}
