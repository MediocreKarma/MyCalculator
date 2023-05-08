#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(0);
	Calculator::MyForm calculatorApp;
	Application::Run(% calculatorApp);
}
