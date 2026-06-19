#include<bits/stdc++.h>
using namespace std;

int a[52];
int main(){
	freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
	int n;cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s=="DA") a[0]++;
		else if(s=="D2") a[1]++;
		else if(s=="D3") a[2]++;
		else if(s=="D4") a[3]++;
		else if(s=="D5") a[4]++;
		else if(s=="D6") a[5]++;
		else if(s=="D7") a[6]++;
		else if(s=="D8") a[7]++;
		else if(s=="D9") a[8]++;
		else if(s=="DT") a[9]++;
		else if(s=="DJ") a[10]++;
		else if(s=="DQ") a[11]++;
		else if(s=="DK") a[12]++;
		else if(s=="CA") a[13]++;
		else if(s=="C2") a[14]++;
		else if(s=="C3") a[15]++;
		else if(s=="C4") a[16]++;
		else if(s=="C5") a[17]++;
		else if(s=="C6") a[18]++;
		else if(s=="C7") a[19]++;
		else if(s=="C8") a[20]++;
		else if(s=="C9") a[21]++;
		else if(s=="CT") a[22]++;
		else if(s=="CJ") a[23]++;
		else if(s=="CQ") a[24]++;
		else if(s=="CK") a[25]++;
		else if(s=="HA") a[26]++;
		else if(s=="H2") a[27]++;
		else if(s=="H3") a[28]++;
		else if(s=="H4") a[29]++;
		else if(s=="H5") a[30]++;
		else if(s=="H6") a[31]++;
		else if(s=="H7") a[32]++;
		else if(s=="H8") a[33]++;
		else if(s=="H9") a[34]++;
		else if(s=="HT") a[35]++;
		else if(s=="HJ") a[36]++;
		else if(s=="HQ") a[37]++;
		else if(s=="HK") a[38]++;
		else if(s=="SA") a[39]++;
		else if(s=="S2") a[40]++;
		else if(s=="S3") a[41]++;
		else if(s=="S4") a[42]++;
		else if(s=="S5") a[43]++;
		else if(s=="S6") a[44]++;
		else if(s=="S7") a[45]++;
		else if(s=="S8") a[46]++;
		else if(s=="S9") a[47]++;
		else if(s=="ST") a[48]++;
		else if(s=="SJ") a[49]++;
		else if(s=="SQ") a[50]++;
		else if(s=="SK") a[51]++;
	}
	int cnt=0;
	for(int i=0;i<52;i++){
		if(a[i]==0) cnt++;
	}
	cout<<cnt;
} 
