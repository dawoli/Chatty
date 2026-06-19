#include<bits/stdc++.h>
using namespace std;
int n,maxn;
struct node {
	int x,y,z;
} a[100010];
int a1[100010],a2[100010],a3[100010];
bool cmp1(int xx,int yy) {
	int p=abs(a[xx].x-max(a[xx].y,a[xx].z));
	int q=abs(a[yy].x-max(a[yy].y,a[yy].z));
	return p>q;
}
bool cmp2(int xx,int yy) {
	int p=abs(a[xx].y-max(a[xx].x,a[xx].z));
	int q=abs(a[yy].y-max(a[yy].x,a[yy].z));
	return p>q;
}
bool cmp3(int xx,int yy) {
	int p=abs(a[xx].z-max(a[xx].y,a[xx].x));
	int q=abs(a[yy].z-max(a[yy].y,a[yy].x));
	return p>q;
}
void dfs(int xx,int cnt,int b,int c,int d){
	if(xx==n+1){
		maxn=max(cnt,maxn);
		return;
	}
	for(int i=1;i<=3;i++){
		if(i==1&&b<n/2){
			dfs(xx+1,cnt+a[xx].x,b+1,c,d);
		}
		if(i==2&&c<n/2){
			dfs(xx+1,cnt+a[xx].y,b,c+1,d);
		}
		if(i==3&&d<n/2){
			dfs(xx+1,cnt+a[xx].z,b,c,d+1);
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0); 
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		int xx=0,yy=0,zz=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		if(n<=20){
			maxn=0;
			dfs(1,0,0,0,0);
			cout<<maxn<<"\n"; 
			continue; 
		}
		int ma=n/2,cnt=0;
		for(int i=1; i<=n; i++) {
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z) {
				a1[++xx]=i;
				cnt+=a[i].x;
			} else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) {
				a2[++yy]=i;
				cnt+=a[i].y;
			} else {
				a3[++zz]=i;
				cnt+=a[i].z;
			}
		}
		if(xx>ma) {
			sort(a1+1,a1+xx+1,cmp1);
			for(; xx>ma; xx--) {
				int xxx=a1[xx];
				cnt-=a[xxx].x;
				if(a[xxx].y>=a[xxx].z&&yy<ma) {	
					a2[++yy]=xxx;
					cnt+=a[xxx].y;
				} else {
					a3[++zz]=xxx;
					cnt+=a[xxx].z;
				}
			}
		}
		if(yy>ma) {
			sort(a2+1,a2+yy+1,cmp2);
			for(; yy>ma; yy--) {
				int yyy=a2[yy];
				cnt-=a[yyy].y;
				if(a[yyy].x>=a[yyy].z&&xx<ma) {
					a1[++xx]=a2[yy];
					cnt+=a[a2[yy]].x;
				} else {
					a3[++zz]=a2[yy];
					cnt+=a[a2[yy]].z;
				}
			}
		}
		if(zz>ma) {
			sort(a3+1,a3+zz+1,cmp3);
			for(; zz>ma; zz--) {
				int zzz=a3[zz];
				cnt-=a[zzz].z;
				if(a[zzz].y>=a[zzz].z&&yy<ma) {
					a2[++yy]=a3[zz];
					cnt+=a[zzz].y;
				} else {
					a1[++xx]=a3[zz];
					cnt+=a[a3[zz]].x;
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
