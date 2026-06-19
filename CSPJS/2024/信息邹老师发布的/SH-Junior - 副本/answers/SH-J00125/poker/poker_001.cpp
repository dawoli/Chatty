#include<bits/stdc++.h>
using namespace std;
int check(char x){
	if(x=='A'){
		return 1;
	}
	else if(x=='T'){
		return 10;
	}
	else if(x=='J'){
		return 11;
	}
	else if(x=='Q'){
		return 12;
	}
	else if(x=='K'){
		return 13;
	}
	else{
		return x-'0';
	}
}
int sum[10][20];
int cnt = 0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	char a,b;
	int c;
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a>>b;
		c=check(b);
		if(a=='D'){
			sum[1][c]++;
		}
		else if(a=='C'){
			sum[2][c]++;
		}
		else if(a=='H'){
			sum[3][c]++;
		}
		else if(a=='S'){
			sum[4][c]++;
		}
	}
	for(int i = 1;i<=4;i++){
		for(int j = 1;j<=13;j++){
			if(sum[i][j]==0){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
