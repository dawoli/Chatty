#include<iostream>
#include<cmath>
using namespace std;
int a[5145],n,x,ct,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	if(!a[i])
	x=0;
	else
	ct++;
    }
    if(x==1)
    cout<<n/2;
    else if(k==1) 
    cout<<ct;
    else
    cout<<ct/2;
} 
