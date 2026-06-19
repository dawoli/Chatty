#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int t[15][105]; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		char c,p;
		cin>>c>>p;
		int a;
		if(c=='D')a=1;
		if(c=='C')a=2;
		if(c=='H')a=3;
		if(c=='S')a=4;
		if('2'<=p&&p<='9')t[a][p-'0']=1;
		if(p=='A')t[a][1]=1;
		if(p=='T')t[a][10]=1;
		if(p=='J')t[a][11]=1;
		if(p=='Q')t[a][12]=1;
		if(p=='K')t[a][13]=1;
	}
	int sum=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(!t[i][j])sum++;
		}
	}
	cout<<sum;
	return 0;
} 
