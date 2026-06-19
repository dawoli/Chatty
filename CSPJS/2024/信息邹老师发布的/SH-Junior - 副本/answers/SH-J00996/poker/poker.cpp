#include<bits/stdc++.h>
using namespace std;
int n,a[53];
char s[3];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int ans=0;
		scanf("%s",s+1);
		if(s[1]=='C'){
			ans+=13;
		}
		if(s[1]=='H'){
			ans+=26;
		}
		if(s[1]=='S'){
			ans+=39;
		}
		if(s[2]=='A'){
			ans+=1;
		}
		else if(s[2]=='T'){
			ans+=10;
		}
		else if(s[2]=='J'){
			ans+=11;
		}
		else if(s[2]=='Q'){
			ans+=12;
		}
		else if(s[2]=='K'){
			ans+=13;
		}
		else{
			ans+=s[2]-'0';
		}
		a[ans]++;
	}
	int ans=0;
	for(int i=1;i<=52;i++){
		if(a[i]>0){
			ans++;
		}
	}
	printf("%d",52-ans);
	return 0;
}
