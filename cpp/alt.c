// alpha: translate alphabetic chars on input into ASCII-type art
// description here: https://open.kattis.com/problems/anewalphabet
int getchar(void);
int putchar(int);
int printf(const char*, ...);

// Our 'alphabet'
const char* alpha[] = {"@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|Z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"};

int main() {
    int c = getchar();
    // While we have chars to read
    do {
       // Not an alphabet character, let it thru
       if(c < 65 || c > 122 || (c >= 91 && c <= 96))
        putchar(c);
       // This is an alphabet character, translate
       else
        printf(alpha[c < 97 ? c - 65 : c - 97]);
    } while((c = getchar()) > 0);
}
