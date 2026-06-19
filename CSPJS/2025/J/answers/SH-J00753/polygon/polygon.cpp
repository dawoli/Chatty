#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int N;
int One=0;
long long Ans=0;
int A[100000];
void DFS(int dep,int V,int Max,int U,int F){
	int f=F;
	if(U>=3&&V>Max*2&&!f) Ans=(Ans+1)%Mod,f=1;
	if(dep>N) return;
	DFS(dep+1,V+A[dep],A[dep],U+1,0);
	DFS(dep+1,V,Max,U,f);
}
long long C_(int X,int Y){
	int Cur=0;
	long long Cnt1=1;
	long long Cnt2=1;
	long long Cnt3=1;
	for(int i=1;i<=X;i++) Cnt1*=i%Mod;
	for(int i=1;i<=Y;i++) Cnt2*=i%Mod;
	for(int i=1;i<=(X-Y);i++) Cnt3*=i%Mod;
	return Cnt1/Cnt2/Cnt3;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);		
	cin>>N;
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<=N;i++) One+=A[i];
	if(One==N){
		for(int i=1;i<=N;i++){
			for(int j=2;j<=(N-i);j++){
				Ans+=C_(N-i,j);
				Ans%=Mod;
			}
		}
		cout<<Ans%Mod<<endl;
		return 0;
	}
	if(N>25) return 0;
	sort(A+1,A+N+1);
	DFS(1,0,0,0,0);
	printf("%lld\n",Ans%Mod);
	return 0;
}
