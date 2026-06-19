#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	int cnt=0;
	string s[100];
	for(int i=1;i<=n;i++){
		cin>>s[i];
		int o=0;
		for(int j=1;j<i;j++){
			if(s[j]==s[i]){
				o=1;
				break;
			}
		}
		if(o==0){
			cnt++;
		}
	}
	cout<<52-cnt;
	return 0;
} 
