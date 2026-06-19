#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N],q1[N],q2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	} 
	for(int j=1;j<=q;j++){
		cin>>q1[j]>>q2[j];
	}
	int ans=0;
	for(int i=1;i<=q;i++){
		if(q1[i].size()!=q2[i].size()){cout<<0<<endl; continue;}
		for(int j=1;j<=n;j++){
			if(q1[i].find(s1[j])==string::npos) continue;
			int id=q1[i].find(s1[j]);
			string temp="";
			for(int k=0;k<id;k++){
				temp+=q1[i][k];
			}
			temp+=s2[j];
			for(int k=id+s1[j].size();k<q1[i].size();k++){
				temp+=q1[i][k];
			} 
			if(temp==q2[i]) ans++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	
} 
