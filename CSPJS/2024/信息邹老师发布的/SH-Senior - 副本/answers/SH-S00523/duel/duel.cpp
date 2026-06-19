#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
int cnt,ans;
bool aliv[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	cnt++;
	int nw=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[nw]){
			aliv[nw++]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!aliv[i])ans++;
	}
	cout<<ans;
	return 0;
}
