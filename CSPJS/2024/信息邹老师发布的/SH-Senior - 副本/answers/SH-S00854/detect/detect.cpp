#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,m,L,V,d[maxn],v[maxn],a[maxn],s[maxn],ans1,ans2,flag[maxn],pos1[maxn],pos2[maxn];
double p[maxn],t[maxn];
struct node{int val,tag;}c[maxn];
bool cmp(node x,node y){return x.val<y.val;}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		ans1=0;ans2=0;
		memset(flag,0,sizeof(flag));
		memset(pos1,0,sizeof(pos1));
		memset(pos2,0,sizeof(pos2));
		
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]!=0)t[i]=(double)(V*V-v[i]*v[i])/(double)(2*a[i])+(double)d[i];
		}
		for(int i=1;i<=m;i++)cin>>p[i];
		sort(p+1,p+1+m);
		for(int i=1;i<=n;i++){
			if(a[i]>0){
				if(t[i]<(double)d[i])t[i]=d[i];
				pos1[i]=lower_bound(p+1,p+1+m,t[i])-p+1;
				if(pos1[i]<=m){
					ans1++;
					pos2[i]=m;
					flag[i]=1;
				}
			}
			else if(a[i]==0){
				if(v[i]>V){
					pos1[i]=lower_bound(p+1,p+1+m,d[i])-p+1;
					if(pos1[i]<=m){
						ans1++;
						pos2[i]=m;
						flag[i]=1;
					}
				}
			}
			else{
				if(t[i]<(double)d[i])continue;
				if(t[i]>(double)L)t[i]=(double)L;
				pos1[i]=lower_bound(p+1,p+1+m,d[i])-p+1,pos2[i]=lower_bound(p+1,p+1+m,t[i])-p;
				if(p[pos2[i]]!=t[i])pos2[i]--;
				if(pos1[i]<=pos2[i]){
					ans1++;
					flag[i]=1;
				}
			}
		}
		int num=0;
		for(int i=1;i<=n;i++)
			if(flag[i]==1){
				c[++num]={pos1[i],0};
				c[++num]={pos2[i],1};
			}
		sort(c+1,c+1+num,cmp);
		int cnt=0;
		for(int i=1;i<=num;i++){
			if(c[i].tag==0)cnt++;
			else if(cnt!=0){
				cout<<c[i].val<<endl;
				ans2++;
				cnt=0;
			}
		}
		cout<<ans1<<" "<<m-ans2<<endl;
	}
	return 0;
}
