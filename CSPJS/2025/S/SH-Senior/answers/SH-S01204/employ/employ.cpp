#include<bits/stdc++.h>
using namespace std;
int n,m,k,l;
string s;
int a[505];
bool vis[505];
int q[105];
const int mod=998244353;
long long ans=0;

bool judge(){
//	for(int i=1;i<=n;i++){
//		cout<<q[i]<<" ";
//	}
//	cout<<"\n";
	int cnt=0,p=0;
	for(int i=1;i<=n;i++){
		if(cnt<q[i] && s[i-1]=='1'){
			p++;
		}
		else{
			cnt++;
		}
	}
	return p>=m;
}

void f(int num){
	if(num>n){
		if(judge()){
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			q[num]=a[i];
			f(num+1);
			vis[i]=0;
		}
	}
}

void solveA(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(1);
	cout<<ans;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	l=s.size();
	solveA();
	return 0;
}
