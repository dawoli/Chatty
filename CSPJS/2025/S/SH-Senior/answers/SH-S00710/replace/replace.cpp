#include<bits/stdc++.h>
using namespace std;
string a[200005][4];
int an[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string g,h;
		cin>>g;
		cin>>h;
		a[i][0]=g;
		a[i][1]=h;
		an[i][0]=g.size(); 
		int p=0,u=0;
		for(int j=0;j<a[i][0].size();j++){
			if(a[i][0][j]!=a[i][1][j]){
				
				p=j;
				an[i][1]=p;
			}
		}
		for(int j=a[i][0].size()-1;j>=0;j--){
			if(a[i][0][j]!=a[i][1][j]){
				
				u=j;
				an[i][2]=u;
			}
		}
		for(int I=u;I<=p;I++){
			a[i][2]+=a[i][0][I];
			a[i][3]+=a[i][1][I];
		}
	}
	while(q--){
		int ans=0,p=0,u=0;
		string t,tt,ttt="",tttt="";
		cin>>t;
		cin>>tt;
		if(t.size()!=tt.size()) {
			continue;
		}
		for(int j=0;j<t.size();j++){
			if(t[j]!=tt[j]){
				
				p=j;
			}
		}
		for(int j=t.size()-1;j>=0;j--){
			if(t[j]!=tt[j]){
				
				u=j;
			}
		}
		for(int i=u;i<=p;i++){
			ttt+=t[i];
			tttt+=tt[i];
		}
		for(int i=1;i<=n;i++){
			if(an[i][0]>t.size()){
				continue;
			}
			if(ttt==a[i][2] and tttt==a[i][3]){
				for(int e=an[i][1]-1;e>=0;e--){
					if(a[i][0][e]!=t[p-an[i][1]+e]){
						continue;
					}
				}
				for(int e=an[i][2];e<an[i][0];e++){
					if(a[i][0][e]!=t[u+e-an[i][2]+1]){
						continue;
					}
				}
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
