#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10010],kk,cchs[10010],chs[10010];
long long res,ans=LONG_LONG_MAX,t[20][10010],st[20],c[20],stt=LONG_LONG_MAX;
bool xt[10010];
priority_queue<int> h; 
struct edge{
	int x,y;
	long long w;
}a[1000010];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if (x==f[x]) return x;
	return f[x]=find(f[x]);
}
int fdmin(int x,int p){
	int rr=INT_MAX,nn=1,idx;
	while (p){
//		cout<<p%2;
		if (p%2==1&&rr>t[nn][x]){
			rr=t[nn][x];
			cchs[x]=nn;
		}
		nn++;
		p>>=1;
	}
//	cout<<" "<<rr<<"\n";
	return rr;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i = 1; i <= m; i++){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	sort(a+1,a+1+m,cmp);
//	cout<<a[1].w<<" "<<a[2].w<<"\n";
	for (int i = 1; i <= k; i++){
		cin>>c[i];
		for (int j = 1; j <= n; j++){
			cin>>t[i][j];
			st[i]+=t[i][j];
		}
	}
//	cout<<"\n";
	for (int i = 1; i <= (1<<k)-1; i++){
		int p=i,nn=1;
		long long now=0;
		while (p){
			now+=c[nn];
			nn++;
			p>>=1;
		}
		for (int j = 1; j <= n; j++){
			now+=fdmin(j,i);
		}
//		cout<<now<<"\n";
		if (stt>now){
			stt=now;
			memcpy(chs,cchs,sizeof chs);
		}
	}
	for (int j = 1; j <= n; j++){
		f[j]=j;
//		cout<<t[chs[j]][j]<<" ";
	}
	for (int i = 1; i <= m; i++){
		int x=find(a[i].x),y=find(a[i].y);
		if (x!=y){
//			cout<<stt<<" "<<res<<"\n";
			if (k>0) ans=min(ans,stt+res);
			else ans=res;
			res+=a[i].w;
			kk++;
//			cout<<ans<<"\n";
			if (t[chs[x]][x]>t[chs[y]][y]){
				if (!xt[x]){
					xt[x]=1;
//					stt-=t[chs[x]][x];
					h.push(t[chs[x]][x]);
					f[x]=y;
				}
				if (!xt[y]){
					xt[y]=1;
					h.push(t[chs[y]][y]);
//					stt-=t[chs[y]][y];
//					f[y]=x;
				}
			}
			else {
				if (!xt[y]){
					xt[y]=1;
					h.push(t[chs[y]][y]);
//					f[y]=x;
				}
				else if (!xt[x]){
					xt[x]=1;
					h.push(t[chs[x]][x]);
					f[x]=y;
				}
			}
			f[x]=y;
			if (h.size()){
				stt-=h.top();
				h.pop();
			}
			if (kk==n-1){
				if (k>0) ans=min(ans,res+stt);
				else ans=res;
//				cout<<ans<<"\n";
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
