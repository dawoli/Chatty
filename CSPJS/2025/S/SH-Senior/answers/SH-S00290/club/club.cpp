#include<bits/stdc++.h>
using namespace std;
struct club{
	int id;
	long long val;
};
struct nOde{
	club b[4];
}a[100005];
long long T,n,cnt[4],ans,c[100005][4],d[100005];
bool flag=1;
bool cmp(nOde p,nOde q){
	if(p.b[1].val==q.b[1].val){
		if(p.b[2].val<q.b[2].val) return p.b[3].val<q.b[3].val;
		return p.b[2].val<q.b[2].val;
	}
	return p.b[1].val<q.b[1].val;
}
bool cmpp(club p,club q){
	return p.val>q.val;
}
bool cmppp(int p,int q){
	return p>q;
}
void dfs(long long x,long long sum){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<(n>>1)){
			cnt[i]++;
			dfs(x+1,sum+c[x][i]);
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		
		if(n<=10){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					cin>>c[i][j];
				}
			}
			dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		
		for(int i=1;i<=n;i++){
			club tmp[4];
			for(int j=1;j<=3;j++){
				cin>>tmp[j].val;
				tmp[j].id=j;
			}
			d[i]=tmp[1].val;
			if(tmp[2].val!=0||tmp[3].val!=0) flag=0;
			sort(tmp+1,tmp+4,cmpp);
			for(int j=1;j<=3;j++){
				a[i].b[j]=tmp[j];
			}
		}
		if(flag){
			sort(d+1,d+1+n,cmppp);
			for(int i=1;i<=n/2;i++){
				ans+=d[i];
			}
			cout<<ans<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				club res=a[i].b[j];
				if(cnt[res.id]<n/2){
					cnt[res.id]++;
					ans+=res.val;
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
