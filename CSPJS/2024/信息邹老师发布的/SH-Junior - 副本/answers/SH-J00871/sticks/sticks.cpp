#include<iostream>
#include <cstdio>
#include<fstream>
using namespace std;
int T,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
		cout<<-1<<endl;continue;
		}
		int a,b;
		string s="";
		a=n/7;b=n%7;
		for(int i=0;i<a;i++){
			s+="8";
		}
		if(b==1){//(a>=1)"8"+1->"10"
			s[0]='0';
			s="1"+s;
		}
		if (b==2){//2->"1"
			s="1"+s;
		}
		if(b==3){//借2得"2"
		    if(a>=2){s[0]='0';s[1]='0';s="2"+s;}
		    //借 2得"2" ,"8"借2得"2" 
			else if(a>=1){s[0]='2';s="2"+s;}
			else s="7";//3->7
	    }
	    if(b==4){//借1得2 
	        if(a>=1){s[0]='0';s="2"+s;}
	        else s="4";
	    }
	    if(b==5)s="2"+s;
	    if (b==6)s="6"+s;
		cout<<s<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
//保证位数尽可能少
//位数相同保证前导数小 
