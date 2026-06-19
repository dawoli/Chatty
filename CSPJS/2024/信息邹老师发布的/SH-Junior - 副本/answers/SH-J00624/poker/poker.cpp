#include<bits/stdc++.h>
using namespace std;
int n,t[5][15];
string a[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n; 
	if(n==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=0,y=0;
		if(a[i][0]=='D')x=1;
		else if(a[i][0]=='C')x=2;
		else if(a[i][0]=='H')x=3;
		else x=4;
		if(a[i][1]=='A')y=1;
		else if(a[i][1]=='2')y=2;
		else if(a[i][1]=='3')y=3;
		else if(a[i][1]=='4')y=4;
		else if(a[i][1]=='5')y=5;
		else if(a[i][1]=='6')y=6;
		else if(a[i][1]=='7')y=7;
		else if(a[i][1]=='8')y=8;
		else if(a[i][1]=='9')y=9;
		else if(a[i][1]=='T')y=10;
		else if(a[i][1]=='J')y=11;
		else if(a[i][1]=='Q')y=12;
		else y=13;
		t[x][y]=1;
	}
	int sum=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=13;j++){
			if(t[i][j])sum++;
		}
	}
	cout<<52-sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
