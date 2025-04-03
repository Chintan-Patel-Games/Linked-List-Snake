#pragma once
#include "LinkedListLib/LinkedList.h"

namespace LinkedListLib
{
	namespace DoubleLinked
	{
		class DoubleLinkedList : public LinkedList
		{
		protected:
			virtual Node* createNode() override;

		public:
			DoubleLinkedList();
			~DoubleLinkedList();

			void insertNodeAtHead() override;
			void insertNodeAtTail() override;
			void insertNodeAtMiddle() override;
			void insertNodeAtIndex(int index) override;
			void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

			void removeNodeAtHead() override;
			void removeNodeAtTail() override;
			void removeNodeAtMiddle() override;
			void removeNodeAt(int index) override;
			void removeNodeAtIndex(int index);
			void removeAllNodes() override;
			void removeHalfNodes() override;
			void shiftNodesAfterRemoval(Node* cur_node);

			Direction reverse() override;
		};
	}
}