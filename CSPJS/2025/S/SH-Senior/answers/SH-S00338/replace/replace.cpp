#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
string s1[200010],s2[200010];
bool check(string s1,string s2,string t1,string t2,int pos){
	for(int i=0;i<s1.size();i++){
		t1[i+pos]=s2[i];
	}
	for(int i=0;i<t1.size();i++){
		if(t1[i]!=t2[i])return 0;
	}
	return 1;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		int ans=0;
		for(int i=1;i<=n;i++){
			int pos=0;
			for(int j=0;j<t1.size();j++){
				if(s1[i][pos]==t1[j]){
					pos++;
				}
				else{
					pos=0;
				}
				if(pos==s1[i].size()-1){
					if(check(s1[i],s2[i],t1,t2,j-pos+1)){
						ans++;
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
