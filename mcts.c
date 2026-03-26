//Monte Carlo Tree Search

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {

    int value;
    struct Node** children;
    int childCount;
    int visits;
    double totalReward;
} Node;

Node* createNode (int childCount) {

    Node* node = malloc(sizeof(Node));
    node ->childCount = childCount;
    node->visits = 0;
    node->totalReward = 0;

    if (childCount > 0) {
        node ->children = malloc(childCount * sizeof(Node*));
    } else {
        node ->children = NULL;
    }

    return node;
}

int rollout  (Node* node ) {

    //random 
    if (node ->childCount == 0)
        return rand() % 10;

    int index = rand () % node ->childCount;
    return rollout(node->children[index]);

}

void propagate (Node* node, int reward) {

    node ->visits++;
    node ->totalReward += reward;
}

void MCTS (Node* root, int iterations ) {

    for (int i = 0; i < iterations; i++ ) {

        Node* node = root;

        while (node ->childCount > 0) {
            int index = rand () % node->childCount;
            node = node ->children[index];
        }

        int rew = rollout(node);
        propagate(node, rew);
    }
}


int main () {

    srand(time(NULL));
    Node* root = createNode(2);
    root->children[0] = createNode(0);
    root->children[1] = createNode(0);
    MCTS(root, 1000);

    printf("Child 0 (avg) reward: %.2f\n",
           root->children[0]->totalReward / (root->children[0]->visits));
    printf("Child 1 (avg) reward: %.2f\n",
           root->children[1]->totalReward / (root->children[1]->visits));

    return 0;
}