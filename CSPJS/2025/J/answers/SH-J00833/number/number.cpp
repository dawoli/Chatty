#include<bits/stdc++.h>
using namespace std;/*
bool cmp(int x,int y){
	return x>y;
}*/
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[15]={};
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]=='0')a[1]++;
		if(s[i]=='1')a[2]++;
		if(s[i]=='2')a[3]++;
		if(s[i]=='3')a[4]++;
		if(s[i]=='4')a[5]++;
		if(s[i]=='5')a[6]++;
		if(s[i]=='6')a[7]++;
		if(s[i]=='7')a[8]++;
		if(s[i]=='8')a[9]++;
		if(s[i]=='9')a[10]++;
	}//sort(a+1,a+k+1,cmp);
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
