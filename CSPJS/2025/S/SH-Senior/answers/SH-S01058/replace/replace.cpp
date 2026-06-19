#include <bits/stdc++.h>
using namespace std;
struct eyzfc{
	string s1;
	string s2;
	char s3[1086];
	char s4[1086];
	int si;
	int lj;
}a[200086];
int answ[200086];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i].s1>>a[i].s2;
		int l=-1,r=-1;
		for(int j=0;j<a[i].s1.size();j++){
			if(a[i].s1[j]!=a[i].s2[j]){
				if(l==-1){
					l=j;
					a[i].lj=l;
				}
				r=j;
			}
		}
		a[i].si=0;
		for(int j=l;j<=r;j++){
			a[i].s3[j-l]=a[i].s1[j];
			a[i].s4[j-l]=a[i].s2[j];
			a[i].si++;
		}
	}
	
	for(int bcy=0;bcy<q;bcy++){
		string A,B;
		cin>>A>>B;
		if(A.size()!=B.size()){
			answ[bcy]=0;
			continue;
		}
		int siz=A.size();
		int l=-1,r=-1;
		for(int i=0;i<siz;i++){
			if(A[i]!=B[i]){
				if(l==-1){
					l=i;
				}
				r=i;
			}
		}
		char C[10086],D[10086];
		int si2=0;
		for(int j=l;j<=r;j++){
			C[j-l]=A[j];
			D[j-l]=B[j];
			si2++;
		}
		for(int i=0;i<n;i++){
			bool ifs2=true;
			if(si2!=a[i].si){
				ifs2=false;
			}
			for(int j=0;j<si2;j++){
				if(C[j]!=a[i].s3[j]){
					ifs2=false;
					break;
				}
				if(D[j]!=a[i].s4[j]){
					ifs2=false;
					break;
				}
			}
			if(ifs2){
				bool ifs=true;
				int cnt2=0;
				for(int j=l-a[i].lj;j<l-a[i].lj+a[i].s1.size();j++){
					if(A[j]!=a[i].s1[cnt2]){
						ifs=false;
						break;
					}
					if(B[j]!=a[i].s2[cnt2]){
						ifs=false;
						break;
					}
					cnt2++;
				}
				if(ifs){
					answ[bcy]++;
				}
			}
		}
	}
	for(int bcy=0;bcy<q;bcy++){
		cout<<answ[bcy]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
