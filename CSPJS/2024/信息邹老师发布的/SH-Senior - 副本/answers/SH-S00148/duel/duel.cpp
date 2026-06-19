#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<=(b);i++)
#define rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
#define maxn 200010

ll n,t;
ll a[maxn],s[maxn],top=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	fo(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int i=1,j=n,ans=n;
	fo(i,1,n){
		if(a[i]!=a[i-1]){
			top++;
		}
		s[top]++;
	}
//	fo(i,1,top)cout<<s[i]<<' ';cout<<endl;
	fo(i,2,top){
		if(s[i]>s[i-1])ans-=s[i-1];
		else ans-=s[i],s[i]+=(s[i-1]-s[i]);
	}
	cout<<ans;
	return 0;
}
