#include<bits/stdc++.h>
using namespace std;
struct node{
	int num,value;
};
bool cmp(node p,node q){
	return p.value>q.value;
}
void solve(){
	int vis[100005]={0};
	int n;
	cin>>n;
	node a[105],b[105],c[105];
	for(int i = 1;i<=n;i++){
		a[i].num=i,b[i].num=i,c[i].num=i;
		cin>>a[i].value>>b[i].value>>c[i].value;
	}
	int ans=0;
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	sort(c+1,c+1+n,cmp);
	queue<node> a1,b1,c1;
	for(int i = 1;i<=n;i++){a1.push({a[i].num,a[i].value});}
	for(int i = 1;i<=n;i++){b1.push({b[i].num,b[i].value});}
	for(int i = 1;i<=n;i++){c1.push({c[i].num,c[i].value});}
	int st1=n/2,st2=n/2,st3=n/2;
	for(int i = 1;i<=n;i++){
		int maxx=-1,cnt=-1,shetuan=-1;
		if(vis[a1.front().num]==1) a1.pop();
		if(vis[b1.front().num]==1) b1.pop();
		if(vis[c1.front().num]==1) c1.pop();
		if(a1.front().value>maxx&&st1>0){maxx=a1.front().value,cnt=a1.front().num,shetuan=1;}
		if(b1.front().value>maxx&&st2>0){maxx=b1.front().value,cnt=b1.front().num,shetuan=2;}
		if(c1.front().value>maxx&&st3>0){maxx=c1.front().value,cnt=c1.front().num,shetuan=3;}
		ans+=maxx;
		vis[cnt]=1;
		if(shetuan==1){st1-=1;}
		if(shetuan==2){st2-=1;}
		if(shetuan==3){st3-=1;}
	} 
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
