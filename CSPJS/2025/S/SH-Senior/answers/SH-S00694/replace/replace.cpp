#include<bits/stdc++.h>
using namespace std;
struct node{
	string s,t;
}a[200005];
long long n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].t;
	}
	for(int i=1;i<=q;i++){
		string ts,tt;
		long long ans=0;
		cin>>ts>>tt;
		for(int j=1;j<=n;j++){
			for(int k=0;k+a[j].s.length()<=ts.length();k++){
				if(a[j].s==ts.substr(k,a[j].s.length())&&ts.substr(0,k)+a[j].t+ts.substr(k+a[j].s.length(),ts.length()-k-a[j].t.length())==tt){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
