#include<bits/stdc++.h>
using namespace std;
#define N 507
#define M 998244353
#define ll long long
int n,m;
string s;
int c[N];
int p[N];
int ksm(int a,int b){
	int ans=a%M;
	while(b){
		if(b&1) ans=ans*a%M;
		a=a*a%M;
		b>>=1;
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	int fl=1;
	for(int i=1;i<=n;++i){
		p[i]=i;
		cin>>c[i];
		fl&=c[i];
	}
	if(n<=10){
		int ans=0;
		do{
			int cnt=0,sum=0;
			for(int i=1;i<=n;++i){
				if(sum>=c[p[i]]) ++sum;
				else if(s[i]=='0') ++sum;
				else ++cnt;
			}
			if(cnt>=m) ++ans;
		}while(next_permutation(p+1,p+n+1));
		cout<<ans%M;
	}
	else{
		cout<<0;
	}
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

¾¡Á¦ÁË 
*/
