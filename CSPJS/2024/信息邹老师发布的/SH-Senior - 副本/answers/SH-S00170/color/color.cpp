#include<bits/stdc++.h>
#define int long long
//#define fin std::cin
//#define fout std::cout
using std::ifstream;
using std::ofstream;
using std::cerr;
ifstream fin("color.in");
ofstream fout("color.out");
int score(int a[],bool color[],int n){
	int ret=0;
	for(int i=1;i<n;i++){
		int l=i-1;
		bool flag=true;
		while(flag){
			if(l<0) flag=false;
			else {
				if(color[i]==color[l]) flag=false;
				else l--;
			}
		}
		if(l==-1){
			continue;
		}
		else {
			if(a[i]==a[l]) ret+=a[i];
		}
	}
	return ret;
}
int solve(int a[],int n){
	bool tmp[n];
	int ret=-1;
	for(int i=0;i<(1ULL<<n);i++){
		int t=i;
		for(int j=0;j<n;j++){
			tmp[j]=t%2;
			t>>=1;
		}
		//for(int j=0;j<n;j++) cerr<<tmp[j]<<" ";
		//cerr<<"\n";
		int sol=score(a,tmp,n);
		if(sol>ret) ret=sol;
	}
	return ret;
}
signed main(){
	int T;
	fin>>T;
	for(int i=0;i<T;i++){
		int n;
		fin>>n;
		int a[n];
		for(int j=0;j<n;j++) fin>>a[j];
		fout<<solve(a,n)<<"\n";
	}
	/*
	int a[3]={1,2,1};
	bool u[3]={0,1,0};
	cerr<<score(a,u,3);
	*/
	return 0;
}
