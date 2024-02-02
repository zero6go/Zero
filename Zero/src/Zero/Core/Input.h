#pragma once

#include <glm/glm.hpp>

#include "Zero/Core/KeyCodes.h"
#include "Zero/Core/MouseCodes.h"

namespace Zero {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}