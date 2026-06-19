#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;

int n,m,cnt;
int c[505];
bool flagA=true;

ll ksm(ll a,int k){
	//cout<<a<<" "<<k<<endl;
	if(k<=1)return a%mod;
	if(k%2==1)return a*ksm(a,k-1)%mod;
	return ksm((a%mod)*a%mod,k/2)%mod;
}

int cal(int a,int b){
	//cout<<a<<b<<endl;
	if(a<2*b)return cal(a,a-b);
	ll num=1;
	for(int i=a;i>=a-b+1;i--){
		//cout<<num<<endl;
		num=num*i%mod;
		
	}
	//cout<<num<<endl;
	for(int i=1;i<=b;i++){
		//cout<<i<<" "<<ksm(i,mod-2)%mod<<endl;
		num=num*ksm(i,mod-2)%mod;
	}
	
	return num;
}

bool cmp(int x,int y){
	return x>y;
}

int main(){
	//cout<<ksm(2,10)<<endl;
	//cout<<cal(7,3)<<endl;
	//cout<<cal(62,47)<<endl;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
//	cout<<s<<endl;
	for(int i=0;i<n;i++){
		if(s[i]=='1')continue;
		//cout<<i<<" "<<s[i]<<endl;
		flagA=false;
		break;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)cnt++;
	}
	if(flagA){
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++)cout<<c[i]<<" ";
		//cout<<endl;
		//cout<<c[47]<<endl;
		//cout<<cnt<<endl;
		cout<<cal(cnt,m)<<endl;
		return 0;
	}
	if(m==1){
		
	}
	
	
	return 0;
}
