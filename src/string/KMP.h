#include <stdio.h>
#include <string.h>
/*
@author: Steven Yu 2024/12/10
 */

using namespace std;
const int N = 100010;
const int M = 10010;
//Knuth-Morries-Prat
class KMP{
    private:
        int m,n;
        char s[N],p[M];
        int ne[M],nextVal[M];
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
        void print_nextVal(){
            for(int i =0; i <m ;i++){
                cout<<nextVal[i]<<" ";
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
        //求next数组，此算法很巧妙
        void get_next( ){
            for(int i = 2,j=0;i<= this->m; i++){
                while (j && p[i] != p[j+1]) j = ne[j]; //MSVC下有bug，怀疑数组没有正确初始化导致的
                if(p[i] == p[j+1]) j ++ ;
                ne[i] = j;
                }
            print_ne();
        }

        //kmp的优化，求nextVal数组
        //笔算时j从1开始
        //若next[j] == j;令next[j] = next[next[j]];
        void get_nextVal(){
            get_next();
            //nextVal[0]  =0;cpp中数组元素默认值为0，可以不写
            //cout<<this->m<<endl;
            for(int j = 1; j <m;j++ ){
                int t = j;
                nextVal[j] = ne[j];
                //cout<<"for"<<nextVal[j]<<" "<<t<<endl;
                while(p[t+1] == p[ne[t]+1] && t>0){
                        t = ne[t];
                        nextVal[j] = ne[t];
                        //cout<<"while"<<nextVal[j]<<" "<<t<<endl;
                    }
                }
        print_nextVal();
        }
        int match(){
            for(int i  =1, j = 0;i <= this->n; i++){			
                while(j && s[i] != p[j+1]) {
                        j = ne[j];
                }
                printf("i = %d j + 1= %d\n",i,j+1);
                if (s[i] == p[j+1]) j ++;
                if (j == m)
                    {
                        printf("%d \n", i - j + 1);
                        return i-j+1;
                        //j=ne[j];
                    }
                }
            return -1;
        }

        int match_nextVal(){
            cout<<n<<endl;
            for(int i  =1, j = 0;i <= n; i++){			
                while(j && s[i] != p[j+1]) {
                        j = nextVal[j];
                }
                printf("i = %d j + 1= %d\n",i,j+1);
                if (s[i] == p[j+1]) j ++;
                if (j == m)
                    {
                        printf("%d\n ", i - j + 1);
                        return i-j+1;
                        //j=ne[j];
                    }
                }
            return -1;
        }

};

