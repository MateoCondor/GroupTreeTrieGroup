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
//Clase singleton
#pragma once
#include "Trie.h"
#include "graphics.h"
#include <cstdlib>
#include <string>
#include <iostream>

class TreeTrieGraphic {
private:
	TreeTrieGraphic() = default;
	~TreeTrieGraphic() = default;
	
	void drawTrie(TreeTrieNode* root);
	void displayMenu();
	int readInteger(std::string message);
	

	TreeTrie trie;
	TreeTrieNode* lastSearch;

public:
	TreeTrieGraphic(const TreeTrieGraphic&) = delete;
	TreeTrieGraphic& operator = (const TreeTrieGraphic&) = delete;
	
	static TreeTrieGraphic& instance() {
		static TreeTrieGraphic instance;
		return instance;
	}
	int init();
};

