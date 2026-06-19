#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number3.in","r",stdin);
freopen("number3.out","w",stdout);
string s;
cin>>s;
int a[s.size()];
for(int i=0;i<s.size();i++){
	if(s[i]=='1'){
		  a[i]=1;
	}else 	if(s[i]=='2'){
		  a[i]=2;
	}else 	if(s[i]=='3'){
		  a[i]=3;
	}else 	if(s[i]=='4'){
		  a[i]=4;
	}else 	if(s[i]=='5'){
		  a[i]=5;
	}else 	if(s[i]=='6'){
		  a[i]=6;
	}else 	if(s[i]=='7'){
		  a[i]=7;
	}else 	if(s[i]=='8'){
		  a[i]=8;
	}else 	if(s[i]=='9'){
		  a[i]=9;
	}
   	
}	
for(int l=0;l<s.size();l++){
for(int i=0;i<s.size();i++){
	if(a[i]>9){
		a[i]==0;
		}
	if(i>0){
	if(a[i]<a[i+1]){																						
    	int j=a[i];
		a[i]=a[i+1];
		a[i+1]=j; 
	} 
	    if(a[i]>a[i-1]){
    	int j=a[i];
		a[i]=a[i-1];
		a[i-1]=j; 
	}	
	}
     
}

}
for(int i=0;i<s.size();i++){
	if(a[i]==0){
		continue;
	}
	cout<<a[i];
}
return 0;
}
