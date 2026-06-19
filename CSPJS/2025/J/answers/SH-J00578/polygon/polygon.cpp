#include <bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long N,A[6000],Ans;
bool F=1;
void Dfs(int Cur,int NumS,int Sum){
	if(Cur>N){return ;}
	Dfs(Cur+1,NumS,Sum);
	Dfs(Cur+1,NumS+1,Sum+A[Cur]);
	if(NumS+1>=3&&Sum>A[Cur]){Ans++;}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>N;
	for(int I=1;I<=N;I++){
		cin>>A[I];
		if(A[I]!=1){F=0;}
	}
	if(N<=20){
		sort(A+1,A+N+1);
		Dfs(1,0,0);
		Ans=Ans%Mod;
	}
	else if(F){
		int Js=(N*(N-1)*(N-2)/6)%Mod;
		for(int I=3;I<=N;Js=(Js*(N-I)/(++I))%Mod){
			Ans=(Ans+Js)%Mod;
		}
	}
	cout<<Ans;
	return 0;
}
