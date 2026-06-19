#include<bits/stdc++.h>
using namespace std;
int n,s[100005],tt[5];
long long ans;
struct node{
	int k1,k2,k3;
}a[100005];
void dfs(int num){
	num++;
	if(num>n){
		long long mx=0;
		for(int i=1;i<=n;i++){
			if(s[i]==1)mx+=a[i].k1;
			else if(s[i]==2)mx+=a[i].k2;
			else if(s[i]==3)mx+=a[i].k3;
		}
		ans=max(mx,ans);
		return;
	}
	for(int i=1;i<=3;i++){
		s[num]=i;
		tt[i]++;
		if(tt[i]<=n/2)dfs(num);
		tt[i]--;
		s[num]=0;
	}
	return;
}
int main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(tt,0,sizeof(tt));
		ans=0;
		cin>>n;
		if(n<100000){
			for(int i=1;i<=n;i++){
			cin>>a[i].k1>>a[i].k2>>a[i].k3;
			}
			dfs(0);	
		}
		else{
			priority_queue<int>q;
			for(int i=1;i<=n;i++){
			cin>>a[i].k1>>a[i].k2>>a[i].k3;
			q.push(a[i].k1);
			}
			for(int i=1;i<=n/2;i++){
				ans+=q.top();
				q.pop();
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
