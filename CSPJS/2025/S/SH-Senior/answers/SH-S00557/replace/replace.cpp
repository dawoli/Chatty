#include<bits/stdc++.h>
using namespace std;
const int N=200009;
string s[N],d[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i]>>d[i];
	}
	for(int i=0;i<q;i++){
		string t,u;
		cin>>t>>u;
		long long ans=0;
		for(int k=0;k<n;k++){
			long long ef=t.size()-s[k].size();
			for(int j=0;j<=ef;j++){
				string oi=t.substr(j,s[k].size());
				if(s[k]==oi){
					string e=t.substr(0,j);
					string pi=t.substr(j+s[k].size(),n-j+s[k].size());
					string m=e+d[k]+pi;
					if(m==u) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
