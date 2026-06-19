#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100002],b[100002],c[100002],cnt=0,sum=0;//yuan,,,tong,,,yuan_su
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(b[a[i]]==1){
			c[++cnt]=a[i];
		}
	}
	sort(c+1,c+cnt+1);
	int last=0;
	for(int i=1;i<=cnt;i++){
		if(c[i]==last) continue;
		sum+=min(b[c[i]],b[c[i+1]]);
	}
	cout<<n-sum<<endl;
	return 0;
}
