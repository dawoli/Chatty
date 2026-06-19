#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int num[500006];
struct sq{
	int _l,_r;
}xx[500006];
bool cmp(sq a_,sq b_){
	return a_._l<b_._l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=num[i];
		for(int j=i;j<=n;j++){
			if(cnt==k){
				ans++;
				xx[ans]._l=i;
				xx[ans]._r=j;
				break;
			}
			cnt=cnt^num[j+1];
		}
	}
	if(ans==1&&ans==0)
	{
		cout<<ans;
		return 0;
	}
	sort(xx+1,xx+ans+1,cmp);
	int ll,rr=xx[1]._r;
	int w=ans;
	for(int i=1;i<ans;i++){
		ll=xx[i+1]._l;
		if(rr>=ll){
			w--;
			rr=min(rr,xx[i+1]._r);
		}
		else{
			rr=xx[i+1]._r;
		}
	} 
	cout<<w;
	fclose(stdin);fclose(stdout);
	return 0;
}
