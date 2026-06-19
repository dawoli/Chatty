#include<bits/stdc++.h>
using namespace std;
string s[110];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(s[i]==s[j]&&i!=j)	k++;
		}
	}
	cout<<52-(n-k/2);
	return 0;
}
