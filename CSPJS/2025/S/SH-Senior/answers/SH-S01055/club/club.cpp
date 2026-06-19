#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001][3],ans[100001],fn,bad[100001],x,y,z,i;

int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int cnt1 = 0,cnt2=0,cnt3=0,k=n/2;
		for(i = 0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if (a[i][0]>=a[i][1] and a[i][0]>=a[i][2]){ans[i]=0;cnt1++;}
			else if (a[i][0]<a[i][1] and a[i][1]>=a[i][2]){ans[i]=1;cnt2++;}
			else{ans[i]=2;cnt3++;}	
			fn += a[i][ans[i]];
		}
		if( cnt1 <= k and cnt2 <= k and cnt3 <= k){cout<<fn;fn=0;}
		else{int d,m;
			if(cnt1>k){d=0;m=cnt1-k;}else if(cnt2>k){d=1;m=cnt2-k;}else{d=2;m=cnt3- k;}
			int d1 = (d+1)%3, d2 = (d+2)%3;
			for(i = 0;i<n;i++){
				if (ans[i]==d){
				x = a[i][d];
				y = a[i][d1];z=a[i][d2];
				bad[i]=min(x-y,x-z);}
				else bad[i]=20001;
			}
			sort(bad,bad+n);
			for (i =0;i<m;i++){
				fn -= bad[i];
			}
			cout<<fn;fn=0;
		}
		if (t>=1)cout<<endl;
	}
	fclose(stdin);fclose(stdout);
}
