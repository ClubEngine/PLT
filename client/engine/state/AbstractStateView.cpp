#include "AbstractStateView.hpp"

AbstractStateView::AbstractStateView(ViewHelper &helper)
	: mHelper(helper)
{
}

sf::RenderTarget &AbstractStateView::getRenderTarget() const
{
	return mHelper.getRenderTarget();
}
