#include<bits/stdc++.h>
using namespace std;
string A;
int B[1000010],LB=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>A;
	for(int i = 0;i<A.length();i++){
		if(!((A[i]>='A'&&A[i]<='Z')||(A[i]>='a'&&A[i]<='z'))){
			B[++LB]=A[i]-'0';
		}
	}
	sort(1+B,1+B+LB);
	for(int i = LB;i>=1;i--){
		cout<<B[i];
	}
	return 0;
}
