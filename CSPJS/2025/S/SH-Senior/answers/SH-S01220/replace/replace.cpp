#include<bits/stdc++.h>
#define N 200009
using namespace std;
typedef long long ll;
ll n,q;
string s[N][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(ll i=1;i<=n;i++)cin>>s[i][1]>>s[i][2];
	while(q--){
		string st,ed;
		ll cnt=0;
		cin>>st>>ed;
		if(st.size()!=ed.size()){cout<<0<<endl;continue;}
		for(ll i=1;i<=n;i++){//³¢ÊÔÌæ»»ÎªµÚiÖÖ 
			ll sz=s[i][1].size(),stz=st.size();
			if(stz<sz) continue;
			for(ll j=0;j<=n-sz+1;j++){
				string a="";
				for(ll i=j;i<=min(j+sz-1,stz-1);i++) a+=st[i];
				//string a=st.substr(j,sz);
				//cout<<i<<"="<<a<<endl;
				if(a==s[i][1]){
					string now=st.substr(0,j)+s[i][2]+st.substr(j+sz,st.size()-j-sz);
					//cout<<i<<"="<<now<<endl;
					if(now==ed) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
