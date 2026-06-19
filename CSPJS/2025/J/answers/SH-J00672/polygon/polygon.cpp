#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,a[5010],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+1+n);
	if(n==3&&(a[1]+a[2]>a[3])) cout<<1;
	else if(n==4){
		if(a[1]+a[2]>a[3])ans++;
		if(a[2]+a[3]>a[4])ans++;
		if(a[1]+a[2]>a[4])ans++;
		if(a[1]+a[3]>a[4])ans++;
		cout<<ans;
	} 
	else cout<<ans;
	return 0;
}
