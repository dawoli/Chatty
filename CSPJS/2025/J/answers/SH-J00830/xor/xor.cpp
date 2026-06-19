#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N];
struct xor_lrs{
	long long l_l,r_r;
}lrs[N];
bool cmp(xor_lrs a,xor_lrs b){
	return a.r_r<b.r_r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool a1=1;
	bool b1=1;
	bool c1=(k<=225);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1=a1&&a[i];
		b1=b1&&a[i]>=0&&a[i]<=1;
		c1=c1&&a[i]<=225;
	}
	if(a1){
		cout<<n/2;
		return 0;
	}
	if(b1){
		if(k==1){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(a[i]) ans++;
			}
			cout<<ans;
			return 0;
		}
		if(k==0){
			int ans=0;
			for(int i=1;i<=n;i++){
				if(!a[i]){
					ans++;
					continue;
				}
				if(a[i]==a[i-1]&&a[i]==1){
					ans++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	int ans=1,cnt=0,l_r=1;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int cnt=0;
			for(int i=l;i<=r;i++){
				cnt^=a[i];
				//cout<<cnt<<' ';
			}
			//cout<<endl;
			if(cnt==k){
				lrs[l_r].l_l=l;
				lrs[l_r].r_r=r;
				l_r++;
				//cout<<l_r<<' ';
			}
		}
	}
	sort(lrs+1,lrs+l_r,cmp);
	int rr=lrs[1].r_r;
	for(int i=2;i<=l_r;i++){
		if(lrs[i].l_l>rr){
			ans++;
			rr=lrs[i].r_r;
		}
	}
	cout<<ans;
	return 0;
}
