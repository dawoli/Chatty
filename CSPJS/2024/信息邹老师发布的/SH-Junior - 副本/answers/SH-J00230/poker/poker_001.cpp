#include<bits/stdc++.h>
using namespace std;
struct att {
	char a[3];
	int b;
	
}A[59];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int N,ans=0;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i].a;
		int fla=1;
		for(int j=0;j<i;j++){
			if(A[i].a[0]==A[j].a[0]&&A[i].a[1]==A[j].a[1]){
				fla=0;
				break;
				
			}
			
		}
		if(fla){
			ans++;
	    }
	}
	cout<<52-ans;
	return 0;
}
