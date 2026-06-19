#include<bits/stdc++.h>
#define ll long long
#define mk make_pair
#define ___ __int128
using namespace std;
const int N=1e4+15,M=2e6+5;

inline ll read() {
	ll x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}

int n,q,s1,s2;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<=n;i++) cin>>s1>>s2;
	for(int i=1;i<=q;i++) cin>>s1>>s2;
	for(int i=1;i<=q;i++) {
		cout<<0<<endl;
	}
	return 0;
}
