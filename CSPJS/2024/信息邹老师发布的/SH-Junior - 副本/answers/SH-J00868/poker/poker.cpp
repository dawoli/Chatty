#include<bits/stdc++.h>
using namespace std;

const int N=57;

string ss[N];

int d[N],c[N],h[N],s[N];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>ss[i];
		if(ss[i][0]=='D'){
			if(ss[i]=="DA")d[1]++;
			if(ss[i]=="D2")d[2]++;
			if(ss[i]=="D3")d[3]++;
			if(ss[i]=="D4")d[4]++;
			if(ss[i]=="D5")d[5]++;
			if(ss[i]=="D6")d[6]++;
			if(ss[i]=="D7")d[7]++;
			if(ss[i]=="D8")d[8]++;
			if(ss[i]=="D9")d[9]++;
			if(ss[i]=="DT")d[10]++;
			if(ss[i]=="DJ")d[11]++;
			if(ss[i]=="DQ")d[12]++;
			if(ss[i]=="DK")d[13]++;
		}
		if(ss[i][0]=='C'){
			if(ss[i]=="CA")c[1]++;
			if(ss[i]=="C2")c[2]++;
			if(ss[i]=="C3")c[3]++;
			if(ss[i]=="C4")c[4]++;
			if(ss[i]=="C5")c[5]++;
			if(ss[i]=="C6")c[6]++;
			if(ss[i]=="C7")c[7]++;
			if(ss[i]=="C8")c[8]++;
			if(ss[i]=="C9")c[9]++;
			if(ss[i]=="CT")c[10]++;
			if(ss[i]=="CJ")c[11]++;
			if(ss[i]=="CQ")c[12]++;
			if(ss[i]=="CK")c[13]++;
		}
		if(ss[i][0]=='H'){
			if(ss[i]=="HA")h[1]++;
			if(ss[i]=="H2")h[2]++;
			if(ss[i]=="H3")h[3]++;
			if(ss[i]=="H4")h[4]++;
			if(ss[i]=="H5")h[5]++;
			if(ss[i]=="H6")h[6]++;
			if(ss[i]=="H7")h[7]++;
			if(ss[i]=="H8")h[8]++;
			if(ss[i]=="H9")h[9]++;
			if(ss[i]=="HT")h[10]++;
			if(ss[i]=="HJ")h[11]++;
			if(ss[i]=="HQ")h[12]++;
			if(ss[i]=="HK")h[13]++;
		}
		if(ss[i][0]=='S'){
			if(ss[i]=="SA")s[1]++;
			if(ss[i]=="S2")s[2]++;
			if(ss[i]=="S3")s[3]++;
			if(ss[i]=="S4")s[4]++;
			if(ss[i]=="S5")s[5]++;
			if(ss[i]=="S6")s[6]++;
			if(ss[i]=="S7")s[7]++;
			if(ss[i]=="S8")s[8]++;
			if(ss[i]=="S9")s[9]++;
			if(ss[i]=="ST")s[10]++;
			if(ss[i]=="SJ")s[11]++;
			if(ss[i]=="SQ")s[12]++;
			if(ss[i]=="SK")s[13]++;
		}
	}
	int ans=52;
	for(int i=1;i<=13;i++){
		if(d[i])ans--;
		if(c[i])ans--;
		if(s[i])ans--;
		if(h[i])ans--;
	}
	cout<<ans<<'\n';
	return 0;
} 
