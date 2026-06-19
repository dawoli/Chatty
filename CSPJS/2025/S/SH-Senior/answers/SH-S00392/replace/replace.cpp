#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,q;
string a[N],b[N];
string x,y;
int solve(){
	int ans=0;
	for(int l=0;l<x.size();l++){
		if(l!=0)
			if(x[l-1]!=y[l-1]) break;
		for(int j=1;j<=n;j++){
			if(l+a[j].size()-1>x.size()-1) continue;
			bool fl=true;
			for(int i=0;i<y.size();i++){
				char aa,bb=y[i];
				if(i<l || l+a[j].size()-1<i) aa=x[i];
				else{
					if(x[i]!=a[j][i-l]){
						fl=false;
						break;
					}
					aa=b[j][i-l];
				}
				if(aa!=bb){
					fl=false;
					break;
				}
			}
			if(fl){
				//cout<<l<<" "<<j<<"\n";
				ans++;
			}
		}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
//	for(int i=1;i<=q;i++) cout<<"0\n";
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(q--){
		cin>>x>>y;
		if(x.size()!=y.size()) cout<<"0\n";
		else cout<<solve()<<"\n";
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
