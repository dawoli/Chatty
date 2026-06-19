#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans=1;
char s[505];
bool flag=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			flag=1;
			break;
		} 
	}
	if(flag==0){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		printf("%d\n",ans);
		return 0;
	} 
	return 0;
} 
