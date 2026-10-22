
#include "copy.h"
int check_pram(int argc,const char *srcfile,int pronum)
{
    if(argc<3){
    printf("argc<3\n");
    return -1;
    }
    if((access(srcfile,F_OK))!=0){
    printf("文件不存在\n");
    return -1;
    }
    if(pronum<=0){
    printf("进程数量必须大于0\n");
    return -1;
    }
    return 0;
}
