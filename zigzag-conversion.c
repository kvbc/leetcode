// leetcode.com/problems/zigzag-conversion

char* convert(char *s, int numRows) {
    int slen = strlen(s);
    char *rs = malloc((slen + 1) * sizeof(char)); // result string
    rs[slen] = '\0';
    
    if (numRows == 1) {
        strncpy(rs, s, slen);
        return rs;
    }
    
    int ri = 0; // rs idx
    int si = 0; // s idx
    int y = 1;
    int r = 1; // row
    for (int i = 0; ri < slen;) {
        rs[ri++] = s[i];
        if (y == numRows) i +=  numRows * 2 - 2; // integrate into the expression below?
        else              i += (numRows * 2) - (y * 2);
        if (i >= slen) {
            i = ++si;
            y = ++r;
            continue;
        }
        if (y > 1)
        if (y < numRows)
            y = numRows - y + 1;
    }
    
    return rs;
}
