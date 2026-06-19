#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n,buc[3];
struct point{
	int v,id;
};
struct node{
	point b[3];
}a[N];
bool pcmp(point x,point y){
	if(x.v==y.v) return x.id<y.id;
	return x.v>y.v;
}
bool cmp(node x,node y){
	if(x.b[0].v==y.b[0].v) return x.b[1].v>y.b[1].v;
	return x.b[0].v>y.b[0].v;
}
inline int read(){
	char ch=getchar();int ret=0,coef=1;
	while(!isdigit(ch)){
		if(ch=='-') coef*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+ch-'0';
		ch=getchar();
	}
	return ret*coef;
}
void solve(){
	buc[0]=buc[1]=buc[2]=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		a[i].b[0].v=read();
		a[i].b[1].v=read();
		a[i].b[2].v=read();
		a[i].b[0].id=0,a[i].b[1].id=1,a[i].b[2].id=2;
		sort(a[i].b,a[i].b+3,pcmp);
	}
	sort(a+1,a+n+1,cmp);
	long long ans=0;
	for(int i=1;i<=n;++i){
		buc[a[i].b[0].id]++;
		ans+=(long long)a[i].b[0].v;
	}
	int p=-1,t=0;
	if(buc[0]>n/2) p=0,t=buc[0]-n/2;
	if(buc[1]>n/2) p=1,t=buc[1]-n/2;
	if(buc[2]>n/2) p=2,t=buc[2]-n/2;
	if(p==-1){
		cout<<ans<<endl;
		return ;
	}
	for(int i=1;i<=n;++i)
		a[i].b[0].v=a[i].b[1].v-a[i].b[0].v;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		if(a[i].b[0].id==p){
			if(t>0){
				t--;
				ans+=(long long)a[i].b[0].v;
			}
		}
	}
	cout<<ans<<endl;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
