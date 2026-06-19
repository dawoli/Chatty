#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=998244353;
int duo[505];
int n,m,zero,ans;
char s[1001];
int c[505];
void pre(){
	duo[0]=1;
	duo[1]=1;
	for(int i=2;i<=500;i++){
		duo[i]=(duo[i-1]*i)%M;
	}
	for(int i=1;i<=n;i++)cin>>s[i];
}
bool vis[505];

bool flag1=true;
void solveA(){
	zero=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0)zero++;
	}
	if(zero+m>n){
		cout<<0<<endl;
		return;
	}
	
	cout<<ans<<endl;
}
int check(int num){
	int mul=1;
	int tmp=1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			tmp++;	
			continue;
		}
		int ttmp=0;
		for(int j=1;j<=n;j++)if(c[j]>=tmp)ttmp++;
		ttmp-=(num-i+tmp-1);
		if(ttmp<=0){
			mul=0;
			break;
		}
		mul=(mul*ttmp)%M;
	}
	mul*=duo[tmp-1];
	mul%=M;
	return mul;
}
void dfs(int pos,int cnt){
	if(pos>n){
		if(cnt>=m){
			ans+=check(cnt);
			ans%=M;
		}
		return ;
	}
	vis[pos]=false;
	if(s[pos]=='0')dfs(pos+1,cnt);
	else{
		vis[pos]=true;
		dfs(pos+1,cnt+1);
		vis[pos]=false;
		dfs(pos+1,cnt);
	}
} 
void bruce(){
	dfs(1,0);
	cout<<ans<<endl;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	pre();
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		if(s[i]!='1'){
			flag1=false;
			zero++;
		}
	}
	if(zero+m>n){
		cout<<0<<endl;
		return 0;
	}
	if(m==n){
		if(flag1)cout<<duo[n]<<endl;
		else cout<<0<<endl;
		return 0;
	}
	if(flag1){
		solveA();
		return 0;
	}
	if(n<=18){
		bruce();
		return 0;
	}
	
	return 0;
}

