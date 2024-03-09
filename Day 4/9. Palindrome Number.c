bool isPalindrome(int x) {
    //negative num is always false
    if(x < 0) {
        return false;
    }
    int numOfDigit=0;
    int temp = x;
    int firstHalf;
    int secondHalf;

    //count the number of digits
    while(temp > 0) {
        temp /= 10;
        numOfDigit++;
    }
    printf("number of digit is %d\n",numOfDigit);

    //split x into 2 halves
    firstHalf = x / pow(10,numOfDigit/2);
    secondHalf = x - firstHalf * pow(10,numOfDigit/2);
    if(numOfDigit % 2 == 1){    //if odd number of digits   e.g. 27472  //get rid of the '4' in firstHalf
        firstHalf /= 10;
    }
    printf("firstHalf is %d, secondHalf is %d\n", firstHalf, secondHalf);

    //reverse 2nd half
    int reversedSecondHalf=0;
    int remainder;
    while (secondHalf != 0){
        remainder = secondHalf % 10;
        reversedSecondHalf = reversedSecondHalf * 10 + remainder;
        secondHalf /= 10;
    }
    int numOfDigitForFirst = 0;
    int numOfDigitForSecond = 0;
    int temp2=firstHalf;
    int temp3=reversedSecondHalf;
    while(temp2 > 0) {
        temp2 /= 10;
        numOfDigitForFirst++;
    }
    while(temp3 > 0) {
        temp3 /= 10;
        numOfDigitForSecond++;
    }
    printf("1st half has %d digits, 2nd half has %d digits\n", numOfDigitForFirst, numOfDigitForSecond);
    if(numOfDigitForFirst > numOfDigitForSecond) {
        reversedSecondHalf = reversedSecondHalf * pow(10,numOfDigitForFirst - numOfDigitForSecond);
    }
    printf("reversed 2nd half is %d\n", reversedSecondHalf);

    //compare 1st half against reversed 2nd half
    for(int i=0; i<numOfDigit/2; i++) {
        // if (firstHalf % 10 == 0) {
        //     reversedSecondHalf /= 10;
        //     continue;
        // }
        if (firstHalf % 10 == reversedSecondHalf % 10) {
            firstHalf /= 10;
            reversedSecondHalf /= 10;
        }
        else{
            return false;
        }
    }
    return true;
}