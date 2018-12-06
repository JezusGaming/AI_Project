#include "Application2D.h"
#include <crtdbg.h>
#include "Heap.h"
#include <iostream>
using namespace std;
int main() 
{
	//At start of main()
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Application2D* app = new Application2D();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}