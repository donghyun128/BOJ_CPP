
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct treeNode
{
    char data;
    struct treeNode* left;
    struct treeNode* right;
};

void visit(struct treeNode* root)
{
    if (root->data != '.')
        printf("%c", root->data);
    else return;
}

void preSearch(struct treeNode* root)
{
    visit(root);
    if (root->left != NULL)
        preSearch(root->left);
    if (root->right != NULL)
        preSearch(root->right);
}

void midSearch(struct treeNode* root)
{
    if (root->left != NULL)
        midSearch(root->left);
    visit(root);
    if (root->right != NULL)
        midSearch(root->right);
}

void postSearch(struct treeNode* root)
{
    if (root->left != NULL)
        postSearch(root->left);
    if (root->right != NULL)
        postSearch(root->right);
    visit(root);
}

struct treeNode* createNode(char data) 
{
    struct treeNode *newNode;
    newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void append_left(struct treeNode* root,struct treeNode* left)
{
    root->left = left;
}
void append_right(struct treeNode* root, struct treeNode* right)
{
    root->right = right;
}

struct treeNode* searchNode(struct treeNode *node, char data)
{
    if (node != NULL)
    {
        if (node->data == data)
            return node;
        else
        {
            if (node->left != NULL)
            {
                treeNode* tmp = searchNode(node->left, data);
                if (tmp != NULL)
                    return tmp;
            }
        }
        if (node->right !=NULL)
            return searchNode(node->right, data);
    }
    return NULL;
}
int main()
{
    int N;
    int cnt = 0;
    struct treeNode* root = createNode('A');
    struct treeNode* tmp = createNode(NULL);
    scanf("%d", &N);
    getchar();
    for(int i=0; i<N; i++)
    {
        char data, l, r;
        scanf("%c %c %c", &data, &l, &r);
        getchar();
        tmp = searchNode(root, data);
        if (tmp == NULL)
        {
            tmp = createNode(data);
        }
        if (l != '.')
            append_left(tmp,createNode(l));
        if (r != '.')
            append_right(tmp,createNode(r));

    }

    preSearch(root); 
    printf("\n");
    midSearch(root);
    printf("\n");
    postSearch(root);
}

