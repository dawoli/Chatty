#include<bits/stdc++.h>
using namespace std;
//memset(a,0,sizeof(a));
int t;
int cren[100010];
int delta[100050];
int cmp(int a,int b){
	if(delta[a]<delta[b]){
		return 1;
	}
	else return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		memset(delta,0,sizeof(delta));
		int n=0;
		int ansa=0;//最高为1e9int即可 
		int ansb=0;
		int ansc=0;
		int lena=0;
		int lenb=0;
		int lenc=0;
		
		cin>>n;
		int mana[n+10],manb[n+10],manc[n+10],aren[n+10],bren[n+10];
		int nnk=n/2;//nn为n的一半 
		int a,b,c;
		for(int i=1;i<=n;i++){
			cin>>mana[i]>>manb[i]>>manc[i];//三个满意度 

			if(mana[i]>manb[i]){
				if(mana[i]>manc[i]){//a最大 ,存a进去 
					delta[i]=mana[i]-max(manb[i],manc[i]);
					aren[lena]=i;
					lena++;
					ansa+=mana[i];
				}
				else{//c最大 
					delta[i]=manc[i]-mana[i];
					cren[lenc]=i;
					lenc++;
					ansc+=manc[i];
				}
			}
			else if(manb[i]>manc[i]){//b最大 
				delta[i]=manb[i]-max(mana[i],manc[i]);
				bren[lenb]=i;
				lenb++;
				ansb+=manb[i];//
			}
			else{//c最大 
				delta[i]=manc[i]-manb[i];
				cren[lenc]=i;
				lenc++;
				ansc+=manc[i];
			}
		}
		
		if(lena>nnk){//先判越界，然后踢人 
			sort(aren,aren+lena,cmp);
			int kk=0;
			while(lena>nnk){
				lena=lena-1;
				ansa=ansa-delta[aren[kk]];
				kk=kk+1;
			}
		}
		else if(lenb>nnk){
			sort(bren,bren+lenb,cmp);
			int kk=0;
			while(lenb>nnk){
				lenb=lenb-1;
				ansb=ansb-delta[bren[kk]];
				kk=kk+1;
			}
		}
		else if(lenc>nnk){
			sort(cren,cren+lenc,cmp);
			int kk=0;
			while(lenc>nnk){
				lenc=lenc-1;
				ansc=ansc-delta[cren[kk]];
				kk=kk+1;
			}
		}
		cout<<ansa+ansb+ansc<<endl;
	}

	
	return 0;
}
