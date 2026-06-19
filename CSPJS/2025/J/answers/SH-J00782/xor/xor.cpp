#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
const int N=5e5+20;
int n,k,dp[N],e[32];
void init(){
	e[0]=1;
	for(int i=1;i<=31;i++){
		e[i]=e[i-1]*2;
	}
}
string totwo(int x){
	string s;
	while(x!=0){
		s=s+char(x%2+'0');
		x/=2;
	}
	return s;
}
int xo(int x,int y){
	string s=totwo(x);
	string s1=totwo(y);
	int l=s.length();
	int l1=s1.length();
	int len=max(l,l1);
	int ans=0;
	for(int i=0;i<len;i++){
		if(i>=l)s[i]='0';
		if(i>=l1)s1[i]='0';
		if(s[i]!=s1[i]){
			ans+=e[i];
		}
	}
	return ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	init();
	cin>>n>>k;
	queue<int> q;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		q.push(x);
	}
	int ans=0;
	vector<int> nxo;
	if(q.front()==k)ans++;
	else nxo.push_back(q.front());
	q.pop();
	while(!q.empty()){
		int x=q.front();
		if(x==k){
			ans++;
			x=0;
			nxo.clear();
		}
		else{
			for(int j=0;j<nxo.size();j++){
				nxo[j]=xo(nxo[j],x);
				if(nxo[j]==k){
					ans++;
					x=0;
					nxo.clear();
					break;
				}
			}
		}
		nxo.push_back(x);
		q.pop();
	}
	cout<<ans;
	return 0;
}
