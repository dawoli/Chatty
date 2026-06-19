#include<cstdio>
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n, t, u, v;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		u=t/7;
		v=t%7;
		if(v==0){
			if(u==0){
				printf("-1");
			}
			else{
				for(int i=0;i<u;i++){
					printf("8");
				}
			}
		}
		else if(v==1){
			if(u==0){
				printf("-1");
			}
			else{
				printf("10");
				for(int i=1;i<u;i++){
					printf("8");
				}
			}
		}
		else if(v==2){
			printf("1");
			for(int i=0;i<u;i++){
				printf("8");
			}
		}
		else if(v==3){
			if(u==0){
				printf("7");
			}
			else if(u==1){
				printf("22");
			}
			else{
				printf("200");
				for(int i=2;i<u;i++){
					printf("8");
				}
			}
		}
		else if(v==4){
			if(u==0){
				printf("4");
			} 
			else{
				printf("20");
				for(int i=1;i<u;i++){
					printf("8"); 
				}
			}
		}
		else if(v==5){
			printf("2");
			for(int i=0;i<u;i++){
				printf("8");
			}
		}
		else if(v==6){
			printf("6");
			for(int i=0;i<u;i++){
				printf("8");
			}
		}
		printf("\n");
	}
}
