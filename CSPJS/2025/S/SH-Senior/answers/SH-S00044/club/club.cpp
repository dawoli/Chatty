#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
struct node{
	int a,b,c;
}a[maxn];
int cnt[5];
bool cmp(node x,node y){
	int lx,ly;
	if(x.a>x.b){
		if(x.a>x.c){
			lx=x.a-max(x.b,x.c);
		}else{
			lx=x.c-x.a;
		}
	}else{
		if(x.b>x.c){
			lx=x.b-max(x.a,x.c);
		}else{
			lx=x.c-x.b;
		}
	}
	if(y.a>y.b){
		if(y.a>y.c){
			ly=y.a-max(y.b,y.c);
		}else{
			ly=y.c-y.a;
		}
	}else{
		if(y.b>y.c){
			ly=y.b-max(y.a,y.c);
		}else{
			ly=y.c-y.b;
		}
	}
	return lx>ly;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			int id1,id2;
			if(a[i].a>a[i].b){
				if(a[i].a>a[i].c){
					id1=1;
					if(a[i].b>a[i].c)id2=2;
					else id2=3;
				}else{
					id1=3;
					id2=1;
				}
			}else{
				if(a[i].b>a[i].c){
					id1=2;
					if(a[i].a>a[i].c)id2=1;
					else id2=3;
				}else{
					id1=3;
					id2=2;
				}
			}
			if(cnt[id1]+1<=n/2){
				cnt[id1]++;
				if(id1==1)ans+=a[i].a;
				else if(id1==2)ans+=a[i].b;
				else ans+=a[i].c;
			}else{
				cnt[id2]++;
				if(id2==1)ans+=a[i].a;
				else if(id2==2)ans+=a[i].b;
				else ans+=a[i].c;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
