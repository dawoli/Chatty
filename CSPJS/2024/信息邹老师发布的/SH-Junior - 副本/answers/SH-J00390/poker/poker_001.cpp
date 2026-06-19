#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void read(ll &x){
	int res=1;char c;c=getchar();
	while(c<'0'||c>'9'){if(c=='-')res=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
	x*=res;
}
ll n,num;
map<string,ll>mp;
string a;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;mp[a]++;
		if(mp[a]==1)num++;
	}
	cout<<52-num;
	return 0;
}
