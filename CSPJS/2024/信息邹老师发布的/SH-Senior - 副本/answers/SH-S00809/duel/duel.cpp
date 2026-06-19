#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;
const int N=1e5+5;
int n,a[N],mp[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	int ans=0;
	a[0]=a[1];
	rep(i,1,n)
		if(a[i]!=a[i-1]){
			if(mp[a[i]]>=mp[a[i-1]]){
				ans+=mp[a[i-1]];
			}
			else{
				ans+=mp[a[i]];
				mp[a[i]]+=(mp[a[i-1]]-mp[a[i]]);
			}
		}
	cout<<(n-ans)<<endl;
	return 0;
} 
