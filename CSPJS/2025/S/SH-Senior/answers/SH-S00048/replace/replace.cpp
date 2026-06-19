#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#define maxn 200010
#define P 377202511017
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,q,nxt[maxn];
map<ull,ull> m;
ull data[maxn];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	ios::sync_with_stdio(0);
	cin>>n>>q;
	string a,b;ull h1,h2;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		h1=h2=0;
		for(int j=0;j<a.length();++j)h1=h1*P+a[j]-'a'+1;
		for(int j=0;j<b.length();++j)h2=h2*P+b[j]-'a'+1;
		if(m.count(h1))nxt[i]=m[h1];
		m[h1]=i,data[i]=h2;
	}
	while(q--){
		cin>>a>>b;
		int len=a.length(),cnt=0,maxl=0,maxr=len-1;
		while(a[maxl]==b[maxl])++maxl;
		while(a[maxr]==b[maxr])--maxr;
		//printf("#%d %d %d\n",q,maxl,maxr);
		for(int i=0;i<=maxl;++i){
			h1=h2=0;
			for(int j=i;j<maxr;++j)h1=h1*P+a[j]-'a'+1;
			for(int j=i;j<maxr;++j)h2=h2*P+b[j]-'a'+1;
			for(int j=maxr;j<len;++j){
				h1=h1*P+a[j]-'a'+1;
				h2=h2*P+b[j]-'a'+1;
				//printf("%d %d %llu %llu\n",i,j,h1,h2);
				if(m.count(h1)){
					for(int k=m[h1];k;k=nxt[k])
						if(data[k]==h2)++cnt;
					//printf("%d %d\n",i,j);
				}
			}
		}printf("%d\n",cnt);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

2
0

5 2
a b
ac bc
dac dbc
acd bcd
d g
ddacdg ddbcdg
*/

