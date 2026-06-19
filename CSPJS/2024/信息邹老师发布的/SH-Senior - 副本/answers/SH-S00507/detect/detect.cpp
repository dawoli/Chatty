#include<bits/stdc++.h>
using namespace std;
int n,m,L,V;
const int N=100009;
int d[N],v[N],a[N],p[N];
bool isCondition1(){
	for(int i=1;i<=n;i++)
		if(a[i]!=0) return 0;
	return 1;
}
void solve1(){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(v[i]>V){
			if(d[i]>p[m]) continue;
			else cnt++;
		}
	cout<<cnt<<" "<<(!cnt?m:m-1)<<endl; 
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		if(isCondition1()) solve1(); 
	}
	return 0;
}
