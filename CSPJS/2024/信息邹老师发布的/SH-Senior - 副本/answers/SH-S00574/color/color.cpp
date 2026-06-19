#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll T,n,A[N],B[N],B_[N],lB,lB_;
void makeB(ll p){
	lB=lB_=0;
	int i=1;
	while(p){
		if(p&1)
			B[++lB]=A[i];
		else
			B_[++lB_]=A[i];
		p>>=1;++i;
	}
}
void solveBF(){
	ll p=1<<n,score,maxScore=0;
	for(ll i=0;i<p;++i){
		makeB(i);score=0;
		for(int j=1;j<lB;j++)if(B[j]==B[j+1])score+=B[j];
		for(int j=1;j<lB_;j++)if(B_[j]==B_[j+1])score+=B_[j];
		maxScore=max(maxScore,score);
	}
	cout<<maxScore<<'\n';
}
void solve(){
	solveBF();
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>A[i];
		if(n<=15)
			solveBF();
		else
			solve();
	}
	return 0;
}

