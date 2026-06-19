#include<bits/stdc++.h>
using namespace std;
long long a[10][20]={0};long long n,cnt=0;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int len=s.length();
		if(s[0]=='D'&&s[1]=='A') a[1][1]++;
		else if(s[0]=='D'&&s[1]==50) a[1][2]++;
		else if(s[0]=='D'&&s[1]==51) a[1][3]++;
		else if(s[0]=='D'&&s[1]==52) a[1][4]++;
		else if(s[0]=='D'&&s[1]==53) a[1][5]++;
		else if(s[0]=='D'&&s[1]==54) a[1][6]++;
		else if(s[0]=='D'&&s[1]==55) a[1][7]++;
		else if(s[0]=='D'&&s[1]==56) a[1][8]++;
		else if(s[0]=='D'&&s[1]==57) a[1][9]++;
		else if(s[0]=='D'&&s[1]=='T') a[1][10]++;
		else if(s[0]=='D'&&s[1]=='J') a[1][11]++;
		else if(s[0]=='D'&&s[1]=='Q') a[1][12]++;
		else if(s[0]=='D'&&s[1]=='K') a[1][13]++;
		else if(s[0]=='C'&&s[1]=='A') a[2][1]++;
		else if(s[0]=='C'&&s[1]=='2') a[2][2]++;
		else if(s[0]=='C'&&s[1]=='3') a[2][3]++;
		else if(s[0]=='C'&&s[1]=='4') a[2][4]++;
		else if(s[0]=='C'&&s[1]=='5') a[2][5]++;
		else if(s[0]=='C'&&s[1]=='6') a[2][6]++;
		else if(s[0]=='C'&&s[1]=='7') a[2][7]++;
		else if(s[0]=='C'&&s[1]=='8') a[2][8]++;
		else if(s[0]=='C'&&s[1]=='9') a[2][9]++;
		else if(s[0]=='C'&&s[1]=='T') a[2][10]++;
		else if(s[0]=='C'&&s[1]=='J') a[2][11]++;
		else if(s[0]=='C'&&s[1]=='Q') a[2][12]++;
		else if(s[0]=='C'&&s[1]=='K') a[2][13]++;
		else if(s[0]=='H'&&s[1]=='A') a[3][1]++;
		else if(s[0]=='H'&&s[1]=='2') a[3][2]++;
		else if(s[0]=='H'&&s[1]=='3') a[3][3]++;
		else if(s[0]=='H'&&s[1]=='4') a[3][4]++;
		else if(s[0]=='H'&&s[1]=='5') a[3][5]++;
		else if(s[0]=='H'&&s[1]=='6') a[3][6]++;
		else if(s[0]=='H'&&s[1]=='7') a[3][7]++;
		else if(s[0]=='H'&&s[1]=='8') a[3][8]++;
		else if(s[0]=='H'&&s[1]=='9') a[3][9]++;
		else if(s[0]=='H'&&s[1]=='T') a[3][10]++;
		else if(s[0]=='H'&&s[1]=='J') a[3][11]++;
		else if(s[0]=='H'&&s[1]=='Q') a[3][12]++;
		else if(s[0]=='H'&&s[1]=='K') a[3][13]++;
		else if(s[0]=='S'&&s[1]=='A') a[4][1]++;
		else if(s[0]=='S'&&s[1]=='2') a[4][2]++;
		else if(s[0]=='S'&&s[1]=='3') a[4][3]++;
		else if(s[0]=='S'&&s[1]=='4') a[4][4]++;
		else if(s[0]=='S'&&s[1]=='5') a[4][5]++;
		else if(s[0]=='S'&&s[1]=='6') a[4][6]++;
		else if(s[0]=='S'&&s[1]=='7') a[4][7]++;
		else if(s[0]=='S'&&s[1]=='8') a[4][8]++;
		else if(s[0]=='S'&&s[1]=='9') a[4][9]++;
		else if(s[0]=='S'&&s[1]=='T') a[4][10]++;
		else if(s[0]=='S'&&s[1]=='J') a[4][11]++;
		else if(s[0]=='S'&&s[1]=='Q') a[4][12]++;
		else if(s[0]=='S'&&s[1]=='K') a[4][13]++;
	}
	for(int i=1;i<5;i++){
		for(int j=1;j<=13;j++){
			if(a[i][j]==0){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
