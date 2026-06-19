#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
long long ans,cnt;
bool st[100010],att[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		st[i]=1;
	}
	sort(a+1,a+n+1);
	for(int i=1,j=2;i<=n,j<=n;){
		if(a[i]==a[j]||att[j]==1||st[i]==0){
			j++;
		}
		else{
			st[i]=0;
			att[j]=1;
			i++;
			j++;
		}
	}
	for(int i=1;i<=n;i++){
		if(st[i]){
			//cout<<a[i]<<" "; 
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
