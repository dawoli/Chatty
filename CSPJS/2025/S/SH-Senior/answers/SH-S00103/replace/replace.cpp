#include<bits/stdc++.h>
using namespace std;
map<string,map<string,int> > mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(mp[s1][s2]>0)
			mp[s1][s2]+=1;
		else mp[s1][s2]=1;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(mp[t1][t2]>0) cout<<mp[t1][t2];
		else cout<<0;
		cout<<endl;
	}
	return 0;
}
