#include<bits/stdc++.h> 
using namespace std;
int a[100005];
long long sum;
double p;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    double sum1=sum-sum/30*3;
    if(sum>=k){
        p=sum*0.8;
        if(p>sum1)
            cout<<fixed<<setprecision(2)<<sum1;
        else
        {
            cout<<fixed<<setprecision(2)<<p;
        }
    }
    else
    {
        cout<<fixed<<setprecision(2)<<sum1;
    }
    return 0;
}
