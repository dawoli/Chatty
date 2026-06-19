#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+9;
int t;
void solve(){
	int n,m,l,vm,ch=0,a;
	cin>>n>>m>>l>>vm;
	int d[maxn],v[maxn],p[maxn];
	for(int i=0;i<n;i++)scanf("%d%d%d",&d[i],&v[i],&a);
	for(int i=0;i<m;i++)scanf("%d",&p[i]);
	sort(p,p+m);
	for(int i=0;i<n;i++){
		if(v[i]>vm&&d[i]<=p[m-1])ch++;
	}
	if(ch!=0)cout<<ch<<' '<<m-1<<endl;
	else cout<<ch<<' '<<m<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t>0){
    	t--;
    	solve();
	}
	return 0;
}
