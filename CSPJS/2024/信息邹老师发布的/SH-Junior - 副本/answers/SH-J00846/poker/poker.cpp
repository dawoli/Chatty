#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,b[53]={0},c=52;
	string a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a=="DA")b[1]++;
		if(a=="D2")b[2]++;
		if(a=="D3")b[3]++;
		if(a=="D4")b[4]++;
		if(a=="D5")b[5]++;
		if(a=="D6")b[6]++;
		if(a=="D7")b[7]++;
		if(a=="D8")b[8]++;
		if(a=="D9")b[9]++;
		if(a=="DT")b[10]++;
		if(a=="DJ")b[11]++;
		if(a=="DQ")b[12]++;
		if(a=="DK")b[13]++;
		if(a=="CA")b[14]++;
		if(a=="C2")b[15]++;
		if(a=="C3")b[16]++;
		if(a=="C4")b[17]++;
		if(a=="C5")b[18]++;
		if(a=="C6")b[19]++;
		if(a=="C7")b[20]++;
		if(a=="C8")b[21]++;
		if(a=="C9")b[22]++;
		if(a=="CT")b[23]++;
		if(a=="CJ")b[24]++;
		if(a=="CQ")b[25]++;
		if(a=="CK")b[26]++;
		if(a=="HA")b[27]++;
		if(a=="H2")b[28]++;
		if(a=="H3")b[29]++;
		if(a=="H4")b[30]++;
		if(a=="H5")b[31]++;
		if(a=="H6")b[32]++;
		if(a=="H7")b[33]++;
		if(a=="H8")b[34]++;
		if(a=="H9")b[35]++;
		if(a=="HT")b[36]++;
		if(a=="HJ")b[37]++;
		if(a=="HQ")b[38]++;
		if(a=="HK")b[39]++;
		if(a=="SA")b[40]++;
		if(a=="S2")b[41]++;
		if(a=="S3")b[42]++;
		if(a=="S4")b[43]++;
		if(a=="S5")b[44]++;
		if(a=="S6")b[45]++;
		if(a=="S7")b[46]++;
		if(a=="S8")b[47]++;
		if(a=="S9")b[48]++;
		if(a=="ST")b[49]++;
		if(a=="SJ")b[50]++;
		if(a=="SQ")b[51]++;
		if(a=="SK")b[52]++;
		else{
			b[0]++;
		}
	}
	for(int i=1;i<=52;i++){
		if(b[i]!=0)c--;}
	cout<<c;
	return 0;
}
