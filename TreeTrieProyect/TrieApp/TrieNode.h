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
#include <string>

#define trieNodeCharSize 26

///////////////////////////////////////////////////////////
//Forma grafica 
//PARAMETROS PARA REALIZAR LA GRAFICA 
//TENEMOS LAS COORDENADAS y PARAMETROS
/////////////////////////////////////////////////////////

class TreeTrieNodeGraphicsCoordinates {

private:
	int _x = 0;
	int _y = 0;
	int _width = 0;
	int* _childWidths = new int[trieNodeCharSize];

public:
	TreeTrieNodeGraphicsCoordinates(int x = 0, int y = 0, int width = 0) {
		_childWidths = new int[trieNodeCharSize];
		_x = x;
		_y = y;
		_width = width;

		for (int i = 0; i < trieNodeCharSize; i++) {
			*(_childWidths + i) = 0;
		}
	}

	void x(int x) {
		_x = x;
	}

	void y(int y) {
		_y = y;
	}

	void width(int width) {
		_width = width;
	}

	int x() const {
		return _x;
	}

	int y() const {
		return _y;
	}

	int width() const {
		return _width;
	}

	int getChildWidth(int index) const {
		return *(_childWidths + index);
	}

	void setChildWidth(int index, int width) {
		*(_childWidths + index) = width;
	}

};

class TreeTrieNode {
private:
	std::string _wordRemainder;
	bool _isWord;
	TreeTrieNode* _parent = nullptr;
	TreeTrieNode* _children[trieNodeCharSize];
	TreeTrieNodeGraphicsCoordinates* _guiParams = new TreeTrieNodeGraphicsCoordinates();
	
public:
	TreeTrieNode(std::string value);
	std::string getWordRemainder();
	bool isWord() const;
	void setIsWord(bool isWord);
	TreeTrieNode* getParent();
	void setParent(TreeTrieNode* parent);
	TreeTrieNode* getChild(int index);
	void setChild(int index, TreeTrieNode* child);
	TreeTrieNodeGraphicsCoordinates*& guiParams();
	int countChildren();


};




