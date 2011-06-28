
//
// ast.c
//
// Copyright (c) 2011 TJ Holowaychuk <tj@vision-media.ca>
//

#include "ast.h"

// TODO: error handling

/*
 * Alloc a luna value and assign the given `node`.
 */

luna_value_t *
luna_node(luna_node_t *node) {
  luna_value_t *self = malloc(sizeof(luna_value_t));
  self->type = LUNA_TYPE_NODE;
  self->value.as_obj = node;
  return self;
}

/*
 * Alloc and initialize a new block node.
 */

luna_block_node_t *
luna_block_node_new() {
  luna_block_node_t *self = malloc(sizeof(luna_block_node_t));
  self->base.type = LUNA_NODE_BLOCK;
  self->stmts = luna_array_new();
  return self;
}

/*
 * Alloc and initialize a new int node with the given `val`.
 */

luna_int_node_t *
luna_int_node_new(int val) {
  luna_int_node_t *self = malloc(sizeof(luna_int_node_t));
  self->base.type = LUNA_NODE_INT;
  self->val = val;
  return self;
}

/*
 * Alloc and initialize a new float node with the given `val`.
 */

luna_float_node_t *
luna_float_node_new(float val) {
  luna_float_node_t *self = malloc(sizeof(luna_float_node_t));
  self->base.type = LUNA_NODE_FLOAT;
  self->val = val;
  return self;
}

/*
 * Alloc and initialize a new id node with the given `val`.
 */

luna_id_node_t *
luna_id_node_new(const char *val) {
  luna_id_node_t *self = malloc(sizeof(luna_id_node_t));
  self->base.type = LUNA_NODE_ID;
  self->val = val;
  return self;
}

/*
 * Alloc and initialize a new string node with the given `val`.
 */

luna_string_node_t *
luna_string_node_new(const char *val) {
  luna_string_node_t *self = malloc(sizeof(luna_string_node_t));
  self->base.type = LUNA_NODE_STRING;
  self->val = val;
  return self;
}

/*
 * Alloc and initialize a unary `op` node with `expr` node.
 */

luna_unary_op_node_t *
luna_unary_op_node_new(luna_token op, luna_node_t *expr) {
  luna_unary_op_node_t *self = malloc(sizeof(luna_unary_op_node_t));
  self->base.type = LUNA_NODE_UNARY_OP;
  self->op = op;
  self->expr = expr;
  return self;
}

/*
 * Alloc and initialize a binary `op` node with `left` and `right` nodes.
 */

luna_binary_op_node_t *
luna_binary_op_node_new(luna_token op, luna_node_t *left, luna_node_t *right) {
  luna_binary_op_node_t *self = malloc(sizeof(luna_binary_op_node_t));
  self->base.type = LUNA_NODE_BINARY_OP;
  self->op = op;
  self->left = left;
  self->right = right;
  return self;
}