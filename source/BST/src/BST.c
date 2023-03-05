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

/// @todo equal function for user defined types

sForestNode *bstSearch( sForestNode *node, const forestData_t * data )
{
    sForestNode *result = node;
    while( NULL != result && *data != result->mData )
    {
        result = result->mData > *data ? result->mpRight : result->mpLeft;
    }
    return result;
}

sForestNode *bstMin( sForestNode *node )
{
    /// @todo check node = NULL
    sForestNode *result = node;
    for( ;result->mpLeft; result = result->mpLeft )
        ;

    return result;
}

sForestNode *bstMax( sForestNode *node )
{
    /// @todo check node = NULL
    sForestNode *result = node;
    for( ;result->mpLeft; result = result->mpRight )
        ;

    return result;
}

sForestNode *bstNextNode( sForestNode *node )
{

}

sForestNode *bstPrevNode( sForestNode *node )
{

}

 /// @todo foo checking..
 /// @todo foo ret val checking??
forestStatusCode_t bstPreorder( sForestNode *node, treeFoo foo )
{
    if( NULL == node )
    {
        return 0;
    }

    foo( &node->mData );
    bstPreorder( node->mpLeft, foo );
    bstPreorder( node->mpRight, foo );
}

forestStatusCode_t bstInorder( sForestNode *node, treeFoo foo )
{
    if( NULL == node )
    {
        return 0;
    }

    bstPreorder( node->mpLeft, foo );
    foo( &node->mData );
    bstPreorder( node->mpRight, foo );
}

forestStatusCode_t bstPostorder( sForestNode *node, treeFoo foo )
{
    if( NULL == node )
    {
        return 0;
    }

    bstPreorder( node->mpLeft, foo );
    bstPreorder( node->mpRight, foo );
    foo( &node->mData );
}

