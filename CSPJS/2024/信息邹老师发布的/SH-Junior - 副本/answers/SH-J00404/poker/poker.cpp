#include<bits/stdc++.h>
using namespace std;
int n,a[100][100],c,num,ans;
int main(){
	
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
    string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D')c=1;
		else if(s[0]=='C')c=2;
		else if(s[0]=='H')c=3;
		else c=4;
		if(s[1]=='A')num=1;
		else if(s[1]=='T')num=10;
		else if(s[1]=='J')num=11;
		else if(s[1]=='Q')num=12;
		else if(s[1]=='K')num=13;
		else num=s[1]-'0';
		a[c][num]=1;
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j])ans++;
		} 
	}
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
