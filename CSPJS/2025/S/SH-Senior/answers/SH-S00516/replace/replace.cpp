#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=200009;
ll n,q,cnts[N],cntt[N];
string s1[N],s2[N],t1[N],t2[N];

void solveBF(ll m){
	ll ans=0;
	bool ok=1;
	for(ll i=1;i<=n;i++){
		if(cnts[i]!=cntt[m]) continue;
		else{
			ll po=0;
			for(ll j=0;j<t1[m].size();j++){
				if(t1[m][j]==s1[i][0]&&t2[m][j]==s2[i][0]){
					po=j; ok=1;
					for(ll k=po;k<=po+s1[i].size()-1;k++){
						if(s1[i][k]!=s2[i][k]){
							ok=0;
							break;
						}
					}
					if(ok==1) ans+=1;
				
				}
			}
			
		}
		
	}
	cout<<ans<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		for(ll j=0;j<s1[i].size();j++){
			if(s1[i][j]!=s2[i][j]) cnts[i]++;
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>t1[i]>>t2[i];
		for(ll j=0;j<t1[i].size();j++){
			if(t1[i][j]!=t2[i][j]) cntt[i]++;
		}
		solveBF(i);
	}
	//if(q==1) solveA();
	return 0;
}
