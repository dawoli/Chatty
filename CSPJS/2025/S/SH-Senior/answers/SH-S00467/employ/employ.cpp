#include<bits/stdc++.h>
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
const int mod=998244353;
int n,m;
string a;
int b[505],c[505];
int f[505];
long long solve2(int i,int nc,int num){
	if(i==n){
		if(num>=m) return 1;
		else return 0;
	}
	long long res=0;
	for(int x=1;x<=n;++x){
		if(f[x]==1) continue;
		if(b[x]<=nc) f[x]=1,res=res+solve2(i+1,nc+1,num),res=res%mod,f[x]=0;
		else f[x]=1,res=res+solve2(i+1,nc,num+1),res=res%mod,f[x]=0;
	}
	return res%mod;
}
long long solve(int i,int nc,int num){
	//cout<<i<<" "<<a[i]<<" "<<nc<<" "<<num<<"\n";
	if(num>=m){
		long long res=1;
		for(int i=1;i<=n-num-nc;++i){
			res*=i;
			res%=mod;
		}
		return res;
	}
	if(i==n){	
		return 0;
	}
	if(a[i]=='0'){
		long long res=0;
		for(int x=1;x<=n;++x){
			if(f[x]==1) continue;
			f[x]=1,res=res+solve(i+1,nc+1,num),res=res%mod,f[x]=0;
		}
		return res%mod;
	}
	else{
		long long res=0;
		for(int x=1;x<=n;++x){
			if(f[x]==1) continue;
			if(b[x]<=nc) f[x]=1,res=res+solve(i+1,nc+1,num),res=res%mod,f[x]=0;
			else f[x]=1,res=res+solve(i+1,nc,num+1),res=res%mod,f[x]=0;
		}
		return res%mod;
	}
}
int main(){
	fin>>n>>m;
	fin>>a;
	for(int i=1;i<=n;++i){
		fin>>b[i];
		f[i]=0;
	}
	bool flaga=true;
	for(int i=0;i<n;++i){
		if(a[i]=='0'){
			flaga=false;
			break;
		}
	}
	if(flaga == true and false){
		fout<<solve2(0,0,0)%mod;
	}
	sort(b+1,b+n+1);
	fout<<solve(0,0,0)%mod;
}

