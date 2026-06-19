#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,int> mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	while(n--){
		string s1,s2;
		cin>>s1>>s2;
		mp[{s1,s2}]++;
	}
	if(q>=1000){
		while(q--){
			cout<<"0\n";
		}
		return 0;
	}
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		int l=0,r=len-1,ans=0;
		while(s1[l]==s2[l]){
			l++;
		}
		while(s1[r]==s2[r] and l<=r){
			r--;
		}
		r++;
		for(int i=l;i>=0;i--){
			for(int j=r;j<=len;j++){
				string t1=s1.substr(i,j-i);
				string t2=s2.substr(i,j-i);
				if(mp.count({t1,t2})) ans+=mp[{t1,t2}];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
