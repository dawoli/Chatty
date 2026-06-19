#include <iostream>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,fl=1,cnt=0,ccnt;
	cin>>n>>k;
	int l[n+5];
	for(int i=0;i<n;i++){
		cin>>l[i];
		if(l[i]!=1 && l[i]) fl=0;
		if(fl && l[i]==1) cnt++;
		if(l[i]==k)ccnt++;
	}
	if(fl && k==0) cout<<cnt/2;
	else if(fl && k==1) cout<<cnt;
	else{
		cout<<ccnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
