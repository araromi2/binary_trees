#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
	      const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	/* Check if one of the nodes is the ancestor of the other */
	if (first == second)
		return ((binary_tree_t *)first);

	/* Check if one of the nodes is the parent of the other */
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (second == first->parent)
		return ((binary_tree_t *)second);

	/* Recursively search in the left and right subtrees */
	return (binary_trees_ancestor(first->parent, second->parent));
}
