//质检员精神 
#include <bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
int arr[100010][3]={};
struct club{
	int x;
	int y;
};
club arr0[100010]={};
club arr1[100010]={};
club arr2[100010]={};
bool cmp(club a,club b){
	return a.y<b.y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		int a=0,b=0,c=0;
		long long ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
			int zd=max(arr[i][0],max(arr[i][1],arr[i][2]));
			ans+=zd;
			if(zd==arr[i][0]){
				arr0[a].x=zd;
				arr0[a++].y=zd-max(arr[i][1],arr[i][2]);
			}
			else if(zd==arr[i][1]){
				arr1[b].x=zd;
				arr1[b++].y=zd-max(arr[i][0],arr[i][2]);
			}
			else if(zd==arr[i][2]){
				arr2[c].x=zd;
				arr2[c++].y=zd-max(arr[i][0],arr[i][1]);
			}
	    }
    	if(a>(n/2)){
    		sort(arr0,arr0+a,cmp);
    		for(int i=0;i<a-n/2;i++){
    			ans-=arr0[i].y;
			}
		}
		else if(b>(n/2)){
			sort(arr1,arr1+b,cmp);
    		for(int i=0;i<b-n/2;i++){
    			ans-=arr1[i].y;
			}
		}
		else if(c>(n/2)){
			sort(arr2,arr2+c,cmp);
    		for(int i=0;i<c-n/2;i++){
    			ans-=arr2[i].y;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
