#include <iostream>
#include <cstdio>
using namespace std;
const int N=5e5+5;
int n,k,a[N],s[N];
int f[N],lst[1<<22];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	fill(lst+1,lst+(1<<21)+1,-1);
	for(int i=1;i<=n;i++) {
		f[i]=f[i-1];
		if(lst[s[i]^k]!=-1) f[i]=max(f[i],f[lst[s[i]^k]]+1);
		lst[s[i]]=i;
	}
	cout<<f[n];
	return 0;
}
