#include <bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,count=0,h=0;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int b=3;
	while(b<=n){
		h=0;
		int max=0;
		for(int i=0;i<n;++i){
		    for(int j=0;j<=b;++j){
			    h+=a[j];
			    if(max<=a[j])
			       max=a[j];
		    }
            if(h>max*2)
               count++;
        }
        b++;
	}
	cout<<count<<endl;
	return 0;
}
