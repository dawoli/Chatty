#include<bits/stdc++.h>
using namespace std;
char LL[1000005];
int getnum(string a){
	int idx=0;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9')LL[idx++]=a[i];
	}
	return idx;
}
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int Len=getnum(s);
	sort(LL+0,LL+Len,cmp);
	for(int i=0;i<Len;i++){
		//cout<<(int)(LL[i]);
		cout<<LL[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
