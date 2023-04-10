#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BinarySearchTree_t
{
    char *word;
    struct BinarySearchTree_t *left;
    struct BinarySearchTree_t *right;
};
typedef struct BinarySearchTree_t BinarySearchTree;

//void dump_tree(BinarySearchTree *root);
char *insertWord(BinarySearchTree **ptree, char *word);

char *insertWord(BinarySearchTree **ptree, char *word)
{
    if (*ptree == NULL)
    {
        BinarySearchTree *tmp = malloc(sizeof(BinarySearchTree));
        tmp->word = strdup(word);
        tmp->left = NULL;
        tmp->right = NULL;
        *ptree = tmp;
        return tmp->word;
    }
    else
    {
        BinarySearchTree *tree = *ptree;
        int r = strcmp(tree->word, word);
        if (r == 0)
        {
            return tree->word;
        }
        else if (r < 0)
            return insertWord(&tree->right, word);
        else
            return insertWord(&tree->left, word);
    }
}
void inorder(BinarySearchTree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s \n", root->word);
        inorder(root->right);
    }
}

int main()
{
    char *word_defs[] = {"catter", "doggy","boxer","foxy"};
    BinarySearchTree *root = 0;

    for (int i = 0; i < sizeof(word_defs) ; i++)
    {
        printf("%zu: Add %s\n", i, word_defs[i]);
        insertWord(&root, word_defs[i]);
                    inorder(root);
    }


    return 0;
}


