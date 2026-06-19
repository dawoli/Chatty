#include<bits/stdc++.h>
using namespace std;
int a[510],b[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,cnt=1,ans=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=i,cnt*=i;
	for(int i=1;i<=cnt;i++){
		int k=0;
		for(int j=1;j<=n;j++)if(j-k-1<a[b[j]]&&s[j-1]=='1')k++;
		if(k>=m)ans++;
		next_permutation(b+1,b+n+1);
	}
	cout<<ans;
	return 0;
}
