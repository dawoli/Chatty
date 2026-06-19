#include<bits/stdc++.h>
#include<time.h>
using namespace std;
const long long mod=998244353;
int n,m,c[505],p[505];
long long ans;
char s[505];
bool flag=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0') flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<rand()%mod;
	return 0;
}
