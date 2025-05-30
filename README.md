# 🐍 Linked List Snake

A console-based version of the classic **Snake** game implemented in C++. This project uniquely integrates **Linked List** and **Doubly Linked List** data structures to represent the snake and simulate operations based on the food it consumes.

## 🎮 Gameplay Features

- Console-based interface with keyboard input
- Classic snake movement and growth
- Different food types trigger unique linked list operations
- Game over on self-collision

## 🧠 Data Structures in Action

This project uses:

- The snake body is managed using a **Singly Linked List** or a **Doubly Linked List**, based on the selected branch, with food items triggering corresponding operations.
- **Food-triggered behaviors**:
  - 🍔 Burger - Insert at head
  - 🧀 Cheese - Insert in middle
  - 🍕 Pizza - Insert at tail
  - 🍎 Apple - Delete at head
  - 🥭 Mango - Delete at middle
  - 🍊 Orange - Delete at tail
  - ☠️ Poison - Delete half nodes
  - 🍷 Alcohol - Reverse Direction

- Each food item maps to a specific **linked list operation**, turning gameplay into a fun data structure demo.

## 🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- SFML

## 🚀 How to Run

  ### Steps

  ```bash
  git clone https://github.com/Chintan-Patel-Games/Linked-List-Snake.git
  ```
  
  - Run the game

## 📚 Concepts Demonstrated

- Singly and Doubly Linked Lists
- Dynamic memory management
- Collision detection
- Input handling and game loop structure
- Encapsulation and modular design using C++
