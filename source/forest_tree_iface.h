

#ifndef _FOREST_TREE_IFACE_H_
#define _FOREST_TREE_IFACE_H_

#include "forest.h"

typedef struct sForestNode
{
    struct sForestNode *mpLeft;
    struct sForestNode *mpRight;
    forestData_t mData;
} sForestNode;

typedef struct
{
    /// @todo general interface
    forestStatusCode_t ( *insert )( sForestNode *node, const forestData_t * const restrict data );
    forestStatusCode_t ( *delete )( sForestNode *node, const forestData_t * const restrict data );
} sForestIFace;

typedef struct sIForestTree
{
    sForestNode *mpHeader;

    sForestIFace mFunctions;

    /// @todo magic num for assert...
    uint32_t SIGNATURE; /// @todo Настраиваемый параметр?

    /// @todo Нужны?
    eForestTreeType mType;
    size_t mSize;
};

#endif // _FOREST_TREE_IFACE_H_
