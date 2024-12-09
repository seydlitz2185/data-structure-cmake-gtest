#include <iostream>
#include <math.h>
#define ElementType int
using std::cout;
/// @brief 
/// @param a 
/// @return 

void print_array(int a[],int N){
    for(int i =0;i<N;++i){
        cout<<a[i]<<" ";
    }
    printf("\n");
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void InsertionSort(int a[],int N){
    print_array(a,N);
    for(int i=1;i<N;++i){
        int sentinal =a[i];
        for(int j=i;j>0;--j){
            if(a[j]<a[j-1]){
                a[j]=a[j-1];
                a[j-1]=sentinal;
                //printf("\nswap a[%d] and a[%d]\n",j,j-1);
            }
        }
    }
    print_array(a,N);
    return ;
}

void BinarySearchInsertionSort(int a[],int N){
    print_array(a,N);
    for(int i=1;i<N;++i){
        int sentinal =a[i];
        int low,high,mid;
        low=0;
        high=i;
        while (low<=high){
            mid=(low+high)/2;
            if(sentinal>a[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        for(int j =i;j>mid;--j){
            a[j]=a[j-1];
            //printf("\nswap a[%d] and a[%d]\n",j,j-1);
        }
        a[mid]=sentinal;
    }
    print_array(a,N);
    return ;
}

void shellsort(int a[],int N){
    print_array(a,N);
    int offset=N;
    int length=1;
    while (offset/2>0){
        offset/=2;
        length=ceil(N/offset);
        //printf("offset is %d;length is %d\n",offset,length);
        int start=0;
        while (start<offset){
           // printf("a[%d]=%d ",start,a[start]);
            for(int i=start+offset;i<N;i+=offset){
                int sentinal=a[i];
               // printf("a[%d]=%d ",i,a[i]);
                for(int j=i;j-offset>0;j-=offset){
                    if(a[j]<a[j-offset]){
                        a[j]=a[j-offset];
                        a[j-offset]=sentinal;
                       // printf("\nswap a[%d] and a[%d]\n",j,j-offset);
                    }
                }
            }
            start++;
            //printf("\n");
        }
    }
    print_array(a,N);
    return;
 }


void bubblesort(int a[],int N){
    print_array(a,N);
    for(int i = 1; i < N; i++){
        int t = i;    
        for( int j = i; j > 0;j--){
            if(a[t] < a[j-1]){
                swap(a[t],a[j-1]);
                t = j-1;
                //printf("\nswap a[%d]=%d and a[%d] = %d\n",t,a[t],j-1,a[j-1]);
            }
        }
    }
    print_array(a,N);
    return;
}

void quicksort(int a[],int N){
    print_array(a,N);
}