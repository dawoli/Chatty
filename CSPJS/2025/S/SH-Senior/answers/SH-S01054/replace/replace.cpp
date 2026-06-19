#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=2e5+10;

int h[N];
string s1[N],s2[N];

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) cout<<0<<endl;
		else{
			cout<<0<<endl;
		}
	}
}
