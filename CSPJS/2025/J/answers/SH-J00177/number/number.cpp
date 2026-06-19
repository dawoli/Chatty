#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int count=0;
	string s;
	cin>>s;
	int x=s.length();
	for(int i=0;i<x;i++){
		if(s[i]>='0' && s[i]<='9'){
			count++;
			a[count]=s[i];
		}
		
	}
	if(x==1){
		cout<<s[0];
		return 0;
	}
	for(int i=1;i<=count;i++){
		a[i]=a[i]-48;
	}
	sort(a+1,a+count+1,cmp);
	for(int i=1;i<=count;i++){
		cout<<a[i];
	}
	return 0;
}
