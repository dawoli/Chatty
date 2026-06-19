#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n;
	long long a[100][100]={};
	cin>>n;
	for(int i=0;i<n;i++){
		char t[10];
		long long x,y; 
		cin>>t;
		if(t[0]=='C'){
			y=0;
		}else if(t[0]=='S'){
			y=1;
		}else if(t[0]=='H'){
			y=2;
		}else if(t[0]=='D'){
			y=3;
		} 
		if(t[1]=='A'){
			x=0;
		}else if(t[1]=='2'){
			x=1;
		}else if(t[1]=='3'){
			x=2;
		}else if(t[1]=='4'){
			x=3;
		}else if(t[1]=='5'){
			x=4;
		}else if(t[1]=='6'){
			x=5;
		}else if(t[1]=='7'){
			x=6;
		}else if(t[1]=='8'){
			x=7;
		}else if(t[1]=='9'){
			x=8;
		}else if(t[1]=='T'){
			x=9;
		}else if(t[1]=='J'){
			x=10;
		}else if(t[1]=='Q'){
			x=11;
		}else if(t[1]=='K'){
			x=12;
		}
		a[x][y]++;
	}
	int sum=0;
	for(int i=0;i<=12;i++){
		for(int j=0;j<=3;j++){
			if(a[i][j]==0){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
