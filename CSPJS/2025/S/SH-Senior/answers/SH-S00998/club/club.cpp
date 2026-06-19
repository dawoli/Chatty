#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxx=0;
struct person{
	int maxx1,maxx1id,tmp;
	bool operator<(person x){
		return tmp<x.tmp;
	}
};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<person>v;
		v.clear();
		int want[3]={};
		long long ans=0;
		for(int i=1;i<=n;i++){
			int a[3];
			cin>>a[0]>>a[1]>>a[2];
			int tmp2=0;
			if(a[1]>a[0]){
				want[a[2]>a[1]?2:1]++;
				tmp2=a[2]>a[1]?2:1;
			}
			else{
				want[a[2]>a[0]?2:0]++;
				tmp2=a[2]>a[0]?2:0;
			}
			sort(a,a+3);
			v.push_back((person){a[2],tmp2,a[2]-a[1]});
			//cerr<<"pushed "<<a[2]<<' '<<tmp2<<' '<<a[2]-a[1]<<'\n';
			ans+=a[2];
		} 
		maxx=(want[1]>want[0]?(want[2]>want[1]?2:1):(want[2]>want[0]?2:0));
		vector<person>vv;
		for(int i=0;i<n;i++){
			if(v[i].maxx1id==maxx)vv.push_back(v[i]);
		}
		sort(vv.begin(),vv.end());
		sort(want,want+3);
		for(int i=0;i<want[2]-n/2;i++){
			ans-=vv[i].tmp;
		}
		cout<<ans<<endl;
	}
}
