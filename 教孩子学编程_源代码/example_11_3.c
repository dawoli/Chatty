#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *fp1, *fp2, *fp;       int m, x, y;
    fp1=fopen("f01.txt","r");  fp=fopen("f.txt","w");
    fp2=fopen("f02.txt","r");  m = 0;         //A：读取文件前
    while(!feof(fp1) && !feof(fp2)) {         //C：循环执行
        if (m==0) {                               //C0：首次读取
            fscanf(fp1,"%d",&x); fscanf(fp2,"%d",&y); m=1;
        }
        else {
            if (x<y) fscanf(fp1,"%d",&x);   //C1：读取下一个x
            else fscanf(fp2,"%d",&y);        //C2：读取下一个y
        }
        if (x<y) fprintf(fp,"%d ",x);       //C3：输出较小的x
        else fprintf(fp,"%d ",y);            //C4：输出较小的y
    }
    while(!feof(fp1)) {        //D：文件f01.txt未读完时循环执行
        if (x<y) {              //D1：文件f02.txt的最后值大于x时
            fscanf(fp1,"%d",&x);              //D0：读取下一个x
            if (x<y) fprintf(fp,"%d ",x);   //D3：输出较小的x
            else fprintf(fp,"%d ",y);        //D4：输出较小的y
        }
        else {                   //D2：文件f02.txt的最后值小于x时
            fprintf(fp,"%d ",x);    //D5：输出x 
            fscanf(fp1,"%d",&x);    //D6：再次从f01.txt读取数据
        } 
    }
    while(!feof(fp2)) {        //E：文件f02.txt未读完时循环执行
        if (x>y) {              //E1：文件f01.txt的最后值大于y时
            fscanf(fp2,"%d",&y);              //E0：读取下一个y
            if (x>y) fprintf(fp,"%d ",y);   //E3：输出较小的y
            else fprintf(fp,"%d ",x);        //E4：输出较小的x
        }
        else {                   //E2：文件f01.txt的最后值小于y时
            fprintf(fp,"%d ",y);       //E5：输出y
            fscanf(fp2,"%d",&y);       //E6：从f02.txt读取数据
        } 
    }
    if (x<y) fprintf(fp,"%d ",y);             //F1：输出最后y
    else fprintf(fp,"%d ",x);                  //F2：输出最后x
    fclose(fp1); fclose(fp2); fclose(fp);
    return 0;
}

