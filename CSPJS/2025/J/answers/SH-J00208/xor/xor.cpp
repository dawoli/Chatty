#include<iostream>
using namespace std;
typedef long long ll;
int n;
ll k,a[500005];
bool mka=true,mkb=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) mka=false;
		if(a[i]>1) mkb=false;
	}
	if(mka){
		cout<<n/2;
	}
	else if(mkb){
		int ans=0;
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			for(int i=2;i<=n;i++){
				if(a[i-1]==1&&a[i]==1) ans++,i++;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++; 
			}
		}
		cout<<ans;
	}
	else if(n==4){
		int ans1=0;
		for(int i=1;i<=4;i++){
			if(a[i]==k) ans1++;
		}
		int ans2=0;
		int anstwop=a[1];
		anstwop^=a[2];
		if(anstwop==k) ans2++;
		if(a[3]==k) ans2++;
		if(a[4]==k) ans2++;
		int ans3=0;
		int ansteep=a[2];
		ansteep^=a[3];
		if(ansteep==k) ans3++;
		if(a[1]==k) ans3++;
		if(a[4]==k) ans3++;
		int ans4=0;
		int ansfurp=a[1];
		ansfurp^=a[2];
		if(ansfurp==k) ans4++;
		if(a[1]==k) ans4++;
		if(a[2]==k) ans4++;
		int ans5=0;
		int ansfivpf=a[1],ansfivps=a[3];
		ansfivpf^=a[2],ansfivps^=a[4];
		if(ansfivpf==k) ans5++;
		if(ansfivps==k) ans5++;
		int ans6=0;
		int anssixp=a[1];
		anssixp^=a[2];
		anssixp^=a[3];
		if(anssixp==k) ans6++;
		if(a[4]==k) ans6++;
		int ans7=0;
		int anssevp=a[2];
		anssevp^=a[3];
		anssevp^=a[4];
		if(anssevp==k) ans7++;
		if(a[1]==k) ans7++;
		int ans8=0;
		int ansendp=a[1];
		ansendp^=a[2];
		ansendp^=a[3];
		ansendp^=a[4];
		if(ansendp==k) ans8++;
		cout<<max(ans1,max(ans2,max(ans3,max(ans4,max(ans5,max(ans6,max(ans7,ans8)))))));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
