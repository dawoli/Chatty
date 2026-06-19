#include<bits/stdc++.h>
using namespace std;
int n;
int mk[4][13];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	while(n--){
		char c,c1;
		cin>>c>>c1;
		if(c=='D'){
			if(c1>='2'&&c1<='9'){
				mk[0][c1-'0'-1]=1;
			}
			else if(c1=='T')	mk[0][9]=1;
			else if(c1=='J')	mk[0][10]=1;
			else if(c1=='Q')	mk[0][11]=1;
			else if(c1=='K')	mk[0][12]=1;
			else	mk[0][0]=1; 
		}
		else if(c=='C'){
			if(c1>='2'&&c1<='9'){
				mk[1][c1-'0'-1]=1;
			}
			else if(c1=='T')	mk[1][9]=1;
			else if(c1=='J')	mk[1][10]=1;
			else if(c1=='Q')	mk[1][11]=1;
			else if(c1=='K')	mk[1][12]=1;
			else	mk[1][0]=1; 
		}
		else if(c=='H'){
			if(c1>='2'&&c1<='9'){
				mk[2][c1-'0'-1]=1;
			}
			else if(c1=='T')	mk[2][9]=1;
			else if(c1=='J')	mk[2][10]=1;
			else if(c1=='Q')	mk[2][11]=1;
			else if(c1=='K')	mk[2][12]=1;
			else	mk[2][0]=1; 
		}
		else{
			if(c1>='2'&&c1<='9'){
				mk[3][c1-'0'-1]=1;
			}
			else if(c1=='T')	mk[3][9]=1;
			else if(c1=='J')	mk[3][10]=1;
			else if(c1=='Q')	mk[3][11]=1;
			else if(c1=='K')	mk[3][12]=1;
			else	mk[3][0]=1; 
		}
	} 
	int ans=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++){
			if(!mk[i][j])	ans++;
		} 
	cout<<ans;
} 
