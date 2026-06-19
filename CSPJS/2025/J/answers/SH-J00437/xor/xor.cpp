#include<bits/stdc++.h>
using namespace std;
#define N 500005
int n,k,a[N],res,d[N],s[N];
//d[i]表示[i:]中第一个满足条件的下标 
struct Range{
	int l,r;
	bool operator < (const Range &b) const{
		return r<b.r;
	}
}; 
vector<Range> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) if((s[j]^s[i-1])==k){
			d[i]=j;
			v.push_back(Range{i,d[i]});
			break;
		}
	}
	sort(v.begin(),v.end());
	unsigned int j=0;
	int r=0,ans=0;
	while(r<=n&&j<v.size()){
		ans++;
		r=v[j].r;
		while(v[j].l<=r&&j<v.size()){j++;}
	}
	cout<<ans;
	return 0;
}
