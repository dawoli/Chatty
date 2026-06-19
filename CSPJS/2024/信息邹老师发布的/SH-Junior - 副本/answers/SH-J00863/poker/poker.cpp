#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
unordered_map<string,bool>flag;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		cin>>s;
		if(!flag[s]){
			flag[s]=true;
			ans--;
		}
	}
	printf("%d",ans);
	return 0;
}

