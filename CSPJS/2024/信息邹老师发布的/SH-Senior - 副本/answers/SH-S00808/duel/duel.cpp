#include<bits/stdc++.h>
using namespace std;
int n,r[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("","r",stdin);
	freopen("","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;++i)
		cin>>r[i];
	sort(r+1,r+n+1,cmp);
	cout<<" ";
	int p[100005];
	int ans = 0,t = 0;
	for(int i = 1;i<=n;++i){
		if(r[i]!=t){
			t = r[i];
			ans++;
			p[ans]=i;
		}
	}
	p[ans+1]=n+1;
	int q = 0;
	int xx[100005];
	for(int i =s ans;i>=1;--i){
		xx[i] = p[i+1]-p[i];
	}
	for(int i = 2;i<=ans;++i){
		q+=min(xx[i],xx[i-1]);
		xx[i-1]=max(xx[i-1]-xx[i],0);
		xx[i]+=xx[i-1];
	}
	cout<<n-q;
	return 0;
}
