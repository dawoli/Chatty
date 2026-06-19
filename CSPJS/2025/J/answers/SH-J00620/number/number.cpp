#include<bits/stdc++.h>
using namespace std;
string s;
char n[1000005];
int a[1000005];
int cnt;
int is_num(char x){
	if((x>='A'&&x<='Z')||(x>='a'&&x<='z'))return 0;
	else return 1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		n[i]=s[i];
		if(is_num(n[i])){
			cnt++;
			a[cnt]=n[i]-'0';
		}
		else continue;
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--)cout<<a[i];
	return 0;
} 
