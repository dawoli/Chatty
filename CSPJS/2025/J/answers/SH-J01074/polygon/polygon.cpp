#include<bits/stdc++.h>
using namespace std;
int n,a[5001],sum,cnt,res,r;
long long ans;
bool cmp(int x,int y){
	return x>y;
}
int f(int o,int p){
	if(o==p)return 1;
	if(p-o==1||o==1)return p-1;
	return f(o-1,p-1)+f(o,p-1);
}
int main(){
 freopen("polygon.in","r",stdin);
 freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		r=max(r,a[i]);
	}
	int l=1,r=3;
	sort(a+1,a+n+1,cmp);
	if(r==1){
		for(int i=3;i<=n;i++){
			ans+=f(i+1,n+1);
			ans=ans%998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	while(l<=n-2){
		sum=0;
		cnt=a[r];
		for(int i=l;i<=r;i++)sum+=a[i];
		if(cnt*2<sum){
			ans++;
			res=sum-cnt*2;
		}
		for(int i=l;res-a[i]>0;i++)ans++;
		if(r==n){
			l++;
			r=l+2;
		}
		else if(r<n)r++;
	}
	cout<<ans%998244353;
	return 0;
}
