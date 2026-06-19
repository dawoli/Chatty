#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,a[54]={};
	cin>>n;
	for(int i=0;i<n;i+=1){
		string s;
		cin>>s;
		int num;
		if(s[0]=='D'){
			num=0;
		}
		if(s[0]=='C'){
			num=13;
		}
		if(s[0]=='H'){
			num=26;
		}
		if(s[0]=='S'){
			num=39;
		}
		
		if(s[1]=='A'){
			num+=1;
		}
		if(s[1]=='2'){
			num+=2;
		}
		if(s[1]=='3'){
			num+=3;
		}
		if(s[1]=='4'){
			num+=4;
		}
		if(s[1]=='5'){
			num+=5;
		}
		if(s[1]=='6'){
			num+=6;
		}
		if(s[1]=='7'){
			num+=7;
		}
		if(s[1]=='8'){
			num+=8;
		}
		if(s[1]=='9'){
			num+=9;
		}
		if(s[1]=='T'){
			num+=10;
		}
		if(s[1]=='J'){
			num+=11;
		}
		if(s[1]=='Q'){
			num+=12;
		}
		if(s[1]=='K'){
			num+=13;
		}
		a[num]=1;
	}
	n=52;
	for(int i=1;i<53;i+=1){
		n-=a[i];
	}
	cout<<n<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

