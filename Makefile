LDFLAG+=-lpthread
threadtest: threadtest.c
	gcc threadtest.c -lpthread -o threadtest
taskmonitor: taskmonitor.c
