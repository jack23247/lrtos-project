pb_byte_t recvBuf[20], tmpBuf[20];
int bytesRead = 0, bytesReadTotal = 0, lastBytesRead = 0, bytesMissing;
for(;;) {
    bytesMissing = 20 - bytesRead; 
    /* Read a set amount of bytes from Otto
     * into the receiving buffer. */
    bytesRead = read_from_otto(bytesMissing, recvBuf);
    bytesReadTotal += bytesRead;
    if (bytesRead < 20) {
        for (int i = 0; i < bytesRead; i++)
            tmpBuf[lastBytesRead + i] = recvBuf[i];
        lastBytesRead += bytesRead;
    }
    if (bytesReadTotal == 20) {
        if (lastBytesRead) {
            /* The message in the temporary buffer 
             * can be deserialized. */
        } else {
            /* The message in the receiving buffer 
             * can be deserialized. */
        }
        /* After the message has been deserialized,
         * the counters can be cleared. */
        bytesReadTotal = 0;
        lastBytesRead = 0;
    }
    sched_yield();
}