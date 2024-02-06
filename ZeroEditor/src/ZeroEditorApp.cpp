#include <Zero.h>
#include <Zero/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Zero {

	class ZeroEditor : public Application
	{
	public:
		ZeroEditor(const ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "ZeroEditor";
		spec.CommandLineArgs = args;

		return new ZeroEditor(spec);
	}

}