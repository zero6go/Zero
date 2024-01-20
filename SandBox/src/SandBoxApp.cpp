#include <Zero.h>

class SandBox : public Zero::Application {
public:

	SandBox()
	{

	}

	~SandBox()
	{

	}

};

Zero::Application* Zero::CreateApplication() 
{
	return new SandBox();
}