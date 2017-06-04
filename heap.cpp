#include <iostream>
#include "heap.h"

/*
heap->Elem[0] is remained empty.
*/

namespace ubike{

	void Insert(HeapType* heapPtr, BikePtr newBike){
		try{
			if(heapPtr->Number == 255)
				throw "Heap is full.";

			heapPtr->Number ++;

			int currentIdx = Number;
			// Swap child with its parent if child has higher priority.
			while(currentIdx != 1 && (heapPtr->Elem[currentIdx/2])->Mileage < newBike->Mileage){
				heapPtr->Elem[currentIdx] = heapPtr->Elem[currentIdx/2];
				currentIdx /= 2;
			}
			heapPtr->Elem[currentIdx] = newBike;
		}
		catch(const char* err){ std::cout << err << std:endl; }
	}

	bool IsEmpty(HeapType* heapPtr){ return heapPtr->Number == 0; }

	BikePtr Top(HeapType* heapPtr){
		try{
			if(IsEmpty(heapPtr))
				throw "Heap is empty.";
			return heapPtr->Elem[1];
		}
		catch(const char* err){ std::cout << err << std::endl; }
	}

	void RemoveMax(HeapType* heapPtr){
		try{
			if(IsEmpty(heapPtr)){
				throw "Heap is empty.";
			}

			heapPtr->Elem[1] = NULL; // Remove root.
			BikePtr lastBike = heapPtr->Elem[heapPtr->Number];
			heapPtr->Elem[heapPtr->Number] = NULL; // Remove the last element.
			heapPtr->Number --;

			int currentIdx = 1; // Check heap propety from root.
			int child = 2; // Left child of root.

			while(child <= heapPtr->Number){
				// Select the larger child.
				// If both children have same priority, choose left child.
				if(child < heapPtr->Number && (heapPtr->Elem[child])->Mileage < (heapPtr->Elem[child+1])->Mileage)
					child ++;
				// If last element is larger than its children, then leave while loop.
				if(lastBike->Mileage > (heapPtr->Elem[child])->Mileage)
					break;

				// Move the child up.
				heapPtr->Elem[currentIdx] = heapPtr->Elem[child];
				// Go to the next level.
				currentIdx = child;
				child *= 2;
			}

			heapPtr->Elem[currentIdx] = lastBike;
		}
		catch(const char* err){ std::cout << err << std::endl; }
	}

	void Remove(HeapType* heapPtr, BikePtr bike){
		try{
			if(IsEmpty(heapPtr))
				throw "Heap is empty."

			BikePtr lastBike = heapPtr->Elem[heapPtr->Number];
			heapPtr->Number --;

			int currentIdx = bike->cursor;
			int parent = currentIdx / 2; // 
			int child = currentIdx * 2; // Left child of current node.

			// Last element has lower priority than its children.
			if(lastBike->Mileage < (heapPtr->Elem[child])->Mileage || lastBike->Mileage < (heapPtr->Elem[child+1])->Mileage){
				// Bubble down.
				while(child <= heapPtr->Number){
					// Select the larger child.
					// If both children have same priority, choose left one.
					if(child < heapPtr->Number && (heapPtr->Elem[child])->Mileage < (heapPtr->Elem[child+1])->Mileage){
						child ++;
					}
					if(lastBike->Mileage > (heapPtr->Elem[child])->Mileage)
						break;

					// Move the child up.
					heapPtr->Elem[currentIdx] = heapPtr->Elem[child];
					// Go to the next level.
					currentIdx = child;
					child *= 2;
				}
				heapPtr->Elem[currentIdx] = lastBike;
			}
			else if(lastBike->Mileage > (heapPtr->Elem[parent])->Mileage){
				// Bubble up.
				while(parent >= 1){
					// Parent has higher priority.
					if(lastBike->Mileage < (heapPtr->Elem[parent])->Mileage)
						break;

					// Move the parent down.
					heapPtr->Elem[currentIdx] = heapPtr->Elem[parent];
					// Go to the previous level.
					currentIdx = parent;
					parent /= 2;
				}
				heapPtr->Elem[currentIdx] = lastBike;
			}
		}
		catch(const char* err){ std::cout << err << std::endl; }
	}
};