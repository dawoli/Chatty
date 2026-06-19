#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m;
int a[maxn];
int ans1,ans2;
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n+m;i++) cin>>a[i];
	cout<<n<<" "<<m;
	return 0;
}
