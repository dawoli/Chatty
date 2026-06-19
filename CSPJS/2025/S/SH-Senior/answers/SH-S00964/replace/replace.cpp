#include<bits/stdc++.h>
using namespace std;
int n,q,st,en,tot,cnt;
string s1[200005],s2[200005],t1,t2,t;
struct zc{
	int s,e,id;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	if(q>1) return 0;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	cin>>t1>>t2;
	for(int i=0;i<t1.size();i++)
	if(t1[i]!=t2[i]){st=i;break;}
	for(int i=t1.size()-1;i>=0;i--)
	if(t1[i]!=t2[i]){en=i;break;}
	for(int j=1;j<=n;j++){
		int p,q;
		for(int i=0;i<s1[j].size();i++)
		if(s1[i][j]!=s2[i][j]){p=i;break;}
		for(int i=s1[j].size()-1;i>=0;i--)
		if(s1[j][i]!=s2[j][i]){q=i;break;}
		if(q-p!=en-st) continue;cout<<p<<q<<endl;
		bool ff=0;
		for(int i=0;i<=q-p;i++){
			if(s1[j][p+i]!=t1[st+i] || s2[j][p+i]!=t2[st+i]){
				ff=1;break;
			}
		}
		if(ff==0) continue;
		if(p>st) continue;
		if(s1[j].size()-q>t1.size()-en) continue;
		for(int i=0;i<s1[j].size();i++){
			if(s1[j][i]!=t1[st-p+i] || s2[j][i]!=t2[st-p+i]){
				ff=0;break;
			}
		}
		if(ff) cnt++;
	}
	cout<<cnt;
	return 0;
}
