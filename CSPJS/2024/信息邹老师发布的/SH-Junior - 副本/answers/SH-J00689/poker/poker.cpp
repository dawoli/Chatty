#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<utility>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;
int p[53],n;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		char a,b;
		cin>>a>>b;
		if(a=='S'){
			if(b=='T')p[10]=1;
			else if(b=='J')p[11]=1;
			else if(b=='Q')p[12]=1;
			else if(b=='K')p[13]=1;
			else p[b-'0']=1;
		}else if(a=='H'){
			if(b=='T')p[23]=1;
			else if(b=='J')p[24]=1;
			else if(b=='Q')p[25]=1;
			else if(b=='K')p[26]=1;
			else p[b-'0'+13]=1;
		}else if(a=='C'){
			if(b=='T')p[36]=1;
			else if(b=='J')p[37]=1;
			else if(b=='Q')p[38]=1;
			else if(b=='K')p[39]=1;
			else p[b-'0'+26]=1;
		}else if(a=='D'){
			if(b=='T')p[49]=1;
			else if(b=='J')p[50]=1;
			else if(b=='Q')p[51]=1;
			else if(b=='K')p[52]=1;
			else p[b-'0'+39]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=52;i++){
		ans+=p[i];
	}
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
