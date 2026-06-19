#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN];
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=2,ans=n;
	while(r<=n){
		if(a[r]>a[l]) l++,ans--;
		r++;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
