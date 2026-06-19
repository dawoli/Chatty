#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n==0||n==1) printf("%s\n","-1");
		else if(n==2) printf("%s\n","1");
		else if(n==3) printf("%s\n","7");
		else if(n==4) printf("%s\n","4");
		else if(n==5) printf("%s\n","2");
		else if(n==6) printf("%s\n","6");
		else{
			int k=n/7,r=n%7,cnt8=0;
			string fir="";
			if(r==0) cnt8=k;
			if(r==1) cnt8=k-1,fir="10";
			if(r==2) cnt8=k,fir="1";
			if(r==3) cnt8=k-1,fir="22";
			if(r==4) cnt8=k-1,fir="20";
			if(r==5) cnt8=k,fir="2";
			if(r==6) cnt8=k,fir="6";
			for(int i=1;i<=cnt8;i++) fir+="8";
			for(int i=0;i<fir.size();i++) printf("%c",fir[i]);
			printf("\n");
		}
	}
	return 0;
}
