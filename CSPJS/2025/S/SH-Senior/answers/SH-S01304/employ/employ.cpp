#include<bits/stdc++.h>
using namespace std;
long long n,m,x[100005],c[100005],d[100005],id[100005],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) id[i]=i;
	do{
		int now=0,f=0;
		for(int i=1;i<=n;i++) if(now>=c[id[i]]||s[i-1]=='0') now++;else f++;
		if(f>=m) ans++;
	}while(next_permutation(id+1,id+n+1));
	cout<<ans<<endl;
	return 0;
}

