#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10009;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	string s[N][2],t[2];
	for(int i=0;i<n;i++)
		cin>>s[i][0]>>s[i][1];
	for(int i=0;i<m;i++){
		int cnt=0;
		cin>>t[0]>>t[1];
		string tmp=t[0];
		for(int j=0;j<n;j++){
			int p=t[0].find(s[j][0]);
			while(p!=-1){
				for(int k=0;k<s[j][0].size();k++)
					t[0][k+p]=s[j][1][k];
				if(t[0]==t[1])cnt++;
				t[0]=tmp;
				p=t[0].find(s[j][0],p+1);
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
