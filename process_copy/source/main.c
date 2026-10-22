
#include "copy.h"
int main(int argc,char **argv)
{
    char *src=argv[1];
    char *dest=argv[2];
    int pronum=atoi(argv[3]);
    if(check_pram(argc,src,pronum)<0){
    return -1;
    }
    int blocksize=block_cur(src,pronum);
    printf("大小:%d",blocksize);
    process_create(src,dest,pronum,blocksize);
    process_wait();
    printf("OK");
    return 0;
}
