 /** ***************************************************************************
 * @file forest.h
 * @brief @todo 
 * Общий файл - интерфейс для доступа к проекту
 * @autor Петров А.С. petrov.sanya1998@yandex.ru
 * ****************************************************************************/

#ifndef _FOREST_H_
#define _FOREST_H_

/// @todo
/* --- GENERAL TODO LIST  ----------------------------------------------------- */
/// @todo some type of exception?
/// @todo need doxy docs
/// @todo need compile time 




/* --- Псевдонимы ----------------------------------------------------------- */

/** ****************************************************************************
* @brief Тип данных для узлов деревьев.
* @typedef forestData_t
* *****************************************************************************/
typedef int forestData_t;

/** ****************************************************************************
* @brief Тип данных для узлов деревьев.
* @typedef forestData_t
* *****************************************************************************/
typedef int forestStatusCode_t;

typedef void ( *forestFunction_f ) ( forestData_t * const restrict data );

typedef struct sIForestTree sIForestTree;

typedef enum eForestTreeType
{
    FOREST_TYPE_BST,
    FOREST_TYPE_RBT
    /// @todo АВЛ дерево 2-3 дерево
} eForestTreeType;

sIForestTree *forestMakeTree( eForestTreeType type );

/// @todo Some type overload?
forestStatusCode_t insert( sIForestTree *tree,
                           const forestData_t * const restrict data );

sIForestTree *forestDeleteTree( void );


#endif // _FOREST_H_
