# Game Trees and Strategies

A collection of fundamental tree-based algorithms used in game decision-making and problem solving.

## Overview

This project showcases multiple tree search and decision strategies commonly used in games and artificial intelligence, focusing on clarity and educational value.

## Implemented Algorithms

- AND-OR Trees  
  Used for problem-solving scenarios involving combined (AND) and alternative (OR) decisions.

- Minimax  
  Classic algorithm for two-player games, modeling optimal play for both sides.

- Alpha-Beta Pruning  
  Optimization of Minimax that reduces the number of explored nodes.

- Monte Carlo Tree Search (MCTS)  
  Uses random simulations to evaluate decisions in large or uncertain search spaces.

- Behavior Trees  
  Structured approach for decision-making based on sequences and selectors.

## Technologies

- Language: C  
- Concepts: recursion, dynamic memory allocation, tree structures  

## How to Run

Compile each file separately:

```bash
gcc filename.c -o program
./program