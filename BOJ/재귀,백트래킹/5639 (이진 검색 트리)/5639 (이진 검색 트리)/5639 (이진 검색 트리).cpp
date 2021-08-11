// 5639 (이진 검색 트리).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

struct BST
{
    int data;
    struct BST* left;
    struct BST* right;
};

void insertNode(struct BST *root,int data)
{
    struct BST *newNode = (BST*)malloc(sizeof(BST));
    if (root->data > data)
    {
        if (root->left == NULL)
            root->left = newNode;
        else
            insertNode(root->left, data);
    }

    else if (root->data < data)
    {
        if (root->right == NULL)
            root->right = newNode;
        else
            insertNode(root->right, data);
    }
}

pre 

int main()
{
    struct BST *root = (BST*)malloc(sizeof(BST));
    cin >> root->data;
    int num;
    while (1)
    {
        cin >> num;
        insertNode(root, num);
    }
}
