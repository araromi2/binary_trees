#include "binary_trees.h"
void print_level(const binary_tree_t *tree, int level, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
		print_level(tree, i, func);
}

/**
 * print_level - Prints a level of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @level: Level to print
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 0)
		func(tree->n);

	else if (level > 0)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree. If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	return (right_height + 1);
}
