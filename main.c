#include <stdio.h>
#define INDEXES_MAX 100
typedef struct {
    int status;
    int indexes[INDEXES_MAX];
    int indexes_size;
}INDEXES;
int strlen_k(const char* str)
{
    int count = 0;
    while (str[count] != '\0' && str[count] != -52)
    {
        count++;
    }
    return count;
}
int strnncmp_k(const char* str1, const char* str2,int str1_size,int str2_size,int start_index){

    for (int i = 0; i<str2_size; i++){
        if (str1[start_index+i] != str2[i]){
            return 0;
        }
    }

    return 1;
}
INDEXES findAllch_k(const char *str,const char ch, int count){
    INDEXES indexes;
    indexes.status = 0;
    for(int g= 0; g<INDEXES_MAX; g++){
        indexes.indexes[g] = -999;
    }
    int ii = 0;
    int si =0;
    while (str[si] != '\0' && si < count) {
        if (str[si] == ch) {
            indexes.status = 1;
            indexes.indexes[ii++] = si;

        }
        si++;
    }
    indexes.indexes_size = ii;
    return indexes;
}

INDEXES findAllstr_k(const char *target,const char *str,int target_count, int str_count){
    INDEXES result,data;
    data.status =0;
    for(int g= 0; g<INDEXES_MAX; g++){
        data.indexes[g] =-999;
    }
    int si = 0;
   result = findAllch_k(target,str[0],strlen_k(target));
   if (result.status){

       for(int i=0;i<result.indexes_size;i++){
           int start_index = result.indexes[i];
           int status = strnncmp_k(target,str, strlen_k(target), strlen_k(str),start_index);
           if (status){
               data.status = 1;
               data.indexes[si++] = start_index;
//               printf("\n found-%d \n",start_index);
//               printf("data.indexes[%d] = %d", si-1,data.indexes[si-1]);
           }
       }
   }else{
       data.status = 0;
   }
    data.indexes_size = si;
////    printf("data.status = %d",data.status);
//        for (int s=0; s<si-1; s++){
//        printf("\n  data.indexes [%d] = %d ",s,data.indexes[s]);
//    }
    return data;
}

int main(){
    char data[100][100];
    char str[100] = "I*am*am*student" ;
    INDEXES result;

    result = findAllstr_k(str,"student", strlen_k(str), strlen_k("student"));
    if (result.status){
        for (int i =0; i< result.indexes_size; i++){
            printf("%d\t",result.indexes[i]);
        }
    }

    return 0;
}