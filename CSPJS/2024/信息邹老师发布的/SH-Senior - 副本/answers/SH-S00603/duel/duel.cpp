#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int n,t,mx,realmonster,a[100000];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&t),++a[t],mx=max(mx,t);
	int ans=n;
	for(int i=0;i<=mx;++i){
		realmonster=a[i];
		for(int j=0;j<i;++j)
			if(a[i]&&a[j]){
				ans -=min(a[j],a[i]);
				a[j]-=min(a[j],a[i]);
				a[i]-=min(a[j],a[i]);
			}
		a[i]=realmonster;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
