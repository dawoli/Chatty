/*
  aabb
         4/2=2;
  01 23
  abcdab
  012     6/2=3
     345
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<s1.size()/2;i++)
		cout<<s1[i];
	cout<<s2;
	for(int i=s1.size()/2;i<s1.size();i++)
		cout<<s1[i];
	return 0;
}
