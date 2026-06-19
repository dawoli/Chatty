#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int t;
struct node{
	int a,b,c,x,q;
}p[100005];
bool cmpmka(node x,node y){
	return x.a>y.a;
}
bool cmpcab(node x,node y){
	if(x.a-x.b==y.a-y.b) return x.b<y.b;
	return x.a-x.b>y.a-y.b;
}
bool cmpcba(node x,node y){
	if(x.b-x.a==y.b-y.a) return x.a<y.a;
	return x.b-x.a>y.b-y.a;
}
bool cmpcaq(node x,node y){
	if(x.a-x.q==y.a-y.q) return x.q<y.q;
	return x.a-x.q>y.a-y.q;
}
bool cmpcbq(node x,node y){
	if(x.b-x.q==y.b-y.q) return x.q<y.q;
	return x.b-x.q>y.b-y.q;
}
bool cmpccq(node x,node y){
	if(x.c-x.q==y.c-y.q) return x.q<y.q;
	return x.c-x.q>y.c-y.q;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int pa=0,pb=0,pc=0;
		ll ans=0;
		bool mka=true,mkb=true;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].a>p[i].b&&p[i].a>p[i].c) pa++,p[i].x=p[i].a;
			else if(p[i].b>p[i].a&&p[i].b>p[i].c) pb++,p[i].x=p[i].b;
			else if(p[i].c>p[i].b&&p[i].c>p[i].a) pc++,p[i].x=p[i].c;
			if(p[i].c!=0) mka=false,mkb=false;
			else if(p[i].b!=0) mka=false;
		}
		if(mka){
			sort(p+1,p+n+1,cmpmka);
			for(int i=1;i<=n/2;i++){
				ans+=p[i].a;
			}
			cout<<ans;
		}
		else if(mkb){
			node pm[100005];
			int cnt=0;
			if(pa>n/2){
				for(int i=1;i<=n;i++){
					if(p[i].x==p[i].a){
						pm[++cnt].a=p[i].a;
						pm[cnt].b=p[i].b;
						pm[cnt].c=p[i].c;
						pm[cnt].x=p[i].x;
					}
					else ans+=p[i].x;
				}
				sort(pm+1,pm+cnt+1,cmpcab);
				for(int i=1;i<=n/2;i++){
					ans+=pm[i].x;
				}
				for(int i=n/2+1;i<=cnt;i++){
					ans+=pm[i].b;
				}
				cout<<ans;
			}
			else if(pb>n/2){
				for(int i=1;i<=n;i++){
					if(p[i].x==p[i].b){
						pm[++cnt].a=p[i].a;
						pm[cnt].b=p[i].b;
						pm[cnt].c=p[i].c;
						pm[cnt].x=p[i].x;
					}
					else ans+=p[i].x;
				}
				sort(pm+1,pm+cnt+1,cmpcba);
				for(int i=1;i<=n/2;i++){
					ans+=pm[i].x;
				}
				for(int i=n/2+1;i<=cnt;i++){
					ans+=pm[i].a;
				}
				cout<<ans;
			}
			else if(pa<=n/2&&pb<=n/2){
				for(int i=1;i<=n;i++){
					ans+=p[i].x;
				}
				cout<<ans;
			}
		}
		else{
			node pm[100005];
			int cnt=0;
			if(pa<=n/2&&pb<=n/2&&pc<=n/2){
				for(int i=1;i<=n;i++){
					ans+=p[i].x;
				}
				cout<<ans;
			}
			else if(pa>n/2){
				for(int i=1;i<=n;i++){
					if(p[i].x==p[i].a){
						pm[++cnt].a=p[i].a;
						pm[cnt].b=p[i].b;
						pm[cnt].c=p[i].c;
						pm[cnt].x=p[i].x;
						pm[cnt].q=max(p[i].b,p[i].c);
					}
					else ans+=p[i].x;
				}
				sort(pm+1,pm+cnt+1,cmpcaq);
				for(int i=1;i<=n/2;i++){
					ans+=pm[i].x;
				}
				for(int i=n/2+1;i<=cnt;i++){
					ans+=pm[i].q;
				}
				cout<<ans;
			}
			else if(pb>n/2){
				for(int i=1;i<=n;i++){
					if(p[i].x==p[i].b){
						pm[++cnt].a=p[i].a;
						pm[cnt].b=p[i].b;
						pm[cnt].c=p[i].c;
						pm[cnt].x=p[i].x;
						pm[cnt].q=max(p[i].a,p[i].c);
					}
					else ans+=p[i].x;
				}
				sort(pm+1,pm+cnt+1,cmpcbq);
				for(int i=1;i<=n/2;i++){
					ans+=pm[i].x;
				}
				for(int i=n/2+1;i<=cnt;i++){
					ans+=pm[i].q;
				}
				cout<<ans;
			}
			else if(pc>n/2){
				for(int i=1;i<=n;i++){
					if(p[i].x==p[i].c){
						pm[++cnt].a=p[i].a;
						pm[cnt].b=p[i].b;
						pm[cnt].c=p[i].c;
						pm[cnt].x=p[i].x;
						pm[cnt].q=max(p[i].b,p[i].a);
					}
					else ans+=p[i].x;
				}
				sort(pm+1,pm+cnt+1,cmpccq);
				for(int i=1;i<=n/2;i++){
					ans+=pm[i].x;
				}
				for(int i=n/2+1;i<=cnt;i++){
					ans+=pm[i].q;
				}
				cout<<ans;
			}
		}
		cout<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
