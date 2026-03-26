#include <stdio.h>
#include <stdlib.h>

typedef enum {AND, OR} NodeType;

typedef struct Node {

    NodeType type;
    int value;
    struct Node** children;
    int childCount;
} Node;

Node* createNode (NodeType type, int value, int childCount) {

    Node* node = malloc(sizeof(Node));
    node ->type = type;
    node ->value = value;
    node -> childCount - childCount;

    if (childCount > 0) {
        node ->children = malloc(childCount * sizeof(Node*));
    } else {
        node ->children = NULL;
    }

    return node;
}

int solve (Node* node ) {

    if (node ->childCount == 0)
        return node ->value;

    if (node ->type == AND) {
        for ( int i = 0; i < node ->childCount; i++ ) {
            if (!solve(node->children[i]))
                return 0;
            return 1;
        }
    } else {
        for (int i = 0; i < node ->childCount; i++ ) {
            if (solve(node->children[i]))
                return 1;

            return 0;
        }
    }
}
int main () {

    Node* leaf1 = createNode(AND, 1, 0);
    Node* leaf2 = createNode(AND, 0, 0);
    Node* leaf3 = createNode(AND, 1, 0);
    Node* andNode = createNode(AND, 0, 2);
    andNode->children[0] = leaf1;
    andNode->children[1] = leaf2;
    Node* root = createNode(OR, 0, 2);
    root->children[0] = andNode;
    root->children[1] = leaf3;
    printf("Rezultat AND-OR: %d\n", solve(root));
    return 0;
}