#define ABEND 1
int exit_code = ABEND;
if (exit_code > 0) {
    syslog(LOG_WARNING, "%s%i",
           "(EXAMPLE) Abnormal exit code detected: ", 
           exit_code);
}