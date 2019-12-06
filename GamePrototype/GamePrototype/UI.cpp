#include "UI.h"
UI::UI(float x, float y, int health) {
	switch (health) {
	case 0:
		this->tx.loadFromFile("Assets/UI/3x/hp0.png");
			break;
	case 1:
		this->tx.loadFromFile("Assets/UI/3x/hp1.png");
		break;
	case 2:
		this->tx.loadFromFile("Assets/UI/3x/hp2.png");
		break;
	case 3:
		this->tx.loadFromFile("Assets/UI/3x/hp3.png");
		break;
	default:
			break;
	}
	this->sp.setTexture(tx);
	//this->sp.setOrigin(tx.getSize().x / 2, 0.f);
	this->sp.setPosition(x,y);
}
/*void UI:: drawHP(int health) {
	if (health == 0) {
		tx.loadFromFile("Assets/UI/3x/hp.png");
		sp.setTexture(tx);
	}
	if (health == 1) {
		tx.loadFromFile("Assets/UI/3x/hp1.png");
		sp.setTexture(tx);

	}if (health == 2) {
		tx.loadFromFile("Assets/UI/3x/hp2.png");
		sp.setTexture(tx);
	}
}*/