#include "classes.h"
#ifndef CLASSES_H
#define CLASSES_H


Pin::Pin(const sf::Vector2f position_deneme) :pos{ position_deneme } {
	std::cout << "PIN constructor called for this: " << this << '\n';
	pinlist_all_vector.push_back(this);
}

Object::Object(sf::Texture t[2], sf::Sprite s) : textures{ *t }, sprite{ s } {
	std::cout << "OBJECT constructor called for this: " << this << '\n';
}

Object::Object() {
	std::cout << "OBJECT default constructor called for this: " << this << '\n';
}

LogicElement::LogicElement(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[4]) :Object(t, s), pins{ Pin(v[0]), Pin(v[1]),Pin(v[2]),Pin(v[3]) }{
	std::cout << "Logic Element constructor for this : " << this << '\n';
}

void LogicElement::divide_pins(Pin(&p)[4]) {
	for (auto& x : p) {
		if (x.type == Pin::pinType::INPUT) {
			Pin::pinlist_input.push_back(&x);
			std::cout << "Pin X: " << x.pos.x << "Pin Y: " << x.pos.y << '\n';
		}
		else if (x.type == Pin::pinType::OUTPUT)
		{
			Pin::pinlist_output.push_back(&x);
			std::cout << "Pin X: " << x.pos.x << "Pin Y: " << x.pos.y << '\n';
		}
	}
}
LogicElement::LogicElement() {
	std::cout << "Logic Element DEFAULT constructor for this : " << this << '\n';
}

Not::Not(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[2]) : LogicElement(t, s, v) {
	pins[0].type = Pin::pinType::INPUT;
	pins[1].type = Pin::pinType::OUTPUT;
	pins[0].state = Pin::pinState::HIGHZ;
	pins[1].state = Pin::pinState::HIGHZ;
	std::cout << "NOT GATE constuctor called for this: " << this << "\n\n";
	Pin::pinlist_input.push_back(&pins[0]);
	Pin::pinlist_output.push_back(&pins[1]);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
}

Wire::Wire(sf::Texture t[2], sf::Sprite s) : Object(t, s) {
	std::cout << "WIRE constuctor called for first and last time. object this: " << this << "\n\n";
}

Led::Led(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[2]) : LogicElement(t, s, v) {
	std::cout << "LED constuctor called for this: " << this << "\n\n";
	pins[0].type = Pin::pinType::INPUT;
	pins[1].type = Pin::pinType::OUTPUT;
	pins[0].state = Pin::pinState::HIGHZ;
	pins[1].state = Pin::pinState::HIGHZ;
	Pin::pinlist_input.push_back(&pins[0]);
	Pin::pinlist_output.push_back(&pins[1]);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);

}

And::And(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[3]) : LogicElement(t, s, v) {
	std::cout << "AND GATE constuctor called for this: " << this << "\n\n";
	pins[0].type = Pin::pinType::INPUT;
	pins[1].type = Pin::pinType::INPUT;
	pins[2].type = Pin::pinType::OUTPUT;
	pins[0].state = Pin::pinState::HIGHZ;
	pins[1].state = Pin::pinState::HIGHZ;
	pins[2].state = Pin::pinState::HIGHZ;
	Pin::pinlist_input.push_back(&pins[0]);
	Pin::pinlist_input.push_back(&pins[1]);
	Pin::pinlist_output.push_back(&pins[2]);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);

}

Or::Or(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[3]) : LogicElement(t, s, v) {
	std::cout << "OR GATE constuctor called for this: " << this << "\n\n";
	pins[0].type = Pin::pinType::INPUT;
	pins[1].type = Pin::pinType::INPUT;
	pins[2].type = Pin::pinType::OUTPUT;
	pins[0].state = Pin::pinState::HIGHZ;
	pins[1].state = Pin::pinState::HIGHZ;
	pins[2].state = Pin::pinState::HIGHZ;
	Pin::pinlist_input.push_back(&pins[0]);
	Pin::pinlist_input.push_back(&pins[1]);
	Pin::pinlist_output.push_back(&pins[2]);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
}

Xor::Xor(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[3]) : LogicElement(t, s, v) {
	std::cout << "XOR GATE constuctor called for this: " << this << "\n\n";
	pins[0].type = Pin::pinType::INPUT;
	pins[1].type = Pin::pinType::INPUT;
	pins[2].type = Pin::pinType::OUTPUT;
	pins[0].state = Pin::pinState::HIGHZ;
	pins[1].state = Pin::pinState::HIGHZ;
	pins[2].state = Pin::pinState::HIGHZ;
	Pin::pinlist_input.push_back(&pins[0]);
	Pin::pinlist_input.push_back(&pins[1]);
	Pin::pinlist_output.push_back(&pins[2]);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);

}

