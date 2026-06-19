#include<bits/stdc++.h>
using namespace std;
int x[509],id[509];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool ok=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			ok=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[i];
		id[i]=i;
	}
	if(ok){
		int tm=0;
		for(int i=1;i<=n;i++){
			if(x[i]!=0) tm++;
		}
		long long p=1;
		for(int i=tm;i>tm-m;i--){
			p*=i;
			p%=998244353;	
		}
		for(int i=1;i<=n-tm;i++){
			p*=i;
			p%=998244353;	
		}
		cout<<p;
		return 0;
	}
	if(n==m){
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		long long p=1;
		for(int i=1;i<=n;i++){
			p*=i;
			p%=998244353;	
		}
		cout<<p;
	}
	int ans=0;
	do{
		int num=0;
		int nj=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				nj++;
				continue;
			}
			if(nj<x[id[i]]) num++;
			else nj++;
		}
		if(num>=m){
			ans++;
		}
	}while(next_permutation(id+1,id+n+1));
	cout<<ans;
	return 0;
} 
