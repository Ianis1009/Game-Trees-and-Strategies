#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {

    int value;
    struct Node** children;
    int childCount;
} Node;

Node* createNode ( int value, int childCount ) {

    Node* node = malloc(sizeof(Node));
    node ->value = value;
    node ->childCount = childCount;

    if (childCount > 0)
        node ->children = malloc(childCount * sizeof (Node*));
    else
        node ->children = NULL;

    return node;
}

int minimax (Node* node, int isMax) {

    if (node ->childCount == 0) {
        return node ->value;
    }

    if (isMax) {
        int best = INT_MIN;
        for (int i = 0; i < node ->childCount; i++ ) {
            int val = minimax(node->children[i], 0);
            if (val > best) {
                best = val;
            }
            
        }

        return best;
       
    }  else {
            int best = INT_MAX;
            for (int i = 0; i < node->childCount; i++ ) {

                int val = minimax(node->children[i], 1);
                if (val < best) {
                    best = val;
                }
            }

            return best;
        }
}
int main () {

    Node* n1 = createNode(3, 0);
    Node* n2 = createNode(5, 0);
    Node* n3 = createNode(2, 0);
    Node* n4 = createNode(9, 0);
    Node* min1 = createNode(0, 2);
    min1->children[0] = n1;
    min1->children[1] = n2;
    Node* min2 = createNode(0, 2);
    min2->children[0] = n3;
    min2->children[1] = n4;
    Node* root = createNode(0, 2);
    root->children[0] = min1;
    root->children[1] = min2;

    printf("Rezultat Minimax: %d\n", minimax(root, 1));
    return 0;
}