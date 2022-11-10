//编写一个文件拷贝程序（CopyFile.c）
//CopyFile.c可以对输入的文件name.txt进行备份，备份后的文件名为“原文件名＋_backup“，并打印出文件的大小。
//格式如下：./CopyFile test

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    char buff[1024];
    long len;
    char *origin_path = (char *)argv[1];
    int fo = open(origin_path, O_RDWR|O_CREAT);
    char *ext = strchr(origin_path, '.');
    char *temp = (char*)malloc((strlen(origin_path) + 8) * sizeof(char));
    char *backup_path = temp;
    char *suffix = "_backup";
    while (origin_path != ext){
        *temp = *(origin_path++);
        temp++;
    }
    while (*suffix != '\0') {
        *temp = *suffix++;
        temp++;
    }
    while (*ext != '\0'){
        *temp = *ext++;
        temp++;
    }
    int fb = open(backup_path, O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
    while ((len = read(fo, buff, 1024))) write(fb, buff, len);
    struct stat st;
    stat(backup_path, &st);
    printf("%lld 字节\t\t%s", st.st_size, backup_path);
}