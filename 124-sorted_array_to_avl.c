#include "binary_trees.h"
avl_t *sorted_array_to_avl_rec(int *array, size_t start, size_t end, avl_t *parent);

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	tree = sorted_array_to_avl_rec(array, 0, size - 1, NULL);
	return (tree);
}

/**
 * sorted_array_to_avl_rec - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @start: Start index of the array
 * @end: End index of the array
 * @parent: Pointer to the parent node of the current node
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl_rec(int *array, size_t start, size_t end, avl_t *parent)
{
	avl_t *node;
	size_t mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = sorted_array_to_avl_rec(array, start, mid - 1, node);
	node->right = sorted_array_to_avl_rec(array, mid + 1, end, node);

	return (node);
}
