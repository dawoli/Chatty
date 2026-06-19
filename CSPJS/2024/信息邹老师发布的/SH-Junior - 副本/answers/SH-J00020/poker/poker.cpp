#include<bits/stdc++.h>
using namespace std;
string s[60];
int n,ans;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[i][0]==s[j][0] && s[i][1]==s[j][1]){
				ans++;
			}
		}
	}
	cout<<52-(n-ans);
	return 0;
}
