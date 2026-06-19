#include<bits/stdc++.h>
using namespace std;

int n,a[100005],ans;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);ans=n;
	for(int i=1,j=1;i<=n;i++){
		if(j<i&&a[i]>a[j]){
			ans--;j++;
		}
	}
	cout<<ans;
	return 0;
}
