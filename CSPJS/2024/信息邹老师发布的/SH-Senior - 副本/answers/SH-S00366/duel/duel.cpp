#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
bool dth[N],att[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int j=1;
	for(int i=1;i<=n && j<=n;i++){
		while((a[j]<=a[i] || att[j]) && j<=n) j++;
		if(j<=n){
			att[j]=true;
			dth[i]=true;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!dth[i])ans++;
	}
	cout<<ans;
	return 0;
}

