#include<bits/stdc++.h>
using namespace std;

int n,q;
string mp1[200005],mp2[200005];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>mp1[i]>>mp2[i];
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int pos1=1e9,pos2=-1,cnt=0;
		for(int i=0;i<s1.length();i++){
			if(s1[i]!=s2[i]){
				pos1=min(pos1,i);
				pos2=max(pos2,i);
			}
		}
		string st=s1.substr(pos1,pos2-pos1+1),fst=s2.substr(pos1,pos2-pos1+1);
		for(int i=1;i<=n;i++){
			if(s1.find(mp1[i])!=string::npos&&mp1[i].find(st)!=string::npos&&mp2[i].find(fst)!=string::npos){
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
