#include<stdio.h>
#include<string.h>
int main(){
	int x;
    FILE *fp0,*fp1,*fp2; 
    fp0 = fopen("separate.txt","r");
    fp1 = fopen("test11_6Odd.txt","w");
    fp2 = fopen("test11_6Even.txt","w");

	while(!feof(fp0)){
        fscanf(fp0,"%d",&x);
		if(x%2 != 0) fprintf(fp1,"%d ",x); 
        else fprintf(fp2,"%d ",x);   

	}
    fclose(fp1); fclose(fp2); fclose(fp0);
	return 0;
}
