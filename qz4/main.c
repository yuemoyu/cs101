#include<stdio.h>
#include<stdlib.h>

int swap(int* i, int* j){
	int tmp;
	tmp= *i;
	*i =*j;
	*j =tmp;
} 

int swaparray(int a[],int b[],int size){
	for(int i=0;i<size;i++){
		int tmp=a[i];
	    a[i]=b[i];
	    b[i]=tmp;
	}
}

int printarray(int a[],int size){
	for(int i=0;i<size;i++){
		if(i==size-1){
			printf("%d]\n",a[i]);
		}else{
			printf("%d,",a[i]);
		}
	}
}

char* copy_string(char* s) {
	int size = 0;
	while(s[size++]);
	char* cp_str = (char*)calloc(size, sizeof(char));
	for(int i = 0; i < size - 1; i++) {
		cp_str[i] = s[i];
	}	
	cp_str[size] = '\0';
	return cp_str;
}

int main(){
	int n=1,m=2;
	int i;
	int size=10;
	int source[10]={0,9,8,7,6,5,4,3,2,1};
	int dest[10]={10,20,30,40,50,60,70,80,90,100};
	swap(&n,&m);
	printf("No.1-------------------\nafter swap, n =%d, m =%d\n",n,m);
	swaparray(source,dest,size);
	printf("No.2-------------------\nafter swap array,source array =[");
	printarray(source,size);
	printf("after swap array,dest array =[");
	printarray(dest,size);
	
	char str[] = "IU!IU!IU!IU!";
	char* cp_str = copy_string(str);
	printf("No.3----------\n");
	printf("copy string = %s\n", cp_str);
	free(cp_str);
	return 0;
}
