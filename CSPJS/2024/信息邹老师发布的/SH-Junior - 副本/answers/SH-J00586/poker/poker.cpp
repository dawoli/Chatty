#include<bits/stdc++.h>
using namespace std;

bool d[60],c[60],h[60],s[60]; 
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	char ds1,x;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>ds1;
		if(x=='D'){
			if(ds1=='A')d[1]=true;
			if(ds1=='2')d[2]=true;
			if(ds1=='3')d[3]=true;
			if(ds1=='4')d[4]=true;
			if(ds1=='5')d[5]=true;
			if(ds1=='6')d[6]=true;
			if(ds1=='7')d[7]=true;
			if(ds1=='8')d[8]=true;
			if(ds1=='9')d[9]=true;
			if(ds1=='T')d[10]=true;
			if(ds1=='J')d[11]=true;
			if(ds1=='Q')d[12]=true;
			if(ds1=='K')d[13]=true;
		}
		if(x=='C'){
			if(ds1=='A')c[1]=true;
			if(ds1=='2')c[2]=true;
			if(ds1=='3')c[3]=true;
			if(ds1=='4')c[4]=true;
			if(ds1=='5')c[5]=true;
			if(ds1=='6')c[6]=true;
			if(ds1=='7')c[7]=true;
			if(ds1=='8')c[8]=true;
			if(ds1=='9')c[9]=true;
			if(ds1=='T')c[10]=true;
			if(ds1=='J')c[11]=true;
			if(ds1=='Q')c[12]=true;
			if(ds1=='K')c[13]=true;
		}
		if(x=='H'){
			if(ds1=='A')h[1]=true;
			if(ds1=='2')h[2]=true;
			if(ds1=='3')h[3]=true;
			if(ds1=='4')h[4]=true;
			if(ds1=='5')h[5]=true;
			if(ds1=='6')h[6]=true;
			if(ds1=='7')h[7]=true;
			if(ds1=='8')h[8]=true;
			if(ds1=='9')h[9]=true;
			if(ds1=='T')h[10]=true;
			if(ds1=='J')h[11]=true;
			if(ds1=='Q')h[12]=true;
			if(ds1=='K')h[13]=true;
		}
		if(x=='S'){
			if(ds1=='A')s[1]=true;
			if(ds1=='2')s[2]=true;
			if(ds1=='3')s[3]=true;
			if(ds1=='4')s[4]=true;
			if(ds1=='5')s[5]=true;
			if(ds1=='6')s[6]=true;
			if(ds1=='7')s[7]=true;
			if(ds1=='8')s[8]=true;
			if(ds1=='9')s[9]=true;
			if(ds1=='T')s[10]=true;
			if(ds1=='J')s[11]=true;
			if(ds1=='Q')s[12]=true;
			if(ds1=='K')s[13]=true;
		}
	}
	int cnt=0;
	for(int i=1;i<=13;i++){
		if(d[i]==false)cnt++;
	}
	for(int i=1;i<=13;i++){
		if(c[i]==false)cnt++;
	}
	for(int i=1;i<=13;i++){
		if(h[i]==false)cnt++;
	}
	for(int i=1;i<=13;i++){
		if(s[i]==false)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
