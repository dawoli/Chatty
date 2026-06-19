/*melcome me
  2       pos
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1="",s2="";
	int cnt=0;
	getline(cin,s1);
	getline(cin,s2);
	for(int i=0;i<s1.length();i++){
		//[i,i+s2.size()-1]==s2 [0,1]
		int flag=1,j,k=0;
		for(j=i,k=0;j<=i+s2.size()-1;j++,k++){
			if(s1[j]!=s2[k]){
				flag=0;
				break;
			}
		}
		if(flag==1) cnt++;
		
	}
	cout<<cnt<<endl;
	return 0;
}
