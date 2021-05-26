typedef struct timespec timespec_t;
typedef unsigned long long int nsec_t;

static inline nsec_t to_ns(const timespec_t* ts) {
    return ((nsec_t)ts->tv_sec * NSEC_PER_SEC) + ts->tv_nsec;
}

static inline nsec_t gettime_ns(timespec_t* ts) {
    if (clock_gettime(USE_CLOCK, ts) == -1) {
        exit(EXIT_FAILURE);
    }
    return to_ns(ts);
}