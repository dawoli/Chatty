#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	char in[55][5]={'0'};
	int a[55][5]={0};
	for(int i=1;i<=n;i++){
		cin>>in[i];
		int temp;
		if(in[i][1]=='T')temp=10;
		else if(in[i][1]=='J')temp=11;
		else if(in[i][1]=='Q')temp=12;
		else if(in[i][1]=='K')temp=13;
		else if(in[i][1]=='A')temp=1;
		else temp=in[i][1]-48;
		if(in[i][0]=='D'){
			a[temp][1]=1;
		}
		else if(in[i][0]=='C'){
			a[temp][2]=1;
		}
		else if(in[i][0]=='H'){
			a[temp][3]=1;
		}
		else if(in[i][0]=='S'){
			a[temp][4]=1;
		}
	}
	int cnt=0;
	for(int i=1;i<=13;i++){
		for(int j=1;j<=4;j++){
			if(a[i][j]==1){
				cnt++;
			}
		}
	}
	cout<<52-cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
