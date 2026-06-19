#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","I",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3)cout<<"0";
	else{
		int a,b;
		int cnt=0;
		int q,w,e;
		cin>>q>>w>>e;
		if((q+w+e)>2*max(max(q,w),e))cnt++;
//		if((q+w+r)>2*max(max(q,w),r))cnt++;
//		if((q+w+t)>2*max(max(q,w),t))cnt++;
//		if((q+e+r)>2*max(max(q,e),r))cnt++;
//		if((q+e+t)>2*max(max(q,e),r))cnt++;
//		if((q+r+t)>2*max(max(q,r),t))cnt++;
//		if((w+e+r)>2*max(max(w,e),r))cnt++;
//		if((w+e+t)>2*max(max(w,e),r))cnt++;
//		if((w+r+t)>2*max(max(w,r),t))cnt++;
//		if((e+r+t)>2*max(max(e,r),t))cnt++;
//		if((q+w+e+r)>2*max(max(max(q,w),e),r))cnt++;
//		if((q+w+e+t)>2*max(max(max(q,w),e),t))cnt++;
//		if((q+e+r+t)>2*max(max(max(q,e),r),t))cnt++;
//		if((w+e+r+t)>2*max(max(max(w,e),r),t))cnt++;
//		if((q+w+e+r+t)>2*max(max(max(max(q,w),e),r),t))cnt++;
		cout<<cnt;
	}
}
