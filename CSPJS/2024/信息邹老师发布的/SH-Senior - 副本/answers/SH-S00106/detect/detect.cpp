//若一辆车的加速度为0
//那如果它超速，它从头到尾都会超速
//若一辆车的加速度为正 
//那它从一点开始，直到最北边会一直超速
//若一辆车的加速度为负
//那它的速度降到限速后就不再超速
//所以对于加速度为0的车而言
//只要有一个测速仪它就会被检测到
//对加速度为正的车而言
//只用看已被检测的最后超速的那辆车
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int d,v,a;
}car[100010];
int n,m,len,lim,t,ans1,ans2,nowlst,minn;
int p[100010],l,r;
vector<pair<int,int>>qu,qu2;
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		ans1=ans2=0;
		qu.clear(),qu2.clear();
		scanf("%lld%lld%lld%lld",&n,&m,&len,&lim);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&car[i].d,&car[i].v,&car[i].a);
			if(car[i].a==0&&car[i].v>lim){
				qu.push_back({car[i].d,len});
			}
			if(car[i].a>0){
				if(car[i].v>lim){
					qu.push_back({car[i].d,len});
				}else{
					l=car[i].d+(lim*lim-car[i].v*car[i].v)/(2*car[i].a);
					l++;
					if(l<=len){
						qu.push_back({l,len});
					}
				}
			}
			if(car[i].a<0){
				if(car[i].v<=lim) continue;
				r=car[i].d+(lim*lim-car[i].v*car[i].v)/(2*car[i].a);
				if((lim*lim-car[i].v*car[i].v)%(2*car[i].a)==0) r--;
				qu.push_back({car[i].d,min(r,len)});
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%lld",&p[i]);
		}
		for(auto i:qu){
			l=lower_bound(p+1,p+1+m,i.first)-p;
			r=upper_bound(p+1,p+1+m,i.second)-p-1;
			if(l<=r){
//				cout<<i.first<<" "<<i.second<<" "<<l<<" "<<r<<endl;
				ans1++;
				qu2.push_back({l,r});
			}
		}
		printf("%lld ",ans1);
		if(ans1==0){
			printf("%lld\n",m);
			continue;
		}
		sort(qu2.begin(),qu2.end());
		nowlst=qu2[0].first,minn=qu2[0].second,ans2=1;
		for(int i=1;i<qu2.size();i++){
			if(qu2[i].first>nowlst){
				if(minn>=qu2[i].first){
					nowlst=qu2[i].first;
					minn=min(minn,qu2[i].second);
				}else{
					nowlst=qu2[i].first;
					minn=qu2[i].second;
					ans2++;
				}
			}else{
				minn=min(minn,qu2[i].second);
			}
		}
		printf("%lld\n",m-ans2);
	}
	return 0;
} 
