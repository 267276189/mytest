#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

void do_subtask(pid_t ppid){
	int i=0;
	int ret = 0;
	sleep(1);
	sleep(1);
//	ret = kill(ppid, 9);
	printf("ret = %d\n", ret);
	for( i=0; i< 10; i++){
		sleep(1);
		printf("subtask pid %d\n", getpid());
	}
}

int main(){
	pid_t pid=0;
	pid_t subpid=0;
	pid=getpid();
	printf("main task id=%d\n",pid); 
	subpid=fork();
	if (subpid==0){
		do_subtask(pid);
	}
	int i=0;
	//kill(subpid, pid);
	exit(0); 
	for( i=0; i<5; i++){
		sleep(1);
		printf("main task delay %d\n", i);
	}
	printf("main task exit!\r\n");
	return 0;
}
