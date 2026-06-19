#include<bits/stdc++.h>
using namespace std;
const int mod=99824353;
int n,m,a[5005];
int chu[5005],chunum=1;
string s;
long long cn(int nn,int m){
	int bb=1;
	long long ans=1;
	for(int i=nn;i>nn-m;i--){
		ans*=i;
		while(ans%(long long)chu[bb]==0&&bb<=m){
			int k=ans/chu[bb];
			ans=k;
			bb++;
		}
	}
	return ans;
}
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool flaga=1;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1')flaga=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=5000;i++){
//		chu[chunum]=i;
//		chunum++;
//	}
	if(flaga==1){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=(long long)mod;
		}
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
