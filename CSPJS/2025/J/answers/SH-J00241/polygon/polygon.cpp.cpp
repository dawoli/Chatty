#include<bits/stdc++.h>
using namespace std;
int a[5010],c[5010],n,ans=0,x,y,z;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cin>>x>>y>>z;
		if(x>y) swap(x,y);
		if(y>z) swap(y,z);
		if(x+y+z>z*2){
			cout<<1;
		}else{
			cout<<0;
		}return 0;
	}if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+a[i];
		if(c[i]>a[i]*2){
			ans++;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(c[j]-c[i-1]>a[j]*2&&j-i>=3){
				ans++;
				for(int k=1;k<=n;k++){
					if(c[j]-c[i-1]-a[k]>a[j]*2&&j-i-1>=3){
						ans++;
					}
				}
			}
		}
	}cout<<ans+1;
	return 0;
}
