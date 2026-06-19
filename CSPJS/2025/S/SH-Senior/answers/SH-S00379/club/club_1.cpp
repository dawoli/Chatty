#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N][5],n,t,m,sum=0,b[N][5][5],ans[N],cnt[5];
bool check(int i,int x){
	return cnt[i]+x<=m;
}
signed main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxn=max(a[i][1],max(a[i][2],a[i][3]));
			sum+=maxn;
			for(int j=1;j<=3;j++){
				if(a[i][j]==maxn){
					ans[i]=j;
				} 
			}
			cnt[ans[i]]++;
			for(int j=1;j<=3;j++){
				for(int k=1;k<=3;k++){
					b[i][j][k]=a[i][j]-a[i][k];
				}
			}
		}
		for(int i=1;i<=3;i++){
			if(check(i,0)==1){
				continue;
			}else{
				while(check(i,0)){
					int minn=1e9,pos=0,to=0;//最小损失 倒霉孩子 倒霉孩子去哪里 
					for(int j=1;j<=n;j++){
						if(ans[j]!=i) continue;
						int mi=1e9;// 倒霉孩子的最小损失
						for(int k=1;k<=3;k++){
							if(b[j][i][k]<mi and check(k,1)){//能去 
								mi=b[j][i][k];
								to=k;
							}
						}
						if(mi<minn){
							minn=mi;pos=j;
						}
					}
					sum-=minn;
					ans[pos]=to; 
					cnt[i]--;
					cnt[to]++;
				}
			}
		}
		cout << sum << endl;
		sum=0;m=0;n=0;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(ans,0,sizeof ans);
		memset(cnt,0,sizeof cnt);
	}
	return 0;
}

