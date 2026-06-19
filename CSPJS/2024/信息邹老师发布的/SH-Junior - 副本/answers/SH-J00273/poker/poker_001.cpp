#include<bits/stdc++.h>
using namespace std;
int A[53];
int N;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>N;
	memset(A,0,sizeof(A));
	string s;
	int x;
	while(N--){
		cin>>s;
		x=0;
		if(s[1]>='2'&&s[1]<='9')x=s[1]-'0';
		if(s[1]=='T')x=10;
		if(s[1]=='A')x=1;
		if(s[1]=='J')x=11;
		if(s[1]=='Q')x=12;
		if(s[1]=='K')x=13;
		if(s[0]=='D')x+=0;
		if(s[0]=='C')x+=13;
		if(s[0]=='H')x+=26;
		if(s[0]=='S')x+=39;
		A[x]++;
	}
	int ans=0;
	for(int i=1;i<=52;i++){
		if(A[i]==0)ans++;
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
