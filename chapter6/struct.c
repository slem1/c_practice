#include <stdio.h>
#include <string.h>



struct _key {
    char *word;
    int count;
};

struct point makePoint(int, int);
void countInTab();
struct _key *binsearch(char *word, struct _key tabs[], int n);


struct point {
    int x;
    int y;
};

struct rect {
    struct point a;
    struct point b;
};


struct _key keytabs[] = {
    {"auto", 0},
    {"break", 0},
    {"case", 0},
    {"void", 0}
};

#define NKEYS (sizeof(keytabs) / sizeof(struct _key))

struct _key *binsearch(char *word, struct _key *tabs, int n){

    int lo = 0;
    int hi = n-1;
    int mid;
    int cond;

    while(lo <= hi){
        mid = (lo + hi) / 2;

        if((cond = strcmp(word, tabs[mid].word)) < 0 ){
            hi = mid;
        }else if(cond > 0){
            lo = mid;
        }else {
            return &tabs[mid];
        }
    }

    return NULL;
}

void countInTab(){


    struct _key  *res = binsearch("auto", keytabs, 4);

    if(res != NULL){
        res->count++;
    }

    for (int i =0; i< NKEYS; i++){
        printf("%s=%d\n", keytabs[i].word, keytabs[i].count);
    }

}


int main(int argc, char *argv[]){

    struct point p1 = {12, 15};
    struct point p2 = makePoint(18, 25);

    struct rect r;

    r.a = p1;
    r.b = p2;


    countInTab();

}

struct point makePoint(int x, int y){
    struct point p;
    p.x = x;
    p.y = y;

    return p;
}