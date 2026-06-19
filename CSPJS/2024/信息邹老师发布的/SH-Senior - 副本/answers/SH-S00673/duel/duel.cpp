#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans,a[N];
int s[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int i,g=0,k=1;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=n;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		s[i]=1;
	}
	for(i=1;i<n;i++){
		if(a[i]==a[i+1]){
			s[k]++;
			if(g&&s[g]) s[g]--,ans--;
		}else{
			s[k]--;
			ans--;
			g=k;
			k=i+1;
		}
	}
	cout<<ans;
	return 0;
}
