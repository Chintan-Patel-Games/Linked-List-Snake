#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"

namespace LinkedList
{
	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Player::Direction default_direction;

		Node* createNode();
		sf::Vector2i getNewNodePosition(Node* reference_node);

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void render();

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