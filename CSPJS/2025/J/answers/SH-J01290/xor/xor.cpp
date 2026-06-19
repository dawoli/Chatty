#include<bits/stdc++.h>
using namespace std;
int n,k,a[105000],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	int l=0,r=0,w;
	while(l<n){
		w=a[l];
		while(r<n){
			r++;
			if(w==k){
				ans++;
				cout<<l<<' '<<r<<endl;
				l=r-1;
				break;
			}
			else w=w^a[r];
		}
		l++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
