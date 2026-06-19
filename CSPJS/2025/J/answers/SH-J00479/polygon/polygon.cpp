#include<bits/stdc++.h>
using namespace std;
ifstream fin("polygon.in");
ofstream fout("polygon.out");
const int maxn=5005;
const int mod=998244353;
int n;
int a[50000];
map<pair<int,pair<int,int>>,int> f;
long long solve(int i,int ma,long long sum,int num){
	if(i==n+1){
		if(ma*2<sum and num>=3) return 1;
		else return 0;
	}
	if(f[{i,{ma,sum}}]>0 and num>=3) return f[{i,{ma,sum}}];
	return f[{i,{ma,sum}}]=(solve(i+1,max(a[i],ma),sum+a[i],num+1)%mod+solve(i+1,ma,sum,num+1)%mod)%mod;
}
int main(){
	fin>>n;
	for(int i=1;i<=n;++i){
		fin>>a[i];
	}
	fout<<solve(1,0,0,0); 
}

