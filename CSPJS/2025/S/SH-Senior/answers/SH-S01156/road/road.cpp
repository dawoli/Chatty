#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int c[11],a[11][10001];
long long tot=1e14;
bool d[11],e[11],f[10001];
struct node{
	int u,v,w;
};
node t[1000001];
node temp[2000001];
bool cmp(node x,node y){
	return x.w<y.w;
}
void search(int num){
	for(int i=1;i<=k;i++){
		if(num>k){
			long long sum=0,cnt=0,ccnt=0;
			for(int i=1;i<=m;i++){
				ccnt++;
				temp[i].u=t[i].u,temp[i].v=t[i].v,temp[i].w=t[i].w;
			}
			for(int i=1;i<=k;i++){
				if(d[i]){
					cnt++;
					for(int j=1;j<=n;j++){
						ccnt++;
						temp[ccnt].u=n+i,temp[ccnt].v=j,temp[ccnt].w=a[i][j];
					}
				}
			}
			sort(temp+1,temp+ccnt+1,cmp);
			int last;
			for(int i=1;i<=n+cnt-1;i++){
				if(temp[i].u>n){
					last=i;
					if(!e[temp[i].u-n]) e[temp[i].u-n]=1;
					sum+=c[temp[i].u-n];
				}
				if(temp[i].u<=n) f[temp[i].u]=1;
				f[temp[i].v]=1;
				sum+=temp[i].w;
			}
			int lost=0;
			for(int i=1;i<=n;i++){
				if(!f[i]){
					lost=i;
					break;
				}
			}
			if(lost>0){
				for(int i=n+cnt;i<=ccnt;i++){
					if(temp[i].u==lost||temp[i].v==lost) sum=sum-temp[last].w+temp[i].w;
				}
			}
			tot=min(tot,sum);
		}
		else{
			d[i]=1;
			search(num+1);
			d[i]=0;
			search(num+1);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>t[i].u>>t[i].v>>t[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	search(1);
	cout<<tot;
	fclose(stdin);
	fclose(stdout);
}
