// alpha: translate alphabetic chars on input into ASCII-type art
// description here: https://open.kattis.com/problems/anewalphabet
int getchar(void);
int putchar(int);
int printf(const char*, ...);
typedef unsigned char byte;
typedef unsigned char* string;

const string arr[26] = {
    "@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", 
    "0", "|D", "(,)", "|Z", "$", "']['", "|_|", "\\/", "\\/\\/", "}{", "`/", "2"
};

int main() {
    int c;
    while((c = getchar()) > 0) {
        if(c >= 65 && c <= 122 && (c < 91 || c > 96))
        {
            printf(arr[(c < 97 ? c - 65 : c - 97)]);
        }
        else
        {
            putchar(c);
        }
    }
}
