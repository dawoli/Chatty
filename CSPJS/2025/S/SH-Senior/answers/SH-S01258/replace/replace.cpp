#include<bits/stdc++.h>
using namespace std;
int n,q,ans;
string s[200005][2];
string t1,t2;
bool cmp(int st,int en){
	for(int i=st;i<=en;i++){
		if(t1[i]!=t2[i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			int pos1=t1.find(s[i][1]);
			int pos2=t2.find(s[i][2]);
			if(pos1==pos2&&pos1<=t1.length())
			{
				if(cmp(0,pos1-1) && cmp(pos1+s[i][1].length(),t1.length()))
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
