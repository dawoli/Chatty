#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int T,n,ans,k,len,g,gg;
int q;
int dn[15]={6,2,5,-1,4,-1,6,3,7,-1};//摆出0~9分别需要的木棍个数 {6,2,5,5,4,5,6,3,7,6}
long long dp[10005]={-1,-1,1,7,4,2,6,8,16};
/*void dfs(int k,int remain){// k:位权  (个：0 十：1……)  remain:剩余木棍数 
	
	if(remain<0) return ;//回溯
	/*if(remain==0 && ans!=0 && i*pow(10,k-1)){
		ans=-1;	
		return ;
	}*/
	/*if(remain==0 ) return ;
	//if(){//在边界内
		for(int i=0;i<=8;i++){
			if(dn[i] != -1){
				if((remain-dn[i]==0) && (ans+i*pow(10,k)==0)!=0 && (i*pow(10,k))==0)  return ;
				remain-=dn[i];
				ans+=i*pow(10,k);
				
				dfs(k+1,remain);
				remain+=dn[i];//回溯 
				ans-=i*pow(10,k);
			}
		} 
	//}
}*/
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		g=0,gg=0;
		if(n==1){
			cout<<-1;
			continue;	
		}	
		/*len=0;
		k=0;
		for(int i=9;i<=n;i++){
			int x=dp[i-1];
			while(x){
				x/=10;
				len++;
			}
			//cout<<len<<endl;
			x=dp[i-1];
			for(int j=0;j<=len-3;j++){//复制后len-2位数 
				g=x%10;
				dp[i]+=g*pow(10,j);
				x/=10;
			}
			//cout<<dp[i]<<' ';
			k=len-3+1;//位权 
			//对前两位进行 2 -> 6 -> 8 ->进位   只有最高位可以是 1 
			g=x%10;
			if(g == 2) dp[i] += 6*pow(10,k);
			if(g == 6) dp[i] += 8*pow(10,k);
			if(g!=8){
				gg=x/10%10 ;
				k++;
				dp[i] += gg*pow(10,k);
			}
			//cout<<gg*pow(10,k)<<' ';
			if(g == 8){//进位 
				//最高位的进位情况 1-> 2 -> 6 -> 8 -> 1 
				if(gg == 1) dp[i] += 2*pow(10,k);
				if(gg == 2) dp[i] += 6*pow(10,k);
				if(gg == 6) dp[i] += 8*pow(10,k);
				if(gg == 8){//88 -> 168  即 8 -> 16 
					
					dp[i] += 6*pow(10,k);
					k++;
					dp[i] += 1*pow(10,k);
				}
				//cout<<dp[i]<<' ';
			}
			cout<<dp[i]<<endl;
		}*/
		else if(n==2){
			cout<<1;
			continue;	
		}
		else if(n==3){
			cout<<7;
			continue;	
		}
		else if(n==4){
			cout<<4;
			continue;	
		}
		else if(n==5){
			cout<<2;
			continue;	
		}
		else if(n==6){
			cout<<6;
			continue;	
		}
		else if(n==7){
			cout<<8;
			continue;	
		}
		else if(n==8){
			cout<<10;
			continue;	
		}
		else if(n==9){
			cout<<18;
			continue;	
		}
		else if(n==10){
			cout<<22;
			continue;	
		}
		else if(n==11){
			cout<<26;
			continue;	
		}
		else if(n==12){
			cout<<28;
			continue;	
		}
		else if(n==13){
			cout<<68;
			continue;	
		}
		else if(n==14){
			cout<<88;
			continue;	
		}
		else if(n==15){
			cout<<108;
			continue;	
		}
		else if(n==16){
			cout<<188;
			continue;	
		}
		else if(n==17){
			cout<<228;
			continue;	
		}
		else if(n==18){
			cout<<208;
			continue;	
		}
		else if(n==19){
			cout<<288;
			continue;	
		}
		else if(n==20){
			cout<<688;
			continue;	
		}
		else if(n==21){
			cout<<888;
			continue;	
		}
		else if(n==22){
			cout<<1088;
			continue;	
		}
		else if(n==23){
			cout<<1888;
			continue;	
		}
		else if(n==24){
			cout<<2288;
			continue;	
		}
		else if(n==25){
			cout<<2088;
			continue;	
		}
		else if(n==26){
			cout<<2888;
			continue;	
		}
		else if(n==27){
			cout<<6888;
			continue;	
		}
		else if(n==28){
			cout<<8888;
			continue;	
		}
		else if(n==29){
			cout<<10888;
			continue;	
		}
		else if(n==30){
			cout<<18888;
			continue;	
		}
		else if(n==31){
			cout<<22888;
			continue;	
		}
		else if(n==32){
			cout<<20888;
			continue;	
		}
		else if(n==33){
			cout<<28888;
			continue;	
		}
		else if(n==34){
			cout<<68888;
			continue;	
		}
		else if(n==35){
			cout<<88888;
			continue;	
		}
		else if(n==36){
			cout<<108888;
			continue;	
		}
		else if(n==37){
			cout<<188888;
			continue;	
		}
		else if(n==38){
			cout<<228888;
			continue;	
		}
		else if(n==39){
			cout<<208888;
			continue;	
		}
		else if(n==40){
			cout<<288888;
			continue;	
		}
		else if(n==41){
			cout<<688888;
			continue;	
		}
		else if(n==42){
			cout<<888888;
			continue;	
		}
		else if(n==43){
			cout<<1088888;
			continue;	
		}
		else if(n==44){
			cout<<1888888;
			continue;	
		}
		else if(n==45){
			cout<<2288888;
			continue;	
		}
		else if(n==46){
			cout<<2088888;
			continue;	
		}
		else if(n==47){
			cout<<2888888;
			continue;	
		}
		else if(n==48){
			cout<<6888888;
			continue;	
		}
		else if(n==49){
			cout<<8888888;
			continue;	
		}
		else if(n==50){
			cout<<10888888;
			continue;	
		}
		if(n%7==1){
			cout<<"10";
			q=(n-1)/7;
			for(int i=1;i<q;i++) cout<<'8';
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
