#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],c[N],t,ans;
bool clr[N];
int main(){
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  scanf("%d",&t);
  while(t--){
  	scanf("%d",&n);
  	memset(a,0,sizeof(a));
  	memset(clr,0,sizeof(clr));
  	memset(c,0,sizeof(c));
  	ans=0;
  	scanf("%d",&a[0]);
  	clr[0]=0;
  	c[0]=0;
  	for(int i=1;i<n;i++){
  	  scanf("%d",&a[i]);
  	  clr[i]=!clr[i-1];
  	  for(int j=i-1;j>=0;j--){
  	  	if(a[j]==a[i]){
  	  	  c[i]=a[i]+c[j];
  	  	  clr[i]=clr[j];
  	  	  for(int k=j+1;k<i;k++){
  	  	  	if(clr[k]==clr[i]){
  	  	  	  if(c[k]<c[i]){
			    clr[k]=!clr[i];
			    c[k]=0;
			  }
			  else{
			  	clr[i]=!clr[i];
			  	c[i]=0;
			  }
			}
		  }
		  break;
		}
	  }
	}
	for(int i=0;i<n;i++){
	  ans+=c[i];
	}
	printf("%d\n",ans);
  }
  return 0;
}
