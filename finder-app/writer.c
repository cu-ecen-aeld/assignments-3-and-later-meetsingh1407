#include <syslog.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // Open a connection to the logger
    openlog("Writer.c", LOG_PID | LOG_CONS, LOG_USER);

    if(argc < 3){
        syslog(LOG_ERR, "Incomplete arguments.");
        exit(1);
    }

    FILE *my_file = fopen(argv[2],"w");
    if(my_file == NULL){
        syslog(LOG_ERR, "Unable to create/open file.");
        exit(0); 
    }

    // Write to file. 
    if(fputs(argv[1],my_file) < 0){
        syslog(LOG_ERR, "%s", strerror(errno));
        exit(0); 
    }

    // Write a log message
    syslog(LOG_DEBUG, "Writing %s to %s", argv[1], argv[2]);

    // Close the file. 
    if(fclose(my_file) != 0){
        syslog(LOG_DEBUG, "%s", strerror(errno));
		exit(0);
    }

    closelog();

    return 0;
}
