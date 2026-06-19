#include<stdio.h>
#define RI 100001
int a[RI];
int n,m,i,r,t;
int getint,getcha;
FILE *get,*put;
int get_int(){
	getint=0;
	while(getcha<'0'||getcha>'9')
		getcha=fgetc(get);
	while(getcha>='0'&&getcha<='9'){
		getint*=10;
		getint+=getcha-'0';
		getcha=fgetc(get);
	}
	return getint;
}
int main(){
	get=fopen("duel.in","r");
	put=fopen("duel.out","w");
	n=get_int();
	while(i<n)
	{
		++i;
		r=get_int();
		++a[r];
	}
	i=1;
	m=n;
	while(i<RI){
		if(t<=a[i]){
			m-=t;
			t=a[i];
		}
		else{
			m-=a[i];
		}
		++i;
	}
	fprintf(put,"%d\n",m);
	fclose(get);
	fclose(put);
	return 0;
}

