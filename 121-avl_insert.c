#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the
 * AVL tree for inserting the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (!tree)
		return (NULL);

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left)
			return (avl_insert(&(*tree)->left, value));

		node = binary_tree_node(*tree, value);
		(*tree)->left = node;
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			return (avl_insert(&(*tree)->right, value));

		node = binary_tree_node(*tree, value);
		(*tree)->right = node;
	}
	else
		return (NULL);

	return (node);
}
