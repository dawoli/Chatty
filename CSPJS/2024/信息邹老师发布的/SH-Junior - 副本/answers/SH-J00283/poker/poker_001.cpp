#include<bits/stdc++.h>
using namespace std;
string s[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		bool flag=true;
		for(int j=1;j<i;j++){
			if(s[j]==s[i]){
				flag=false;
			}
		}
		if(flag)cnt++;
	}
	cout<<52-cnt;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
