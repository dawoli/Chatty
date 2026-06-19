#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void read(ll &x){
	int res=1;char c;c=getchar();ll p=0;
	while(c<'0'||c>'9'){if(c=='-')res=-1;c=getchar();}
	while(c>='0'&&c<='9'){p=(p<<3)+(p<<1)+(c-'0');c=getchar();}
	p*=res;
	x=p;
}
ll n,num;
map<string,ll>mp;
string a;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		cout<<1<<endl;
	}
	return 0;
}
