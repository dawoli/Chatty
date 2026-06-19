#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
 	freopen("xor.out","w",stdout);
int a,b;
cin>>a>>b;
int qwe[a];
bool sdf[a][a];
int q[a][a];
for(int i=0;i<a;i++){
	for(int j=0;j<a;j++){
		q[i][j] = -1;
		sdf[i][j] = 0;
	} 
}
for(int i=0;i<a;i++){
	cin>>qwe[i];
	q[i][i] = qwe[i];
}
for(int i=0;i<a;i++){
	for(int j=i+1;j<a;j++){
		q[i][j] = q[i][j-1]^qwe[j];
	}
}


int y=0;
for(int i=0;i<a;i++){
	for(int j=0;j<a-i;j++){
		if(sdf[j][j+i] == 0&&q[j][j+i] == b){
		   y++;
		  

		for(int m=j;m>=0;m--){
		   	for(int n = j+i;n<a;n++){
		   		sdf[m][n] = 1;
			   }
		   }
	
		}
	} 
}
cout<<y;
return 0;
}

/*
for(int i=0;i<a;i++){
	for(int j=0;j<a;j++){
		cout<<q[i][j]<<" ";
	}
	cout<<endl;
}
*/
//101 1 1 1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

