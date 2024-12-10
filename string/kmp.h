#include <stdio.h>
#include <string.h>
/*
@author: Steven Yu 2024/12/10
 */

using namespace std;
const int N = 100010;
const int M = 10010;

class KMP{
    private:
        int m,n;
        char s[N],p[M];
        int ne[M];
    public:
        void print_s(){
            for(int i =0; i <=n ;i++){
                cout<<s[i]<<" ";
            }
            cout<<endl;
        }
        void print_p(){
            for(int i =0; i <=m ;i++){
                cout<<p[i]<<" ";
            }
            cout<<endl;
        }

        void print_ne(){
            for(int i =0; i <m ;i++){
                cout<<ne[i]<<" ";
            }
            cout<<endl;
        }
        void Init(char s[],char p [], int n ,int m){
            this->n = n;
            this->m = m;
            memcpy(this->s+1,s,n);
            memcpy(this->p+1,p,m);
            print_s();
            print_p();
        }
        
        void get_next( ){
            for(int i = 2,j=0;i<= this->m; i++){
                while (j && p[i] != p[j+1]) j = ne[j];
                if(p[i] == p[j+1]) j ++ ;
                    ne[i] = j;
                }
            print_ne();
        }

        int match(){
            for(int i  =1, j = 0;i <= this->n; i++){			
                while(j && s[i] != p[j+1]) {
                        j = ne[j];
                }
                printf("i = %d j + 1= %d\n",i,j+1);
                if (s[i] == p[j+1]) j ++;
                if (j +1== m)
                    {
                        printf("%d ", i - n + 1);
                        return j;
                        //j=ne[j];
                    }
                }
            return -1;
        }

};

