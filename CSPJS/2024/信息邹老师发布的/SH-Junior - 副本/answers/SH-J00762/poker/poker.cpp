#include<bits/stdc++.h>
using namespace std;

string s="DACAHASAD2C2H2S2D3C3H3S3D4C4H4S4D5C5H5S5D6C6H6S6D7C7H7S7D8C8H8S8D9C9H9S9DTCTHTSTDJCJHJSJDQCQHQSQDKCKHKSK";

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,cnt=0;
	string c;
	cin>>n;
	for (int i=1;i<=n*2;i+=2){
		cin>>c[i]>>c[i+1];
		for (int j=0;j<s.size();j+=2){
			if (c[i]+c[i+1]==s[j]+s[j+1] && s[j]!=0 && s[j+1]!=0){
				s[j]=0;
				s[j+1]=0;
				break;
			}
		}
	}
	for (int i=0;i<s.size();i+=2){
		if (s[i]!=0 && s[i+1]!=0){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
