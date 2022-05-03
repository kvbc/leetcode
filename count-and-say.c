// leetcode.com/problems/count-and-say
// 1 <= n <= 30

// O(n)
// assuming the return value is later freed
char* countAndSay (int n) {
    // buflen for n=30 is 4462
    // 4462 / 30 ~= 150
    char *rbuf = malloc(150 * n * sizeof(char)); // read buffer
    char *wbuf = malloc(150 * n * sizeof(char)); // write buffer
    rbuf[0] = '1';
    int buflen = 1;
    
    for (int i = 0; i < n - 1; i++) {
        int count = 0;
        char c = rbuf[0];
        int writetop = 0;
        int len = buflen;
        for (int j = 0; j < len;) {
            while (rbuf[j] == c)
                count++, j++;
            char oldc = c;
            c = rbuf[j];
            wbuf[writetop++] = count + '0';
            wbuf[writetop++] = oldc;
            buflen = writetop;
            count = 0;
        }
        char *buf = wbuf; // swap buffers
        wbuf = rbuf;
        rbuf = buf;
    }
    
    free(wbuf);
    rbuf[buflen] = '\0';
    return rbuf;
}
