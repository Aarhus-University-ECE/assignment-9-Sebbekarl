/*
 * Search an expression using DFS.
 */

#include <stdio.h>  /* scanf, printf */
#include <stdlib.h> /* abort */
#include <assert.h>
#include <stdbool.h> /* bool, true, false */
#include "dfs.h"

void DFT(node *root)
{
  /* creates a stack to store the nodes to traverse the tree in the correct order */
  stack *node_stack = (stack *)malloc(sizeof(stack));
  node_stack->next = NULL;

  /* put root in the stack to start traversal */
  push(node_stack, root);

  /* loops as long as there are more nodes in the stack */
  while (!isEmpty(node_stack))
  {
    /* gets node, set visited to true and prints the value */
    node *temp = pop(node_stack)->node;
    temp->visited = true;
    printf("%d, ", temp->num);

    /* checks if the node has children and if so pushes them to the stack */
    if (temp->rchild != NULL)
      push(node_stack, temp->rchild);

    if (temp->lchild != NULL)
      push(node_stack, temp->lchild);
  }

  printf("\n");
}

node *make_node(int num, node *left, node *right)
{
  /* allocates memory for new node and initializes it values and returns the pointer */
  node *new_node = (node *)malloc(sizeof(node));
  new_node->lchild = left;
  new_node->rchild = right;
  new_node->visited = false;
  new_node->num = num;
  return new_node;
}

void free_node(node *p)
{
}

void print_node(node *p)
{

  if (p == NULL)
    printf("NULL\n");
  else
    printf("%d", p->num);
}

void print_tree(node *p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf(" ");
  printf("| ");

  if (p == NULL)
    printf("NULL\n");
  else
    printf("[%d]\n", p->num);

  if (p->lchild)
  {
    print_tree(p->lchild, depth + 1);
  }

  if (p->rchild)
    print_tree(p->rchild, depth + 1);
}

stack *push(stack *topp, node *node)
{
  stack *new_node = (stack *)malloc(sizeof(stack)); // allocates memory for a new node
  new_node->node = node;
  new_node->next = topp->next; // sets next of the new node to the current head
  topp->next = new_node;       // changes the head to the new node so that it's on top
}

bool isEmpty(stack *topp)
{
  return topp->next == NULL;
}

node *top(stack *topp)
{
  return 0;
}

// Utility function to pop topp
// element from the stack

stack *pop(stack *topp)
{
  assert(topp->next != NULL);    // assert to make sure there's something to pull out of the stack
  stack *data = topp->next;      // get the data that need to be returned
  topp->next = topp->next->next; // sets the head to the nex element in the stack
  return data;
}

void print_stack(stack *topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
  {

    print_node(temp->node);
    printf("\n");

    temp = temp->next;
  }

  printf("====\n");

  return;
}
