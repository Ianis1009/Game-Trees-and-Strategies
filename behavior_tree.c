#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {ACTION, SEQUENCE, SELECTOR} NodeType;

typedef struct Node {

    NodeType type;
    int (* action) (void);
    struct Node** children;
    int childCount;
} Node;

Node* createNode (NodeType type, int (*action)(void), int childCount) {

    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->action = action;
    node->childCount = childCount;

    if (childCount > 0)
        node ->children = malloc(childCount * sizeof(Node*));
    else
        node ->children = NULL;

    return node;
}

int actionA () {

    printf(" A ");
    return 1;
}

int actionB () {

    printf(" B ");
    return 0;
}

int actionC () {

    printf(" C ");
    return 1;
}

int Tree (Node * node) {

    if (node->type == ACTION) {
        return node ->action();
    }

    if (node->type == SEQUENCE) {
        for ( int i = 0; i < node ->childCount; i++ ) {
            if (!Tree(node->children[i]))
                return 0;
        }

        return 1;
    } else {

        for ( int i = 0; i < node ->childCount; i++ ) {
            if (Tree(node->children[i]))
                return 1;

            return 0;
        }
    }
}

int main () {

    Node* seq = createNode(SEQUENCE, NULL, 2);
    seq->children[0] = createNode(ACTION, actionA, 0);
    seq->children[1] = createNode(ACTION, actionB, 0);

    Node* root = createNode(SELECTOR, NULL, 2);
    root->children[0] = seq;
    root->children[1] = createNode(ACTION, actionC, 0);

    printf("Running Behavior Tree:\n");
    int result = Tree(root);
    printf("Result: %d\n", result);
    
    return 0;
}