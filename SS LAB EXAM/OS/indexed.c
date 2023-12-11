#include <stdio.h>

struct file {
    char fname[10];
    int index, length;
} f[10];

void main() {
    int n;
  	int allocated[10]={0};
  	int bno[50][50];

    printf("Enter no. of files:");
    scanf("%d", &n);

    // Get the details of each file
    for (int i = 0; i < n; i++) 
    {
        printf("\nEnter file name:");
        scanf("%s", f[i].fname);
        x: printf("Enter index block:");
         scanf("%d", &f[i].index);
        if(allocated[f[i].index])
        {
          printf("Index block is already allocated --try another\n");
          goto x;
        }
        allocated[f[i].index]=1;
        printf("Enter no.of blocks:");
        scanf("%d", &f[i].length);
        printf("Enter block numbers:\n");
        for (int j = 0; j < f[i].length; j++) 
        {
          int chumma;
           y: chumma=0;
           int temp;
           scanf("%d", &temp);
          

            // Check if the block is already allocated
            if (allocated[temp] == 1) {
                printf("Block %d is already allocated-->enter another block\n",temp);
                goto y;
            }
          allocated[temp] = 1;
          bno[f[i].index][j]=temp;
        }
      
      printf("\n");
      for(int j=0;j<f[i].length;j++)
        {
          printf("%d ----> %d\n",f[i].index,bno[f[i].index][j]);
        }
    }

    // Print the details of each file
    printf("\nFile\tindex\tsize\n");
    for (int i = 0; i < n; i++) {
     
        printf("%s\t%d\t\t%d\n", f[i].fname, f[i].index, f[i].length);
       
    }

}