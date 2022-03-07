#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE*fp;
int num[6]={0};

void lotto(){
    int var,exist,tmp,n=0;
    for(int i=0;i<6;i++){
        num[i]=0;
    }
    while(n<5){
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
    for(int i=0;i<5;++i){
        for(int j=0;j<i;++j){
            if(num[j]>num[i]){
                tmp=num[j];
                num[j]=num[i];
                num[i]=tmp;
            }
        }
    }    
    num[5]=rand()%10+1;
    for(int i=0;i<6;i++){
        fprintf(fp,"%02d ",num[i]);
    }
}

int main()
{
    int n=2;
    srand(time(NULL));
    printf("請問您要買幾組樂透彩: %d\n",n);
    //scanf("%d",&n);
    printf("購買的%d組樂透組合在 lotto.txt\n", n);
    fp=fopen("lotto.txt","w+");
    fprintf(fp,"========lotto649=========\n");
    time_t curtime;
    time(&curtime);
    fprintf(fp,"=%s",ctime(&curtime));
    
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
}
