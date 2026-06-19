#include<bits/stdc++.h>
using namespace std;
struct color{
	int v,l,r;
}val[100005];

bool cmp(color a,color b){
	return a.v>b.v;
}
int n,nums[100005];
vector <int> vec[10005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	//int val[100005]={0};
	cin>>t;
	for(int q=1;q<=t;q++){
		int var=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>nums[i];
			if(vec[nums[i]].empty()){
				var++;
			}
			vec[nums[i]].push_back(i);
		}
		if(var==n){
			cout<<"0"<<endl;
			break;
		}
		else{
			for(int i=1;i<=n;i++){
				val[i].v=vec[i].size()*i;
				val[i].l=vec[i][1];
			//	cout<<"h"<<endl;
				val[i].r=vec[i][vec[i].size()-1];
			}
			sort(val+1,val+n+1,cmp);
			int ans=val[1].v;
			int le=val[1].l;
			int ri=val[1].r;
			//cout<<"h"<<endl;
			for(int i=2;i<=n;i++){
				if(ri<val[i].l||le>val[i].r){
					ans+=val[i].v;
					le=min(le,val[i].l);
					ri=max(ri,val[i].r);
				}
			}
			cout<<ans<<endl;
		}
		
	}

	return 0;
}

