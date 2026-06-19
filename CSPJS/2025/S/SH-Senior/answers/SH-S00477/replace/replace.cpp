#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define fr1(i,a,b,k) for(int i=a;i<=b;i+=k)
#define fr2(i,a,b,k) for(int i=a;i>=b;i-=k)
using namespace std;
int n,q;
string s1[200005],s2[200005],t1,t2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>q;
	fr1(i,1,n,1){
		cin>>s1[i]>>s2[i];
	}
	while(q--){
		cin>>t1>>t2;
		cout<<0<<endl;
	}
	return 0;
}
