#include<bits/stdc++.h>
using namespace std;
int number[1000000],id=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(!isalpha(s[i])){
			number[id]=s[i]-'0';
			id++;
		}
	}
	sort(number,number+id,cmp);
	for(int i=0;i<id;i++) cout<<number[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
