void dl_miss_handler(int sig) {
    assert(sig != 0);
    // Do something before calling the default handler
    (void)signal(SIGXCPU, SIG_DFL); // Call the default handler
}
