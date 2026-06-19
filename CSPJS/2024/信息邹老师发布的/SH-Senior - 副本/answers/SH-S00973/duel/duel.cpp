#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int a[100005]={0};
	long long minn=0x3f3f3f3f3f;
	int maxn=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
		if(x<minn) minn=x;
		if(x>maxn) maxn=x;
	}
	int ans=0;
	for(int i=minn;i<=maxn;i++){
		if(ans<a[i]) ans=a[i];
	}
	cout<<ans;
}
