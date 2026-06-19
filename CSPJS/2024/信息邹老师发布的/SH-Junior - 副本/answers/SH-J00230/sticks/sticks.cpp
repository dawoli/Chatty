#include<bits/stdc++.h>
using namespace std;
int A[10]={6,2,5,-1,4,-1,6,3,7,-1};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("stick.out","r",stdout);
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int as,aj[1000]={-1};
		cin>>as;
		int w=(as+6)/7;
		if(as==1&&as==0){
			cout<<-1;
			continue;
		}
		else {for(int k=1;k<=w;k++){
			if(i==1)
			for(int j=1;j<10;j++){
				if(A[j]==as%7){
					aj[i]=j;
					as/=7;
					break;
				}
			}
			else{
				for(int j=0;j<10;j++){
				if(A[j]==as%7){
					aj[i]=j;
					as/=7;
					break;
				}
			}
			}
			
		}
		if(aj[i]==-1) {
			cout<<"-1";
			continue;
		}
		else for(i=w;i>0;i--){
			if(aj[i]==0&&i==w) cout<<6;
			
			else cout<<aj[i];
		}
		}
		cout<<endl;
	}
	return 0;
}
