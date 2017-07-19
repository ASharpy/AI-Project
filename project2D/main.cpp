#include "Application2D.h"

int main() {

		try
		{
			// allocation
			auto app = new Application2D();

			// initialise and loop
			app->run("AIE", 1280, 720, false);

			// deallocation
			delete app;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		catch (...)
		{
			std::cerr << "Unspecified error." << std::endl;
		}
		system("pause");
		return 0;
	
}