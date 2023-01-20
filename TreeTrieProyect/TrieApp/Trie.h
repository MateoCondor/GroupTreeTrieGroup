/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
		INGENIERA DE SOFTWARE

	AUTORES:
		Mateo Javier Condor Sosa
		Luis Ariel Burbano Pacheco
		Susana Camila Morales Noroña
	FECHA DE CREACION:
		06/01/20223
	FECHA DE MODIFICACION:
		17/01/2023
*/
#pragma once
#include "TrieNode.h"
#include <string>

#define trieStartingY 100
#define trieNodeWidth 70
#define trieNewNodeX 100
#define trieNewNodeY 50
#define trieWidthSeparation 50
#define trieHeightSeparation 60

class TreeTrie {

public:
	void insert(std::string value);
	void remove(std::string value);
	TreeTrieNode* find(std::string value);
	TreeTrieNode* root();
	
private:
	void insertRecursive(std::string value, TreeTrieNode* node);
	TreeTrieNode* findRecursive(std::string value, TreeTrieNode* root);
	std::string transformValue(std::string value);
	void cleanup(TreeTrieNode* node);
	void resize();
	int numChildren(TreeTrieNode* node);
	void setNewPositions(TreeTrieNode* node, int x, int y);
	int resizeWidths(TreeTrieNode* node);
	TreeTrieNode* rootP = nullptr;
};
