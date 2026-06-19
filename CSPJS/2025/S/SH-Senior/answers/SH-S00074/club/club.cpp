#include<bits/stdc++.h>
using namespace std;
int n,a[8][100005],ans,t;
void f(int k,int v,int cnt,bool tag[100005]){
	if (cnt==0||k>3){
		ans=max(ans,v);
		return ;
	}
	f(k+1,v,cnt,tag);
	for (int i=1;i<=n;i++){
		if (!tag[i]){
			tag[i]=1;
			f(k+1,v+a[k][i],cnt,tag);
			f(k,v+a[k][i],cnt-1,tag);
			tag[i]=0;
		}
	}
} 
bool g[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--){
		ans=0;
		cin >> n;
		for (int j=1;j<=n;j++){
			for (int i=1;i<=3;i++){
				cin >> a[i][j];
			}
		}
		f(1,0,n/2,g);
		cout << ans<<endl;
	}
	return 0;
} 
