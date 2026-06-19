#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,n,k,q,r,c,flag,s[101][2001],num,st,ed;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k>>q;
		for(int j=1;j<=n;j++){
		    num=0;
		    do{
		    	num++;
				cin>>s[j][num];
			}	while(getchar()!='\n');
			num-=1;
			s[j][1]=num;
		}
		for(int j=1;j<=q;j++){
			cin>>r>>c;
			flag=0;
			if(r==1){
				for(int p=1;p<=n;p++){
					for(int q=2;q<=s[p][1]+1;q++){
						if(s[p][q]==1)st=q;
						if(s[p][q]==c)ed=q;
						if(q-p>=0&&q-p<k){
							cout<<"1"<<endl;
							flag=1;
							break;
						}
					}
					if(flag==1)break;
				}
				if(flag==0)cout<<"0"<<endl;
			}
		}
	}
	return 0;
}
