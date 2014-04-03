#ifndef ABSTRACTSTATEMODEL_HPP
#define ABSTRACTSTATEMODEL_HPP

#include <SFML/System.hpp>

#include "helpers/ModelHelper.hpp"
#include "helpers/ViewHelper.hpp"
#include "helpers/ControllerHelper.hpp"

class AbstractStateModel : sf::NonCopyable
{
	public:
		AbstractStateModel(ModelHelper & helper);
		
		virtual bool update(sf::Time dt) = 0;
		
	private:
		ModelHelper & mHelper;
};

#endif // ABSTRACTSTATEMODEL_HPP
