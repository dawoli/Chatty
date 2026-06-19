#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5010];
bool flag[5010];
int rp; 
void dfs(int now,int cnt,int maxx,int all){
	if(cnt>=3 and all>2*maxx)ans++;
	if(cnt==n)return;
	for(int i=now+1;i<n;i++){
		if(flag[i]==false and a[i]+all>2*maxx){
			flag[i]=true;
			dfs(i,cnt+1,max(maxx,a[i]),all+a[i]);
			flag[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	rp++;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		flag[i]=true;
		for(int j=i+1;j<n;j++){
			flag[j]=true;
			dfs(j,2,max(a[i],a[j]),a[i]+a[j]);
			flag[j]=false;
		}
		flag[i]=false;
	}
	cout<<ans<<endl;
	return 0;
}
