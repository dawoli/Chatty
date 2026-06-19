#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 100005
struct C{
	int le,re;
}c[N];
int inv;
long long T,n,m,l,v,p[N*10],ans1,ans2;
bool vis[N*10];
bool cmp(C a,C b){
	return a.re<b.re;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		ans1=ans2=0;
		memset(p,0,sizeof(p));
		memset(c,0,sizeof(c));
		memset(vis,0,sizeof(vis));
		cin>>n>>m>>l>>v;
		int di,vi,ai;
		for(int i=1;i<=n;i++){
			double pl;
			cin>>di>>vi>>ai;
			if(vi>v&&ai>=0){
				inv++;
				c[inv].le=di;
				c[inv].re=l;
			}else if(vi<=v&&ai>0){
				pl=double((v*v-vi*vi))/double(2*ai);
				if(pl+di<=l){
					inv++;
					c[inv].le=int(pl+di+1);
					c[inv].re=l;
				}
			}else if(vi>=v&&ai<0){
				inv++;
				c[inv].le=di;
				pl=double((v*v-vi*vi))/double(2*ai);
				if(pl+di<=l){
					c[inv].re=int(pl+di-0.0001);
				}else{
					c[inv].re=l;
				}
			}
		}
		sort(c+1,c+inv+1,cmp);
		for(int i=1;i<=m;i++){
			cin>>di;
			p[di]=true;
		}
		for(int i=1;i<=inv;i++){
			for(int j=c[i].re;j>=c[i].le;j--){
				if(p[j]==true){
					ans1++;
					break;
				}
			}
		}
		for(int i=1;i<=inv;i++){
			int rem=0;
			for(int j=c[i].re;j>=c[i].le;j--){
				if(vis[j]==true){
					rem=1;
					break;
				}
			}
			if(rem){
				continue;
			}else{
				for(int j=c[i].re;j>=c[i].le;j--){
					if(p[j]==true){
						ans2++;
						vis[j]=true;
						break;
					}
				}
			}
		}
		cout<<ans1<<" "<<m-ans2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
