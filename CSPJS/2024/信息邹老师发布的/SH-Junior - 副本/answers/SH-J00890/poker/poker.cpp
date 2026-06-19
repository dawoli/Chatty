#include<bits/stdc++.h>
using namespace std;
char a[100],b[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	cin>>n;
	ans-=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<i;j++){
			if(a[i]==a[j]&&b[i]==b[j]){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
