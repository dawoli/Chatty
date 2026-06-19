#include<bits/stdc++.h> //I fuck CCF 
#define int long long //我要上迷惑行为大赏 
using namespace std;
const int N=2e5+10;
int n,q;
struct node{
	string l,r;
}a[N];
int ans;
string s1,s2;
void solve(){
	ans=0;
	cin>>s1>>s2;
	for(int i=1;i<=n;i++){
		string x=s1;
		for(int k=0;k<x.length();k++){
			for(int j=0;k+j<x.length();j++){
				if(x[k+j]!=a[i].l[j])break;
				if(j==a[i].l.length()-1){//匹配成功 
					for(int id=0;id<a[i].l.length();id++){
						x[k+id]=a[i].r[id];
					}if(x==s2){
						ans++;
//						cout<<x<<' '<<s2<<' ';
					}for(int id=0;id<a[i].l.length();id++){
						x[k+id]=s1[k+id];
					}break;
				}
			}
		}
	}cout<<ans<<"\n";
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
	}while(q--){
		solve();
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
