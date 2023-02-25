 #include "forest.h"

#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#include "forest_tree_iface.h"

/// @todo Инверсия зависимостей...?
#include "BST.h"

/// @todo private header




sIForestTree *forestMakeTree( eForestTreeType type )
{
    sIForestTree *userTree = NULL;
    switch( type )
    {
    case FOREST_TYPE_BST:
        userTree = bstMakeTree();
        break;
/*
    case FOREST_TYPE_RBT:

        break;
*/
    default:
        /// @todo error!
        break;
    }

    /// @todo normal make tree..

    return userTree;
}





forestStatusCode_t insert( sIForestTree *tree,
                           const forestData_t * const restrict data )
{
    /// @todo check it... ?
    tree->mFunctions.insert( tree->mpHeader, data );
    return 0;
}

forestStatusCode_t delete( sIForestTree *tree,
                           const forestData_t * const restrict data )
{
    tree->mFunctions.delete( tree->mpHeader, data );
    return 0;
}


