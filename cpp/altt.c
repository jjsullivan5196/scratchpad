int getchar(void);int putchar(int);int printf(const char*,...);const char*alpha[]={"@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]","[]\\[]","0","|D","(,)","|Z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"};int main(){int c=getchar();do{if(c<65||c>122||(c>=91&&c<=96))putchar(c);else printf(alpha[c<97 ? c-65 : c-97]);}while((c=getchar())>0);}