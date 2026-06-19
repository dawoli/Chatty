#include <bits/stdc++.h>
using namespace std;
bool v[501];
int ans[501];
int a[501];
int n,m;
int ans1=0;
string s1;
void dfs(int k,int cnt,int cnt2){
	if(n==k){
		for(int i=0;i<n;i++){
			if(cnt<=a[i])cnt2++;
			if (s1[i]=='0')cnt++;
			
		}
		if(cnt2>=m)ans1++;
	}
	for(int i=0;i<n;i++){
		if(v[i])continue;
		v[i]=true;
		ans[k]=i;
		if(cnt<=a[i] and s1[i]=='1')cnt2++;
		if (s1[i]=='0' or cnt>a[i])cnt++;
		if(cnt2>=m){
			ans1++;
			return;
		}
		dfs(k+1,cnt,cnt2);
		v[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=0;i<n;i++)cin>>a[i];
	dfs(0,0,0);
	cout<<ans1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
