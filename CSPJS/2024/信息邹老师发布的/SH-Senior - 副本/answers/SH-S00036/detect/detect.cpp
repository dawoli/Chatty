#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,v,a;
}cars[100003];
int nums[100003];
pair<int,int> a[100003];
int calc(int num,int where){
	int tmp=ceil(sqrt(cars[num].v*cars[num].v+2*cars[num].a*(where-cars[num].d)));
	return tmp;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,l,v,iindex=0,ans=0;
		scanf("%d%d%d%d",&n,&m,&l,&v);
		for(int i=1;i<=n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			cars[i]={a,b,c};
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&nums[i]);
		}
		sort(nums+1,nums+m+1);
		for(int i=1;i<=n;i++){
			int l,r,first,second;
			l=1,r=m;
			while(l<r){
				int mid=(l+r)>>1;
				if(nums[mid]>=cars[i].d){
					r=mid;
				}else{
					l=mid+1;
				}
			}
			first=l;
			r=m;
			if(calc(i,nums[first])<=v && cars[i].a<=0)continue;
			if(calc(i,nums[m])<=v && cars[i].a>=0)continue;
			while(l<r){
				int mid=(l+r)>>1;
				if(calc(i,nums[mid])>v){
					if(cars[i].a<=0)l=mid;
					else r=mid;
				}else{
					if(cars[i].a<=0)r=mid-1;
					else l=mid+1;
				}
			}
			if(cars[i].a>0)a[++iindex]={second,m};
			else a[++iindex]={first,second};
		}
		sort(a+1,a+iindex+1);
		int start=a[1].first,end=a[1].second;
		for(int i=2;i<=iindex;i++){
			if(a[i].first>=start && a[i].first<=end){
				start=a[i].first;
				end=min(a[i].second,end);
			}else{
				ans++;
				start=a[i].first;
				end=a[i].second;
			}
		}
		ans++;
		printf("%d %d\n",iindex,m-ans);
	}
	return 0;
}
/*
1
5 5 15 3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
*/
