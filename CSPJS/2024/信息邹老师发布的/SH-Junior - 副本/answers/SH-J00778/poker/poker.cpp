#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,ans=0,card[4][13];
string now,color,num;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>now;
		color=now[0];
		num=now[1];
		if(color=="D"){
			if(num=="A") card[0][0]++;
			else if(num=="2") card[0][1]++;
			else if(num=="3") card[0][2]++;
			else if(num=="4") card[0][3]++;
			else if(num=="5") card[0][4]++;
			else if(num=="6") card[0][5]++;
			else if(num=="7") card[0][6]++;
			else if(num=="8") card[0][7]++;
			else if(num=="9") card[0][8]++;
			else if(num=="T") card[0][9]++;
			else if(num=="J") card[0][10]++;
			else if(num=="Q") card[0][11]++;
			else if(num=="K") card[0][12]++;
		}
		else if(color=="C"){
			if(num=="A") card[1][0]++;
			else if(num=="2") card[1][1]++;
			else if(num=="3") card[1][2]++;
			else if(num=="4") card[1][3]++;
			else if(num=="5") card[1][4]++;
			else if(num=="6") card[1][5]++;
			else if(num=="7") card[1][6]++;
			else if(num=="8") card[1][7]++;
			else if(num=="9") card[1][8]++;
			else if(num=="T") card[1][9]++;
			else if(num=="J") card[1][10]++;
			else if(num=="Q") card[1][11]++;
			else if(num=="K") card[1][12]++;
		}
		else if(color=="H"){
			if(num=="A") card[2][0]++;
			else if(num=="2") card[2][1]++;
			else if(num=="3") card[2][2]++;
			else if(num=="4") card[2][3]++;
			else if(num=="5") card[2][4]++;
			else if(num=="6") card[2][5]++;
			else if(num=="7") card[2][6]++;
			else if(num=="8") card[2][7]++;
			else if(num=="9") card[2][8]++;
			else if(num=="T") card[2][9]++;
			else if(num=="J") card[2][10]++;
			else if(num=="Q") card[2][11]++;
			else if(num=="K") card[2][12]++;
		}
		else if(color=="S"){
			if(num=="A") card[3][0]++;
			else if(num=="2") card[3][1]++;
			else if(num=="3") card[3][2]++;
			else if(num=="4") card[3][3]++;
			else if(num=="5") card[3][4]++;
			else if(num=="6") card[3][5]++;
			else if(num=="7") card[3][6]++;
			else if(num=="8") card[3][7]++;
			else if(num=="9") card[3][8]++;
			else if(num=="T") card[3][9]++;
			else if(num=="J") card[3][10]++;
			else if(num=="Q") card[3][11]++;
			else if(num=="K") card[3][12]++;
		}
	}
	for(int i=0;i<4;i++)
		for(int j=0;j<13;j++)
			if(card[i][j]==0) ans++;
	cout<<ans<<endl;
	return 0;
}
