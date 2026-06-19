#include<bits/stdc++.h>
using namespace std;
int n,a[100005],maax,sum;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;cin>>tmp;
		a[tmp]++;maax=max(maax,tmp);
	}
	for(int i=2;i<=maax;i++){
		if(a[i]!=0){
			sum+=min(a[i],a[i-1]);a[i]-=min(a[i],a[i-1]);
		}
		a[i]+=a[i-1];
	}
	cout<<n-sum;
	return 0;
}
