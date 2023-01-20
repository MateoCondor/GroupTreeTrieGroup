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
#include "TrieApp.h"

int TreeTrieGraphic::init()
{
	int left = GetSystemMetrics(SM_CXSCREEN) / 2 - 1100 / 2;
	int top = GetSystemMetrics(SM_CYSCREEN) / 2 - 700 / 2;
	initwindow(1100, 700, "Arbol Trie Proyect", left, top);
	drawTrie(trie.root());
	displayMenu();
	closegraph();
	return 0;
}

void TreeTrieGraphic::drawTrie(TreeTrieNode* root)
{
	if (root == nullptr) {
		return;
	}

	TreeTrieNodeGraphicsCoordinates* graphicsParams = root->guiParams();
	int width = graphicsParams->width();
	int height = trieNodeWidth;
	int nodeX = graphicsParams->x();
	int nodeY = graphicsParams->y();
	int radius = 20;

	for (int i = 0; i < trieNodeCharSize; i++) {
		TreeTrieNode* child = root->getChild(i);

		if (child != nullptr) {
			TreeTrieNodeGraphicsCoordinates* childGuiParams = child->guiParams();
			setcolor(LIGHTRED);
			line(nodeX, nodeY, childGuiParams->x(), childGuiParams->y()); 
		}
	}

	bool isInSearch = false;
	TreeTrieNode* current = lastSearch;

	while (current != nullptr) {
		if (current == root) {
			isInSearch = true;
			break;
		}

		current = current->getParent();
	}

	if (root->isWord()) {
		setcolor(LIGHTRED);
		setfillstyle(SOLID_FILL, LIGHTRED);
	} else {
		setcolor(LIGHTRED);
		setfillstyle(SOLID_FILL, WHITE);
	}

	if (isInSearch) {
		setcolor(LIGHTMAGENTA);
		setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	}

	fillellipse(nodeX, nodeY, radius, radius);

	if (root->isWord()) {
		setcolor(WHITE);
		setbkcolor(LIGHTRED);
	} else {
		setcolor(BLACK);
		setbkcolor(WHITE);
	}

	if (isInSearch) {
		setcolor(WHITE);
		setbkcolor(LIGHTMAGENTA);
	}

	outtextxy(
		nodeX - textwidth((char*)root->getWordRemainder().c_str()) / 2,
		nodeY - radius / 2 + 2,
		(char*)root->getWordRemainder().c_str());

	setcolor(LIGHTRED);
	setbkcolor(BLACK);
	outtextxy(
		nodeX + radius - 12,
		nodeY - radius - 14,
		(char*)root->getWordRemainder().c_str());

	for (int i = 0; i < 26; i++) {
		TreeTrieNode* child = root->getChild(i);
		drawTrie(child);
	}
}

void TreeTrieGraphic::displayMenu()
{
	int option = 0;
	
	while (true) {
		system("cls");
		std::cout << "|----------------------------------------------------------------|" << std::endl;
		std::cout << "|                     .: MENU ARBOL TRIE :.                      |" << std::endl;
		std::cout << "|----------------------------------------------------------------|" << std::endl;
		std::cout << "|                    ~ 1. Insertar palabra ~                     |" << std::endl;
		std::cout << "|                    ~ 2. Buscar palabra ~                       |" << std::endl;
		std::cout << "|                    ~ 3. Eliminar palabra ~                     |" << std::endl;
		std::cout << "|                    ~ 4. Salir ~                                |" << std::endl;
		std::cout << "|----------------------------------------------------------------|" << std::endl;
		option = readInteger("Opcion: ");

		switch (option) {
			case 1: {
				std::string word;
				std::cout << "Ingresa un valor: ";
				std::cin >> word;
				
				
				TreeTrieNode* found = trie.find(word);

				if (found != nullptr) {
					std::cout << "La palabra ya se encuentra en el arbol" << std::endl;
				}
				else {
					std::cout << "Palabra ingresada" << std::endl;
					trie.insert(word);
				}
				
				cleardevice();
				drawTrie(trie.root());
				
				system("pause");
			}
			break;
			case 2: {
				std::string word;
				std::cout << "Ingrese el valor a buscar: ";
				std::cin >> word;
				TreeTrieNode* found = trie.find(word);
				
				if (found != nullptr) {
					std::cout << "Palabra encontrada" << std::endl;
					lastSearch = found;
				} else {
					std::cout << "Palabra no encontrada" << std::endl;
				}
				
				cleardevice();
				drawTrie(trie.root());

				system("pause");

				lastSearch = nullptr;
				cleardevice();
				drawTrie(trie.root());
			}
			break;
			case 3: {
				std::string word;
				std::cout << "Ingrese el valor a eliminar: ";
				std::cin >> word;
				

				TreeTrieNode* found = trie.find(word);

				if (found != nullptr) {
					std::cout << "Palabra eliminada" << std::endl;
					trie.remove(word);
				}
				else {
					std::cout << "La palabra no se encuentra en el arbol" << std::endl;
					
				}

				cleardevice();
				drawTrie(trie.root());
				system("pause");
			}
			break;
			case 4:
				::exit(0);
			break;
		}
	}
}

int TreeTrieGraphic::readInteger(std::string message)
{
	int selected;

	while (true) {
		std::cout << message;
		std::cin >> selected;

		if (std::cin.fail()) {				
			std::cin.clear();				
			std::cin.ignore(9999, '\n');	
			continue;
		}

		break;
	}

	return selected;
}
