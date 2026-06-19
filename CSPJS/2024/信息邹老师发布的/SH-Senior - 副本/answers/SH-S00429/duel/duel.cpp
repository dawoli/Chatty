#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> v;
inline int bsearch(int l,int r,int key){
	while(l<r){
		int mid=(l+r)/2;
		if(v[mid]<key&&v[mid+1]>=key){
			return mid;
		}
		else if(v[mid]<key){
			l=mid+1;
		}
		else if(v[mid]>=key){
			r=mid;
		}
	}
	return -1;
}
signed main(){
	freopen("duel4.in","r",stdin);
	freopen("duel4.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	int cnt=0;//离场的怪兽个数 
	for(register int i=0;i<n;i++){
		register int aim=bsearch(0,n-1,v[i-cnt]);
		//cout<<aim<<endl;
		//cout<<"!0"<<endl;
		if(aim==-1||aim>=n-cnt){
			continue;
		}
		//cout<<"!1"<<endl;
		v.erase(v.begin()-1+aim);
		//cout<<"!2"<<endl;
		cnt++;
		
	}
	cout/*<<"cnt:"*/<<n-cnt<<endl;
	return 0;
}
