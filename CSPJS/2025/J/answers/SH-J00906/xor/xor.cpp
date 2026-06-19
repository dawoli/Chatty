#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define int long long
#define N 555555
int n,k,a[N],r,ans,s[N],l[N];
signed main(){
	open("xor");
	cin>>n>>k;
	memset(l,-1,sizeof(l));
	l[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(l[s[i]^k]>=r)
			++ans,r=i;
		l[s[i]]=i;
	}
	cout<<ans<<endl;
}
