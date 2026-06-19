#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct eddgggeeee{
	int u,v,w;
};
eddgggeeee arr[100005];
int n,m,k;
bool cmp(eddgggeeee q,eddgggeeee e){
	return q.w <e.w ;
}
int h[10009];
int f(int x){
	if(h[x]==x)return x;
	return f(h[x]);
}
ll ans;
ll temp;
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>arr[i].u>>arr[i].v>>arr[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>temp;
		for(int j=0;j<n;j++)cin>>temp;
	}
	for(int i=1;i<=10005;i++)h[i]=i;
	sort(arr+1,arr+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1){
			cout<<ans;
			return 0;
		}
		int temp1=f(arr[i].u),temp2=f(arr[i].v);
		if(temp1!=temp2){
			h[temp1]=temp2;
			ans+=arr[i].w;
			cnt++;
		}
	}
	cout<<0;
	return 0;
}
