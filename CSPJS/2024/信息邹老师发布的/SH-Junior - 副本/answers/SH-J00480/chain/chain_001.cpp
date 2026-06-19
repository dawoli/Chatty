#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int s[1009][2009],l[N],r[N],c[N],n,k,q;
map<pair<int,int>,int> mp; 
bool isCondition1(){
	for(int i=1;i<=q;i++)
		if(r[i]>1) return 0;
	return 1;
}
void solve1(){
	int valid=0;
	for(int x=1;x<=q;x++){
		for(int i=1;i<=n;i++)
			if(mp[make_pair(c[x],x)]){
				cout<<1<<endl;
				valid=1;
				break;
			}
		if(!valid) cout<<0<<endl;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++) cin>>s[i][j],mp[make_pair(s[i][j],i)]=1;
		}
		for(int i=1;i<=q;i++)
			cin>>r[i]>>c[i];
		if(isCondition1()) solve1();
	}
	return 0;
}
