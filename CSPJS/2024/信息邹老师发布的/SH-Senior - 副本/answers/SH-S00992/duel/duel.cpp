#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;ans=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int pos=1;
	for(int i=1;i<=n;i++){
		while(a[pos]<=a[i]&&pos<=n) pos++;
		if(pos>n) break;
		pos++;ans--;
	}
	cout<<ans;
	return 0;
} 
