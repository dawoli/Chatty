#include<bits/stdc++.h>
using namespace std;
int n,a[100005],sum,ans;

int main(){
	freopen("duel4.in","r",stdin);
	freopen("duel4.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]==j){
			sum++;
			if(ans>0){
				ans--;
			}
			continue;
		}else{
			j=a[i];
			ans+=sum;
			ans--;
			sum=1;
		}
	}
	if(a[n]==a[n-1]){
		ans+=sum;
		
	}else{
		ans++;
	}
	cout<<ans;
	return 0;
} 
