// 3_4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream.h"

class CFltArray
{
	float *data;
	int size;
public:
	CFltArray(int s, float a[])
	{
		size = s;
		data = new float[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = a[i];
		}
	}
	~CFltArray()
	{
		delete []data;
	}
	int Size()
	{
		return size;
	}
	void Resize(int s)
	{
		/*
		size = s;
		delete []data;
		data = new float[size];
		*/
		if (s > size)
		{
			float *p;
			p = new float[s];
			for (int i = 0; i < size; i++)
			{
				p[i] = data[i];
			}

			delete []data;
			data = p;
			size = s;
		}
		else
		{
			float *p;
			p = new float[s];
			for (int i = 0; i < s; i++)
				p[i] = data[i];

			delete []data;
			data = p;
			size = s;
		}
	}

	float &operator[](int index)
	{
		if (index >= size || index < 0)
		{
			cout << "Out of bound" << endl;
			return data[0];
		}
		
		return data[index];
	}

	CFltArray(const CFltArray &ary)
	{
		size = ary.size;
		data = new float[size];
		for (int i = 0; i < size; i++)
			data[i] = ary.data[i];
	}

	CFltArray operator=(CFltArray &ary)
	{
		if (this != &ary)
		{
			delete []data;

			size = ary.size;
			data = new float[size];
			for (int i = 0; i < size; i++)
				data[i] = ary.data[i];
		}

		return *this;
	}
};


int main(int argc, char* argv[])
{
	float a[5] = {float(1.1), float(2.2) , float(3.3), float(4.4), float(5.5)};

	CFltArray ary(5, a);

	ary.Resize(6);

	ary[0] = float(12.3);

	CFltArray ary2 = ary;
	CFltArray ary3(ary);

	ary3 = ary2;

	return 0;
}
