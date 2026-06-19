#include<bits/stdc++.h>
using namespace std;
bool isok[8][16];
int n,sum=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		if(s[1]>='2'&&s[1]<='9'){
			if(s[0]=='D')
				isok[0][s[1]-49]=1;
			else if(s[0]=='C')
				isok[1][s[1]-49]=1;
			else if(s[0]=='H')
				isok[2][s[1]-49]=1;
			else
				isok[3][s[1]-49]=1;
		}
		else if(s[1]=='T'){
			if(s[0]=='D')
				isok[0][9]=1;
			else if(s[0]=='C')
				isok[1][9]=1;
			else if(s[0]=='H')
				isok[2][9]=1;
			else
				isok[3][9]=1;
		}
		else if(s[1]=='A'){
			if(s[0]=='D')
				isok[0][0]=1;
			else if(s[0]=='C')
				isok[1][0]=1;
			else if(s[0]=='H')
				isok[2][0]=1;
			else
				isok[3][0]=1;
		}
		else if(s[1]=='J'){
			if(s[0]=='D')
				isok[0][10]=1;
			else if(s[0]=='C')
				isok[1][10]=1;
			else if(s[0]=='H')
				isok[2][10]=1;
			else
				isok[3][10]=1;
		}
		else if(s[1]=='Q'){
			if(s[0]=='D')
				isok[0][11]=1;
			else if(s[0]=='C')
				isok[1][11]=1;
			else if(s[0]=='H')
				isok[2][11]=1;
			else
				isok[3][11]=1;
		}
		else{
			if(s[0]=='D')
				isok[0][12]=1;
			else if(s[0]=='C')
				isok[1][12]=1;
			else if(s[0]=='H')
				isok[2][12]=1;
			else
				isok[3][12]=1;
		}
		cout<<i<<endl;
		for(int k=0;k<4;k++){
			for(int j=0;j<13;j++)
				cout<<isok[k][j];
			cout<<endl;
		}
		cout<<endl;
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(!isok[i][j])sum++;
	cout<<sum<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
