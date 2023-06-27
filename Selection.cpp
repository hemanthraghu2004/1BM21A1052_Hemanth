#include<iostream>
using namespace std;
/*  n| count/n | count/n2 | count/n3 |
    10   4.5         0.45     0.045
    100  49.5        0.495    0.00495
    500  249.5       0.499    0.000998
    1000 499.5       0.4995   0.0004995*/
class Sorting{
public:

    int arr[1000];
    int n,min,count=0,temp;
    void ins(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            arr[i]=i;
    }
    int arrSort(int arr[],int n)
    {
        for(int i=0;i<n-1;i++)
        {
            min=i;
            for(int j=i+1;j<n;j++)
            {
                ++count;
                if(arr[j]<arr[min])
                    min=j;

            }
            temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
        return count;
    }
};

int main()
{
    Sorting s;
    s.arr;
    cout<<"Enter number of elements: ";
    cin>>s.n;
    s.ins(s.arr,s.n);
    s.count = s.arrSort(s.arr,s.n);
    cout<<"\nBasic operation:"<<s.count;
    cout<<"\nCount/n: "<<((float)s.count/s.n);
    cout<<"\nCount/n^2: "<<((float)s.count/(s.n*s.n));
    cout<<"\nCount/n^3: "<<((float)s.count/(s.n*s.n*s.n));
    return 0;
}
