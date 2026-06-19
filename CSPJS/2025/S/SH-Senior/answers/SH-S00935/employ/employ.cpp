#include<bits/stdc++.h>
using namespace std;
int b[510],c[510];
bool s[510]={0};
	int n,m,ans=0;
void f(int k,int o,int l){
	if(k>n){
		if(o>=m){
			ans++;
		}
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(s[i]==1){
				continue;
			} 
			if(b[k]==1&&l<c[i]&&s[i]==0){
				k++;
				s[i]=1;
				o++;
				f(k,o,l);
				k--;
				s[i]=0;
				o--;
			}
			if(b[k]==0||l>=c[i]){
				l++;
				s[i]=1;
				k++;
				f(k,o,l);
				l--;
				s[i]=0;
				k--;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		string e;
		cin>>e;
		for(int i=0;i<n;i++){
			cin>>c[i];
			if(c[i]==0){
				cout<<0;
				return 0;
			}
			if(e[i]=='0'){
				cout<<0;
				return 0;
			}
		} 
		cout<<1;
		return 0;
	}
	string a;
	int cnt=1;
	cin>>a;
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			b[i+1]=0;
		}
		if(a[i]=='1'){
			b[i+1]=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	if(m==1){
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
	}
	f(1,0,0);
	cout<<ans%998244353;
}
