#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	string s,a[100005];
	int sum=0;
	int number[100005];
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin>>s;

	memset(number,0,sizeof(number));
	for(int i=0;i<s.size();i++){
		if(s[i]-int('0')>=0 && s[i]-int('0')<=9){ 
			number[sum]=s[i]-'0';
			sum++;
		}
	} 
	sort(number,number+sum,cmp);
	for(int i=0;i<sum;i++){
			cout<<number[i];
	}
	return 0;

} 
