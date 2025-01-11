int hammingWeight(int n) {
    if(n == 0)
        return 0;
    int current = n;
    int result = 0;
    while(current > 0){
        if(current%2 == 1){
            result ++;
        }
        current = current / 2;
    }
    return result;
}
