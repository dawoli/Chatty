#include<bits/stdc++.h>
using namespace std;
int n,q;
string a[200005];
string b[200005];
map<string,string>t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		t[a[i]]=b[i];
	}
	while(q--){
		int l=-1,r;
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<x.size();i++){
			if(x[i]!=y[i]){
				r=i;
				if(l==-1){
					l=i;
				}
			}
		}
		string now,to;
		for(int i=l;i<=r;i++){
			now+=x[i];
			to+=y[i];
		}
		string now2=now;
		string to2=to;
		int ans=0;
//		if(t[now]==to){
//			ans++;
//		}
		for(int i=l;i>=0;i--){
			string tt,ttt;
			for(int j=i;j<l;j++){
				tt+=x[j];
				ttt+=y[j];
			}
			tt+=now2;
			ttt+=to2;
			if(t[tt]==ttt){
				ans++;
			}
			for(int j=r+1;j<x.size();j++){
				tt+=x[j];
				ttt+=y[j];
				if(t[tt]==ttt){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
