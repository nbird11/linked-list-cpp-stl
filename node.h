/***********************************************************************
 * Header:
 *    NODE
 * Summary:
 *    One node in a linked list (and the functions to support them).
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        Node         : A class representing a Node
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Nathan Bird, Brock Hoskins
 ************************************************************************/

#pragma once

#include <cassert>     // for ASSERT
#include <iostream>    // for NULL

/*************************************************
 * NODE
 * the node class.  Since we do not validate any
 * of the setters, there is no point in making them
 * private.  This is the case because only the
 * List class can make validation decisions
 *************************************************/
template <class T>
class Node
{
public:
   //
   // Construct
   //
   Node() : data(T()), pNext(nullptr), pPrev(nullptr) {}
   Node(const T& data) : data(data), pNext(nullptr), pPrev(nullptr) {}
   Node(T&& data) : data(std::move(data)), pNext(nullptr), pPrev(nullptr) {}

   //
   // Member variables
   //
   T data;               // user data
   Node<T>* pNext;       // pointer to next node
   Node<T>* pPrev;       // pointer to previous node
};

/***********************************************
 * COPY
 * Copy the list from the pSource and return
 * the new list
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
template <class T>
inline Node<T>* copy(const Node<T>* pSource)
{
   if (!pSource)
      return nullptr;

   Node<T>* pDestination = new Node<T>(pSource->data);  // copy (not move)
   const Node<T>* pSrcCur = pSource;
   Node<T>* pDesCur = pDestination;

   for (; pSrcCur->pNext; pSrcCur = pSrcCur->pNext)
      pDesCur = insert(pDesCur, pSrcCur->pNext->data, true /*after*/);

   return pDestination;
}

/***********************************************
 * Assign
 * Copy the values from pSource into pDestination
 * reusing the nodes already created in pDestination if possible.
 *   INPUT  : the list to be copied
 *   OUTPUT : return the new list
 *   COST   : O(n)
 **********************************************/
template <class T>
inline void assign(Node<T>*& pDestination, const Node<T>* pSource)
{
   const Node<T>* pSrcCur = pSource;
   Node<T>* pDesCur = pDestination;
   Node<T>* pDesPrevious = nullptr;

   // Move available src elements into available destination slots
   while (pSrcCur && pDesCur)
   {
      pDesCur->data = pSrcCur->data;
      pDesPrevious = pDesCur;
      pDesCur = pDesCur->pNext;
      pSrcCur = pSrcCur->pNext;
   }

   // Src is longer than the dest
   if (pSrcCur)
   {
      pDesCur = pDesPrevious;

      while (pSrcCur)
      {
         pDesCur = insert(pDesCur, pSrcCur->data, true /*after*/);
         // Make sure if pDestination is null that it is set to point to the head.
         if (!pDestination)
            pDestination = pDesCur;
         pSrcCur = pSrcCur->pNext;
      }
   }
   // Dest is longer than the src
   else if (pDesCur)
   {
      // If we have a previous node, update its next pointer
      if (pDesPrevious)
         pDesPrevious->pNext = nullptr;
      // If we don't have a previous node, we're deleting from the start
      else
         pDestination = nullptr;

      // Delete pDesCur and all nodes after it
      clear(pDesCur);
   }
}


/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(Node<T>*& pLHS, Node<T>*& pRHS)
{
   std::swap(pLHS, pRHS);
}

/***********************************************
 * REMOVE
 * Remove the node pSource in the linked list
 *   INPUT  : the node to be removed
 *   OUTPUT : the pointer to the parent node
 *   COST   : O(1)
 **********************************************/
template <class T>
inline Node<T>* remove(const Node<T>* pRemove)
{
   Node<T>* pReturn = nullptr;

   if (!pRemove)
      return pReturn;

   // Connect neighboring nodes to each other.
   if (pRemove->pPrev)
      pRemove->pPrev->pNext = pRemove->pNext;
   if (pRemove->pNext)
      pRemove->pNext->pPrev = pRemove->pPrev;

   // Return a node next to the removed node, prev over
   //    next according to the pseudocode.
   if (pRemove->pPrev)
      pReturn = pRemove->pPrev;
   else
      pReturn = pRemove->pNext;

   delete pRemove;
   // pRemove is not referenced again, so no need to set it to nullptr.

   return pReturn;
}


/**********************************************
 * INSERT
 * Insert a new node the the value in "t" into a linked
 * list immediately before the current position.
 *   INPUT   : t - the value to be used for the new node
 *             pCurrent - a pointer to the node before which
 *                we will be inserting the new node
 *             after - whether we will be inserting after
 *   OUTPUT  : return the newly inserted item
 *   COST    : O(1)
 **********************************************/
template <class T>
inline Node<T>* insert(Node<T>* pCurrent,
                       const T& t,
                       bool after = false)
{
   Node<T>* pNew = new Node<T>(t);

   if (pCurrent && !after)  // before
   {
      // point new to existing
      pNew->pNext = pCurrent;
      pNew->pPrev = pCurrent->pPrev;

      // point existing to new
      pCurrent->pPrev = pNew;
      if (pNew->pPrev)
         pNew->pPrev->pNext = pNew;
   }
   else if (pCurrent && after)  // after
   {
      // point new to existing
      pNew->pNext = pCurrent->pNext;
      pNew->pPrev = pCurrent;

      // point existing to new
      pCurrent->pNext = pNew;
      if (pNew->pNext)
         pNew->pNext->pPrev = pNew;
   }

   return pNew;
}

/******************************************************
 * SIZE
 * Find the size an unsorted linked list.
 *  INPUT   : a pointer to the head of the linked list
 *  OUTPUT  : number of nodes
 *  COST    : O(n)
 ********************************************************/
template <class T>
inline size_t size(const Node<T>* pHead)
{
   size_t s = 0;
   for (const Node<T>* p = pHead; p; p = p->pNext)
      s++;
   return s;
}

/***********************************************
 * DISPLAY
 * Display all the items in the linked list from here on back
 *    INPUT  : the output stream
 *             pointer to the linked list
 *    OUTPUT : the data from the linked list on the screen
 *    COST   : O(n)
 **********************************************/
template <class T>
inline std::ostream& operator << (std::ostream& out, const Node<T>* pHead)
{
   for (const Node<T>* p = pHead; p; p = p->pNext)
   {
      out << p->data;
      if (p->pNext) out << " -> ";
   }
   return out;
}

/*****************************************************
 * FREE DATA
 * Free all the data currently in the linked list
 *   INPUT   : pointer to the head of the linked list
 *   OUTPUT  : pDestination set to NULL
 *   COST    : O(n)
 ****************************************************/
template <class T>
inline void clear(Node<T>*& pHead)
{
   while (pHead)
   {
      Node<T>* pDelete = pHead;
      pHead = pHead->pNext;
      delete pDelete;
   }
}


