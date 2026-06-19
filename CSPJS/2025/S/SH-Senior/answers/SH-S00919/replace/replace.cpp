#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,p[N];
string a[N],b[N],t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		int aa=0,bb=0;
		for(int j=0;j<a[i].size();j++){
			if(a[i][j]=='b'){
				aa=j;
				break;
			}
		}
		for(int j=0;j<b[i].size();j++){
			if(b[i][j]=='b'){
				bb=j;
				break;
			}
		}
		p[i]=bb-aa;
	}
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0;
			continue;
		}
		int aa=0,bb=0;
		for(int j=0;j<t1.size();j++){
			if(t1[j]=='b'){
				aa=j;
				break;
			}
		}
		for(int j=0;j<t2.size();j++){
			if(t2[j]=='b'){
				bb=j;
				break;
			}
		}
		int step=bb-aa,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].size()>t1.size())
				continue;
			if(step==p[i])ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
