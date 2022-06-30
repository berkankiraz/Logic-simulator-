#pragma once
#include <SFML/Graphics.hpp>
#define MAX_CONNECTIONS 32
#include <iostream>
#include<vector>



class Object {
public:
	friend class Simulator;
	Object* next = nullptr;
	bool locked = true;
	sf::RenderWindow* window = nullptr;
	sf::Texture textures[2];
	sf::Sprite sprite;
	bool state = true;
	bool selected = false;
	Object(sf::Texture t[2], sf::Sprite s);
	Object();
	inline static std::vector<sf::Sprite> new_sprites_vec;

};



class Pin {
public:
	enum class pinType { INPUT, OUTPUT }; //enum for pin type (input or output pin)
	enum class pinState { HIGHZ, LOW, HIGH }; //enum for pin state
	int index; //Index of the pin for an element
		//First input pin has index 0, second input pin has index 1, output pin has index 2, so on…
	pinType type; //whether this pin is input or output
	bool isSrc[MAX_CONNECTIONS]; //whether this pin is the starting point of
		// the wire connected to it or the ending point
		// for that wire for every connection it has
	Pin* connectedTo[MAX_CONNECTIONS]; //List of other pins this pin is connected to
	Object* wires[MAX_CONNECTIONS]; //Wires connected to this pin
	int numConnections; //Number of connections on this pin
	sf::Vector2f pos; //Screen position of the pin
	pinState state; //Logic state of the signal on this pin
	inline static std::vector<Pin*> pinlist_all_vector;
	inline static std::vector<Pin*> pinlist_input;
	inline static std::vector<Pin*> pinlist_output;
	inline static int counter = 0;
	friend class LogicElement;
	friend class Wire;
	Pin() {
		std::cout << "DEFAULT PIN constructor called. its garbage object this:" << this << '\n';
	}
	Pin(const sf::Vector2f position_deneme);
	~Pin() {
		std::cout << "PIN Destructor called for this: " << this << '\n';
	}
};

class Wire : public Object {
public:
	sf::Vertex line[2]; //End point vertices for the wire
	Pin* pins[2]; //A list of pins that this wire is connected to
	Wire(sf::Texture t[2], sf::Sprite s);
	inline static std::vector<Wire> wire_vector;
	friend class Pin;
	void run();
};

class LogicElement :public Object {
public:
	Pin  pins[4]; //List of pins of the logic element
	int numPins; //Number of pins of the logic element
	sf::Vector2f pos;
	LogicElement(sf::Texture t[2], sf::Sprite s, sf::Vector2f[4]);
	LogicElement();
	void print_info();
	void divide_pins(Pin(&p)[4]);
	inline static std::vector<LogicElement*>objects_vec;
	virtual void run() = 0;
};

class Not : public LogicElement {
public:
	Not(sf::Texture[2], sf::Sprite, sf::Vector2f[2]);

	~Not() {
		std::cout << "Not destructor called.\n";
	}
	void run();
};
/*



*/
class And : public LogicElement {
public:
	And(sf::Texture[2], sf::Sprite, sf::Vector2f[3]);

	~And() {
		std::cout << "And destructor called.\n";
	}
	void run();
};

class Or : public LogicElement {
public:
	Or(sf::Texture[2], sf::Sprite, sf::Vector2f[3]);

	~Or() {
		std::cout << "Or destructor called.\n";
	}
	void run();
};

class Xor : public LogicElement {
public:
	Xor(sf::Texture[2], sf::Sprite, sf::Vector2f[3]);

	~Xor() {
		std::cout << "XOR destructor called.\n";
	}
	void run();
};

class Clock : public LogicElement {
public:
	Clock(sf::Texture[2], sf::Sprite, sf::Vector2f[1]);

	~Clock() {
		std::cout << "Clock destructor called.\n";
	}
	void run();
};

class Vdd : public LogicElement {
public:
	Vdd(sf::Texture[2], sf::Sprite, sf::Vector2f[1]);

	~Vdd() {
		std::cout << "Vdd destructor called.\n";
	}
	void run();
};

class Ground : public LogicElement {
public:

	Ground(sf::Texture[2], sf::Sprite, sf::Vector2f[1]);

	~Ground() {
		std::cout << "Ground destructor called.\n";
	}
	void run();
};

class Led : public LogicElement {
public:
	Led(sf::Texture[2], sf::Sprite, sf::Vector2f[2]);

	~Led() {
		std::cout << "Led destructor called.\n";
	}
	void run();

	// dikkat textures array 2 elemanli olacak
};



class Dff : public LogicElement {
public:
	Dff(sf::Texture[2], sf::Sprite, sf::Vector2f[4]);

	~Dff() {
		std::cout << "Dff destructor called.\n";
	}
	void run();

};

class Start :public LogicElement {


};

class Stop :public LogicElement {

};

class Simulator {
public:
	sf::RenderWindow* window; //Pointer to SFML render window
	Object* head; //Pointer to a list of objects on screen

	void simulate();
	//Simulator() {
	//	head = nullptr;
	//}
	//
	//void addObject() {
	//	Object* obj = new Object();
	//	obj->next = head;
	//	head = obj;
	//}

	//void deleteObject() {
	//	Object* ptr = head;
	//	Object* prev = nullptr;
	//	if (!head) {
	//		std::cout << "List is empty\n";
	//		return;
	//	}
	//	while (ptr) {
	//		if (ptr-> /* getNumber() == no  ) {
	//			if (prev)
	//				prev->next = ptr->next;
	//			else
	//				head = ptr->next;
	//			delete ptr;
	//			//delete prev; ????????
	//			return;
	//		}
	//		prev = ptr;
	//		ptr = ptr->next;
	//	}
	//}

};
