#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <stdio.h>

#define MAX 100
#define true 1
#define false 0

using namespace std;


struct Array
{
    int data[MAX];
    int n;
    Array()
    {
        for(int i=0;i<n;i++)
        {
            data[i]=-1;
        }
    }
};

class FIFO
{
protected:

    int longest;
    Array input;
    int k;
    int FreeSpace;

    Array Result[MAX];
    Array Prev;

public:

    FIFO()
    {
        longest=0;

        inputFile();
        FreeSpace=0;
    }

    void inputFile()
    {
        FILE *f;
        char *path;
        cout<<"Nhap duong dan cua file: ";
        gets(path);
        f = fopen(path,"rt");
        fscanf(f,"%d",&input.n);
        fscanf(f,"%d",&k);
        for(int i=0;i<input.n;i++)
        {
            fscanf(f,"%d",&input.data[i]);
        }
        fclose(f);
    }

    void Input ()
    {
        cout<<"\nNhap so luong khung trang n= ";
        cin>>input.n;
        cout<<"\nNhap k= ";
        cin>>k;

        for(int i=0;i<input.n;i++)
        {
            cout<<"\nNhap phan tu thu "<<i+1<<" = ";
            cin>>input.data[i];
        }

    }

    void doOverlay()
    {
        int count = 0;

        while (count < input.n)
        {
            if(FreeSpace<k)// con cho trong
            {
                if(isExist(Prev,input.data[count]))
                {
                    Result[count] = Prev;
                    count++;
                }
                else
                {
                    Prev.n = k;

                    Prev.data[FreeSpace] = input.data[count];
                    FreeSpace++;

                    Result[count] = Prev;

                    count++;
                }
            }
            else
            {
                if(isExist(Prev,input.data[count]))
                {
                    Result[count] = Prev;
                    count++;
                }
                else
                {
                    Prev.data[longest] = input.data[count];
                    increaseLongest();

                    Result[count] = Prev;

                    count++;
                }
            }
        }
    }

    void increaseLongest()
    {
        longest++;

        if(longest == k)
        {
            longest = 0;
        }

    }

    int isExist(Array Prev, int T)
    {
        for(int i=0;i< Prev.n;i++)
        {
            if(T == Prev.data[i])
            {
                return true;
            }
        }
        return false;
    }

    void Output()
    {
        for(int i=0;i<input.n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if (Result[i].data[j] == -1)
                {
                    cout<<" ";
                    continue;
                }
                cout<<Result[i].data[j]<<" ";
            }
            cout<<endl;
        }
    }

    void OutputInput()
    {
        for(int i=0;i<input.n;i++)
        {
            cout<<input.data[i]<<" ";
        }
        cout<<endl<<endl;
    }

};

class TLU: public FIFO//The Least Using: wana know in Vietnamese? -> Google translate =.=!
{
public:

    int findTLU (Array Prev,int count)
    {
        int Min=0;
        int min = 0;
        int T=0;

        for(int i=count;i<input.n;i++ )
        {
            if(Prev.data[T] == input.data[i])
            {
                min++;
            }
        }
        T++;

        while(T<Prev.n)
        {
            int temp =0;
            for(int i=count;i<input.n;i++ )
            {
                if(Prev.data[T] == input.data[i])
                {
                    temp++;
                }
            }
            if(min > temp)
            {
                min = temp;
                Min= T;
            }
            T++;
        }

        return Min;
    }

    void doOverlay()
    {
        int count = 0;

        while (count < input.n)
        {
            if(FreeSpace<k)// con cho trong
            {
                if(isExist(Prev,input.data[count]))
                {
                    Result[count] = Prev;
                    count++;
                }
                else
                {
                    Prev.n = k;

                    Prev.data[FreeSpace] = input.data[count];
                    FreeSpace++;

                    Result[count] = Prev;

                    count++;
                }
            }
            else
            {
                if(isExist(Prev,input.data[count]))
                {
                    Result[count] = Prev;
                    count++;
                }
                else
                {
                    Prev.data[findTLU(Prev,count)] = input.data[count];
                    //increaseLongest();

                    Result[count] = Prev;

                    count++;
                }
            }
        }
    }

};

int main()
{
  

    TLU a;

   //    FIFO a;


    a.doOverlay();
    a.Output();

    getch();
} 
