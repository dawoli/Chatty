#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int a[N]; 
int n;
int ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ans=n;
	int i=1,j=2;
	while(i<=n-1&&j<=n){
		while(a[i]==a[j]) j++;
		if(j<=n) ans--,i++,j++;
	}
	cout<<ans;
	return 0;
}
