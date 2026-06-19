/*melcome me
    2       pos
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1="",s2="";
	getline(cin,s1);
	getline(cin,s2);
	int pos=0,cnt=0;
	while(1){
		pos=s1.find(s2,pos);//从起始位置为0开始找s2
		if(pos==-1) break; //string::npos==-1
		cnt++;
		pos+=s2.length();
	}
	cout<<cnt<<endl;
	return 0;
}
