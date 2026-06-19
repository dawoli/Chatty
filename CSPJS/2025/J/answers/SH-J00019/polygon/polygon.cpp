#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5009;
int n;
int a[N];
ll sum=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]){
		    cout<<1<<endl;
		    return 0;
	    }
	    else cout<<0<<endl;
    }
    else{
        for(int i=1;i<=n;i++)
             sum*=2,sum%=998244353;
        cout<<sum-1<<endl;
    }
	return 0;
} 
