#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		mp[s1]=s2;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		int cnt=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) cout<<0<<'\n';
		int l=-1,r=-1;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				r=j;
				break;
			}
			
		}
		for(int j=t1.size()-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				l=j;
				break;
			}
		}
		for(int j=l;j<t1.size();j++){
			for(int k=0;k<=r;k++){
				if(mp[t1.substr(k,j-k+1)]!=" "){
					string t3=t1;
					t1.replace(k,mp[t1.substr(k,j-k+1)].size(),mp[t1.substr(k,j-k+1)]);
					if(t1==t2) cnt++;
					t1=t3;
				}
			}
		}
		
		cout<<cnt<<'\n'; 
	}
	return 0;
} 
