#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;
const int Max = 100000;
int Timerun(clock_t begin, clock_t end)
{
	begin = clock();
	end = clock();
	return double(end - begin)/CLOCKS_PER_SEC;
}

void Taodayngaunhien(int *a, int n)
{
	int i,m,min = 1, max = 100000, temp;
	srand(time(NULL));
	for(i=1;i<= max;i++)
	{
		do
		{
			m = min + rand()%( max - min + 1);
		}while( m == i);
		temp = a[i];
		a[i] = a[m];
		a[m] = temp;
	}
	cout<<a[i];
}

int main()
{
	int n = Max;
	int *a = new int[n];
	clock_t t1, t2;
	t1 = clock();
	Taodayngaunhien(a,n);
	t2 = clock();
	cout<<"\nThoi gian chay cuong trinh la : "<<Timerun(t1,t2)<<" s ";
	delete []a;
	return 0;
}
