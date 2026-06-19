#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","stdin",stdin);
	freopen("polygon.out","stdout",stdout);
	int a[5005],n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans[5005];
	ans[1]=0;
	ans[2]=0;
	for(int i=3;i<=n;i++){
		ans[i]=ans[i-1]+ans[i-2];
		ans[i]%=998,244,353;
		for(int j=1;j<=i-2;j++){
			ans[i]+=j;
			ans[i]%=998,244,353;
		}
	}
	cout<<ans[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
