void* entry_point(void* args) {
    // Register the signal handler
    (void)signal(SIGXCPU, dl_miss_handler);  
    if (sched_setattr(0, &example, 0)) {
        /* An error occurred: probably we didn't have 
         * the correct permissions to change our attributes
         */
        exit(EXIT_FAILURE);
    }
    for(;;) {
        // Our real-time periodic task code goes here
        sched_yield();
    }
}