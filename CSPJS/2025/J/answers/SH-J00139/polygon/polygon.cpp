#include<bits/stdc++.h>
using namespace std;
int a[5001],ans=0;
void f(int x,int y,int ma){
	for(int z=y-1;z>=0;z--){
		if(x+a[z]>ma){
			ans+=(z*(1+z)/2%998244353);
			
		}
		else{
			f(x+a[z],z,ma);
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<n;i++){
		for(int j=i-1;j>=0;j--){
			for(int k=j-1;k>=0;k--){
				if(a[j]+a[k]>a[i]){
					ans+=((1+k)*k/2%998244353);
				}
				else{
					f(a[j]+a[k],k,a[i]);
				}
			}
		}
	}
	cout<<ans;
} 
