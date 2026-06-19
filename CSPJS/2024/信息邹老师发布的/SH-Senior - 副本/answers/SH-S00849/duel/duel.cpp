#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int b[a[n-1]+1];
	for(int i=0;i<=a[n-1]+1;i++){
		b[i]=0;
	} 
	for(int i=0;i<n;i++){
		b[a[i]]+=1;
	}
	int j=0,s=0,ji=0,tmp=0x3f3f3f;
	while(j<n&&ji<a[n-1]+1){
		ji+=1;
		if(b[ji]==0){
			continue;
		}
		else{
			j+=1;
			if(j==1){
				continue;
			}
			s+=min(tmp,b[ji]);
			tmp=b[ji];
		}
	}
	cout<<n-s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}




