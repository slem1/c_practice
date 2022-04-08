#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct entry *lookup(char *key, struct entry *hashtable[] );
struct entry *put(char *key, char *value, struct entry *hashtable[]);
void printHashTable(struct entry *hashtable[]);
int hash(char *data);

static struct entry *hashtable[101];


struct entry {
    struct entry *next;
    char * key;
    char * value;
};

int main(int argc, char **argv){
  
    put("key1", "value1", hashtable);
    put("key2", "value2", hashtable);
    printHashTable(hashtable);

    put("key1", "value3", hashtable);

    printHashTable(hashtable);
    
}


struct entry *lookup(char *key, struct entry *hashtable[] ){

    int hashcode = hash(key);

    for(struct entry *r = hashtable[hashcode]; r!= NULL; r = r->next){
        if(strcmp(r->key, key) == 0){
            return r;      
        }
    }
    return NULL;
}

struct entry *put(char *key, char *value, struct entry *hashtable[]){

    struct entry *result = lookup(key, hashtable);

    if(result == NULL){
        //create new entry
        result = (struct entry *) malloc(sizeof(struct entry));
        result->key = strdup(key);
        result->value = strdup(value);
        //insert at head
        int h = hash(key);
        result->next = hashtable[h];
        hashtable[h]= result;
    } else {
        free(result->value);
        result->value = strdup(value);
    }
    return result;
}


void printHashTable(struct entry *hashtable[]){
    for(int i = 0; i< HASHSIZE; i++){
        if(hashtable[i] != NULL){
            for(struct entry *e = hashtable[i]; e!= NULL; e = e->next){
                printf("(%s,%s) \n", e->key, e->value);
            }
        }
    }
}

int hash(char *data){
    unsigned hashval;
    for(hashval = 0; *data != '\0'; data++){
        hashval = *data + 31 * HASHSIZE;
    }
    return hashval % HASHSIZE;
}

