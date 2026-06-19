#include<bits/stdc++.h>
using namespace std;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		int x=s[i]-'0';
		if(x>=0||x<=9){
			a[x]++; 
		}
	}
	bool flag=false;
	for(int i=9;i>0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
			flag=true;
		}
	}
	if (flag){
		while(a[0]!=0){
			cout<<0;
			a[0]--;
		}
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
