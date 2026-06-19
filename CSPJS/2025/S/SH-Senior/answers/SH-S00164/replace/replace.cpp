#include<bits/stdc++.h>
using namespace std;
int n,q;
map<int,string> m1,m2;
bool special=true;
int mv[5000005],tong[10000005];
int find(string s){
	for(int i=0;i<s.length();i++) if(s[i]=='b') return i;
}
bool check(string s){
	for(int i=0;i<s.length();i++) if(s[i]!='b'&&s[i]!='a') return true;
	return false;
}
bool pic[1005];
bool check2(int l,int r,string s1,string s2){
	for(int i=0;i<s1.length();i++){
		if(i>=l&&i<=r)continue;
		if(s1[i]!=s2[i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>m1[i]>>m2[i];
		if(check(m1[i])||check(m2[i])) special=false;
	}
	if(special){
		for(int i=1;i<=n;i++) {mv[i]=find(m2[i])-find(m1[i]);tong[mv[i]+1000000]++;}
		while(q--){
			string s1,s2;
			cin>>s1>>s2;
			cout<<tong[find(s2)-find(s1)+1000000]<<endl;
		}
	}
	else {
		while(q--){
			int ans=0;
			string s1,s2;
			cin>>s1>>s2;
			for(int i=1;i<=n;i++) pic[i]=true;
			for(int i=0;i<s1.length();i++){
				for(int j=i;j<s1.length();j++){
					for(int k=1;k<=n;k++){
						if(!pic[k]) continue;
						if(pic[k]&&m1[k].length()==j-i&&check2(i,j,s1,s2)==true) ans++;
						if(s1[j]!=m1[k][j-i]||s2[j]!=m2[k][j-i]) pic[k]=false;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
