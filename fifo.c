#include<stdio.h>

int main (){

int n,framescount;
printf("Enter the total number of entries count : ");
scanf("%d",&n);

printf("Enter the size of frame : ");
scanf("%d",&framescount);

int pages[n];
int frames[framescount];
int hit =0;
int fault =0;
int counter=0;
printf("Enter the values one by one :");
for(int i=0;i<n;i++){
    scanf("%d",&pages[i]);
}
for(int i=0;i<framescount;i++){
    frames[i]=-1;
}
for(int i=0;i<n;i++){
    int page = pages[i];
    int found = 0;
    for(int j=0;j<framescount;j++){
        if(frames[j]==page){
            found = 1;
            hit++;
            break;
        }
    }
    if(!found){
        frames[counter]=page;
        counter= (counter +1)%framescount;
        fault++;
    }
    printf("Step no %d : ",i+1);
    for(int j=0;j<framescount;j++){
        if(frames[j]==-1){
            printf(" - ");
        }else 
        printf(" %d ",frames[j]);
    }
    if(found)
    printf(  "   (hit)\n");
    else 
    printf("   (fault)\n");


}

    printf("Total no of hits : %d \n",hit);
    printf("Total no of faults : %d",fault);


}