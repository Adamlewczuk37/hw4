#ifndef RECCHECK
#include <iostream>
#endif

#include "equal-paths.h"
using namespace std;


bool equalPathsHelper(Node* root, int temp, int depth);
int findDepth(Node* root, int depth);

bool equalPaths(Node * root)
{
    if (root == NULL){
			return true;
		}
		int depth = 0;
    depth = findDepth(root, 0);
    return equalPathsHelper(root, 0, depth);
}

bool equalPathsHelper(Node* root, int temp, int depth){
		if ((root->left == NULL) && (root->right == NULL)){
				if ((temp == depth) || (temp == 1)){
						return true;
        } else {
            return false;
        }
    } else if ((root->left == NULL) && (root->right != NULL)){
			return equalPathsHelper(root->right, temp + 1, depth);
		}  else if ((root->left != NULL) && (root->right == NULL)){
			return equalPathsHelper(root->left, temp + 1, depth);
		}  else {
			return (equalPathsHelper(root->left, temp + 1, depth) && (equalPathsHelper(root->right, temp + 1, depth)));
		}
}

int findDepth(Node* root, int depth){
    if (root->left != NULL){
        findDepth(root->left, depth + 1);
    } else {
			return depth;
		}
		return depth;
}