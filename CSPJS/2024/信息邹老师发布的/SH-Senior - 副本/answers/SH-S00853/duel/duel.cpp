#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,ans;
int cn[N],se[N];
int main(){
  freopen("duel.in","r",stdin);
  freopen("duel.out","w",stdout);
  scanf("%d",&n);
  ans=n;
  for(int i=0;i<n;i++){
    scanf("%d",&se[i]);
    cn[se[i]]++;
  }
  sort(se,se+n);
  int p=cn[se[0]],pre=se[0];
  for(int i=0;i<n;i++){
  	if(se[i]!=pre){
  	  if(cn[se[i]]>=p){
  	    ans-=p;
  	    p=cn[se[i]];
	  }
	  else{
	  	ans-=cn[se[i]];
	  	//p=p;
	  }
	}
	pre=se[i];
  }
  printf("%d\n",ans);
  return 0;
}
