#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,f1,f2,aa=0;
	cin>>n;
	char a[4][14]={},x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(x=='D'){
			f1=1;
		}else if(x=='C'){
			f1=2;
		}else if(x=='H'){
			f1=3;
		}else{
			f1=0;
		}if(y=='A'){
			f2=1;
		}else  if(y=='T'){
			f2=10;
		}else if(y=='J'){
			f2=11;
		}else if(y=='Q'){
			f2=12;
		}else if(y=='K'){
			f2=13;
		}else{
			f2=int(y-'0');
		}a[f1][f2]=1;
	}
	for(int i=0;i<4;i++){
		for(int j=1;j<14;j++){
			if(a[i][j]==0){
				aa++;
			}
		}
	}cout<<aa;
	return 0;
}
