#ifndef _HEAP_H_
#define _HEAP_H_

#include "datatype.h"

namespace ubike{
	/// @brief Add new node to heap.
	/// @param heapPtr  Pointer to a heap.
	/// @param newBike  Pointer to a bike, which is to be added to heap.
	void Insert(HeapType* heapPtr, BikePtr newBike);

	/// @Check if heap is empty.
	bool IsEmpty(HeapType* heapPtr);

	/// @brief Return the max element.
	BikePtr Top(HeapType* heapPtr);

	/// @brief Delete element with max priority.
	void RemoveMax(HeapType* heapPtr);

	/// @brief Remove certain node in heap.
	void Remove(HeapType* heapPtr, BikePtr bike);
};

#endif // _HEAP_H_