#include<bits/stdc++.h>
using namespace std;
int n; //ÆË¿ËÅÆÊýÁ¿ 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	int flags[52];
	memset(flags, 0, sizeof(flags));
	for (int card=0; card<n;card++){
		char huase;
		char number;
		cin>>huase>>number;
		int shifts = 0;
		if (huase=='C') shifts=13;
		else if (huase =='H') shifts=26;
		else if (huase =='S') shifts=39;
		if (number=='A') flags[shifts]=1;
		else if (number=='2') flags[shifts+1]=1;
		else if (number=='3') flags[shifts+2]=1;
		else if (number=='4') flags[shifts+3]=1;
		else if (number=='5') flags[shifts+4]=1;
		else if (number=='6') flags[shifts+5]=1;
		else if (number=='7') flags[shifts+6]=1;
		else if (number=='8') flags[shifts+7]=1;
		else if (number=='9') flags[shifts+8]=1;
		else if (number=='T') flags[shifts+9]=1;
		else if (number=='J') flags[shifts+10]=1;
		else if (number=='Q') flags[shifts+11]=1;
		else if (number=='K') flags[shifts+12]=1;
	}
	int cnt = 0;
	for (int j=0;j<52;j++){
		if (flags[j]==0)
		cnt += 1;
	}
	cout << cnt;
	return 0;
}