Clock::Clock(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[1]) : LogicElement(t, s, v) {
	std::cout << "CLOCK constuctor called for this: " << this << "\n\n";
	pins[0].type = Pin::pinType::INPUT;
	pins[0].state = Pin::pinState::HIGHZ;
	Pin::pinlist_input.push_back(&pins[0]);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);



}

Vdd::Vdd(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[1]) : LogicElement(t, s, v) {
	std::cout << "VDD constuctor called for this: " << this << "\n\n";
	pins[0].type = Pin::pinType::INPUT;
	pins[0].state = Pin::pinState::HIGH;
	Pin::pinlist_input.push_back(&pins[0]);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);

}

Ground::Ground(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[1]) : LogicElement(t, s, v) {
	std::cout << "GROUND constuctor called for this: " << this << "\n\n";
	pins[0].type = Pin::pinType::INPUT;
	pins[0].state = Pin::pinState::LOW;
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_all_vector.erase(Pin::pinlist_all_vector.end() - 1);
	Pin::pinlist_input.push_back(&pins[0]);

}

Dff::Dff(sf::Texture t[2], sf::Sprite s, sf::Vector2f v[4]) : LogicElement(t, s, v) {
	std::cout << "DFF constuctor called for this: " << this << "\n\n";
	pins[0].type = Pin::pinType::INPUT;
	pins[1].type = Pin::pinType::INPUT;
	pins[2].type = Pin::pinType::OUTPUT;
	pins[3].type = Pin::pinType::OUTPUT;
	pins[0].state = Pin::pinState::HIGHZ;
	pins[1].state = Pin::pinState::HIGHZ;
	pins[2].state = Pin::pinState::HIGHZ;
	pins[3].state = Pin::pinState::HIGHZ;
	Pin::pinlist_input.push_back(&pins[0]);
	Pin::pinlist_input.push_back(&pins[1]);
	Pin::pinlist_output.push_back(&pins[2]);
	Pin::pinlist_output.push_back(&pins[3]);

}

void Vdd::run() {
	for (auto pin_ite : pins) {
		for (auto wire_ite : Wire::wire_vector) {
			if (pin_ite.pos == wire_ite.line[0].position) {
				for (auto pin_ite2 : Pin::pinlist_all_vector) {
					if (pin_ite2->pos == wire_ite.line[1].position) {
						pin_ite2->state = pin_ite.state;
						std::cout << "Pin state has changed to :" << static_cast<int>(pin_ite2->state) << '\n';
						std::cout << "Pin 0->HIGHZ 1->LOW 2->HIGH\n";
					}
				}
			}

			else if (pin_ite.pos == wire_ite.line[1].position) {
				for (auto pin_ite2 : Pin::pinlist_all_vector) {
					if (pin_ite2->pos == wire_ite.line[0].position) {
						pin_ite2->state = pin_ite.state;
						std::cout << "Pin state has changed to :" << static_cast<int>(pin_ite2->state) << '\n';
						std::cout << "Pin 0->HIGHZ 1->LOW 2->HIGH\n";
					}
				}
			}
		}
	}
}

