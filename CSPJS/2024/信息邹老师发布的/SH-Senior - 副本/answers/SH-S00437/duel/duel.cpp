#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int now=1;
	for(int i=1;i<=n;i++){
		for(int j=now;j<=n;j++){
			if(a[j]>a[i]){
				now=j+1;
				ans--;
			}
		}
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
