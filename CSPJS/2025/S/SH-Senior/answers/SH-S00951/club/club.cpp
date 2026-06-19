#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100010][4];
struct node{
	int x,y;
};
bool cmpb1(node s,node t){
	return s.x-s.y<t.x-t.y;
}
bool cmpb2(node s,node t){
	return s.y-s.x<t.y-t.x;
}
bool cmp(int x,int y){
	return x>y;
}
int dfs(int pos,int cnt1,int cnt2,int cnt3){
	if(pos==n+1){
		return 0;
	}
	int x=0;
	if(cnt1<n/2){
		x=max(x,dfs(pos+1,cnt1+1,cnt2,cnt3)+a[pos][1]);
	}
	if(cnt2<n/2){
		x=max(x,dfs(pos+1,cnt1,cnt2+1,cnt3)+a[pos][2]);
	}
	if(cnt3<n/2){
		x=max(x,dfs(pos+1,cnt1,cnt2,cnt3+1)+a[pos][3]);
	}
	return x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T-->0){
		cin>>n;
		bool taska=1,taskb=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0){
				taska=0;
			}
			if(a[i][3]!=0){
				taska=0;
				taskb=0;
			}
		}
		if(n<=300){
			cout<<dfs(1,0,0,0)<<endl;
		}
		else if(taska){
			int q[100010],ansa=0;
			for(int i=1;i<=n;i++){
				q[i]=a[i][1];
			}
			sort(q+1,q+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ansa+=q[i];
			}
			cout<<ansa<<endl;
		}
		else if(taskb){
			int cnt[4]={0,0,0,0},sum[4]={0,0,0,0};
			node c1[100010],c2[100010];
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]){
					cnt[1]++;
					c1[cnt[1]].x=a[i][1];
					c1[cnt[1]].y=a[i][2];
					sum[1]+=a[i][1];
				}
				else{
					cnt[2]++;
					c2[cnt[2]].x=a[i][1];
					c2[cnt[2]].y=a[i][2];
					sum[2]+=a[i][2];
				}
			}
			if(cnt[1]>n/2){
				sort(c1+1,c1+cnt[1]+1,cmpb1);
				for(int i=1;i<=cnt[1]-n/2;i++){
					sum[1]-=c1[i].x;
					sum[2]+=c1[i].y;
				}
			}
			else{
				sort(c2+1,c2+cnt[2]+1,cmpb2);
				for(int i=1;i<=cnt[2]-n/2;i++){
					sum[1]+=c2[i].x;
					sum[2]-=c2[i].y;
				}
			}
			cout<<sum[1]+sum[2]<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=max(a[i][1],max(a[i][2],a[i][3]));
			}
			cout<<ans<<endl;
		}
	}
	
	
	return 0;
}
