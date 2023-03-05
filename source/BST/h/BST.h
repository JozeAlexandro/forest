#ifndef _FOREST_BST_H_
#define _FOREST_BST_H_

#include <stdbool.h>

/// @todo
#include "../../forest_tree_iface.h"

typedef forestStatusCode_t ( treeFoo* )( const forestData_t *data );

sIForestTree *bstMakeTree( void );

void bstDeleteTree( sIForestTree *tree );

forestStatusCode_t bstInsert( sForestNode *node, const forestData_t * const restrict data );
forestStatusCode_t bstDelete( sForestNode *node, const forestData_t * const restrict data );


/// @todo up abstraction foo should'nt proceesing ( give to user ) raw node. Just true/false
sForestNode *bstSearch( sForestNode *node, const forestData_t * data );

/// @brief Finding the minimum element of tree.
/// @todo
sForestNode *bstMin( sForestNode *node );

/// @brief Finding the maximum element of tree.
/// @todo
sForestNode *bstMax( sForestNode *node );


/// @todo THIS STOP!
sForestNode *bstNextNode( sForestNode *node );

sForestNode *bstPrevNode( sForestNode *node );

/// @todo Description

/** ****************************************************************************
 * @brief Traversing the binary search tree in direct order.
 * @details Parent, Left, Right.
 * @param
 * ****************************************************************************/
forestStatusCode_t bstPreorder( sForestNode *node, treeFoo foo );

/** ****************************************************************************
 * @brief Traversing the binary search tree in symmetric order.
 * @details Left, Parent, Right.
 * @param
 * ****************************************************************************/
forestStatusCode_t bstInorder( sForestNode *node, treeFoo foo );

/** ****************************************************************************
 * @brief Traversing the binary search tree in reverse order.
 * @details Right, Parent, Left.
 * @param
 * ****************************************************************************/
forestStatusCode_t bstPostorder( sForestNode *node, treeFoo foo );

#endif // _FOREST_BST_H_
