#include<bits/stdc++.h>
using  namespace std;
map<string,string>mp;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		mp[a]=b;
	}
	while(q--){
		string s1,s2;
		int ans=0;
		cin>>s1>>s2;
		int s=s1.size(),x=0,z=0;
		for(int i=0;i<s;i++){
			if(s1[i]==s2[i])x++;
			else break;
		}
		for(int i=s-1;i>=0;i++){
			if(s1[i]==s2[i])z++;
			else break;
		}
		for(int i=0;i<=x;i++){
			for(int j=s;j>=s-z;j--){
				if(i>=j)break;
				string t1="",t2="";
				for(int k=i;k<j;k++){
					t1+=s1[k];
					t2+=s2[k];
				}
				if(mp.find(t1)!=mp.end())if(mp[t1]==t2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
