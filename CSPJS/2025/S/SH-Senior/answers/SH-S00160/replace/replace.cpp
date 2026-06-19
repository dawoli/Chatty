#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5;
int n,t,ans;
int vis[N];
string a[N],b[N],s,e;
bool judge(string s,int st,int p){
	int l=a[p].size();
	for(int i=0;i<l;i++){
		if(s[st+i]!=a[p][i]) return 0;
	}
	return 1;
}
void dfs(string s,string e){
	if(s == e){
		ans++;
	}
	for(int i=1;i<=n;i++){
		int l=a[i].size();
		int f=0;
		for(int j=0;j<s.size();j++){
			if(judge(s,j,i) && !vis[i]){
				f=j+1;
				break;
			}
		}
		if(f){
			vis[i] = 1;
			string s1="";
			for(int i=0;i<f;i++){
				s1[i] = s[i];
			}
			s1+=b[i];
			dfs(s,e);
			vis[i] = 0;
		}
	}
}
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(t--){
		int ans = 0;
		cin>>s>>e;
		dfs(s,e);
		cout<<ans;
	}
	return 0;
}

