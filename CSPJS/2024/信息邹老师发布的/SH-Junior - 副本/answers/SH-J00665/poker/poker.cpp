#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	string a[60],b[60];
	int n;
	a[0]="-1";
	a[1]="DA";
	a[2]="CA";
	a[3]="HA";
	a[4]="SA";
	a[5]="D2";
	a[6]="C2";
	a[7]="H2";
	a[8]="S2";
	a[9]="D3";
	a[10]="C3";
	a[11]="H3";
	a[12]="S3";
	a[13]="D4";
	a[14]="C4";
	a[15]="H4";
	a[16]="S4";
	a[17]="D5";
	a[18]="C5";
	a[19]="H5";
	a[20]="S5";
	a[21]="D6";
	a[22]="C6";
	a[23]="H6";
	a[24]="S6";
	a[25]="D7";
	a[26]="C7";
	a[27]="H7";
	a[28]="S7";
	a[29]="D8";
	a[30]="C8";
	a[31]="H8";
	a[32]="S8";
	a[33]="D9";
	a[34]="C9";
	a[35]="H9";
	a[36]="S9";
	a[37]="DT";
	a[38]="CT";
	a[39]="HT";
	a[40]="ST";
	a[41]="DJ";
	a[42]="CJ";
	a[43]="HJ";
	a[44]="SJ";
	a[45]="DQ";
	a[46]="CQ";
	a[47]="HQ";
	a[48]="SQ";
	a[49]="DK";
	a[50]="CK";
	a[51]="HK";
	a[52]="SK";
	cin>>n;
	long long cnt[101]={0};
	for(int i=0;i<n;++i){
		cin>>b[i];
		for(int j=1;j<=52;++j){
			if(b[i]==a[j] && cnt[j]==0){
				cnt[j]=1;
			}
		}
	}
	long long ans=52;
	for(int i=1;i<=100;++i){
		if(cnt[i]==1){
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
 
