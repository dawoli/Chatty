#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define down(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
const ll INF=1e15;
const ull BASE=240441620163;
void file(){
	 freopen("club.in","r",stdin);
	 freopen("club.out","w",stdout);
}
const ll N=100009;
//本人最后一个赛季，祭~
//感谢八年来OI带来的欢乐，以及不一样的人生经历~
ll T;
//多测不请空，爆零两行泪
ll a[N][5],n,group[N],dp[209][209][209],cnt1=0,cnt2=0,cnt3=0;
ll ans=-INF;
ll nDelta=0,delta[N];
ll cnt[5];
struct Students{
	ll will1,satisfy1;
	ll will2,satisfy2;
}students[N];
void init(){
	rep(i,1,n)a[i][1]=a[i][2]=a[i][3]=0,group[i]=0;
	rep(i,1,n)students[i]=(Students){0,0,0,0}; 
	rep(i,1,nDelta)delta[i]=0;
	ans=-INF; cnt1=cnt2=cnt3=0; cnt[1]=cnt[2]=cnt[3]=0;
	n=0; nDelta=0;
}
void input(){
	cin>>n;
	rep(i,1,n){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		ll mx=max(a[i][1],max(a[i][2],a[i][3]));
		if(mx==a[i][1])cnt1++;
		else if(mx==a[i][2])cnt2++;
		else if(mx==a[i][3])cnt3++; 
	}
} 
void dfs(ll now){
	if(now==n+1){
		ll res=0; cnt[1]=cnt[2]=cnt[3]=0;
		rep(i,1,n)res+=a[i][group[i]],cnt[group[i]]++;
		ll mx=max(cnt[1],max(cnt[2],cnt[3]));
		if(mx>n/2)return;
		ans=max(ans,res);
		return;
	}
	group[now]=1;
	dfs(now+1);
	group[now]=2;
	dfs(now+1);
	group[now]=3;
	dfs(now+1);
}
void solveBF(){
	dfs(1);
	cout<<ans<<endl;
}
void solveDP(){
	rep(i,0,n/2)
		rep(j,0,n/2)
			rep(k,0,n/2)dp[i][j][k]=0;
	rep(i,0,n/2)
		rep(j,0,n/2){
			if(i+j>n)break;
			rep(k,0,n/2){
				if(i+j+k>n)break;
				ll res=0;
				if(i-1>=0)res=max(res,dp[i-1][j][k]+a[i+j+k][1]);
				if(j-1>=0)res=max(res,dp[i][j-1][k]+a[i+j+k][2]);
				if(k-1>=0)res=max(res,dp[i][j][k-1]+a[i+j+k][3]);
				dp[i][j][k]=res;
			}
		}
	ll ans=-INF;
	rep(i,0,n/2)
		rep(j,0,n/2){
			if(i+j>n)break;
			rep(k,0,n/2){
				if(i+j+k>n)break;
				if(i+j+k!=n)continue;
				ans=max(ans,dp[i][j][k]);
			}
		}
	cout<<ans<<endl;
}
bool OK_A(){
	rep(i,1,n)if(a[i][2]!=0||a[i][3]!=0)return 0;
	return 1;
}
multiset<ll> s;
multiset<ll>::iterator it;
void solveA(){
	s.clear();
	rep(i,1,n)s.insert(a[i][1]);
	ll ans=0;
	rep(i,1,n/2){
		ans+=(*s.rbegin());
		it=s.end(); it--;
		s.erase(it);
	}
	cout<<ans<<endl;
}
void solve_random(){
	ll ans=0;
	rep(i,1,n){
		ll mx=max(a[i][1],max(a[i][2],a[i][3]));
		ans+=mx;
	}
	cout<<ans<<endl;
}
//好经典的部分分提示正解！
//有没有见过美国总统大选的选票呀？
//    Bidden(304 votes)|-------------------------|----------   |v.s.|  --------------| Bidden(234 votes)
//                                              219votes 
void solve(){
	ll ans=0;
	rep(i,1,n){
		ll mx=-INF,mxnum=0;
		rep(j,1,3)if(a[i][j]>mx)mx=a[i][j],mxnum=j;
		ll mid=-INF,midnum=0;
		rep(j,1,3){
			if(j==mxnum)continue;
			if(a[i][j]>mid)mid=a[i][j],midnum=j;
		} 
		students[i]=(Students){mxnum,mx,midnum,mid};
		ans+=mx;
	}
	ll exceed_group_num,transmit_nedded=0;
	if(cnt1>n/2)exceed_group_num=1,transmit_nedded=cnt1-n/2;
	if(cnt2>n/2)exceed_group_num=2,transmit_nedded=cnt2-n/2;
	if(cnt3>n/2)exceed_group_num=3,transmit_nedded=cnt3-n/2; 
	rep(i,1,n){
		if(students[i].will1!=exceed_group_num)continue;
		delta[++nDelta]=students[i].satisfy1-students[i].satisfy2;
	}
	sort(delta+1,delta+nDelta+1);
	rep(i,1,transmit_nedded)ans-=delta[i];
	cout<<ans<<endl;
}
int main(){
	file();
	cin>>T;
	rep(i,1,T){
		init();
		input();
		if(n<=10)
			solveBF();
		else if(OK_A())
			solveA();
		else if(n<=200)
			solveDP();
		else if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
			solve_random();
		else
			solve();
	}
	return 0;
}


