#include <bits/stdc++.h>
//freopen("sticks.in","r","stdin");
//freopen("sticks.out","w","stdout");
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[100001]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<2){
			cout<<-1;
			continue;
		}
		int aa1=0;
		int c=1;
		int cc=1;
		int cnt=0;
		int panduan=0;
		while(panduan!=1){
			int aa=cc;
		    while(aa!=0){
			    aa1=aa%10;
			    aa/=10;
			    if(aa1==0||aa1==6||aa1==9){
			    	cnt+=6;
				}else if(aa1==1){
					cnt+=2;
				}else if(aa1==2||aa1==3||aa1==5){
					cnt+=5;
				}else if(aa1==7){
					cnt+=3;
				}else if(aa1==8){
					cnt+=7;
				}else{
					cnt+=4;
				}
		    }
		    if(cnt=a[i]){
		    	cout<<cc;
		    	panduan=1;
			}else{
				cc++;
			}
	    }
	}
	return 0;
}
