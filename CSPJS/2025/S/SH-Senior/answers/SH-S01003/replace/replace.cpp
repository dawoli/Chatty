#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int l[N],r[N];
map <pair<int,int>,int> mp;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		int posa,posb;
		for(int j=0;j<s1[i].size();j++){
			if(s1[i][j]=='b'){
				posa=j;
				break;
			}
		}
		for(int j=0;j<s2[i].size();j++){
			if(s2[i][j]=='b'){
				posb=j;
				break;
			}
		}
		l[i]=posb-posa;
		r[i]=(s2[i].size()-posb)-(s1[i].size()-posa);
		mp[{l[i],r[i]}]++;
	}
	if(n<=100 or q<=100){
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=0;j+s1[i].size()-1<t1.size();j++){
					if(t1.substr(j,s1[i].size())!=s1[i]){
						continue;
					}
					string tmp=t1.substr(0,j)+s2[i]+t1.substr(j+s1[i].size());
					if(tmp==t2){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
	else{
		while(q--){
			string t1,t2;
			cin>>t1>>t2;
			int posa,posb;
			for(int i=0;i<t1.size();i++){
				if(t1[i]=='b'){
					posa=i;
					break;
				}
			}
			for(int i=0;i<t2.size();i++){
				if(t2[i]=='b'){
					posb=i;
					break;
				}
			}
			int ll=posb-posa;
			int rr=(t2.size()-posb)-(t1.size()-posa);
			cout<<mp[{ll,rr}]<<"\n";
		}
	}
	return 0;
}
