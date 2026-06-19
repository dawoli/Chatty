#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[5005],n,st[505][505],maxx=0,sum[5005];
int chu[5005],chunum=1,ans=0;
bool cmp(int &a,int &b){
	return a>b;
}
long long cn(int aa,int bb){
	long long ans=1;
	int kk=0;
	for(int i=aa;i>aa-bb;i--){
		ans=ans*i;
		while(ans%chu[kk+1]==0&&kk<bb){
			ans/=chu[kk+1];
			kk++;
		}
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(maxx==1){
		for(int i=1;i<=5000;i++){
			chu[chunum]=i;
			chunum++;
		}
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=cn(n,i);
			ans%=mod;
			//cout<<ans<<endl;
		}
		cout<<ans;
		return 0;
	}
	if(n<=3){
		if(a[1]+a[2]+a[3]>maxx*2)cout<<1;
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
