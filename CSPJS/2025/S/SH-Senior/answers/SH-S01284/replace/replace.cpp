#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
map<string,string>d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		d[a]=b;
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		for(int j=0;j<a.size();j++){
			for(int k=1;k<=b.size()-j;k++){
				if(d[a.substr(j,k)]==b.substr(j,k)&&a.substr(0,j)==b.substr(0,j)&&a.substr(j+k,a.size()-j-k+1)==b.substr(j+k,a.size()-j-k+1))ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

