#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N=5e5+10;
ll N,Mod=998244353;
ll A[5010],Ans=0;
int dfs(ll K,ll M,ll B){
	if(K==1&&M-A[K]>=0){
		return 0;
	}
	else if(K==1&&M-A[K]<0&&B>=2){
		Ans++;
		return 0;
	}
	else if(M-A[K]<0&&B>=2){
		Ans+=1;
		Ans%=Mod;
	}
	for(int i = 1;i<=K-1;i++){
		dfs(i,M,B);
		dfs(i,M-A[K],B+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>A[i];
	}
	sort(1+A,1+A+N);
	for(int i = 3;i<=N;i++){
		for(int j = 2;j<=i-1;j++){
			dfs(j,A[i],0);
		}
	}
	cout<<Ans;
	return 0;
}
