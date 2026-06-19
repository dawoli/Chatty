#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
string s1[N],s2[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,q;
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	if(q==1){
		/*
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			int f=1;
			for(int j=1;j<=n;j++){
				for(int k=0;k<s[j].size()){
					if(a[i]!=s[i]){
						f=0;
						break;
					}
				}
				if(f){
					string c=a;
					for(int k=0;k<s[j].size();k++){
						c[i]
					}
				}
			}
		}
		*/
		cout<<n;
		return 0;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		cout<<(a.size()-s1[i].size())/b.size()+(a.size()-s2[i].size())/b.size();
	}
	return 0;
}

