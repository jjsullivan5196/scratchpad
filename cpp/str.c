// alpha: translate alphabetic chars on input into ASCII-type art
// description here: https://open.kattis.com/problems/anewalphabet
int getchar(void);
int putchar(int);
int printf(const char*, ...);
typedef char* str;

// Our 'alphabet', just a pointer to one big string with nulls
// separating the letters
const str alpha = "@\08\0(\0|)\0003\0#\0006\0[-]\0|\0_|\0|<\0001\0[]\\/[]\0[]\\[]\0000\0|D\0(,)\0|Z\0$\0']['\0|_|\0\\/\0\\/\\/\0}{\0`/\0002";

// Get pointer to Nth letter in alphabet
static inline str ptr(const int n) {
    str p = (str)alpha;
    // Basically run strlen to get to the end of n strings
    // p will point to the first char in the letter
    for(int i = 0; i < n; i++) while(*p++);
    return p;
}

int main() {
    int c = 0;
    // While we have chars to read
    while((c = getchar()) > 0) {
       // Not an alphabet character, let it thru
       if(c < 65 || c > 122 || (c >= 91 && c <= 96))
        putchar(c);
       // This is an alphabet character, translate
       else
        printf(ptr(c < 97 ? c - 65 : c - 97));
    }
}
