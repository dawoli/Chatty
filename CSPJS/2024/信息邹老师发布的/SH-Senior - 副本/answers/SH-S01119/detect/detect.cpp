#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,l,vm,d[100005],v[100005],a[100005],p[100005],cnt,pos,mpos,tim,ans,mr;
int find(int x){
	int l=1,r=m,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(p[mid]<x){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	return ans;
}
vector<pair<int,int> > usa;
bool cmp(pair<int,int> a,pair<int,int> b){
	if(a.second-a.first==b.second-b.first)a.first<b.first;
	return a.second-a.first<b.second-b.first;
}
bool flagn;
int main(){
	freopen("detect.in","r",stdin);freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cnt=0,flagn=1;
		usa.clear();
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		memset(a,0,sizeof(a));
		memset(p,0,sizeof(p));
		scanf("%d%d%d%d",&n,&m,&l,&vm);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&d[i],&v[i],&a[i]);
		for(int i=1;i<=m;i++)scanf("%d",&p[i]);
		for(int i=1;i<=n;i++){
			pos=0;
			if(d[i]>p[m])continue;
			if(a[i]==0){
				if(v[i]>vm){
					//printf("%d\n",i);
					cnt++;
					mpos=max(d[i],mpos);
				}
				continue;
			}
			else if(a[i]<0){
				flagn=0;
				if(v[i]<=vm)continue;
				tim=d[i]+(v[i]*v[i]-vm*vm)/(-a[i])/2+1;
				if(tim<p[1])continue;
				pos=find(tim);
				if(p[pos]>=d[i]&&pos<=m){
					//printf("%d %d\n",i,pos);
					cnt++;
					usa.push_back(make_pair(find(d[i])+1,pos));
				}
			}
			else if(a[i]>0){
				if(v[i]*v[i]+2*a[i]*(p[m]-d[i])<=vm*vm)continue;
				//printf("%d %d\n",i,pos);
				cnt++;
				tim=d[i]+(v[i]*v[i]-vm*vm)/a[i]/2+1;
				pos=find(tim)+1;
				mpos=max(pos,mpos);
			}
		}
		if(cnt==0){
			printf("0 %d\n",m);
			continue;
		}
		if(flagn){
			printf("%d %d\n",cnt,m-1);
			continue;
		}
		usa.push_back(make_pair(mpos,m));
		sort(usa.begin(),usa.end(),cmp);
		int len=usa.size();
		ans=0;
		mr=usa[0].second;
		for(int i=1;i<len;i++){
			//printf("%d %d\n",usa[i].first,usa[i].second);
			if(usa[i].first<=mr)ans++;
			else mr=usa[i].second;
		}
		printf("%d %d\n",cnt,ans);
	}
	fclose(stdin);fclose(stdout);
	return 0; 
} 
/*
1
9 10 114934 719
62115 915 -6
44976 920 -17
21788 877 -1
38609 839 -3
44828 982 -8
9713 1000 -109
61421 860 -922
16064 918 -2
33522 989 -11
13230 19868 37544 44774 45209 54175 61486 62595 87581 101248
*/
