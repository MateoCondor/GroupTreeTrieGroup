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
#include "Trie.h"
#include <iostream>
#include <algorithm>

TreeTrieNode* TreeTrie::root() {
	return rootP;
}

void TreeTrie::insert(std::string value) {
	value = transformValue(value);

	if (value.empty()) {
		return;
	}

	if (rootP == nullptr) {
		rootP = new TreeTrieNode("");
		rootP->guiParams()->x(trieNewNodeX);
		rootP->guiParams()->y(trieNewNodeY);
		resize();
	}

	insertRecursive(value, rootP);
}

void TreeTrie::insertRecursive(std::string value, TreeTrieNode* node) {
	if (value.length() == 0) {
		node->setIsWord(true);
		return;
	}

	int index = value[0] - 'A';

	if (node->getChild(index) == nullptr) {
		TreeTrieNode* trieNode = new TreeTrieNode(std::string(1, value[0]));
		trieNode->guiParams()->x(trieNewNodeX);
		trieNode->guiParams()->y(trieNewNodeY);
		node->setChild(index, trieNode);
		node->getChild(index)->setParent(node);
		resize();
	}

	insertRecursive(value.substr(1), node->getChild(index));
}

void TreeTrie::remove(std::string value) {
	std::string sanitized = transformValue(value);
	
	if (sanitized.empty()) {
		return;
	}

	TreeTrieNode* node = findRecursive(sanitized, rootP);

	if (node != nullptr) {
		node->setIsWord(false);
		cleanup(node);
		resize();
	}
}

void TreeTrie::cleanup(TreeTrieNode* node) {
	int children = numChildren(node);
	
	if (children == 0 && !node->isWord()) {
		if (node->getParent() != nullptr) {
			int index = 0;
			
			while (node->getParent()->getChild(index) != node) {
				index++;
			}

			node->getParent()->setChild(index, nullptr);
			cleanup(node->getParent());
		}
	} else {
		//_root = nullptr;
	}
}

TreeTrieNode* TreeTrie::find(std::string value) {
	return findRecursive(transformValue(value), rootP);
}

TreeTrieNode* TreeTrie::findRecursive(std::string value, TreeTrieNode* root) // pregunta 
{
	value = transformValue(value);
	
	if (root == nullptr) {
		return nullptr;
	}

	if (value.empty()) {
		if (root->isWord()) {
			return root;
		} else {
			return nullptr;
		}
	} else {
		int index = value[0] - 'A';
		
		if (root->getChild(index) == nullptr) {
			return nullptr;
		}

		return findRecursive(value.substr(1), root->getChild(index));
	}

	return nullptr;
}

std::string TreeTrie::transformValue(std::string value) {
	std::string sanitized;
	
	std::transform(value.begin(), value.end(), value.begin(), ::toupper); //pregunta 
	
	for (char c : value) {
		if (::isalpha(c)) {
			sanitized += c;
		}
	}
	
	return sanitized;
}

void TreeTrie::resize() { //pregunta 
	resizeWidths(rootP);
	
	if (rootP != nullptr) {
		int startingPoint = rootP->guiParams()->width() / 2 + 1 + 300;
		setNewPositions(rootP, startingPoint, trieStartingY);
	}
}

void TreeTrie::setNewPositions(TreeTrieNode* node, int x, int y) {
	if (node != nullptr) {
		node->guiParams()->x(x);
		node->guiParams()->y(y);
		
		int newX = x - node->guiParams()->width() / 2;
		int newY = y + trieHeightSeparation;

		for (int i = 0; i < trieNodeCharSize; i++) {
			TreeTrieNode* child = node->getChild(i);

			if (child != nullptr) {
				setNewPositions(child, newX + child->guiParams()->width() / 2, newY);
				newX = newX + child->guiParams()->width();
			}
		}
	}
}

int TreeTrie::numChildren(TreeTrieNode* node) {
	if (node == nullptr) {
		return 0;
	}
	
	int children = 0;
	
	for (int i = 0; i < trieNodeCharSize; i++) {
		if (node->getChild(i) != nullptr) {
			children++;
		}
	}

	return children;
}

int TreeTrie::resizeWidths(TreeTrieNode* node) {
	if (node == nullptr) {
		return 0;
	}

	int size = 0;

	for (int i = 0; i < trieNodeCharSize; i++) {
		TreeTrieNode* child = node->getChild(i);
		int width = resizeWidths(child);
		
		node->guiParams()->setChildWidth(i, width);
		size += width;
	}

	int fixedSize = (std::max)(size, trieNodeWidth + 4); //pregunta 
	node->guiParams()->width(fixedSize);

	return fixedSize;
}
