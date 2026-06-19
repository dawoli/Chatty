/*
  大小写转换,例如所有小写字母转换成大写字母
  x >=10  <=20
  10<=x<=20     x=21    x>=10&&x<=20
  10<=21  1
  1<=20
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[1001]={};
	cin.getline(s,1001);
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='a'&&s[i]<='z')
			s[i]-=32;
	}
	cout<<s<<endl;
	return 0;
}
