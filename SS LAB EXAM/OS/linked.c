#include <stdio.h>

struct file {
    char fname[10];
    int start, length, block[10];
} f[10];

void main() {
    int n;
  int allocated[10]={0};


    printf("Enter no. of files:");
    scanf("%d", &n);

    // Get the details of each file
    for (int i = 0; i < n; i++) {
    
        printf("\nEnter file name:");
        scanf("%s", f[i].fname);
    
        printf("Enter no.of blocks:");
        scanf("%d", &f[i].length);
        printf("Enter block numbers needed:\n");
        for (int j = 0; j < f[i].length; j++) {
           x: scanf("%d", &f[i].block[j]);
					if(j==0)
            f[i].start=f[i].block[j];
            // Check if the block is already allocated
          if (allocated[f[i].block[j]] == 1) {
                printf("Block %d is already allocated-->enter another block\n", f[i].block[j]);
                goto x;
            }

            // Mark the block as allocated
            allocated[f[i].block[j]] = 1;
        }
    }

    // Print the details of each file
    printf("File\tstart\tleng\tblock\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t", f[i].fname, f[i].start, f[i].length);
        for (int j = 0; j < f[i].length - 1; j++) {
            printf("%d--->", f[i].block[j]);
        }
        printf("%d", f[i].block[f[i].length-1]);
        printf("\n");
    }

}