#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


FILE*fp;
FILE*bin;
int num[7]={0};
static int currentCount;

void countTimes(){
    int read[1];
    int write[1];    
    if((bin= fopen("binfile.txt", "r")) == NULL){
        bin = fopen("binfile.txt", "wb+");
        write[0] = 1;       
        fwrite(write, sizeof(int), 1, bin);
    }
    else{
        bin = fopen("binfile.txt", "rb+");
        fseek(bin, 0, SEEK_SET);
        fread(read, sizeof(int), 1, bin);
        fclose(bin);    
        write[0] = read[0] + 1;
        bin = fopen("binfile.txt", "wb+");
        fwrite(write, sizeof(int), 1, bin);
    }
    fclose(bin);
    currentCount = write[0];
} 

void lotto(){
    int var,exist,tmp,n=0;
    for(int i=0;i<7;i++){
        num[i]=0;
    }
    while(n<6){
        var=rand()%69+1;
        exist=0;
        for(int i=0;i<=n;i++){
            if(num[i]==var){
                exist=1;
            }
        }
        if(exist==0){
            num[n]=var;
            n++;
        }
    }
    for(int i=0;i<6;++i){
        for(int j=0;j<i;++j){
            if(num[j]>num[i]){
                tmp=num[j];
                num[j]=num[i];
                num[i]=tmp;
            }
        }
    }    
    num[6]=rand()%10+1;
    for(int i=0;i<7;i++){
        fprintf(fp,"%02d ",num[i]);
    }
}

int main()
{
    int n=5;
	char currentName[80];
    srand(time(NULL));
    //printf("請問您要買幾組樂透彩: %d\n",n);
    //scanf("%d",&n);
    //printf("購買的%d組樂透組合在 lotto.txt\n", n);
    countTimes();
    sprintf(currentName, "lotto[%04d].txt", currentCount);
    fp= fopen(currentName,"w+");
    fprintf(fp,"========lotto649=========\n");
    time_t curtime;
    time(&curtime);
    fprintf(fp,"=%s",ctime(&curtime));
    fprintf(fp,"========+ No.%05d +========\n", currentCount);    
    
    
    
    for(int i=1;i<=n;i++){
        fprintf(fp,"[%d]:",i);
        lotto();
        fprintf(fp,"\n");
    }
    for(int j=0;j<(5-n);j++){
        fprintf(fp,"[%d]",j+n+1);
        for(int k=0;k<6;k++){
            fprintf(fp,"-- ");
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"========csie@CGU =========");
    fclose(fp);
    fclose(bin);
}
