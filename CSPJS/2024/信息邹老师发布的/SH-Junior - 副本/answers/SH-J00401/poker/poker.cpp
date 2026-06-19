#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s[52];
	int ifsame=0;
	for(int i=1;i<=n;i++){
		ifsame=0;
		cin>>s[i];
		for(int j=0;j<=i-1;j++){
			if(s[i]==s[j]){
				ifsame=1;
				break;
			}
		}
		if(!ifsame){
			ans++;
		}
	}
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
