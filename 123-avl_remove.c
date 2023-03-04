#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			node = root->right;
			free(root);
			return (node);
		}
		else if (!root->right)
		{
			node = root->left;
			free(root);
			return (node);
		}

		node = root->right;
		while (node->left)
			node = node->left;

		root->n = node->n;
		root->right = avl_remove(root->right, node->n);
	}

	return (root);
}
