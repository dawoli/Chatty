#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
typedef long long ll;
ll n,m,L,V,ans;
ll ad[N],mi[N],x[N],l[N],r[N];
void solve(){
	cin>>n>>m>>L>>V;
	for(int i=1;i<=m;i++)ad[i]=0,mi[i]=0;
	for(int i=1;i<=n;i++){
		int d,v,a;cin>>d>>v>>a;
		if(a>0){
			if(v>V)l[i]=d,r[i]=L;
			else if(v==V)l[i]=d+1,r[i]=L;
			else {
				ll temp=(V*V-v*v)/(2*a)+1+d;
				if(temp<=L)l[i]=temp,r[i]=L; //-
				else l[i]=0,r[i]=-1;
			}
		}
		else if(a==0){
			if(v>V)l[i]=d,r[i]=L;
			else if(v<=V)l[i]=0,r[i]=-1;
		}
		else{
			if(v<=V)l[i]=0,r[i]=-1;
			else {
				ll temp=(v*v-V*V)/(-2*a);
				if(temp*(-2*a)==v*v-V*V)temp--;
				l[i]=d,r[i]=min(temp+d,L); //-
			}
		}
	}
//	for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<endl;
	for(int i=1;i<=m;i++)cin>>x[i];
	ans=0;
	for(int i=1;i<=n;i++){
		if(l[i]==0&&r[i]==-1)continue;
		int p=lower_bound(x+1,x+1+m,l[i])-x,q=upper_bound(x+1,x+1+m,r[i])-x-1;
//		cout<<p<<" "<<q<<endl;
		if(p>q)continue;
		ad[p]++,mi[q+1]++,ans++;
	}
	for(int i=1;i<=m+1;i++)cout<<ad[i]<<" "<<mi[i]<<endl;
	cout<<ans<<" ";
	ans=0;
	bool t=0;//0:+,1:-
	for(int i=1;i<=m+1;i++){
		if(t==0){
			if(mi[i]){
				ans++;
				t=1;
				if(ad[i])t=0;
			}
		}
		else{
			if(ad[i]){
				t=0;
			}
		}
	}
	cout<<m-ans<<endl;
}


int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}
