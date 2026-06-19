#include<bits/stdc++.h>
using namespace std;
				
int n,i=0,j;
int a[100020];

int main(){
	
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	
	 
	cin>>n;
	for(;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int tuichu=0;
	i=1;
	for(;i<n;i++){
		if(a[i]>a[tuichu]){
			tuichu++;
		}
	}
	cout<<n-tuichu;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
