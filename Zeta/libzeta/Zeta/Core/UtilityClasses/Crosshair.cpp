/*
 * Crosshair.cpp
 *
 *  Created on: 5 Αυγ 2015
 *      Author: spiti
 */

#include <Zeta/Core/ShapeRenderer.hpp>
#include <Zeta/Core/System.hpp>
#include <Zeta/Core/UtilityClasses/Crosshair.hpp>
#include <Zeta/Core/UtilityClasses/Vector2.hpp>
#include <Zeta/Core/ZetaConfig.hpp>

namespace Zeta {

void Crosshair::draw(Float x, Float y, Float rotation, Float scale) const {
	ShapeRenderer& renderer = System::getInstance().getShapeRenderer();
	Float posX = position.getX(), posY = position.getY();
	if (backgroundEnabled) {
		renderer.drawFilledRectangle(posX - x, posY - y, (posX + width) - x,
				(posY + height) - y, backgroundColor);
	}
	renderer.drawLine((posX + cross_x) - x, posY - y, (posX + cross_x) - x,
			(posY + height) - y, outlineColor, 1.0f);
	renderer.drawLine(posX - x, (posY + cross_y) - y, (posX + width) - x,
			(posY + cross_y) - y, outlineColor, outlineThickness);
}

} /* namespace Zeta */

