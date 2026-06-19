#include<bits/stdc++.h>
using namespace std;
ifstream fin("xor.in");
ofstream fout("xor.out");
const int maxn=500005;
int n,k; 
int a[maxn];
long long f[maxn];
int main(){
	fin>>n>>k;
	for(int i=1;i<=n;++i){
		fin>>a[i];
		f[i]=-1;
	}
	f[n+1]=0;
	for(int i=n;i>=1;--i){
		long long ans=0;
		long long result=0;
		for(int j=i;j<=n;++j){
			ans=ans^a[j];
			if(ans==k){
				result=max(result,f[j+1]+1);
				break;
			}
			else{
				result=max(result,f[j+1]);
			}
		}
		f[i]=result;
	}
	fout<<f[1];
}

