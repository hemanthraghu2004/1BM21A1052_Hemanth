#include<iostream>
using namespace std;
class rec
{
    public:

        int TOH(int n,int a,int b,int c);
        int GCD(int m,int n);
        int fib(int x);
        int fact(int x);
};

int rec::TOH(int n,int a, int b, int c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        cout<<"\nMoving disc from tower ";
        cout<<a<<"\t"<<c;
        TOH(n-1,b,a,c);
    }
}

int rec::GCD(int m,int n)
{
    if(n==0)
            return m;
    return GCD(n,m%n);
}
int rec::fib(int x)
{
    if(x==1)
        return 0;
    if(x==2)
        return 1;
    return (fib(x-1)+fib(x-2));
}
int rec:: fact(int x)
{
    if(x==0||x==1)
        return 1;
    return x*fact(x-1);
}
int main()
{
    rec r;
    int choice,a=1,b=2,c=3,x,m,n,f;
    while(1)
    {
        cout<<"\nRecursive Functions";
        cout<<"\n1.Tower of Hanoi";
        cout<<"\n2.GCD";
        cout<<"\n3.Fibonnaci";
        cout<<"\n4.Factorial";
        cout<<"\nEnter choice:";
        cin>>choice;

        switch(choice)
        {
            case 1: cout<<"\nEnter number of discs: ";
                    cin>>n;
                    r.TOH(n,a,b,c);
                    break;
            case 2: cout<<"\nEnter First Number: ";
                    cin>>m;
                    cout<<"\nEnter Second Number: ";
                    cin>>n;
                    cout<<"\nGCD: "<<r.GCD(m,n);
                    break;
            case 3: cout<<"\nEnter number of terms: ";
                    cin>>x;
                    for(int i=1;i<=x;i++)
                    {
                        f=r.fib(i);
                        cout<<"\t"<<f;
                    }
                    break;
            case 4: cout<<"\nEnter number: ";
                    cin>>x;
                    cout<<"\nFactorial: "<<r.fact(x);
                    break;
            default:printf("\nEnter valid choice!");
                    break;
        }
    }
    return 0;
}
