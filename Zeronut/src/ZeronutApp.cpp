#include <Zero.h>
#include <Zero/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Zero {

	class Zeronut : public Application
	{
	public:
		Zeronut()
			: Application("Zeronut")
		{
			PushLayer(new EditorLayer());
		}

		~Zeronut()
		{
		}
	};

	Application* CreateApplication()
	{
		return new Zeronut();
	}

}