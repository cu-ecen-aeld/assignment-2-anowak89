#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

int write_file(const char *writefile, const char *writestr) {

    // Check if both arguments are provided
    if (writefile == NULL || writestr == NULL) {
		syslog(LOG_ERR, "Error: writefile or writestr is NULL");
        return 1;
    }

    // Open the file for writing (overwrite existing or create a new file)
    FILE *file = fopen(writefile, "w");
    if (file == NULL) {
        syslog(LOG_ERR, "Error: Unable to open the file. Errno: %d", errno);
        return 1;
    }

    // Write the content to the file
	syslog(LOG_DEBUG,"Writing %s to file %s", writestr, writefile);
    fputs(writestr, file);

    // Close the file
    fclose(file);
	return 0;
}

int main(int argc, char *argv[]) {

	openlog(NULL,0,LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR,"Error: The program was called with wrong parameters.");
        return 1;
    }

    int res = write_file(argv[1], argv[2]);
	if (res != 0) {
		closelog();
		return 1;
	}

	closelog();
    return 0;
}

