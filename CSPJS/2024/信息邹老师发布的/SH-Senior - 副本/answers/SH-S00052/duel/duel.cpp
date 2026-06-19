#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
int n;
int r[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>r[i];
	sort(r+1,r+1+n);
//	int j=upper_bound(r+1,r+1+n,r[1])-r;
//	for(int i=1;i<=n;i++)cout<<r[i]<<" ";cout<<endl;
//	cout<<j;
	int i=1,j=1,ans=n;
	while(j<=n){
		while(r[j]<=r[i])j++;
		if(j>n)continue;
		ans--;
//		cout<<j<<endl;
		i++;j++;
	}
	cout<<ans<<endl;
	return 0;
} 
