#include<bits/stdc++.h>
using namespace std;
const int V=1<<21,N=5e5+5;
int lst[V];
struct T{
	int l,r;
	bool operator<(T t){
		if(r==t.r) return l<t.l;
		return r<t.r;
	}
};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	cin>>n>>k;
	lst[0]=1;
	vector<T> v;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		sum^=x;
		if(lst[sum^k]) v.push_back({lst[sum^k],i});
		lst[sum]=i+1;
	}
	if(v.size()==0){
		cout<<0;
		return 0;
	}
	sort(v.begin(),v.end());
	int lstl=v[0].l,lstr=v[0].r,ans=1;
	for(int i=1;i<v.size();i++){
		int l=v[i].l,r=v[i].r;
		if(l>lstr){
			ans++;
			lstl=l,lstr=r;
		}
	}
	cout<<ans;
	return 0;
}