void Or::run() {
	if ((pins[0].state == Pin::pinState::HIGH) || (pins[1].state == Pin::pinState::HIGH)) {
		pins[2].state = Pin::pinState::HIGH;
		std::cout << "And Third PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
	else {
		pins[2].state = Pin::pinState::LOW;
		std::cout << "And Output PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
}

void Ground::run() {
	for (auto pin_ite : pins) {
		for (auto wire_ite : Wire::wire_vector) {
			if (pin_ite.pos == wire_ite.line[0].position) {
				for (auto pin_ite2 : Pin::pinlist_all_vector) {
					if (pin_ite2->pos == wire_ite.line[1].position) {
						pin_ite2->state = pin_ite.state;
						std::cout << "Pin state has changed to :" << static_cast<int>(pin_ite2->state) << '\n';
						std::cout << "Pin 0->HIGHZ 1->LOW 2->HIGH\n";
					}
				}
			}

			else if (pin_ite.pos == wire_ite.line[1].position) {
				for (auto pin_ite2 : Pin::pinlist_all_vector) {
					if (pin_ite2->pos == wire_ite.line[0].position) {
						pin_ite2->state = pin_ite.state;
						std::cout << "Pin state has changed to :" << static_cast<int>(pin_ite2->state) << '\n';
						std::cout << "Pin 0->HIGHZ 1->LOW 2->HIGH\n";
					}
				}
			}
		}
	}
}

void Wire::run() {
	for (auto& x : wire_vector) {
		for (auto& pin_ite : Pin::pinlist_all_vector) {
			if (x.line[0].position == pin_ite->pos) {
				if (pin_ite->state != Pin::pinState::HIGHZ) {
					for (auto& pin_ite2 : Pin::pinlist_all_vector) {
						if (x.line[1].position == pin_ite2->pos) {
							pin_ite2->state = pin_ite->state;
						}
					}
				}
			}

			else if (x.line[1].position == pin_ite->pos) {
				if (pin_ite->state != Pin::pinState::HIGHZ) {
					for (auto& pin_ite2 : Pin::pinlist_all_vector) {
						if (x.line[1].position == pin_ite2->pos) {
							pin_ite2->state = pin_ite->state;
							std::cout << "State of Wire's other PIN has changed to :" << static_cast<int>(pin_ite2->state) << '\n';
							std::cout << "Pin 0->HIGHZ 1->LOW 2->HIGH\n";
						}
					}
				}

			}
		}

	}
}

void Xor::run() {
	if ((pins[0].state == Pin::pinState::HIGH) && (pins[1].state == Pin::pinState::HIGH)) {
		pins[2].state = Pin::pinState::LOW;
		std::cout << "And Third PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
	else if ((pins[0].state == Pin::pinState::LOW) && (pins[1].state == Pin::pinState::LOW)) {
		pins[2].state = Pin::pinState::LOW;
		std::cout << "And Third PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
	else {
		pins[2].state = Pin::pinState::HIGH;
		std::cout << "And Output PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
}

void And::run() {
	if ((pins[0].state == Pin::pinState::HIGH) && (pins[1].state == Pin::pinState::HIGH)) {
		pins[2].state = Pin::pinState::HIGH;
		std::cout << "And Third PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
	else {
		pins[2].state = Pin::pinState::LOW;
		std::cout << "And Output PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
}

void Clock::run() {
	//sf::Clock clock; // starts the clock

	//sf::Time elapsed1 = clock.getElapsedTime();
	//std::cout << elapsed1.asSeconds() << std::endl;
	//clock.restart();

}
void Dff::run() {
	if ((pins[0].state == Pin::pinState::HIGH) && (pins[1].state == Pin::pinState::HIGH)) {
		pins[2].state = Pin::pinState::HIGH;
		pins[3].state = Pin::pinState::LOW;
		std::cout << "And Third PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
	else {
		pins[2].state = Pin::pinState::LOW;
		pins[3].state = Pin::pinState::HIGH;
		std::cout << "And Output PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
}
void Not::run() {
	if (pins[0].state == Pin::pinState::HIGH) {
		pins[1].state = Pin::pinState::LOW;
		std::cout << "NOT Output PIN changed to :" << static_cast<int>(pins[1].state) << '\n';
	}
	else if (pins[0].state == Pin::pinState::LOW) {
		pins[1].state = Pin::pinState::HIGH;
		std::cout << "NOT Output PIN changed to :" << static_cast<int>(pins[2].state) << '\n';
	}
}
void Led::run() {
	sf::Sprite sprite_ledon1;
	sf::Texture ledoff1;
	if (!ledoff1.loadFromFile("../assets/ledoff1.png"))
	{
		std::cout << "Failed to load texture!" << std::endl;
		return;
	}
	sf::Sprite sprite_ledoff1;
	sf::Texture ledon1;
	if (!ledon1.loadFromFile("../assets/ledon1.png"))
	{
		std::cout << "Failed to load texture!" << std::endl;
		return;
	}

	if ((pins[0].state == Pin::pinState::HIGH) && pins[1].state == Pin::pinState::LOW) {
		auto _index = find(LogicElement::objects_vec.begin(), LogicElement::objects_vec.end(), this);
		int index = _index - LogicElement::objects_vec.begin();
		sprite_ledon1.setTexture(ledon1);
		//Object::new_sprites_vec[index] = sprite_ledon1;
		//Object::new_sprites_vec[index].setTexture(ledon1);
		std::cout << "\n\n\nLEDON\n\n\n";
		std::cout << "\n\n\nLEDON\n\n\n";
		std::cout << "\n\n\nLEDON\n\n\n";
	}
	else {
		auto _index = find(LogicElement::objects_vec.begin(), LogicElement::objects_vec.end(), this);
		int index = _index - LogicElement::objects_vec.begin();
		sprite_ledoff1.setTexture(ledoff1);
		//Object::new_sprites_vec[index] = sprite_ledoff1;
		//Object::new_sprites_vec[index].setTexture(ledoff1);
		std::cout << "\n\n\nLEDOFF\n\n\n";
		std::cout << "\n\n\nLEDOFF\n\n\n";
		std::cout << "\n\n\nLEDOFF\n\n\n";

	}
}



void Simulator::simulate() {
	for (auto& x : LogicElement::objects_vec) {
		for (auto i : x->pins) {
			if (i.state != Pin::pinState::HIGHZ) {
				x->run();
			}
		}
	}
	for (auto& x : Wire::wire_vector) {
		x.run();
	}
}



void LogicElement::print_info() {
	std::cout << "\n\nFirst element: " << this << '\n';
}

#endif
