#include<bits/stdc++.h>
using namespace std;
long long a,b[10000],c,d,ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(long long i=1;i<=a;i++){
		cin>>b[i];
} 
	for(long long i=1;i<=a;i++){
		for(long long j=1;j<=a;j++){
			c=0;
			d=0;
			for(long long k=i;k<=j;k++){
				c=max(b[k],c);
				d+=b[k];
			}
			if(d>c*2&&j-i>=2){
				ans++;
				ans=ans%998244353;
			}
		}
	}
	cout<<ans;
}

