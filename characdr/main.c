#include <sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int fd,len;
	char *buf[1024];
	char *s = "HEllo_world!";
	len = strlen(s);
	fd = open("/dev/simple_driver",O_RDWR);
	write(fd,s,len);
	int ret = read(fd,buf,len);
	printf("%d\n",len);
	close(fd);
	return 0;
}

