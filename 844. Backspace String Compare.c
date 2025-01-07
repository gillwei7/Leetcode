// s = "ab#c" t = "ad#c"
int nextValidChar(char* sChar, int index) {
    int backspace = 0;
    while(index >= 0) {
        if(sChar[index] != '#' && backspace == 0) {
            break;
        }
        else if (sChar[index] == '#') {
            backspace ++;
        }
        else {
            backspace--;
        }
        index--;
    }
    return index;
}
bool backspaceCompare(char* s, char* t) {
    if(!s && !t)
        return true;
    if(!s || !t)
        return false;
    int indexS = strlen(s)-1; //5
    int indexT = strlen(t)-1;
    while(indexS >= 0 ||  indexT >= 0) {
        printf("indexS:%d indexT:%d\n", indexS, indexT);
        indexS = nextValidChar(s, indexS);
        indexT = nextValidChar(t, indexT);
        char charS = (indexS >= 0)? s[indexS]:'\0';
        char charT = (indexT >= 0)? t[indexT]:'\0';
        if(charS != charT) {
            return false;
        }
        indexS--;
        indexT--;
    }
    return true;
}
