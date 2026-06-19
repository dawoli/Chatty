#include <bits/stdc++.h>
using namespace std;
int n,a[10000],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;++i){
		for(int j=i+2;j<=n;++j){
			int cnt=0,me=0;
			for(int z=i;z<=j;++z){
				cnt+=a[z];
			}
			for(int z=i;z<=j;++z){
				me=max(me,a[z]);
			}
			if(cnt>2*me){
				sum=(sum+1)%998244353;
			}
		}
	}
	cout<<sum*3/2<<endl;
	return 0;
}
