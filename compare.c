#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void compare(void){


	int nFile_ref,nFile_out;
	int len_ref,len_out;
	int buf_ref,buf_out;
	int n,errors=0;
	int i=0,j=0,k=0;

	if((nFile_ref = open("Reference.life",O_RDONLY)) < 0){
		printf("Not Exist Reference.life File\n");
		printf("Do you want Test \n");
		printf("Add File(name is Reference.life) in directory\n");
		exit(1);
	}
	if((nFile_out = open("ouput.life",O_RDONLY)) < 0){
		printf("file open error!\n");
		exit(1);
	}

	len_ref = lseek(nFile_ref,0,SEEK_END);
	buf_ref = (char *)malloc(sizeof(char)*len_ref);
	lseek(nFile_ref,0,SEEK_SET);
	read(nFile_ref,buf_ref,len_ref);

	len_out = lseek(nFile_out,0,SEEK_END);
	buf_out = (char *)malloc(sizeof(char)*len_out);
	lseek(nFile_out,0,SEEK_SET);
	read(nFile_out,buf_out,len_out);

	for(i=n;n<len_ref;n++){
		if(buf_ref[n] != buf_out[n]) errors++;
	}

	printf("Errors is %d \n", errors);

	return ;
}
