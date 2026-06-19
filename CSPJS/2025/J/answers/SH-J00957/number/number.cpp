#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string str;
	cin >> str;
	int a[10];
	fill(a,a+10,0);
	for(int i=0;i<str.size();i++){
		if(str[i]-'0'<10){
			a[str[i]-'0']++;
		}
	}
	for(int i=0;i<a[9];i++){
		cout<<"9";
	}
	for(int i=0;i<a[8];i++){
		cout<<"8";
	}
	for(int i=0;i<a[7];i++){
		cout<<"7";
	}
	for(int i=0;i<a[6];i++){
		cout<<"6";
	}
	for(int i=0;i<a[5];i++){
		cout<<"5";
	}
	for(int i=0;i<a[4];i++){
		cout<<"4";
	}
	for(int i=0;i<a[3];i++){
		cout<<"3";
	}
	for(int i=0;i<a[2];i++){
		cout<<"2";
	}
	for(int i=0;i<a[1];i++){
		cout<<"1";
	}				
	for(int i=0;i<a[0];i++){
		cout<<"0";
	}					
	fclose(stdin);
	fclose(stdout);
	return 0;
}
