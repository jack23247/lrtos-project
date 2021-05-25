struct sched_attr example = {
    .size = sizeof(example),
    .sched_flags = 0 | SCHED_FLAG_DL_OVERRUN,
    .sched_policy = SCHED_DEADLINE,
    .sched_runtime = 10 * NSEC_PER_MSEC,    // 10ms
    .sched_period = 20 * NSEC_PER_MSEC,     // 20ms
    .sched_deadline = 11 * NSEC_PER_MSEC    // 11ms
};