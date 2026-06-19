#include <bits/stdc++.h>
using namespace std;
string l1[200200],l2[200200];
void solve(){//10%
	int n,q;
	cin>>n>>q;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>l1[i]>>l2[i];
	}
	for(int i=0;i<q;i++){
		ans=0;
		string a,b;
		cin>>a>>b;
		int l=0,r=0;
		for(int j=0;j<a.size();j++){
			if(a[j]!=b[j]){l=j;break;}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]!=b[j]){r=j;break;}
		}
		int length=r-l+1;
		string now=a.substr(l,length);
		string to=b.substr(l,length);
		for(int j=1;j<=n;j++){
			if(l1[j].size()<length)continue;
			for(int k=0;k<l1[j].size()-length+1;k++){
				if(l1[j].substr(k,length)==now&&l2[j].substr(k,length)==to){
					if(l1[j]==a.substr(l-k,l1[j].size())&&l2[j]==b.substr(l-k,l2[j].size())){
						ans++;break;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return ;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	solve();
	return 0;
}
