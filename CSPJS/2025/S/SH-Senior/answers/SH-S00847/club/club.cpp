#include<bits/stdc++.h>
using namespace std;
int p,n;
int s[10001][4];
int num=0;
int ans=0;
int cnt[3]={};
int dfs(int dep){
	for(int i=1;i<=3;i++){
		if(cnt[i]+1<=n/2){
			num+=s[dep][i];
			cnt[i]++;
			if(dep==n){
				ans=max(ans,num);
			}
			else{
				dfs(dep+1);
			}
			num-=s[dep][i];
			cnt[i]--;
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>p;
	for(int o=1;o<=p;o++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i][1]>>s[i][2]>>s[i][3];
		}
		for(int i=1;i<=3;i++){
			cnt[i]=0;
		}
		num=0;
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
