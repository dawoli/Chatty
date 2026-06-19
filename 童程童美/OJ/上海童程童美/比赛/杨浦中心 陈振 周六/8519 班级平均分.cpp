#include<bits/stdc++.h> 
using namespace std;
int a[105],sum,cnt=0;
double p;
int main()
{
	int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum=sum+a[i];
    }
    double p=sum*1.0/n;
    for(int i=1;i<=n;i++){
        if(a[i]>=p)cnt++;
    }
    cout<<fixed<<setprecision(2)<<p<<endl;
    cout<<cnt;
	return 0;
}
