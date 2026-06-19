#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen(stdin,"r","number.in");
	freopen(stdout,"w","number.out");
	char a[100009],s[100009];
	int n,j=0,w,q=0;
	for(int i=0;i<1000000;i++){
		getline(cin,s[i]);
		if(s[i]=='/0'){
			 n=i;
			 break;
		}
	}
	for(int i=0;i<n;i){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[j]=s[i];
			j++;
			if(i<n) w=j;
		}
		for(int i=0;i<w;i++){
			if(a[i]>q) q=a[i];
		}
		for(;q<0;q--){
			for(int i=0;i<w;i++){
			if(a[i]==q) cout<<q;
			}
		}
	} 
	return 0;
}
