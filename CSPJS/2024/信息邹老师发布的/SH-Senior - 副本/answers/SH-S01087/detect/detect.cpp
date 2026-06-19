#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+10;
int T,n,m,l,V,cnt,k,cnt2,csy[N];
int d,v,a,minr;
struct Node{
	int l,r;
}ans[N];
void solve(int i){
	if(a==0&&v>V){ans[i]={d,l};return ;}
	double x=V*V-v*v;
	x/=(2.0*(double)a);
	x+=(double)d;
	if(a>0&&x<=l)ans[i]={(int)ceil(x),l};
	else if(a<0&&v>V&&x>=d+1)ans[i]={d,(int)floor(x)};
	else ans[i]={-1,-1};
	return ;
}
bool cmp(Node a1,Node a2){
	return a1.l<a2.l;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cnt=0;cnt2=0;
		memset(ans,0,sizeof(ans));
		cin>>n>>m>>l>>V;
		for(int i=0;i<n;i++){
			cin>>d>>v>>a;
			solve(i);
		}
		for(int i=0;i<m;i++)cin>>csy[i];
		for(int i=0;i<n;i++){
			if(ans[i].l!=-1&&ans[i].r!=-1){
				ans[i].l=upper_bound(csy,csy+m,ans[i].l)-csy;
				ans[i].r=lower_bound(csy,csy+m,ans[i].r)-csy;
				cnt++;
			}
		}
		sort(ans,ans+n,cmp);
		minr=ans[0].r;
		for(int i=1;i<n;i++){
			if(ans[i].l>minr){
				cnt2++;
				minr=ans[i].r;
			}
		}
		cout<<cnt<<" "<<m-cnt2-1;
		cout<<endl;
	}
}
