#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
int n;
struct abc{
	int a,b,c;
}a[N];
bool cmpAx(abc a,abc b){
	return a.a>b.a;
}
bool cmpAy(abc a,abc b){
	return a.b>b.b;
}
bool cmpAz(abc a,abc b){
	return a.c>b.c;
}
bool Ax=1,Ay=1,Az=1;
bool isA(){
	for(int i=1;i<=n;i++)if(a[i].b!=0||a[i].c!=0)Ax=0;
	for(int i=1;i<=n;i++)if(a[i].a!=0||a[i].c!=0)Ay=0;
	for(int i=1;i<=n;i++)if(a[i].a!=0||a[i].b!=0)Az=0;
	return Ax||Ay||Az;
}
void solveA(){
	if(Ax){
		sort(a+1,a+1+n,cmpAx);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=a[i].a;
		cout<<ans;
	}else if(Ay){
		sort(a+1,a+1+n,cmpAy);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=a[i].b;
		cout<<ans;
	}else if(Az){
		sort(a+1,a+1+n,cmpAz);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=a[i].c;
		cout<<ans;
	}
}
bool Bx=1,By=1,Bz=1;
bool isB(){
	for(int i=1;i<=n;i++)if(a[i].a!=0)Bx=0;
	for(int i=1;i<=n;i++)if(a[i].b!=0)By=0;
	for(int i=1;i<=n;i++)if(a[i].c!=0)Bz=0;
	return Bx||By||Bz;
}
void solveB(){
	vector<abc>p(n+10);
	vector<abc>q(n+10);
	int ans=0;
	int pn=0;
	int qn=0;
	if(Bx){
		for(int i=1;i<=n;i++){
			if(a[i].b>a[i].c){
				p.push_back(a[i]);
				pn++;
				ans+=a[i].b;
			}
			else if(a[i].b<a[i].c){
				q.push_back(a[i]);
				qn++;
				ans+=a[i].c;
			}
			else ans+=a[i].b;
		}
		cout<<ans;
	}else if(By){
		for(int i=1;i<=n;i++){
			if(a[i].c>a[i].a){
				p.push_back(a[i]);
				pn++;
				ans+=a[i].c;
			}
			else if(a[i].c<a[i].a){
				q.push_back(a[i]);
				qn++;
				ans+=a[i].a;
			}
			else ans+=a[i].c;
		}
		cout<<ans;
	}else if(Bz){
		for(int i=1;i<=n;i++){
			if(a[i].a>a[i].b){
				p.push_back(a[i]);
				pn++;
				ans+=a[i].a;
			}
			else if(a[i].a<a[i].b){
				q.push_back(a[i]);
				qn++;
				ans+=a[i].b;
			}
			else ans+=a[i].a;
		}
		cout<<ans;
	}
}
void solve(){
	vector<abc>p(n+10);
	vector<abc>q(n+10);
	vector<abc>r(n+10);
	int ans=0;
	int pn=0;
	int qn=0;
	int rn=0;
	for(int i=1;i<=n;i++){
		if(a[i].a>a[i].b&&a[i].a>a[i].c){
			p.push_back(a[i]);
			pn++;
			ans+=a[i].a;
		}
		else if(a[i].a<a[i].b&&a[i].c<a[i].b){
			q.push_back(a[i]);
			qn++;
			ans+=a[i].b;
		}
		else if(a[i].a==a[i].b&&a[i].b==a[i].c)ans+=a[i].a;
		else{
			r.push_back(a[i]);
			rn++;
			ans+=a[i].c;
		}
	}
	cout<<ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	cin>>T;
	for(ll P=1;P<=T;P++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		if(isA())solveA();
		else if(isB())solveB();
		else solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
