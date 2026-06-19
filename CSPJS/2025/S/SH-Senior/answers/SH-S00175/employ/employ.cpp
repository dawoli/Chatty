#include<bits/stdc++.h>
using namespace std;
const int N=509,MOD=998244353;
int n,m,s[N],c[N],a[N],fraction[N]; //a[i]-> how many days can ppl pass in the first i days
bool A(){
	for(int i=1;i<=n;i++)if(s[i]!=1)return false;
	return true;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string t;
	cin>>t;
	for(int i=0;i<t.size();i++)s[i+1]=t[i]-'0';
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n==m)cout<<0<<endl;
	else if(m==1){

	}
	else if(A()){
		unsigned long long ans=1;
		for(int k=m;k<=n;k++){
			unsigned long long t=1;
			for(int i=1;i<=n;i++)fraction[i]=0;
			for(int i=n;i>=n-m+1;i--){
			//cout<<n<<" "<<m<<endl;
				int num=i,cur=2;
				while(num>1){
					while(num%cur==0)fraction[cur]++,num/=cur;
					cur++;
				}
			}
			for(int i=1;i<=n;i++)for(int j=1;j<=fraction[i];j++)(t*=i)%=MOD;
			(ans+=t)%=MOD;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
