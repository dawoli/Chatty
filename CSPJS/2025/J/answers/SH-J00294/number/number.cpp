#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[100000]={};
	cin>>a;
	int len=strlen(a),c[100000]={},r=0,d[100000]={},x=0,h=0;
	for(int i=0;i<len;i++){
		if('0'<=char(a[i])&&char(a[i])<='9'){c[r]=(a[i]-'0');r++;}
	}
	for(int j=0;j<=r;j++){
	for(int i=0;i<r;i++){
		if(c[i]>d[x]){
			d[x]=c[i];
			h=i;
		}
	}
	x++;
	c[h]={};
}
	for(int i=0;i<x-1;i++){
		cout<<d[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
