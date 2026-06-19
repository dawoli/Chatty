#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500010],sum[500010];
int cnt[500010];
vector<int> b[1200010];
struct node{
	int l,r;
};
vector<node> p;

//9:47 AC T3

int find(int x,int y){
	int l=0,r=b[x].size()-1;
	if(r<l || b[x][r]<y)return -1;
	while(l<r){
		int mid=(l+r)/2;
		if(b[x][mid]<y)l=mid+1;
		else r=mid;
	}
	return b[x][r];
}

bool cmp(node a,node b){
	return a.r<b.r;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	b[0].push_back(0);
	for(int i=1;i<=n;i++){
		b[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
	    int w=sum[i-1]^k;
	    int q=find(w,i);
	    if(q==-1)continue;
	    p.push_back({i,q});
	    //cout<<i<<" "<<q<<endl;
	}
	sort(p.begin(),p.end(),cmp);
	int maxn=-1;
	for(unsigned int i=0;i<p.size();i++){
		if(p[i].l>maxn){
			ans++;
			maxn=max(maxn,p[i].r);
		}
	}
	cout<<ans<<endl;
	return 0;
}
