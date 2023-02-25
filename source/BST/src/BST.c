#include "../../forest.h" /// @todo cmake
#include "BST.h"

#include <stdlib.h>
#include <string.h>

sIForestTree *bstMakeTree( void )
{
    sIForestTree * userTree = NULL;
    userTree = malloc( sizeof( sIForestTree ) );
    userTree->mType = FOREST_TYPE_BST;
    userTree->SIGNATURE = 0xDEADBEEF;
    userTree->mSize = 0;

    userTree->mpHeader = malloc( sizeof( sForestNode ) );
    userTree->mpHeader->mpLeft = userTree->mpHeader->mpRight = NULL;
    memset( &userTree->mpHeader->mData, 0, sizeof( forestData_t ) );

    userTree->mFunctions.insert = bstInsert;
    userTree->mFunctions.delete = bstDelete;

    return userTree;
}

void bstDeleteTree( sIForestTree *tree )
{

}

/// @todo general checking tree's size/signature etc.

forestStatusCode_t bstInsert( sForestNode *node, const forestData_t * const restrict data )
{
    if ( 0 == ( ( sIForestTree* )node )->mSize )
    {
        node->mData = *data;
    }
    /// @todo else find and insert...
}

forestStatusCode_t bstDelete( sForestNode *node, const forestData_t * const restrict data )
{

}


