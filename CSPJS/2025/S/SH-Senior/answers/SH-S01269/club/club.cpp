#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
ll a[N][5];
int ch1,ch2,ch3;
int if1[N];
ll ans=0;
bool vis[N];
struct Node{
	int s,w;
	ll b;
}node[N];
bool cmp(Node A,Node B){
	return A.b>B.b;
}
bool check(){
	if(ch1>(n/2))return 1;
	if(ch2>(n/2))return 1;
	if(ch3>(n/2))return 1;
	return 0;
}
void dfs(int x){
	if(x==n+1){
		if(check())return;
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum+=a[i][if1[i]];
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1)ch1++;
		if(i==2)ch2++;
		if(i==3)ch3++;
		if1[x]=i;
		dfs(x+1);
		if(i==1)ch1--;
		if(i==2)ch2--;
		if(i==3)ch3--;
	}
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<ans<<'\n';
	return;
}
void solve2(){
	int now=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			node[++now]={i,j,a[i][j]};
		}
	}
	sort(node+1,node+1+now,cmp);
	for(int i=1;i<=now;i++){
		if(vis[node[i].s])continue;
		if(node[i].w==1){
			if(ch1+1>(n/2))continue;
			ch1++;
		}
		if(node[i].w==2){
			if(ch2+1>(n/2))continue;
			ch2++;
		}
		if(node[i].w==3){
			if(ch3+1>(n/2))continue;
			ch3++;
		}
		ans+=node[i].b;
	}
	cout<<ans<<endl;
	return;
}
struct Node1{
	int ci,bi;
	ll ma;
	//²îÖµ£¬±àºÅ 
}node1[N];
bool cmp1(Node1 A,Node1 B){
	if(A.ci==B.ci)return A.ma>B.ma;
	else return A.ci>B.ci;
}
void solve3(){
	int now=0;
	for(int i=1;i<=n;i++){
		node1[++now]={abs(a[i][1]-a[i][2]),i,max(a[i][1],a[i][2])};
	}
	sort(node1+1,node1+1+now,cmp1);
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]){
			if(ch1+1>(n/2)){
				ch2++;
				ans+=a[i][2];
			}else{
				ch1++;
				ans+=a[i][1];
			}
		}else{
			if(ch2+1>(n/2)){
				ch1++;
				ans+=a[i][1];
			}else{
				ch2++;
				ans+=a[i][2];
			}
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ch1=0,ch2=0,ch3=0;
		ans=0;
		memset(if1,0,sizeof if1);
		memset(vis,0,sizeof vis);
		if(n<=10){
			solve1();
			continue;
		}
		int why2=0;
		int why3=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(a[i][j]==0&&j==2)why2++;
				if(a[i][j]==0&&j==3)why3++;
			}
		}
		if(why2==n&&why3==n){
			solve2();
			continue;
		}
		if(why3==n){
			solve3();
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
