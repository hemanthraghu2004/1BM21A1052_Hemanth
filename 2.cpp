#include<iostream>
#include<algorithm>
using namespace std;

class LinBin
{
    public:
        int a[500],key,n;
    void Lsearch(int a[],int key,int n)
    {
        int i,flag=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==key)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            cout<<"\nElement is present at: "<<i;
        else
            cout<<"\nElement is not present";
    }
    void Bsearch(int a[],int key, int n)
    {
        std::sort(a, a + n);
        int M,L=0,U=n-1,flag=0;
        while(L<=U)
        {
            M=(L+U)/2;
            if(a[M]==key)
            {
                flag=1;
                break;
            }

            else if(a[M]>key)
            {
                L=M+1;
            }
            else
            {
                U=M-1;
            }
        }
        if(flag)
            cout<<"\nElement present at: "<<M;
        else
            cout<<"\nElement not present";
    }
};
int main()
{
    LinBin Obj;
    int choice;
    cout<<"Enter Number of elements: ";
    cin>>Obj.n;
    for(int i=0; i<Obj.n; i++)
        cin>>Obj.a[i];
    while(1)
    {
        cout<<"\nSearching techniques";
        cout<<"\n1.Linear Search";
        cout<<"\n2.Binary Search";
        cout<<"\n3.Exit";
        cout<<"\nEnter choice:";
        cin>>choice;
        cout<<"\nEnter key:";
        cin>>Obj.key;

        switch(choice)
        {
            case 1: Obj.Lsearch(Obj.a,Obj.key,Obj.n);
                    break;
            case 2: Obj.Bsearch(Obj.a,Obj.key,Obj.n);
                    break;
            case 3: printf("\nExiting...");
                    exit(0);
                    break;
            default:printf("\nEnter valid choice!");
                    break;
        }
    }
}
