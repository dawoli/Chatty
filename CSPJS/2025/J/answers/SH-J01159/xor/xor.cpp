#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
}rec[1009];
int f[1009],dult1[109],dult2[109];
int res[1009][1009];
int n,m,now,flag;
int cmp(node p,node q){
	return p.a<q.a;
}
int ans_all=0;
int bfs(int now_all,int end_time,int cnt_all){
	if(now_all==now){
		ans_all=max(ans_all,cnt_all);
		return 0;
	}
	if(rec[now_all+1].a>end_time)
		bfs(now_all+1,rec[now_all+1].b,cnt_all+1);
	bfs(now_all+1,end_time,cnt_all);
}
int andor(int x,int y){
	for(int i=0;i<=20;i++) dult1[i]=dult2[i]=0;
	int x_=x,y_=y,cnt=0;
	for(int i=20;i>=0;i--){
		if(x_>=pow(2,i)){
			dult1[i]++;
			x_-=pow(2,i);
		}
		if(y_>=pow(2,i)){
			dult2[i]++;
			y_-=pow(2,i);
		}
	}
	for(int i=20;i>=0;i--)
		if(dult1[i]!=dult2[i]) cnt+=pow(2,i);
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(f[i]!=1) flag=1;
		res[i][i]=f[i];
	}
	if(!flag&&m==0){
		cout<<n/2<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ans=0;
			if(i==j) ans=f[i];
			else{
				ans=andor(res[i][j-1],f[j]);
				res[i][j]=ans;
			}
			if(ans==m){
				now++;
				rec[now].a=i,rec[now].b=j;
			}
		}
	}
	sort(rec+1,rec+1+now,cmp);
	bfs(1,rec[1].b,1);
	bfs(1,0,0);
	cout<<ans_all<<endl;
	return 0;
}
