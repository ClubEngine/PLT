#ifndef ABSTRACTSTATEVIEW_HPP
#define ABSTRACTSTATEVIEW_HPP

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

#include "helpers/ModelHelper.hpp"
#include "helpers/ViewHelper.hpp"
#include "helpers/ControllerHelper.hpp"

// http://www.sfml-dev.org/documentation/2.0/classsf_1_1NonCopyable.php
// The type of inheritance (public or private) doesn't matter[...]

class AbstractStateView : sf::NonCopyable
{
	public:
		AbstractStateView(ViewHelper & helper);
		
		virtual bool processInputs(const sf::Event & event) = 0;
		virtual bool update(sf::Time dt) = 0;
		virtual void render() = 0;
	
	protected:
		sf::RenderTarget & getRenderTarget() const;
	
	private:
		ViewHelper & mHelper;
};

#endif // ABSTRACTSTATEVIEW_HPP
