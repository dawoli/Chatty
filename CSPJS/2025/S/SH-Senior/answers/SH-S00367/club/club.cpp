#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,a,b,c,A[maxn],B[maxn],C[maxn],group1,group2,group3,ans1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>=max(b,c)){
				ans1+=a;
				group1++;
				A[group1]=a-max(b,c);
			}
			else if(b>=c){
				ans1+=b;
				group2++;
				B[group2]=b-max(a,c);
			}
			else{
				ans1+=c;
				group3++;
				C[group3]=c-max(a,b);
			}
		}
		if(group1>n/2){
			sort(A+1,A+group1+1);
			int j=1;
			while(group1>n/2){
				group1--;
				ans1-=A[j];
				j++;
			}
		}
		else if(group2>n/2){
			sort(B+1,B+group2+1);
			int j=1;
			while(group2>n/2){
				group2--;
				ans1-=B[j];
				j++;
			}
		}
		else if(group3>n/2){
			sort(C+1,C+group3+1);
			int j=1;
			while(group3>n/2){
				group3--;
				ans1-=C[j];
				j++;
			}
		}
		cout<<ans1<<endl;
		ans1=0,group1=0,group2=0,group3=0;
	}
	return 0;
}
