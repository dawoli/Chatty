#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100010;
int n,mtr[N],mtb[N],ans,m;
void test(){
	for(int i=1;i<=m;i++)cout<<mtr[i]<<" ";
}
void input(){
	cin>>n;
	ans=n;
	for(int i=1,t1;i<=n;i++){
		cin>>t1;
		m=max(m,t1);
		mtr[t1]++;
		mtb[t1]++;
	}
	return;
}
void solve(){
	int l=1,r=2;
	while(l<=m&&mtr[l]==0)l++,r++;
	while(r<=m&&mtb[r]==0)r++;
	if(r>m)return;
	while(r<=m){
		if(mtr[l]<mtb[r]){
			ans-=mtr[l];
			mtb[r]-=mtr[l];
			mtr[l]=0;
			l++;
			while(l<=m&&mtr[l]==0)l++;
			r=l+1;
			while(r<=m&&mtb[r]==0)r++;
		}
		else if(mtr[l]==mtb[r]){
			ans-=mtr[l];
			mtb[r]=0;
			l++;
			while(l<=m&&mtr[l]==0)l++;
			r=l+1;
			while(r<=m&&mtb[r]==0)r++;
		}
		else{
			ans-=mtb[r];
			mtr[l]-=mtb[r];
			mtb[r]=0;
			while(r<=m&&mtb[r]==0)r++;
		}
	}
	return;
}
void output(){
	cout<<ans;
	return;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	input();
	solve();
//	test();
	output();
	return 0;
}
