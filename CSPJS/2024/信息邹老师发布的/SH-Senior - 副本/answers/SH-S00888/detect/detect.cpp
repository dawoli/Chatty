#include<bits/stdc++.h>
using namespace std;
#define likely(x) __builtin_expect(x,1)
#define unlikely(x) __builtin_expect(x,0)
int getfastSum(vector<pair<int,int>>& ranges,int maxValue){
	vector<int> result(maxValue+1);
	for(pair<int,int>& i:ranges){
		result[i.first]++;
		result[i.second]--;
	}
	auto resultdiff=result;
	for(int i=1;i<=maxValue;i++){
		result[i]+=result[i-1];
	}
	unordered_set<int> biggests;
	for(int i=0;i<maxValue;i++){
		if(resultdiff[i]>=0&&resultdiff[i+1]<=0){
			biggests.insert(result[i]);
		}
	}
	int r=0x3f3f3f3f;
	int s=0;
	for(int i=0;i<maxValue;i++){
		if(result[i]<=0&&r!=0x3f3f3f3f){
			s+=r;
			r=0x3f3f3f3f;
		}else if(result[i]>0){
			r=min(r,result[i]);
		}
	}
	return (s>biggests.size()?biggests.size()+1:biggests.size());
} 
#define double long double
#define ld(x) ((double)(x))
void intersect(vector<pair<double,double>>& lines,vector<double>& tests){
	sort(tests.begin(),tests.end());
	vector<pair<int,int>> result;
	int count0=0;
	for(pair<double,double>& p:lines){
		//printf("lines:%lf..%lf\n",p.first,p.second);
		auto s0=upper_bound(tests.begin(),tests.end(),p.first)-tests.begin();
		auto e0=lower_bound(tests.begin(),tests.end(),p.second)-tests.begin();
		//printf("detects:[%d,%d)  (%lf~%lf)\n",s0,e0,tests[s0],tests[e0-1]);
		if(s0!=e0){
			count0++;
			result.push_back(pair<int,int>(s0,e0));
		}
	}
	printf("%d ",count0);
	auto s=getfastSum(result,tests.size()+5);
	printf("%d\n",tests.size()-s);
}
void doProcess(){
	int n,m,L,V;
	scanf("%d %d %d %d",&n,&m,&L,&V);
	L++;
	vector<pair<double,double>> covers(n);
	for(int i=0;i<n;i++){
		int di,vi,ai;
		scanf("%d %d %d",&di,&vi,&ai);
		double start,end;
		if(ai==0){
			if(unlikely(vi<=V)){
				continue;
			}else{
				start=di;
				end=L;
			}
		}else if(ai<0){
			if(unlikely(vi<=V)){
				continue;
			}else{
				start=di;
				end=di+ld(vi*vi-V*V)/((-ai)<<1);
				if(unlikely(end>=L)){
					end=L;
				}
				if(unlikely(fmodl(end,1.0)==0.0)){
					end+=0.1;
				}
			}
		}else{
			if(likely(vi>V)){
				start=di;
			}else{
				start=di+ld(V*V-vi*vi)/(ai<<1);
				if(unlikely(start>=L)){
					continue;
				}
				if(unlikely(fmodl(start,1.0)==0.0)){
					start-=0.1;
				}
			}
			end=L;
		}
		covers[i]=pair<double,double>(start,end);
	}
	vector<double> points(m);
	for(int i=0;i<m;i++){
		int s;
		scanf("%d",&s);
		points[i]=s;
	}
	intersect(covers,points);
}
#undef double
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		doProcess();
	}
	return 0;
}
