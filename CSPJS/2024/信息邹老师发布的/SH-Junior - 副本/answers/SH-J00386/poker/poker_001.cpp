#include<bits/stdc++.h>
using namespace std;
int poker[101][101];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	long long n,d=0,c=0,h=0,s=0,num=0,sum=0,ans=0;
	string k;
	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>k;
		if(k[0]=='D'){
			if(k[1]=='T'){
				poker[0][d]=10;
				d++;
			}
			else if(k[1]=='J'){
				poker[0][d]=11;
				d++;
			}
			else if(k[1]=='Q'){
				poker[0][d]=12;
				d++;
			}
			else if(k[1]=='K'){
				poker[0][d]=13;
				d++;
			}
			else if(k[1]=='A'){
				poker[0][d]=1;
				d++;
			}
			else{
				poker[0][d]=k[1]-'0';
				d++;
			}
		}
		if(k[0]=='C'){
			if(k[1]=='T'){
				poker[1][c]=10;
				c++;
			}
			else if(k[1]=='J'){
				poker[1][c]=11;
				c++;
			}
			else if(k[1]=='Q'){
				poker[1][c]=12;
				c++;
			}
			else if(k[1]=='K'){
				poker[1][c]=13;
				c++;
			}
			else if(k[1]=='A'){
				poker[1][c]=1;
				c++;
			}
			else{
				poker[1][c]=k[1]-'0';
				c++;
			}
		}
		if(k[0]=='H'){
			if(k[1]=='T'){
				poker[2][h]=10;
				h++;
			}
			else if(k[1]=='J'){
				poker[2][h]=11;
				h++;
			}
			else if(k[1]=='Q'){
				poker[2][h]=12;
				h++;
			}
			else if(k[1]=='K'){
				poker[2][h]=13;
				h++;
			}
			else if(k[1]=='A'){
				poker[2][h]=1;
				h++;
			}
			else{
				poker[2][h]=k[1]-'0';
				h++;
			}
		}
		if(k[0]=='S'){
			if(k[1]=='T'){
				poker[3][s]=10;
				s++;
			}
			else if(k[1]=='J'){
				poker[3][s]=11;
				s++;
			}
			else if(k[1]=='Q'){
				poker[3][s]=12;
				s++;
			}
			else if(k[1]=='K'){
				poker[3][s]=13;
				s++;
			}
			else if(k[1]=='A'){
				poker[3][s]=1;
				s++;
			}
			else{
				poker[3][s]=k[1]-'0';
				s++;
			}
		}
	}
	sort(poker[0],poker[0]+13);
	sort(poker[1],poker[1]+13);
	sort(poker[3],poker[3]+13);
	sort(poker[2],poker[2]+13);
	for(int i=0;i<=3;i++){
		sum=0;
		ans=0;
		for(int j=0;j<=12;j++){
			if(poker[i][j]==poker[i][j-1] and poker[i][j]!=0){
				sum++;
			}
			if(poker[i][j]!=0){
				ans++;
			}
		}
		num=num+13-ans+sum;
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
