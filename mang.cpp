#include <iostream>
#include<ctime>
using namespace std;
 
int main()
{
    int so;
    cout << "Nhap so: ";
    cin >> so;
    clock_t begin,end;
    double duration;
    begin = clock();
    cout << "So dao nguoc cua " << so  << " la : ";
    for (; so != 0; so = so / 10) {
        cout << so % 10;
    }
    end = clock();
    duration = (double)(end - begin)/CLOCKS_PER_SEC;
    cout<<"\nThoi gian chay chuong trinh tren la: "<<duration<<" s ";
    return 0;
}
