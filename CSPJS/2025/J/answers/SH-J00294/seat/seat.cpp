#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r,s; 
	cin>>c>>r>>s;
	int a[108]={},la=1,b[108]={},e=0,h=0,p[10][10]={},y=0;
	a[0]=s;
	y=c*r-1;
	for(int i=1;i<=y;i++){
		cin>>a[i];
		la++;
	}
	for(int i=0;i<=la;i++){
		for(int j=0;j<=la;j++){
			if(a[j]>b[e]){
				b[e]=a[j];
				h=j;
			}
		}
		e++;
		a[h]={};
	}
	for(int i=1,k=0;i<=c;i++){
		if(i%2!=0){
			for(int j=1;j<=r;j++){
			p[j][i]=b[k];
			k++;
		}
		}else{
			for(int j=r;j>=1;j--){
			p[j][i]=b[k];
			k++;
		}
		}
		
	}
	for(int i=1,k=0;i<=c;i++){
		for(int j=1;j<=r;j++){
			if(s==p[j][i]){
				cout<<i<<" "<<j;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
																陋室铭
	山不在高，有仙则名，水不在深，有龙则灵，斯是陋室，惟吾德馨，苔痕上阶绿，草色入帘青，谈笑有鸿儒，往来无白丁，可以调素琴，阅金经。
	无丝竹之乱耳，无案牍之劳形，南阳诸葛庐，西蜀子云亭，孔子云：“何陋之有！”
	    登幽州台歌
	前不见古人，后不见来者。
  念天地之悠悠，独怆然而涕下。 
*/ 

