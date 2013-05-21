// Set.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"

class IntSet
{
	int element[100];
	int count;
public:
	IntSet()
	{
		count=0;
	}
	IntSet(int a[], int size)
	{
		count = size;
		for (int i = 0; i < size; i++)
		{
			element[i] = a[i];
		}
	}
	void Empty()
	{
		count=0;
	}
	bool IsEmpty()
	{
		if (count==0)
			return true;
		else
			return false;
	}
	bool IsMemberOf(int a)
	{
		bool ret;
		ret = false;
		for (int i = 0; i < count; i++)
		{
			if (a == element[i])
			{
				ret = true;
				break;
			}
		}

		return ret;
	}
	void Add(int a)
	{
		if (IsMemberOf(a))
			return;

		element[count]=a;
		count++;
	}
	void Sub(int a)
	{
		if (IsMemberOf(a))
		{
			int index;
			for (int i = 0; i < count; i++)
			{
				if (element[i]==a)
				{
					index=i;
					break;
				}
			}
			for (i = index; i < count-1; i++)
			{
				element[i]=element[i+1];
			}
			count--;
		}
	}
	bool IsEqual(IntSet A)
	{
		if (count==A.count)
		{
			for (int i = 0; i < count; i++)
			{
				if ( !IsMemberOf(A.element[i]) )
					return false;
			}

			return true;
		}
		else
			return false;
	}
	IntSet Intersection(IntSet A)
	{
		IntSet tmp;
		for (int i = 0; i < A.count; i++)
		{
			if (IsMemberOf(A.element[i]))
				tmp.Add(A.element[i]);
		}

		return tmp;
	}
	IntSet Union(IntSet A)
	{
		IntSet tmp;
		for (int i = 0; i < count; i++)
			tmp.Add(element[i]);

		for (i = 0; i < A.count; i++)
		{
			if (!IsMemberOf(A.element[i]))
				tmp.Add(A.element[i]);
		}

		return tmp;
	}
	void Print()
	{
		cout << "{";
		for (int i = 0; i < count-1; i++)
			cout << element[i] << ", ";
		if (count==0)
			cout << "}" << endl;
		else
			cout << element[i] << "}"<< endl;
	}
};

int main(int argc, char* argv[])
{
	int a[3] = {1, 2, 3};
	int b[4] = {1, 3, 4, 5};

	IntSet A(a, 3), B(b, 4);
	IntSet C;

	A.Print();
	B.Print();
	C.Print();

	C=A.Intersection(B);
	C.Print();

	C=A.Union(B);
	C.Print();

	if (C.IsEmpty())
		cout << "true" << endl;
	else
		cout << "false" << endl;

	C.Empty();
	C.Print();

	C.Add(1);
	C.Add(2);
	C.Add(3);

	if (C.IsEqual(A))
		cout << "true" << endl;
	else
		cout << "false" << endl;

	C.Sub(1);
	C.Print();
	C.Add(1);
	C.Print();
	C.Sub(3);
	C.Print();

	A.Print();
	B.Print();
	C.Print();

	B.Sub(4);
	B.Print();

	return 0;
}
