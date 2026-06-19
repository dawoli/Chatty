#include<bits/stdc++.h>
using namespace std;
struct node{
	int r;
	bool judge=1;
	int delta;
	bool survive=1;
};

bool cmp(node x,node y){
	return x.r<y.r;
}

int n;
node a[100005];

int main(){
	freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].r;
	}
	sort(a,a+n,cmp);
	for(int i=1;i<n;i++){
		a[i].delta=a[i].r-a[i-1].r;
	}
	
	int target=0;
	
	for(int i=1;i<n;i++){
		if(a[i].r-a[target].r>0 && a[i].judge==1){
			for(int j=target;j<=i-1;j++){
				if(a[j].survive==1){
					a[j].survive=0;
					target=j+1;
					a[i].judge=0;
					break;
				}
			}
		}
	}
	
	
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i].survive!=0){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
    fclose(stdout); 
	
	return 0; 
}
