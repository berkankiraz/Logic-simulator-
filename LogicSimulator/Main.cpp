#include <iostream>
#include <SFML/Graphics.hpp>
#include "classes.h"
#include <vector>

using namespace std;

int main()
{

    sf::Texture and_gate;
    sf::Texture textures_and[2] = { and_gate };

    if (!and_gate.loadFromFile("../assets/AND.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture or_gate;
    sf::Texture textures_or[2] = { or_gate };

    if (!or_gate.loadFromFile("../assets/OR.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture clock;
    sf::Texture textures_clock[2] = { clock };

    if (!clock.loadFromFile("../assets/CLOCK.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture dff;
    sf::Texture textures_dff[2] = { dff };

    if (!dff.loadFromFile("../assets/DFF.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture gnd;
    sf::Texture textures_gnd[2] = { gnd };

    if (!gnd.loadFromFile("../assets/GND.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture ledoff;
    if (!ledoff.loadFromFile("../assets/LEDOFF.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture ledon;
    if (!ledon.loadFromFile("../assets/LEDON.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }
    sf::Texture textures_led[2] = { ledoff, ledon };

    sf::Texture not_element;

    sf::Texture textures_not[2] = { not_element };

    if (!not_element.loadFromFile("../assets/NOT.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture start_button;
    sf::Texture textures_start[2] = { start_button };

    if (!start_button.loadFromFile("../assets/START.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture stop_button;
    sf::Texture textures_stop[2] = { stop_button };

    if (!stop_button.loadFromFile("../assets/STOP.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture vdd;
    sf::Texture textures_vdd[2] = { vdd };

    if (!vdd.loadFromFile("../assets/VDD.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Texture xor_element;
    sf::Texture textures_xor[2] = { xor_element };

    if (!xor_element.loadFromFile("../assets/XOR.png"))
    {
        cout << "Failed to load texture!" << endl;
        return -1;
    }

    sf::Sprite sprite_and;
    sf::Vector2f position_and = sf::Vector2f(sprite_and.getPosition());
    sf::Vector2f pinlist_and_relatively[3] = { };
    sprite_and.setTexture(and_gate);

    sf::Sprite sprite_clock;
    sf::Vector2f position_clock = sf::Vector2f(sprite_clock.getPosition());
    sf::Vector2f pinlist_clock_relatively[1] = { };
    sprite_clock.setTexture(clock);

    sf::Sprite sprite_gnd;
    sf::Vector2f position_gnd = sf::Vector2f(sprite_gnd.getPosition());
    sf::Vector2f pinlist_gnd_relatively[1] = { };
    sprite_gnd.setTexture(gnd);

    sf::Sprite sprite_ledoff;
    sf::Vector2f position_ledoff = sf::Vector2f(sprite_ledoff.getPosition());
    sf::Vector2f pinlist_ledoff_relatively[2] = { };
    sprite_ledoff.setTexture(ledoff);

    sf::Sprite sprite_ledon;
    sf::Vector2f position_ledon = sf::Vector2f(sprite_ledon.getPosition());
    sf::Vector2f pinlist_led_relatively[2] = { };
    sprite_ledon.setTexture(ledon);

    sf::Sprite sprite_dff;
    sf::Vector2f position_dff = sf::Vector2f(sprite_dff.getPosition());
    sf::Vector2f pinlist_dff_relatively[4] = { };
    sprite_dff.setTexture(dff);

    sf::Sprite sprite_not;
    sf::Vector2f position_not = sf::Vector2f(sprite_not.getPosition());
    sf::Vector2f pinlist_not_relatively[2] = { };
    sprite_not.setTexture(not_element);

    sf::Sprite sprite_or;
    sf::Vector2f position_or = sf::Vector2f(sprite_or.getPosition());
    sf::Vector2f pinlist_or_relatively[3] = {  };
    sprite_or.setTexture(or_gate);

    sf::Sprite sprite_start;
    sf::Vector2f position_start = sf::Vector2f(sprite_start.getPosition());
    sf::Vector2f pinlist_start_relatively[2] = { };
    sprite_start.setTexture(start_button);

    sf::Sprite sprite_stop;
    sf::Vector2f position_stop = sf::Vector2f(sprite_stop.getPosition());
    sf::Vector2f pinlist_stop_relatively[2] = { };
    sprite_stop.setTexture(stop_button);

    sf::Sprite sprite_vdd;
    sf::Vector2f position_vdd = sf::Vector2f(sprite_vdd.getPosition());
    sf::Vector2f pinlist_vdd_relatively[1] = { };
    sprite_vdd.setTexture(vdd);

    sf::Sprite sprite_xor;
    sf::Vector2f position_xor = sf::Vector2f(sprite_xor.getPosition());
    sf::Vector2f pinlist_xor_relatively[3] = { };
    sprite_xor.setTexture(xor_element);

    sf::Sprite sprite_wire;
    sf::Texture textures_wire[2];

    // create the window
    float window_height = 900;
    float window_width = 1200;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Logic Simulator");


    // Positioning and Scaling Sprites
    sf::Transform  t_or, t_and, t_dff, t_clock, t_not, t_ledon, t_start, t_stop, t_vdd, t_xor, t_gnd, t_temp;
    sprite_or.setPosition(20.f, window_height * 2 / 10);
    sprite_and.setPosition(20.f, window_height * 1 / 10);
    sprite_clock.setPosition(20.f, window_height * 6 / 10);
    sprite_not.setPosition(20.f, window_height * 3 / 10);
    sprite_ledoff.setPosition(20.f, window_height * 9 / 10);
    sprite_ledoff.setScale(0.7f, 0.7f);
    sprite_start.setPosition(250.f, window_height * 1 / 10 - 50);
    sprite_start.scale(1.f, 1.f);
    sprite_stop.setPosition(500.f, window_height * 1 / 10 - 50);
    sprite_stop.scale(1.f, 1.f);
    sprite_vdd.setPosition(20.f, window_height * 7 / 10);
    sprite_xor.setPosition(20.f, window_height * 4 / 10);
    sprite_gnd.setPosition(20.f, window_height * 8 / 10);
    sprite_dff.setPosition(20.f, window_height * 5 / 10);
    sf::Sprite sprite_array[12] = { sprite_or ,sprite_and,sprite_clock,sprite_not ,sprite_ledoff,sprite_vdd,sprite_xor,sprite_gnd ,sprite_dff };
    enum class sprite_enum { sprite_or, sprite_and, sprite_clock, sprite_not, sprite_ledoff, sprite_vdd, sprite_xor, sprite_gnd, sprite_dff };
    bool draw_sprite = false;
    bool draw_wire = false;
    bool draw_wire2 = true;
    bool mouse_move = false;
    int object_counter = 0;
    int wire_counter = 0;

    // First and last Wire Object. Every wire consists of this wire object 
    sf::VertexArray wires_array(sf::LineStrip, 2);
    sf::Vertex vertices[2];
    Wire wire_object(textures_wire, sprite_wire);





    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

            // List all pins from the Pin List Vector
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Q)) {
                cout << "\n\n\n" << "________________" << "\nPIN LISTESI" << '\n';
                for (auto& x : Pin::pinlist_all_vector) {
                    cout << "Pin X: " << x->pos.x << "     Pin Y: " << x->pos.y << " State: " << static_cast<int>(x->state) << '\n';
                }
                std::cout << "Pin 0->HIGHZ 1->LOW 2->HIGH\n";

                cout << "\n\n\n" << "________________" << '\n';
            }

            // Clearing all the screen
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Y)) {
                LogicElement::objects_vec.clear();
                Object::new_sprites_vec.clear();
                Wire::wire_vector.clear();
                object_counter = 0;
                wire_counter = 0;
            }


            // Events are arrenged from short to long

            // Wiring method
            // First, it calculates the distance of the mouse to all the pins and assigns it to a vector.
            // When "W" is pressed for the first time, it determines the address of the nearest pin as the starting point of the wire.
            // When "W" is pressed for the second time, it determines the address of the other closest pin as the ending point of the wire.
            // With the flags draw wire and draw_wire2, it is checked that whether wire is drawn in every two presses.

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::W)) {
                cout << "W Pressed\n";
                if (draw_wire2) {
                    vector<double> temp_pin_vec;


                    vertices[0].position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    vertices[0].color = sf::Color::Black;
                    for (auto& ite : Pin::pinlist_all_vector) {
                        double hipo = ((ite->pos.x) - (vertices[0].position.x)) * ((ite->pos.x) - (vertices[0].position.x)) +
                            ((ite->pos.y) - (vertices[0].position.y)) * ((ite->pos.y) - (vertices[0].position.y));
                        temp_pin_vec.push_back(hipo);
                    }

                    auto min_index = *min_element(temp_pin_vec.begin(), temp_pin_vec.end());
                    auto it1 = find(temp_pin_vec.begin(), temp_pin_vec.end(), min_index);
                    auto index = it1 - temp_pin_vec.begin();
                    cout << "index: " << index << '\n';
                    auto it2 = Pin::pinlist_all_vector.begin();
                    auto new_index = it2 + index;
                    vertices[0].position = (*new_index)->pos; /*+ sf::Vector2f(50.f, 31.f);*/
                    cout << " X: " << (*new_index)->pos.x << "   Y: " << (*new_index)->pos.y << '\n';

                    wire_object.line[0] = vertices[0];
                    draw_wire2 = false;
                    temp_pin_vec.clear();


                }

                else {
                    vector<double> temp_pin_vec2;
                    vertices[1].position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    vertices[1].color = sf::Color::Black;

                    for (auto& ite : Pin::pinlist_all_vector) {
                        double hipo = ((ite->pos.x) - (vertices[1].position.x)) * (ite->pos.x - (vertices[1].position.x)) +
                            ((ite->pos.y) - (vertices[1].position.y)) * ((ite->pos.y) - (vertices[1].position.y));
                        temp_pin_vec2.push_back(hipo);
                    }
                    auto min_el = *min_element(temp_pin_vec2.begin(), temp_pin_vec2.end());
                    auto it1 = find(temp_pin_vec2.begin(), temp_pin_vec2.end(), min_el);
                    int index = it1 - temp_pin_vec2.begin();
                    auto it2 = Pin::pinlist_all_vector.begin();
                    auto new_index = it2 + index;
                    cout << "index: " << index << '\n';

                    vertices[1].position = (*new_index)->pos; /*sf::Vector2f(50.f, 31.f);*/
                    cout << " X: " << (*new_index)->pos.x << "   Y: " << (*new_index)->pos.y << '\n';

                    wire_object.line[1] = vertices[1];
                    Wire::wire_vector.push_back(wire_object);
                    draw_wire = true;
                    temp_pin_vec2.clear();


                }
            }

            // Starting simulation when we clicked start button
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                // Object which handles simulation
                Simulator s;
                if (sprite_start.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    for (auto x = 0; x < 10; x++)
                        s.simulate();
                }
            }

            // Logic element transport method from sprites in the menu
            // When sprite is clicked, it first enters the while loop and execute the carry process.
            // Then it inserts the carried element from the enum class type into the switch case operator with integral type.
            // Depending on the entered case, the positions of the pins of that logic element with respect to the element are given as an argument to the constructor and an object is created.
            // These created objects are kept in a vector of type LogicElement*.
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                cout << "Left Mouse Button Clicked\n";
                sf::Vector2f mouse_position;
                for (int i = 0; i < sizeof(sprite_array) / sizeof(sf::Sprite); i++) {

                    if (sprite_array[i].getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        Object::new_sprites_vec.push_back(sprite_array[i]);
                        draw_sprite = true;

                        while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            ((Object::new_sprites_vec.end() - 1))->setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                        }
                        mouse_position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                        switch (i) {

                        case(int(sprite_enum::sprite_or)): {
                            cout << "\n\ncase Or is here \n\n";
                            pinlist_or_relatively[0] = (mouse_position + sf::Vector2f(5.f, 15.f));
                            pinlist_or_relatively[1] = (mouse_position + sf::Vector2f(5.f, 45.f));
                            pinlist_or_relatively[2] = (mouse_position + sf::Vector2f(93.f, 30.f));
                            Or orobj(textures_or, sprite_or, pinlist_or_relatively);
                            LogicElement::objects_vec.push_back(&orobj);
                            break;
                        }


                        case(int(sprite_enum::sprite_and)): {
                            cout << "\n\ncase AND is here \n\n";
                            pinlist_and_relatively[0] = (mouse_position + sf::Vector2f(5.f, 15.f));
                            pinlist_and_relatively[1] = (mouse_position + sf::Vector2f(5.f, 45.f));
                            pinlist_and_relatively[2] = (mouse_position + sf::Vector2f(93.f, 30.f));
                            And andobj(textures_and, sprite_and, pinlist_and_relatively);
                            LogicElement::objects_vec.push_back(&andobj);
                            break;
                        }


                        case(int(sprite_enum::sprite_clock)): {
                            cout << "\n\ncase CLOCK is here \n\n";
                            pinlist_clock_relatively[0] = (mouse_position + sf::Vector2f(75.f, 30.f));
                            Clock clockobj(textures_clock, sprite_clock, pinlist_clock_relatively);
                            LogicElement::objects_vec.push_back(&clockobj);
                            break;
                        }


                        case(int(sprite_enum::sprite_not)): {

                            cout << "\n\ncase NOT is here \n\n";
                            pinlist_not_relatively[0] = (mouse_position + sf::Vector2f(5.f, 30.f));
                            pinlist_not_relatively[1] = (mouse_position + sf::Vector2f(93.f, 30.f));
                            Not notobj(textures_not, sprite_not, pinlist_not_relatively);
                            LogicElement::objects_vec.push_back(&notobj);
                            break;
                        }


                        case(int(sprite_enum::sprite_ledoff)):
                        {
                            cout << "\n\ncase LED is here \n\n";
                            pinlist_led_relatively[0] = (mouse_position + sf::Vector2f(13.f * 0.7f, 72.f * 0.7f));
                            pinlist_led_relatively[1] = (mouse_position + sf::Vector2f(29.f * 0.7f, 72.f * 0.7f));
                            Led ledonobj(textures_led, sprite_ledon, pinlist_led_relatively);
                            LogicElement::objects_vec.push_back(&ledonobj);
                            break;

                        }

                        case(int(sprite_enum::sprite_vdd)):
                        {

                            cout << "\n\ncase VDD is here \n\n";
                            //mouse_position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                            pinlist_vdd_relatively[0] = (mouse_position + sf::Vector2f(30.f, 55.f));



                            Vdd vddobj(textures_vdd, sprite_vdd, pinlist_vdd_relatively);
                            LogicElement::objects_vec.push_back(&vddobj);
                            break;


                        }

                        case(int(sprite_enum::sprite_xor)):
                        {
                            cout << "\n\ncase XOR is here \n\n";
                            //mouse_position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                            pinlist_xor_relatively[0] = (mouse_position + sf::Vector2f(5.f, 15.f));
                            pinlist_xor_relatively[1] = (mouse_position + sf::Vector2f(5.f, 45.f));
                            pinlist_xor_relatively[2] = (mouse_position + sf::Vector2f(93.f, 30.f));


                            Xor xorobj(textures_not, sprite_xor, pinlist_xor_relatively);
                            LogicElement::objects_vec.push_back(&xorobj);
                            break;
                        }

                        case(int(sprite_enum::sprite_gnd)):
                        {
                            cout << "\n\ncase GND is here \n\n";
                            //mouse_position = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);

                            pinlist_gnd_relatively[0] = (mouse_position + sf::Vector2f(22.f, 5.f));
                            cout << "\n\n BURASI Pin 1.X: " << pinlist_gnd_relatively[0].x << "   Y: " << pinlist_gnd_relatively[0].y << '\n';


                            Ground gndobj(textures_gnd, sprite_gnd, pinlist_gnd_relatively);
                            LogicElement::objects_vec.push_back(&gndobj);
                            break;

                        }


                        case(int(sprite_enum::sprite_dff)):
                        {
                            cout << "\n\ncase DFF is here \n\n";
                            pinlist_dff_relatively[0] = (mouse_position + sf::Vector2f(5.f, 20.f));
                            pinlist_dff_relatively[1] = (mouse_position + sf::Vector2f(5.f, 40.f));
                            pinlist_dff_relatively[2] = (mouse_position + sf::Vector2f(93.f, 20.f));
                            pinlist_dff_relatively[3] = (mouse_position + sf::Vector2f(93.f, 60.f));
                            Dff dffobj(textures_dff, sprite_dff, pinlist_dff_relatively);
                            LogicElement::objects_vec.push_back(&dffobj);
                            break;

                        }
                        }

                    }

                }

            }

        }
        window.clear(sf::Color::Cyan);
        window.draw(sprite_or, t_or);
        window.draw(sprite_and, t_and);
        window.draw(sprite_clock, t_clock);
        window.draw(sprite_not, t_not);
        window.draw(sprite_ledoff, t_ledon);
        window.draw(sprite_start, t_start);
        window.draw(sprite_stop, t_stop);
        window.draw(sprite_vdd, t_vdd);
        window.draw(sprite_xor, t_xor);
        window.draw(sprite_gnd, t_gnd);
        window.draw(sprite_not, t_not);
        window.draw(sprite_dff, t_dff);

        // The part that all sprites are drawn by looping through the vector
        for (auto i : Object::new_sprites_vec) {
            window.draw(i);
            if (draw_sprite) {
                object_counter++;
                draw_sprite = false;
                cout << "After Drawing \n" << "object: " << object_counter << '\n';
            }

        }

        // The part that all wires are drawn by looping through the vector
        for (auto i = Wire::wire_vector.begin(); i != Wire::wire_vector.end(); i++) {
            window.draw(i->line, 2, sf::Lines);
            if (draw_wire) {
                draw_wire = false;
                draw_wire2 = true;
                wire_counter++;
                cout << "After Wiring \n" << "Wire: " << wire_counter << '\n';
                int counter = 1;
                for (auto x : Wire::wire_vector) {
                    cout << "Starting point of wire " << counter << ":" << x.line[0].position.x << " y:" << x.line[0].position.y << endl;
                    cout << "Ending point of wire " << counter << ":" << x.line[1].position.x << " y:" << x.line[1].position.y << endl;
                    counter++;
                }
            }
        }

        window.display();
    }
    return 0;
}