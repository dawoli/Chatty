#include<bits/stdc++.h> 
using namespace std;
const int maxn=100005;
int t,n,sum[4]={0},ans;
struct node{
	int f,s,t;
}a[maxn];
bool check(){
	for(int i=1;i<=n;i++){
		if(!(a[i].s==0) or !(a[i].t==0)){
			return false;
		}
	}
	return true;
}
bool cmp(node x,node y){
	if(x.f>y.f) return 1;
	else return 0;
}
int dfs(int pos,int ch){
	int tmp;
	sum[ch]++;
	if(pos==n){
		if(ch==1) return a[pos].f;
		if(ch==2) return a[pos].s;
		if(ch==3) return a[pos].t;
	}
	if(sum[1]<(n/2)&&sum[2]<(n/2)&&sum[3]<(n/2)){
		tmp=max(max(dfs(pos+1,1),dfs(pos+1,2)),dfs(pos+1,3));
		if(ch==1) return tmp+a[pos].f;
		if(ch==2) return tmp+a[pos].s;
		if(ch==3) return tmp+a[pos].t;
	}
	else if(sum[1]>=(n/2)&&sum[2]<(n/2)&&sum[3]<(n/2)){
		tmp=max(dfs(pos+1,2),dfs(pos+1,3));
		if(ch==1) return tmp+a[pos].f;
		if(ch==2) return tmp+a[pos].s;
		if(ch==3) return tmp+a[pos].t;
	}
	else if(sum[1]<(n/2)&&sum[2]>=(n/2)&&sum[3]<(n/2)){
		tmp=max(dfs(pos+1,1),dfs(pos+1,3));
		if(ch==1) return tmp+a[pos].f;
		if(ch==2) return tmp+a[pos].s;
		if(ch==3) return tmp+a[pos].t;
	}
	else if(sum[1]<(n/2)&&sum[2]<(n/2)&&sum[3]>=(n/2)){
		tmp=max(dfs(pos+1,2),dfs(pos+1,1));
		if(ch==1) return tmp+a[pos].f;
		if(ch==2) return tmp+a[pos].s;
		if(ch==3) return tmp+a[pos].t;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].f>>a[i].s>>a[i].t;
		if(n==2){
			int one[3]={a[1].f,a[1].s,a[1].t};
			int two[3]={a[2].f,a[2].s,a[2].t};
			sort(one,one+3);
			sort(two,two+3);
			cout<<max(one[2]+two[1],one[1]+two[2])<<endl;
		}
		else if(check()){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].f;
			}
			cout<<ans<<endl;
		}
		else{
			ans=max(dfs(1,1),dfs(1,2));
			ans=max(ans,dfs(1,3));
			cout<<ans<<endl;
		}
	}
	return 0;
}
