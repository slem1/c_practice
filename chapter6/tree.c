#include <stdio.h>
#include <string.h>

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int main()
{

    struct tnode root;
}

struct tnode *allocate()
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *insert(char *word, struct tnode *node)
{

    if (node == NULL)
    {
        node = allocate();
        strcpy(node->word, word);
        node->count = 1;
        node->left = node->right = NULL;
    }
    else if (strcmp(word, node->word) == 0)
    {
        node->count++;
    }
    else if (strcmp(word, node->word) < 0)
    {
        node->left = insert(word, node->left);
    }
    else
    {
        node->right = insert(word, node->right);
    }

    return node;
}

void printTree(struct tnode *node)
{

    if (node == NULL)
    {
        return;
    }
    else
    {
        printTree(node->left);
        printf("value: %s, count %d\n", node->word, node->count);
        printTree(node->right);
    }
}
