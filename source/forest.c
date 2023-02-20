 #include "forest.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>


/// @todo private header


/// @todo Тип/идентификатор
static sIForestTree *trees[ 3 ][ 3 ] = { 0 };

typedef struct sForestNode
{
    struct sForestNode *mpLeft;
    struct sForestNode *mpRight;
    forestData_t mData;
} sForestNode;


struct sIForestTree
{
    /// @todo general interface
    forestStatusCode_t ( *insert )( sForestNode *node, const forestData_t * const restrict data );

    /// @todo magic num for assert...
    uint32_t SIGNATURE; /// @todo Настраиваемый параметр?
    eForestTreeType mType;
    size_t mId;

    size_t mSize;

    sForestNode *mpHeader;
};



typedef struct
{
    sIForestTree mIface;
} sBST;


forestStatusCode_t bstInsert( sForestNode *node, const forestData_t * const restrict data )
{

}


sIForestTree *forestMakeTree( eForestTreeType type )
{
    sIForestTree * userTree = NULL;
    switch( type )
    {
    case FOREST_TYPE_BST:

        break;

    case FOREST_TYPE_RBT:

        break;

    default:
        /// @todo error!
        break;
    }

    /// @todo normal make tree..
    userTree = malloc( sizeof( sBST ) );
    userTree->mId = 0;
    userTree->mType = FOREST_TYPE_BST;
    userTree->SIGNATURE = 0xDEADBEEF;
    userTree->mSize = 0;
    userTree->mpHeader = malloc( sizeof( sForestNode ) );
    userTree->mpHeader->mpLeft = userTree->mpHeader->mpRight = NULL;
    memset( &userTree->mpHeader->mData, 0, sizeof( forestData_t ) );

    userTree->insert = bstInsert;

    return userTree;
}





forestStatusCode_t insert( sIForestTree *tree,
                           const forestData_t * const restrict data )
{
    tree->insert( tree->mpHeader, data );
    return 0;
}




