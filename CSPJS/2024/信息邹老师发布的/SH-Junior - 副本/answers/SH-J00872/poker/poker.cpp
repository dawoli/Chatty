#include<bits/stdc++.h>
using namespace std;
int n,ans,sum;
char a[100][2];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	ans=52-n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(a[i][0]==a[j][0]&&a[i][1]==a[j][1])sum++;
		}
	}
	ans+=sum/2;
	cout<<ans;
	return 0;
}
