#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n;
void solve1(){
	cout<<-1<<endl;
}
ll g[109],ansk,ansg[109];
void copy_ans_g(){
	ansg[ansk+1]=0;
	ansg[ansk+2]=0;
	for(ll i=1;i<=ansk;++i){
		ansg[i]=g[i];
	}
}
bool ifgsmall(ll k){
	if(k<ansk)return 1;
	for(ll i=k;i>=1;--i){
		if(g[i]<ansg[i])return 1;
		else if(g[i]>ansg[i])return 0;
	}
	return 0;
}
void dfs(ll num,ll k){
	if(k>ansk+1)return;
	if(num==1)return;
	if(num<0)return;
	if(num==0){
		k--;
		if(g[k]==0)return;
		if(k>ansk)return;
		if(ifgsmall(k)){
			ansk=k;
			copy_ans_g();
		}
		return;
	}
	g[k]=8;
	dfs(num-7,k+1);
	g[k]=6;
	dfs(num-6,k+1);
	g[k]=0;
	dfs(num-6,k+1);
	g[k]=2;
	dfs(num-5,k+1);
	g[k]=4;
	dfs(num-4,k+1);
	g[k]=7;
	dfs(num-3,k+1);
	g[k]=1;
	dfs(num-2,k+1);
}
void solveBF(){
	ansk=99;
	for(ll i=1;i<=105;++i)ansg[i]=9;
	dfs(n,1);
	if(ansk==99)cout<<-1<<endl;
	else{
		for(ll i=ansk;i>0;--i)cout<<ansg[i];
		cout<<endl;
	}
}
void solveA(){
	for(ll i=1;i<=n/7;++i){
		cout<<8;
	}
	cout<<endl;
}
void solveB(){
	ll m=n%7;
	ll num=(n+6)/7-3;
	if(m==0){
		cout<<888;
	}
	else if(m==1){
		cout<<108;
	}
	else if(m==2){
		cout<<188;
	}
	else if(m==3){
		cout<<200;
	}
	else if(m==4){
		cout<<208;
	}
	else if(m==5){
		cout<<288;
	}
	else if(m==6){
		cout<<688;
	}
	for(ll i=1;i<=num;++i)cout<<8;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(ll tt=1;tt<=T;++tt){
		cin>>n;
		if(n<=1){
			solve1();
		}
		else if(n<=50){
			solveBF();
		}
		else if(n>=100&&n%7==0){
			solveA();
		}
		else{
			solveB();
		}
	}
	return 0;
}
