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
#include "TrieNode.h"

TreeTrieNode::TreeTrieNode(std::string value) {
	_wordRemainder = value;

	for (int i = 0; i < trieNodeCharSize; i++) {
		_children[i] = nullptr;
	}
}

std::string TreeTrieNode::getWordRemainder() {
	return _wordRemainder;
}

bool TreeTrieNode::isWord() const {
	return _isWord;
}

void TreeTrieNode::setIsWord(bool isWord) {
	_isWord = isWord;
}

TreeTrieNode* TreeTrieNode::getParent() {
	return _parent;
}

void TreeTrieNode::setParent(TreeTrieNode* parent) {
	_parent = parent;
}

TreeTrieNode* TreeTrieNode::getChild(int index) {
	return *(_children + index);
}

void TreeTrieNode::setChild(int index, TreeTrieNode* child) {
	*(_children + index) = child;
}

TreeTrieNodeGraphicsCoordinates*& TreeTrieNode::guiParams() {
	return _guiParams;
}

int TreeTrieNode::countChildren() {
	int count = 0;

	for (int i = 0; i < trieNodeCharSize; i++) {
		TreeTrieNode* child = *(_children + i);

		if (child != nullptr) {
			count++;
		}
	}

	return count;
}
