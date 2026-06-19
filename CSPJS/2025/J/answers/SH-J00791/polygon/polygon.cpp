#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5005]={0}, z=0;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int a2[5005]={0};
	for(int i=1; i<=n; i++){
		a2[i]=a2[i-1]+a[i];
	}
	n++;
	long long ans=0;
	while(n--){
		if(n<=2) break;
		for(int i=n-1; i>1; i--){
			for(int j=i-1; j>0; j--){
				if(a2[i]-a2[j-1]>a[n]){
					ans+=j;ans%=998244353;break;
				}
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
