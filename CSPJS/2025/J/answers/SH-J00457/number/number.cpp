#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000055];
int sum=0;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=1;
	for(char i:s){
		if(i=='0'||i=='1'||i=='2'||i=='3'||i=='4'||i=='5'||i=='6'||i=='7'||i=='8'||i=='9'){
			//cout<<i;
			a[cnt]=i;
			cnt++;
			sum++;
		}
	}
	sort(a+1,a+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	} 
	return 0;
	fclose(stdin);
	fclose(stdout);
}
