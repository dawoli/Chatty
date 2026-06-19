#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
}
#define N 555
int n,m,a[N],b[N],ans;
string s;
signed main(){
	open("employ");
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=i;
	do{
		int sum=0;
		for(int i=1;i<=n;i++)
			if(sum>=a[b[i]]||s[i-1]=='0')
				++sum;
//		for(int i=1;i<=n;i++)
//			cerr<<b[i]<<' ';
//		cerr<<endl;
//		cerr<<sum<<endl;
		if(n-sum>=m)++ans;
	}while(next_permutation(b+1,b+1+n));
	cout<<ans<<endl;
}
