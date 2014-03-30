#ifndef COMMANDSTYPE_HPP
#define COMMANDSTYPE_HPP

#include <SFML/System.hpp>


// CommandType

typedef sf::Uint8 CommandType;

const CommandType CT_NONE = 0; 
const CommandType	CT_MOVE = 1;
const CommandType CT_BUILD = 2;
const CommandType	CT_TOTAL = 3;

#endif // COMMANDSTYPE_HPP
