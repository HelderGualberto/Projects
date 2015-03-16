#include "MyForm.h"
#include <stdlib.h>
#include <stdio.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThread]


void main(array<String^>^args){
	
	Application::EnableVisualStyles;
	Application::SetCompatibleTextRenderingDefault;

	windowsforms::MyForm form;
	Application::Run(%form);

}
