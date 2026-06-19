#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int ans=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		if(a[i]>a[j]) {
		ans=ans-1;
		break;
		}
		}
		
	}
	cout<<ans;
}
