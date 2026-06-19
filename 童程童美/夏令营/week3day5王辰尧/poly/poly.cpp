#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    freopen("poly.in","r",stdin);
	freopen("poly.out","w",stdout); 
	int n,a;
    int i;
    cin>>n;
    for(i=n;i>=0;i--)
    {
        cin>>a;
        if(a!=0)
        {
            if(i!=n&&a>0)
                cout<<"+";
            if(fabs(a)>1||i==0)
                cout<<a;
            if(a==-1&&i)
                cout<<"-";
            if(i>1)
                cout<<"x^"<<i;
            if(i==1)
                cout<<"x";
        }
    }
    return 0;
}
