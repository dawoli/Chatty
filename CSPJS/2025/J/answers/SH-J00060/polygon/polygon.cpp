#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;
int f;
long long A(long long x,long long y){
	long long cal=1;
	for(int i=0;i<y;++i){
		cal*=(x-i)%998244353;
		cal%=998244353;
	}
	return cal;
}
long long C(long long x,long long y){
	return A(x,y)/A(y,y);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1){
			f=1;
		}
	}
	if(f==0){
		for(int i=3;i<=n;++i){
	    	ans=(C(n,i)%998244353+ans)%998244353;
    	} 
	    cout<<ans;
	    return 0;
	}
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	return 0;
}
