#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
int n;
const int N=200009;
int A[N];
string binary(int i){
	string t(n+1,0);
	for(int i=0;i<n;i++) t[i]=i;
	int k=0;
	while(i){
		int r=i%2;
		t[++k]=r+'0';
		i/=2;
	}
	reverse(t.begin(),t.end());
	return t;
}
void solveBF(){
	ans=0;
	for(int i=0;i<(1<<n);i++){
		string s=binary(i);
		ll pts=0,lst0=0,lst1=0;
		for(int j=0;j<n;j++){
			if(A[j+1]==A[lst0] && lst0 && s[j]=='0') pts+=A[j+1];
			if(A[j+1]==A[lst1] && lst1 && s[j]=='1') pts+=A[j+1];
			if(s[j]=='0') lst0=j+1;
			else if(s[j]=='1') lst1=j+1;
		}
		ans=max(ans,pts);
	}
	cout<<ans<<endl;
}
void solve(){
	solveBF();
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>A[i];
		if(n<=15) solveBF();
		else solve();
	}
	return 0;
}
