
#include "copy.h"

int block_cur(const char*srcfile,int pronum)
{
    int fd = open("测试文件",O_RDWR);
    int filesize = lseek(fd,0,SEEK_END);
    close(fd);
    if(filesize % pronum == 0)
    return filesize / pronum;
    else
    return filesize / pronum + 1;
}
