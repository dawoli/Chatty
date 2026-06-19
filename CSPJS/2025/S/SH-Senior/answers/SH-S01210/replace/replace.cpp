#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int N=2e5+5; 
const int M=5e6+5;
const int bas1=127,p1=1e9+7,bas2=233,p2=998244353;
int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+(c^48);c=getchar();}
	return x*f;
}
int n,m,q;
int hs1[N],ht1[N],hs2[N],ht2[N],p[N],len[N],dif[N],f1[M],f2[M];
int s1[M],s2[M],t1[M],t2[M];
char s[M],t[M];
int get(int s[],int f[],int l,int r,int p){
	return (s[r]-1ll*s[l-1]*f[r-l+1]%p+p)%p; 
}
struct node{
	int id,x,y,tp,op;
	friend bool operator < (node a,node b){
		return a.x==b.x?a.op>b.op:a.x<b.x;
	}
}a[N*2];
int ans[N];
__gnu_pbds::tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tr[M*2];
void solve(){
	for(int i=1;i<=n;i++){
		cin>>s+1>>t+1;
		int len=strlen(s+1),p=0,dif=0;
		for(int j=1;j<=len;j++){
			if(s[j]=='b') p=j;
			if(t[j]=='b') dif=j;
		}
		a[i]={i,p,len-p,p-dif,1};
	}
	for(int i=1;i<=q;i++){
		cin>>s+1>>t+1;
		int len=strlen(s+1),p=0,dif=0;
		for(int j=1;j<=len;j++){
			if(s[j]=='b') p=j;
			if(t[j]=='b') dif=j;
		}
		a[n+i]={i,p,len-p,p-dif,0};
	}
	sort(a+1,a+n+q+1);
	for(int i=1;i<=n+q;i++){
		int id=a[i].id,y=a[i].y,tp=a[i].tp,op=a[i].op;
		if(op==1)
			tr[tp+M].insert(y);
		else
			ans[id]=tr[tp+M].order_of_key(y+1);
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<endl;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	if(n*q>1e8){
		solve();
		return 0;
	}
	f1[0]=f2[0]=1;
	for(int i=1;i<M;i++)
		f1[i]=1ll*f1[i-1]*bas1%p1,f2[i]=1ll*f2[i-1]*bas2%p2;
	for(int i=1;i<=n;i++){
		cin>>s+1>>t+1;
		len[i]=strlen(s+1);
		for(int j=1;j<=len[i];j++){
			hs1[i]=(1ll*hs1[i]*bas1+s[j])%p1;
			hs2[i]=(1ll*hs2[i]*bas2+s[j])%p2;
			ht1[i]=(1ll*ht1[i]*bas1+t[j])%p1;
			ht2[i]=(1ll*ht2[i]*bas2+t[j])%p2;
			if(s[j]!=t[j]){
				dif[i]++;
				if(!p[i]) p[i]=j;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s+1>>t+1;
		m=strlen(s+1);
		int pos=0,dis=0;
		for(int j=1;j<=m;j++){
			s1[j]=(1ll*s1[j-1]*bas1+s[j])%p1;
			s2[j]=(1ll*s2[j-1]*bas2+s[j])%p2;
			t1[j]=(1ll*t1[j-1]*bas1+t[j])%p1;
			t2[j]=(1ll*t2[j-1]*bas2+t[j])%p2;
			if(s[j]!=t[j]){
				dis++;
				if(!pos) pos=j;
			}
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			int l=1+pos-p[j],r=len[j]+pos-p[j];
			if(l<1||r>m||dif[j]!=dis)
				continue;
			int ps1=get(s1,f1,l,r,p1),ps2=get(s2,f2,l,r,p2),pt1=get(t1,f1,l,r,p1),pt2=get(t2,f2,l,r,p2);
			if(ps1==hs1[j]&&ps2==hs2[j]&&pt1==ht1[j]&&pt2==ht2[j])
				ans++;
		}
		cout<<ans<<endl;
	}
}
