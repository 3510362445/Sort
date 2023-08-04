#include<stdio.h>
#include <stdlib.h>
// 二叉树结点的定义
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 创建排序二叉树
void* insertTree(Node*t_node,int val) {
    Node* node = malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    if (t_node==NULL) {
        t_node = node;//创建根节点
    }
    else {
        Node* temp = t_node;
        while (temp != NULL) {
            if (val < temp->data) {
                if (temp->left == NULL)
                    temp->left = node;
                else
                    temp = temp->left;
            }
            else {
                if (temp->right == NULL)
                    temp->right = node;
                else
                    temp = temp->right;
            }
        }
    }
}
//计算树高
int get_height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    else {
        int left_h = get_height(node->left);
        int right_h = get_height(node->right);
        int max = left_h;
        if (max < right_h)
            max = right_h;
        return max + 1;
    }
}
//计算最大值(所有元素为正)  左边最大、右边最大、根节点比较
int get_max(Node*node) {
    if (node == NULL) {
        return -1;
    }
    else {
        int l_max = get_max(node->left);
        int r_max = get_max(node->right);
        int g_max = node->data;
        int max = g_max;
        if (max < l_max) max = l_max;
        if (max < r_max) max = r_max;
        return max;
    }
}

// 先序遍历二叉树
void preorder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);//根 左 右
        preorder(root->left);
        preorder(root->right);
    }
}

// 中序遍历二叉树
void inorder(Node* root) {// 左 根 右
    if (root != NULL) {
        inorderl(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 后序遍历二叉树
void postorder(Node* root) {// 左 右 根
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node* root = createTree();

    printf("先序遍历结果：");
    preorder(root);
    printf("\n");

    printf("中序遍历结果：");
    inorder(root);
    printf("\n");

    printf("后序遍历结果：");
    postorder(root);
    printf("\n");

    return 0;
}
