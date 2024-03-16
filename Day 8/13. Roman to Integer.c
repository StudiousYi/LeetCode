int romanToInt(char* s) {
    int num = 0;
    char* nextPtr = s;
    while(*s != NULL) {
        switch(*s) {
            case 'I':
                nextPtr++;
                if(*nextPtr == 'V') {
                    num += 4;
                    s++;
                }
                else if(*nextPtr == 'X') {
                    num += 9;
                    s++;
                }
                else {
                    num += 1;
                }
                break;
            case 'V':
                num += 5;
                break;
            case 'X':
                nextPtr++;
                if(*nextPtr == 'L') {
                    num += 40;
                    s++;
                }
                else if(*nextPtr == 'C') {
                    num += 90;
                    s++;
                }
                else {
                    num += 10;
                }
                break;
            case 'L':
                num += 50;
                break;
            case 'C':
                nextPtr++;
                if(*nextPtr == 'D') {
                    num += 400;
                    s++;
                }
                else if(*nextPtr == 'M') {
                    num += 900;
                    s++;
                }
                else {
                    num += 100;
                }
                break;
            case 'D':
                num += 500;
                break;
            case 'M':
                num += 1000;
                break;
            default:
                printf("error: invalid Roman Letter\n");
                break;
        }
        s++;
        nextPtr = s;
    }
    return num;
}