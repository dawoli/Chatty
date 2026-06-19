#include<bits/stdc++.h>
using namespace std;
int p[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=52;
	char li[13];
	li[0]='A';li[1]='2';li[2]='3';li[3]='4';li[4]='5';li[5]='6';li[6]='7';li[7]='8';
	li[8]='9';li[9]='T';li[10]='J';li[11]='Q';li[12]='K';
	string a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		for(int j=0;j<=12;j++){
			if(a[1]==li[j]){
				if(a[0]=='C') p[j]=1;
				if(a[0]=='S') p[13+j]=1;
				if(a[0]=='H') p[26+j]=1;
				if(a[0]=='D') p[39+j]=1;
				break;
			}
		}
	}
	for(int i=0;i<=51;i++){
		if(p[i]==1) ans-=1;
	}
	cout<<ans;
	return 0;
}
