#include<bits/stdc++.h>
using namespace std;
const int N=100009;
struct node{
	int l,r,flag;
	bool operator<(const node &a)const{
		return l<a.l||(l==a.l&&r>a.r);
	}
}x[N];
int n,m,L,V,p[N],bit[N];
//double ;
int lsb(int x){
	return x&(-x);
}
int query(int x){
	int res=0;
	for(;x;x-=lsb(x)){
		res+=bit[x];
	}
	return res;
}
void add(int x,int v){
	for(;x<=m+1;x+=lsb(x)){
		bit[x]+=v;
	}
}
void solve(){
	int cnt=0,ans1=0,ans2=0,lst=-1;
	scanf("%d %d %d %d",&n,&m,&L,&V);
	for(int i=1;i<=n;i++){
		int d,v,a;
		scanf("%d %d %d",&d,&v,&a);
		if(a==0){
			if(v>V){
				cnt++;
				x[cnt].l=d;
				x[cnt].r=L;
			}
		}else if(a>0){
			if(v>V){
				cnt++;
				x[cnt].l=d;
				x[cnt].r=L;
			}else{
				int tmp=(V*V-v*v+2*a)/(2*a)+d;
				if(tmp<=L){
					cnt++;
					x[cnt].l=tmp;
					x[cnt].r=L;
				}
			}
		}else{
			if(v>V){
				cnt++;
				x[cnt].l=d;
				x[cnt].r=min((v*v-V*V-1)/(-2*a)+d,L);
			}
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<x[i].l<<" "<<x[i].r<<endl;
//	}
//	cout<<endl;
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
	}
	p[m+1]=L+1;
	for(int i=1;i<=cnt;i++){
		x[i].l=lower_bound(p+1,p+m+1,x[i].l)-p;
		x[i].r=upper_bound(p+1,p+m+2,x[i].r)-p-1;
		if(x[i].l>x[i].r){
			x[i].flag=-1;
		}else{
			x[i].flag=1;
			ans1++;
		}
	}
	sort(x+1,x+cnt+1);
	for(int i=cnt;i>=1;i--){
		if(x[i].flag==-1){
			continue;
		}
		if(query(x[i].r)){
			x[i].flag=0;
		}else{
			add(x[i].r,1);
		}
	}
//	for(int i=1;i<=cnt;i++){
//		if(x[i].flag==-1){
//			continue;
//		}
//		int j=i-1;
//		while(j>=1){
//			if(x[j].flag==-1){
//				j--;
//				continue;
//			}
//			if(x[j].flag==0){
//				break;
//			}
//			if(x[i].r>x[j].r){
//				break;
//			}
//			x[j].flag=0;
//			j--;
//		}
//	}
	for(int i=1;i<=cnt;i++){
		if(x[i].flag!=1){
			continue;
		}
		add(x[i].r,-1);
//		cout<<x[i].l<<" "<<x[i].r<<endl;
		if(x[i].l>lst){
			lst=x[i].r;
			ans2++;
		}
	}
	printf("%d %d\n",ans1,m-ans2);
//	cout<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
