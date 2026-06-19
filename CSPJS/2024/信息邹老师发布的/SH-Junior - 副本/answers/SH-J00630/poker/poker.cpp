#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string a[52];
	int d[52]={},n;
	cin>>n;
	if(n==52){
		cout<<0;
		return 0;
	}
	else if(n==0){
		cout<<52;
		return 0;
	}
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]=="SA") d[0]++;
		else if(a[i]=="S2") d[1]++;
		else if(a[i]=="S3") d[2]++;
		else if(a[i]=="S4") d[3]++;
		else if(a[i]=="S5") d[4]++;
		else if(a[i]=="S6") d[5]++;
		else if(a[i]=="S7") d[6]++;
		else if(a[i]=="S8") d[7]++;
		else if(a[i]=="S9") d[8]++;
		else if(a[i]=="ST") d[9]++;
		else if(a[i]=="SJ") d[10]++;
		else if(a[i]=="SQ") d[11]++;
		else if(a[i]=="SK") d[12]++;
	
		else if(a[i]=="CA") d[13]++;
		else if(a[i]=="C2") d[14]++;
		else if(a[i]=="C3") d[15]++;
		else if(a[i]=="C4") d[16]++;
		else if(a[i]=="C5") d[17]++;
		else if(a[i]=="C6") d[18]++;
		else if(a[i]=="C7") d[19]++;
		else if(a[i]=="C8") d[20]++;
		else if(a[i]=="C9") d[21]++;
		else if(a[i]=="CT") d[22]++;
		else if(a[i]=="CJ") d[23]++;
		else if(a[i]=="CQ") d[24]++;
		else if(a[i]=="CK") d[25]++;
		
		else if(a[i]=="DA") d[26]++;
		else if(a[i]=="D2") d[27]++;
		else if(a[i]=="D3") d[28]++;
		else if(a[i]=="D4") d[29]++;
		else if(a[i]=="D5") d[30]++;
		else if(a[i]=="D6") d[31]++;
		else if(a[i]=="D7") d[32]++;
		else if(a[i]=="D8") d[33]++;
		else if(a[i]=="D9") d[34]++;
		else if(a[i]=="DT") d[35]++;
		else if(a[i]=="DJ") d[36]++;
		else if(a[i]=="DQ") d[37]++;
		else if(a[i]=="DK") d[38]++;
	
		else if(a[i]=="HA") d[39]++;
		else if(a[i]=="H2") d[40]++;
		else if(a[i]=="H3") d[41]++;
		else if(a[i]=="H4") d[42]++;
		else if(a[i]=="H5") d[43]++;
		else if(a[i]=="H6") d[44]++;
		else if(a[i]=="H7") d[45]++;
		else if(a[i]=="H8") d[46]++;
		else if(a[i]=="H9") d[47]++;
		else if(a[i]=="HT") d[48]++;
		else if(a[i]=="HJ") d[49]++;
		else if(a[i]=="HQ") d[50]++;
		else if(a[i]=="HK") d[51]++;
	}
	int ans=52;
	for(int i=0;i<52;i++){
		if(d[i]!=0) ans-=1;
	}
	cout<<ans;
	return 0;
}
