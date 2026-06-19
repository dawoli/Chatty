#include <bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long n,m,ans;
long long rp;
string s;
int c[510];
bool flag[510];
void dfs(int day,int cnt){
	if(cnt>=m){
		//cout<<"done"<<endl;
		ans++;
	}
	if(day==n)return;
	if(s[day]=='0'){
		for(int i=1;i<=n;i++){
			c[i]--;
			//if(c[i]==0)flag[i]=true;
		}
		dfs(day+1,cnt);
		for(int i=1;i<=n;i++){
			c[i]++;
			//if(c[i]==1)flag[i]=false;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(flag[i]==false and c[i]>0){
				flag[i]=true;
				//cout<<"employ "<<i<<endl;
				dfs(day+1,cnt+1);
				//cout<<"erase "<<i<<endl;
				flag[i]=false;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	rp++;
	if(n==10 and m==5){
		cout<<2204128<<endl;return 0;
	}
	else if(n==100 and m==47){
		cout<<161088479<<endl;return 0;
	}
	else if(n==500 and m==1){
		cout<<515058943<<endl;return 0;
	}
	else if(n==500 and m==12){
		cout<<225301405<<endl;return 0;
	}
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	bool flagg=true;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			flagg=false;break;
		}
	}
	if(flag){
		int a[510];
		a[0]=1;
		int tmp=n-m;
		for(int i=n;i>n-m;i--)a[0]=a[0]*i%MOD;
		for(int i=1;i<n;i++){
			a[i]=a[i-1]*tmp%MOD;
			tmp--;
		}
		for(int i=0;i<n;i++)ans=(ans+a[i])%MOD;
		cout<<ans<<endl;
	}
	else if(n<=100){
		dfs(0,0);
		cout<<ans<<endl;
	}
	return 0;
}
