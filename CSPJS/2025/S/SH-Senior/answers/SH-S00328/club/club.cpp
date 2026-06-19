#include<bits/stdc++.h>

using namespace std;
int t=0,n=0,cnt=0;
void scan(int a){
	for(int i=0;i<n;i++){
		scanf("%d",&a[i][1]);
		scanf("%d",&a[i][2]);
		scanf("%d",&a[i][3]); 
	}
}
int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		cin>>n;
		int const f=n;
		int a[f+5][3],b[f+5];
		scan(a);
		for(int i=0;i<n;i++){
			b[i]=max(a[i][1],a[i][2],a[i][3]);
		};
		}

	}
	return 0;
} 

