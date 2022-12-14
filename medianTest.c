// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MINVALU -10e6
#define MAXVALU  10e6

int max(int A, int B){ if (A>B) return A; else return B; }
int min(int A, int B){ if (A<B) return A; else return B; }

float median_of_merged(int* A, int m, int* B, int n)
{
    if (m>n){return median_of_merged(B,n,A,m);}
    
    int merged_med_index = (m+n+1)/2; //if the size is even this index is for the first element.
    int start_A = 0;
    int end_A   = m;
    
    while(start_A <= end_A)
    {
        int mid_A= (start_A+end_A)/2;
        int left_size_A= mid_A;
        int left_size_B= merged_med_index-mid_A;
        
        int left_A,left_B,right_A,right_B;
        if (left_size_A>0) { left_A=A[left_size_A-1]; } else {left_A=MINVALU;}
        if(left_size_B>0){ left_B=B[left_size_B-1]; } else {left_B=MINVALU;}
        if(left_size_A<m){ right_A=A[left_size_A];   } else {right_A=MAXVALU;}
        if(left_size_B<n){ right_B=B[left_size_B];   } else {right_B=MAXVALU;}
        // printf("(%u, %u, %u, %u)",left_A,right_A,left_B,right_B);
        if (left_A <= right_B && left_B <= right_A) 
        {
             if ((m + n) % 2 == 0) 
             {return (max(left_A, left_B) + min(right_A, right_B)) / 2.0;}
             return max(left_A, left_B);
        }
        else if (left_A > right_B){end_A = mid_A - 1;}
        else    {start_A = mid_A + 1;}
    }
}

int main() {
    // Write C code here
    int A[] = {1, 2, 3, 3};
    int B[] = {4, 7, 8, 10, 22, 23};
    int m=sizeof(A)/sizeof(A[0]);
    int n=sizeof(B)/sizeof(B[0]);
    float Y= median_of_merged(A,m,B,n);
    printf("%0.2f",Y);
    return 0;
}