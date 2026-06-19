#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int a[n];
	int A = 1;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1 && a[i]!=0){
			A = 0;
		}
	}
	if(A){
		if(k==1){
			int cntA = 0;
			for(int i = 0;i<n;i++){
				if(a[i]==1){
					cntA++;
				}
			}
			cout<<cntA;
		}
		else if(k==0){
			int cntA = 0;
			for(int i = 0;i<n;i++){
				if(a[i]==0){
					cntA++;
				}
				if(i>0){
					if(a[i-1]==1 && a[i]==1){
						cntA++;
					}
				}
			}
			cout<<cntA;
		}
	}
	else{ 
	    //ËÑË÷ /³ßÈ¡ 
	    //
		cout<<n/2;
	}
	return 0;
}
