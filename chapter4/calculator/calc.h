#define NUMBER '0'

int getch();
void ungetch(int c);
int getopt(char s[]);

void push(double v);
double pop();

double atof(char s[]);