#include<bits/stdc++.h>
using namespace std;
struct p{
	long long num;
	bool vis;
}A[500010];
long long N,K;
long long Ans=0,Nw=1;
void sol(long long Nw,long long j){
	Nw=A[j].num;
	for(int i=j+1;i<=N;i++){
		if(Nw==K)
			Ans++;
		if(A[i].vis==true)
			Nw=Nw xor A[i].num;
		else
			sol(Nw,j+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&N,&K);
	for(int i=1;i<=N;i++){
		scanf("%lld",&A[i].num),A[i].vis=true;
	}
	for(int i=1;i<=N;i++){
		if(A[i].num==K)
			Ans++,A[i].vis=false;
	}
	sol(0,1);
	cout<<Ans;
return 0;	
}
