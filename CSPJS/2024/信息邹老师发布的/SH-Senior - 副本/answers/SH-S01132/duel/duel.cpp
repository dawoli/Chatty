#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],j,ans;
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
cin>>n;
ans=n;
for(int i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
for(int i=0;i<n;i++){
	while(a[j]<=a[i]&&j<n)j++;
	if(j<n&&a[j]>a[i])ans--;
	j++;
}
cout<<ans;
return 0;
}
