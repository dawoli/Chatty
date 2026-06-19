#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,ans;
string s;
int c[505],vis[20],a[20],b[20];
void f(int depth,int ans1,int ans2){
	if(ans2>=m){
	//	cout<<a[1]<<" "<<a[2]<<" "<<ans2<<" %\n";
	//	cout<<ans<<" ";
		ans=(b[n+1-depth]+ans)%mod;
	//	cout<<depth<<" "<<ans<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if(c[i]>ans1&&s[depth]=='1'){
			//	cout<<i<<" "<<c[i]<<" "<<ans1<<" "<<depth<<" #\n";
				f(depth+1,ans1,ans2+1);				
			}else{
			//	cout<<"$"<<endl;
				f(depth+1,ans1+1,ans2);	
			}
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//3467040
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s='1'+s;
	int flag1=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) flag1++;
	}
	if(n<=18){
		b[0]=1;
		b[1]=1;
		for(int i=2;i<=18;i++){
			b[i]=i*b[i-1]%mod;
		}
		f(1,0,0);
		printf("%lld",ans);
		return 0;
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		if(s[i]!='1') flag=1;
	}
//	if(flag==0){
		if(flag1<m){
			printf("0");
			return 0;
		}
		ans=1;
		for(int i=n;i>=2;i--){
			ans=ans*i%mod;
		}
		printf("%lld",ans);
		return 0;
//	}
	
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
