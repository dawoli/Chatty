#include<bits/stdc++.h>
using namespace std;
const int MAX_A=1e2+5;
int N,M;
int A[MAX_A];
int XY=0,AnsH,AnsL;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>N>>M;
	cin>>A[1];
	for(int i = 2;i<=N*M;i++){
		cin>>A[i];
		if(A[i]>A[1]){
			XY++;
		}
	}
	XY++;
	if(XY%N==0){
		AnsL=XY/N;
		if(AnsL%2==0){
			AnsH=1;
		}
		else{
			AnsH=N;
		}
	}
	else{
		AnsL=XY/N;
		AnsL++;
		XY%=N;
		if(AnsL%2==0){
			AnsH=N-XY+1;
		}
		else{
			AnsH=XY;
		}
	}
	cout<<AnsL<<" "<<AnsH;
	return 0;
}
//2 2
//  1 2
//1 
//2
