#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

class matrix
{
    int **arr,m,n;
public:
    //matrix(){};
    matrix(){m=n=0;};
    matrix(matrix &a)
    {
        m=a.m;
        n=a.n;
        arr = new int* [m];
        for(int i=0;i<m;i++)
            arr[i]=new int[n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            arr[i][j]=a.arr[i][j];
    }
    matrix(int a,int b)
    {
        m=a;
        n=b;
        arr = new int* [m];
        for(int i=0;i<m;i++)
            arr[i]=new int [n];
    }
    void getdata(void);
    void display(void);
    matrix operator+ (matrix&);
    matrix operator- (matrix&);
    matrix& operator* (int);
    matrix& operator/ (int);
};

matrix& matrix::operator/ (int k)
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        arr[i][j]/=k;
    return *this;
}

matrix& matrix::operator* (int k)
{
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        arr[i][j]*=k;
    return *this;
}

matrix matrix::operator- (matrix& a)
{
    matrix c(m,n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        c.arr[i][j]=arr[i][j]-a.arr[i][j];
    return c;
}

matrix matrix::operator+ (matrix& a)
{
    matrix c(m,n);
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        c.arr[i][j]=arr[i][j]+a.arr[i][j];
    return c;
}

void matrix::getdata(void)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"\nEnter a"<<i+1<<j+1<<" ";
            cin>>arr[i][j];
        }
    }
}

void matrix::display(void)
{
    cout<<endl;
    for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
            cout<<endl;
        }
}

main()
{
    int m,n;
    cout<<"\nEnter the dimensions of the matrix ";
    cin>>m>>n;
    matrix a(m,n);
    a.getdata();
    cout<<"\n\nPress 1 to add 2 matrix";
    cout<<"\nPress 2 to subtract 2 matrix";
    cout<<"\nPress 3 to multiply matrix with a constant ";
    cout<<"\nPress 4 to divide matrix with a constant ";
    int op;
    cin>>op;
    switch(op)
    {
    case 1:
        {
            matrix b(m,n);
            cout<<"\nEnter another matrix of same dimension ";
            b.getdata();
            matrix c;
            c=a+b;
            c.display();
            break;
        }
    case 2:
        {
            matrix b(m,n);
            cout<<"\nEnter another matrix of same dimension ";
            b.getdata();
            matrix c;
            c=a-b;
            c.display();
            break;
        }
    case 3:
        {
            int op;
            cout<<"\nEnter the number you want to multiply with ";
            cin>>op;
            a=a*op;
            a.display();
            break;
        }
    case 4:
        {
            int op;
            cout<<"\nEnter the number you want to divide with ";
            cin>>op;
            a=a/op;
            a.display();
            break;
        }
        default: cout<<"\nInvalid option";
    }

}
