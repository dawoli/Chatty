#include<bits/stdc++.h>
using namespace std;
struct City{
	int road[5005][2];
//	int num[5005];
//	int pa;
	int cnt=0;
}city[10005];
int n,m,k;
int c[15],num[15][10005];
pair<pair<int,int>,bool> flag[10005];
int cntf=0,ans=0,cnt[100005];

void qsort(int num, int l,int r){
	if(l<r){
		int mid=(l+r)/2;
		int x=mid-1,y=mid+1;
		while (city[num].road[x][1]<city[num].road[mid][1]&&x>=l) x--;
		while (city[num].road[y][1]>city[num].road[mid][1]&&y<=r) y++;
		swap(city[num].road[x],city[num].road[x]);
		qsort(num,l,mid);
		qsort(num,mid+1,r);
//		ans[0][0]=num[l].first;
//		ans[0][1]=num[l].second;
//		ans[1][0]=num[l+1].first;
//		ans[1][1]=num[l+1].second;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	bool typea=true;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
//		cout<<1<<endl;
		city[u].road[city[u].cnt][1]=w;
		city[v].road[city[v].cnt][1]=w;
		city[u].road[city[u].cnt++][0]=v;
		city[v].road[city[v].cnt++][0]=u;
//		city[u].num[city[u].cnt++]=v;
//		city[v].num[city[v].cnt++]=u;
//		city[u].pa=u;
//		city[v].pa=v;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) typea=false;
		for(int j=1;j<=n;j++){
			cin>>num[i][j];
			if(num[i][j]!=0) typea=false;
		}
	}
	if(typea){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
//		pair<pair<int,int>,int> node={{0,0},0x7fffffff};
		qsort(i,0,city[i].cnt-1);
		for(int j=0;j<city[i].cnt;j++){
			bool built=false;
//			for(int k=0;k<=cntf;k++){
//				if( (flag[k].first.first==i&&flag[k].first.second==city[i].road[j].first)||(flag[k].first.first==city[i].road[j].first&&flag[k].first.second==i) ){
//					built=true;
//					break;
//				}
//			}
			if(cnt[0]-cnt[i]-cnt[city[i].road[j][0]]!=0)
				built=true;
			if(!built){
				cnt[i]++;
				cnt[city[i].road[j][0]]++;
				cnt[0]+=2;
//				flag[cntf].first.first=i;
//				flag[cntf].first.second=city[i].road[j].first;
//				flag[cntf++].second=true;
				ans+=city[i].road[j][1];
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
