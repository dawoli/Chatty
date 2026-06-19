#include<iostream>
using namespace std;
int main(){
	freopen("poker.in","r",fin);
	freopen("poker.in","W",fout);
	int n,a[4][13]={};
	cin>>n;
	string t;
	for(int i=1;i<=n;i++){
		cin>>t;
		int zb;
		if(t[0]=='D'){
			zb=0;
		}
		if(t[0]=='c'){
			zb=1;
		}
		if(t[0]=='H'){
			zb=2;
		}
		if(t[0]=='S'){
			zb=3;
		}
		if(t[1]=='A'){
		    a[zb][0]=1;
		}else if(t[1]=='T'){
			a[zb][9]=1;
		}else if(t[1]=='J'){
			a[zb][10]=1;
		}else if(t[1]=='Q'){
			a[zb][11]=1;
		}else if(t[1]=='K'){
			a[zb][12]=1;
		}else{
			a[zb][int(t[1]-'0')-1]=1;
		}
	}
	int sum=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<13;j++){
			if(a[i][j]==0){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
