#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,l,v,ans,tst[1000010],cnt,minn,maxn;
pair<int,int> s[100010],cars[100010];//0:start 1:query
unordered_map<int,int> ump;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a>b;
}
pair<int,int> slim(int ov,int a,int op){
	pair<int,int> ret;
	if(a>0){
		if(ov>v)
			ret.first=op;
		else{
			ret.first=(v*v-ov*ov+2*a)/(2*a)+op;
			if(ret.first>l)
				return make_pair(1,0);
		}
		ret.second=l;
		return ret;
	}
	if(a==0){
		if(ov>v)
			return make_pair(op,l);
		else
			return make_pair(1,0);
	}
	if(a<0){
		if(ov<=v)
			return make_pair(1,0);
		ret.first=op;
		ret.second=(ov*ov-v*v-1)/(-2*a)+op;
		if(ret.second>l)
			ret.second=l;
		return ret;
	}
}
signed main(){
	freopen("detect.in","r",stdin); 
	freopen("detect.out","w",stdout); 
	int T;
	cin>>T;
	while(T--){
		memset(tst,0,sizeof(tst));
		ans=cnt=0;
		cin>>n>>m>>l>>v;
		minn=l+1;
		maxn=0;
		l++;
		for(int i=0,ov,a,op;i<n;i++){
			cin>>op>>ov>>a;
			op++;
			cars[i]=slim(ov,a,op);
//			cout<<cars[i].first<<" "<<cars[i].second<<endl;
		}
		for(int i=0,t;i<m;i++){
			cin>>t;
			t++;
			tst[t]++;
			s[cnt++]=make_pair(t,1);
//			cout<<t<<"*"<<cnt<<" ";
		}
		for(int i=1;i<=l;i++)
			tst[i]+=tst[i-1];
		for(int i=0;i<n;i++){
			if(tst[cars[i].second]-tst[cars[i].first-1]){
				ans++;
				s[cnt++]=make_pair(cars[i].first,0);
				if(!ump[cars[i].first])
					ump[cars[i].first]=cars[i].second;
				else
					ump[cars[i].first]=min(cars[i].second,ump[cars[i].first]);
				minn=min(minn,cars[i].first);
				maxn=max(maxn,cars[i].second);
//				cout<<cars[i].first<<"~"<<cars[i].second<<endl;
			}
		}
		cout<<ans<<" ";
//		cout<<minn<<endl;
		ans=0;
		int can=1,ourmin=l+1,nowmin;
		sort(s,s+cnt,cmp);
		for(int i=0;i<cnt;i++){
//			cout<<s[i].first<<" "<<can<<" "<<s[i].second<<endl;
			if(s[i].first<minn)
				break;
			if(s[i].first>maxn)
				continue;
			if(s[i].second)
				nowmin=s[i].first;
			else{
				if(ump[s[i].first]<ourmin){
					ans++;
					ourmin=nowmin;
				}
			}
		}
		cout<<m-ans<<endl;
	}
} 
