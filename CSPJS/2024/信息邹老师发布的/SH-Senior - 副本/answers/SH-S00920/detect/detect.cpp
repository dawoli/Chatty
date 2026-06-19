#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=3e5;
struct node{
	int d,v,acc;
}a[maxn];

int n,m,L,V,T,p[maxn],ans1,ans2,pos,cal;
int cnt;

signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout); 
	cin>>T;
	while(T-->0){
		ans1=0;
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].v>>a[i].acc; 
		for(int i=1;i<=m;i++) cin>>p[i];
		sort(p+1,p+1+m);
		
		for(int i=1;i<=n;i++){
			if(a[i].v>V&&a[i].d<=p[m]){
				ans1++;
			}
		}
		cout<<ans1<<" "; 
		if(ans1!=0) cout<<m-1<<endl;
		else cout<<m<<endl;
	}
} 
