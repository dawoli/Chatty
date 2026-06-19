#include<bits/stdc++.h>
using namespace std;
int a[105],n,cnt=0;
string si;
int main(){
	freopen("poker","r",stdin);
	freopen("poker","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>si;
		if(si=="DA") a[1]++;
		if(si=="CA") a[2]++;
		if(si=="HA") a[3]++;
		if(si=="SA") a[4]++;
		if(si=="A2") a[5]++;
		if(si=="C2") a[6]++;
		if(si=="H2") a[7]++;
		if(si=="S2") a[8]++;
		if(si=="A3") a[9]++;
		if(si=="C3") a[10]++;
		if(si=="H3") a[11]++;
		if(si=="S3") a[12]++;
		if(si=="D4") a[13]++;
		if(si=="C4") a[14]++;
		if(si=="H4") a[15]++;
		if(si=="S4") a[16]++;
		if(si=="D5") a[17]++;
		if(si=="C5") a[18]++;
		if(si=="H5") a[19]++;
		if(si=="S5") a[20]++;
		if(si=="D6") a[21]++;
		if(si=="C6") a[22]++;
		if(si=="H6") a[23]++;
		if(si=="S6") a[24]++;
		if(si=="D7") a[25]++;
		if(si=="C7") a[26]++;
		if(si=="H7") a[27]++;
		if(si=="S7") a[28]++;
		if(si=="D8") a[29]++;
		if(si=="C8") a[30]++;
		if(si=="H8") a[31]++;
		if(si=="S8") a[32]++;
		if(si=="D9") a[33]++;
		if(si=="C9") a[34]++;
		if(si=="H9") a[35]++;
		if(si=="S9") a[36]++;
		if(si=="DT") a[37]++;
		if(si=="CT") a[38]++;
		if(si=="HT") a[39]++;
		if(si=="ST") a[40]++;
		if(si=="DJ") a[41]++;
		if(si=="HJ") a[42]++;
		if(si=="CJ") a[43]++;
		if(si=="SJ") a[44]++;
		if(si=="DQ") a[45]++;
		if(si=="CQ") a[46]++;
		if(si=="HQ") a[47]++;
		if(si=="SQ") a[48]++;
		if(si=="DK") a[49]++;
		if(si=="CK") a[50]++;
		if(si=="HK") a[51]++;
		if(si=="SK") a[52]++;
	}
	for(int i=1;i<=52;i++){
		if(a[i]==0) cnt++;
	}
	cout<<cnt;
}
