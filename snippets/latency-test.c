static inline void latency_test_payload(struct timespec* gts) {
    nsec_t curTime = 0, prevTime = 0, deltaTime = 0;
    unsigned int dieRollTotal = 0;
    /* SCHED_DEADLINE Test w/ rand() dice demo (100 rolls/cycle)
     * Period: 20ms; Runtime/WCET: 10ms; Deadline: 11ms */
    for (int i = 0; i < NUM_ITERS; i++) {
        prevTime = curTime;
        /* For the following function to work, a timebase needs
         * to be set at runtime, possibly in main(). */
        curTime = get_time_relative_to_timebase(gts);
        if (curTime != 0 && prevTime != 0) {
            deltaTime = abs((int)(curTime - prevTime - (DL_PERIOD)));
        }
        // Roll some dice to waste CPU time.
        dieRollTotal = 0;
        for (int i = 0; i < 100; i++) {
            dieRollTotal += ((rand() % 6) + 1);
        }
        /* The data can be printed or saved to a file here
         * for later analysis. */
        sched_yield();
    };
}