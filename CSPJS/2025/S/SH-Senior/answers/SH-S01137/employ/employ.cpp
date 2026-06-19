#include<bits/stdc++.h>
using namespace std;
int a[509];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	string s;
	cin>>s;
	int f=1,g=1,h=0;
	for(int i=1;i<=n;i++)f*=s[i]-48,g+=s[i]-48;
	int c=0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>0)c++;
	}
	if(c<m&&f>0)cout<<0;
	else if(f>0){
	}
	else if(m==1){
		
		long long m=1;
		for(long long i=1;i<=n;i++){
			m=(m*i)&998244353;
		}
		
		long long n=1;
		for(long long i=1;i<=c;i++){
			n=(n*(n-g-c+1)/i)&998244353;
		}
		cout<<(m-n+998244353)%998244353;
	}
	else if(m==n){
		long long m=1;
		for(long long i=1;i<=n;i++){
			m=(m*i)&998244353;
		}
		cout<<m;
		if(c==n&&g==n)cout<<m;
		else cout<<0;
	}
	return 0;
}
