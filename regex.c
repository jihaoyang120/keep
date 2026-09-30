#include <sys/stat.h>
#include <fcntl.h>
#include <regex.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
int main(void)
{
    int fd;
    fd = open("1.txt",O_RDWR);
    int size = lseek(fd,0,SEEK_END);
    char * mmap_ptr = NULL;
    char * copy_ptr = NULL;
    mmap_ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    copy_ptr = mmap_ptr;
    close(fd);
    char * regstr = "<a[^>]*href=\"\\([^\"]\\+\\?\\)\"[^>]*>\\([^<]\\{1,\\}\\?\\)</a>";
    int regnum = 3;
    regmatch_t match[regnum];
    regex_t reg;
    regcomp(&reg,regstr,0);
    char url[1024];
    char title[1024];
    while((regexec(&reg,mmap_ptr,regnum,match,0))==0)
    {
        bzero(url,sizeof(url));
        bzero(title,sizeof(title));
        snprintf(url,match[1].rm_eo - match[1].rm_so + 1 , "%s",mmap_ptr+match[1].rm_so);
        snprintf(title,match[2].rm_eo - match[2].rm_so + 1 , "%s",mmap_ptr+match[2].rm_so);

        mmap_ptr += match[0].rm_eo; 
        printf("新闻地址：%s\t新闻标题：%s\n",url,title);
    }

    regfree(&reg);
    munmap(copy_ptr, size);
    printf("done.\n");
    return 0;
}
