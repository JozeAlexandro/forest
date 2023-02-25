#ifndef _BST_H_
#define _BST_H_

/// @todo
#include "../../forest_tree_iface.h"

sIForestTree *bstMakeTree( void );

void bstDeleteTree( sIForestTree *tree );

forestStatusCode_t bstInsert( sForestNode *node, const forestData_t * const restrict data );
forestStatusCode_t bstDelete( sForestNode *node, const forestData_t * const restrict data );



#endif // _BST_H_
