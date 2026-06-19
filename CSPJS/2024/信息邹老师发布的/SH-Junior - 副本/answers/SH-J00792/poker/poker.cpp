#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s[54];
bool flag[54];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=1;j<i;j++){
			if(s[i]==s[j]&&flag[j]==0&&flag[i]==0){
				cnt++;
				flag[i]=flag[j]=1;
			}
			else if(s[i]==s[j]&&flag[j]==1&&flag[i]==0) flag[i]=1;
		}
		if(flag[i]==0){
			cnt++;
			flag[i]=1;
		}
	}
	cout<<52-cnt;
	return 0;
} 
