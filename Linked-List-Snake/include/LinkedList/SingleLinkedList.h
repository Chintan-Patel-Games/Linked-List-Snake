#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"

namespace LinkedList
{
	enum class Operation { HEAD,MID,TAIL };

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;
		int linked_list_size;

		sf::Vector2i default_position;
		Player::Direction default_direction;

		Node* createNode();
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();

		void insertNodeAtHead();
		void insertNodeAtIndex(int index);
		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		void insertNodeAtTail();

		void removeNodeAtHead();
		void removeAllNodes();

		void updateNodeDirection(Player::Direction direction_to_set);
		void updateNodePosition();

		bool processNodeCollision();
		Node* getHeadNode();

		std::vector<sf::Vector2i> getNodesPositionList();
	};
}