#pragma once
#include <cstdint>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <array>
#include <ctime>

namespace Calculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>

	const std::array<std::function<double(double)>, 16> singleNumberOperation = {
		[](double x) -> double {return x * x; },
		[](double x) -> double {return sqrt(x); },
		[](double x) -> double {return pow(10, x); },
		[](double x) -> double {return log10(x); },
		[](double x) -> double {return log(x); },
		[](double x) -> double {return 1 / x; },
		[](double x) -> double {return abs(x); },
		[](double x) -> double {return tgamma(x + 1); },
		[](double x) -> double {return x * x * x; },
		[](double x) -> double {return cbrt(x); },
		[](double x) -> double {return pow(2, x); },
		[](double x) -> double {const double EulerNumber = 2.7182818284590452353602874; return pow(EulerNumber, x); },
		[](double x) -> double {return floor(x); },
		[](double x) -> double {return ceil(x); },
		[](double x) -> double {const double GradesPerRad = 57.2957795; return x * GradesPerRad; },
		[](double x) -> double {const double GradesPerRad = 57.2957795; return x / GradesPerRad; }
	};

	const std::array<std::function<double(double, double)>, 9> doubleNumberOperation = {
		[](double x, double y) -> double {return pow(x, y); },
		[](double x, double y) -> double {return y; },
		[](double x, double y) -> double {return x - floor(x / y) * y; },
		[](double x, double y) -> double {return x / y; },
		[](double x, double y) -> double {return x * y; },
		[](double x, double y) -> double {return x - y; },
		[](double x, double y) -> double {return x + y; },
		[](double x, double y) -> double {return pow(x, 1 / y); },
		[](double x, double y) -> double {return log2(x) / log2(y); }
	};

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button0;
	private: System::Windows::Forms::Button^ negateButton;
	private: System::Windows::Forms::Button^ decimalPointButton;
	private: System::Windows::Forms::Button^ multiplicationButton;
	private: System::Windows::Forms::Button^ additionButton;
	private: System::Windows::Forms::Button^ substractionButton;
	private: System::Windows::Forms::Button^ resultButton;
	private: System::Windows::Forms::Button^ divisionButton;
	private: System::Windows::Forms::TextBox^ txtBox;
	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::Label^ showOperation;
	private: System::Windows::Forms::Button^ eulerButton;
	private: System::Windows::Forms::Button^ backspaceButton;
	private: System::Windows::Forms::Button^ inverseButton;
	private: System::Windows::Forms::Button^ absButton;
	private: System::Windows::Forms::Button^ exponentButton;
	private: System::Windows::Forms::Button^ moduloButton;
	private: System::Windows::Forms::Button^ piButton;
	private: System::Windows::Forms::Button^ factorialButton;
	private: System::Windows::Forms::Button^ paranthesesCloseButton;
	private: System::Windows::Forms::Button^ paranthesesOpenButton;
	private: System::Windows::Forms::Button^ sqrtButton;
	private: System::Windows::Forms::Button^ trigButton;
	private: System::Windows::Forms::Button^ sqrButton;
	private: System::Windows::Forms::Button^ lnButton;
	private: System::Windows::Forms::Button^ log10Button;
	private: System::Windows::Forms::Button^ pow10_xButton;
	private: System::Windows::Forms::Button^ powx_yButton;
	private: System::Windows::Forms::Button^ invertTrigButton;
	private: System::Windows::Forms::Button^ radiansButton;
	private: System::Windows::Forms::Button^ tanhButton;
	private: System::Windows::Forms::Button^ coshButton;
	private: System::Windows::Forms::Button^ sinhButton;
	private: System::Windows::Forms::Button^ tanButton;
	private: System::Windows::Forms::Button^ sinButton;
	private: System::Windows::Forms::Button^ cosButton;
	private: System::Windows::Forms::Button^ arcsinButton;
	private: System::Windows::Forms::Button^ arccosButton;
	private: System::Windows::Forms::Button^ arctanButton;
	private: System::Windows::Forms::Button^ arcsinhButton;
	private: System::Windows::Forms::Button^ arccoshButton;
	private: System::Windows::Forms::Button^ arctanhButton;
	private: System::Windows::Forms::Button^ gradesButton;
	private: System::Windows::Forms::Panel^ trigonometryPanel;
	private: System::Windows::Forms::Button^ moreOptionsButton;
	private: System::Windows::Forms::Panel^ defaultTrigFunctions;
	private: System::Windows::Forms::Panel^ defaultOptionsPanel;
	private: System::Windows::Forms::Button^ powe_xButton;
	private: System::Windows::Forms::Button^ logyButton;
	private: System::Windows::Forms::Button^ pow2_xButton;
	private: System::Windows::Forms::Button^ cbrtButton;
	private: System::Windows::Forms::Button^ cubeButton;
	private: System::Windows::Forms::Button^ yrtButton;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Panel^ funcPanel;
	private: System::Windows::Forms::Button^ randomButton;
	private: System::Windows::Forms::Button^ ceilButton;
	private: System::Windows::Forms::Button^ floorButton;
	private: System::Windows::Forms::Button^ toGradButton;
	private: System::Windows::Forms::Button^ toRadButton;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->defaultOptionsPanel = (gcnew System::Windows::Forms::Panel());
			this->sqrButton = (gcnew System::Windows::Forms::Button());
			this->powx_yButton = (gcnew System::Windows::Forms::Button());
			this->pow10_xButton = (gcnew System::Windows::Forms::Button());
			this->log10Button = (gcnew System::Windows::Forms::Button());
			this->lnButton = (gcnew System::Windows::Forms::Button());
			this->sqrtButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->negateButton = (gcnew System::Windows::Forms::Button());
			this->decimalPointButton = (gcnew System::Windows::Forms::Button());
			this->multiplicationButton = (gcnew System::Windows::Forms::Button());
			this->additionButton = (gcnew System::Windows::Forms::Button());
			this->substractionButton = (gcnew System::Windows::Forms::Button());
			this->resultButton = (gcnew System::Windows::Forms::Button());
			this->divisionButton = (gcnew System::Windows::Forms::Button());
			this->txtBox = (gcnew System::Windows::Forms::TextBox());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->showOperation = (gcnew System::Windows::Forms::Label());
			this->eulerButton = (gcnew System::Windows::Forms::Button());
			this->backspaceButton = (gcnew System::Windows::Forms::Button());
			this->inverseButton = (gcnew System::Windows::Forms::Button());
			this->absButton = (gcnew System::Windows::Forms::Button());
			this->exponentButton = (gcnew System::Windows::Forms::Button());
			this->moduloButton = (gcnew System::Windows::Forms::Button());
			this->piButton = (gcnew System::Windows::Forms::Button());
			this->factorialButton = (gcnew System::Windows::Forms::Button());
			this->paranthesesCloseButton = (gcnew System::Windows::Forms::Button());
			this->paranthesesOpenButton = (gcnew System::Windows::Forms::Button());
			this->trigButton = (gcnew System::Windows::Forms::Button());
			this->invertTrigButton = (gcnew System::Windows::Forms::Button());
			this->radiansButton = (gcnew System::Windows::Forms::Button());
			this->tanhButton = (gcnew System::Windows::Forms::Button());
			this->coshButton = (gcnew System::Windows::Forms::Button());
			this->sinhButton = (gcnew System::Windows::Forms::Button());
			this->tanButton = (gcnew System::Windows::Forms::Button());
			this->sinButton = (gcnew System::Windows::Forms::Button());
			this->cosButton = (gcnew System::Windows::Forms::Button());
			this->arcsinButton = (gcnew System::Windows::Forms::Button());
			this->arccosButton = (gcnew System::Windows::Forms::Button());
			this->arctanButton = (gcnew System::Windows::Forms::Button());
			this->arcsinhButton = (gcnew System::Windows::Forms::Button());
			this->arccoshButton = (gcnew System::Windows::Forms::Button());
			this->arctanhButton = (gcnew System::Windows::Forms::Button());
			this->gradesButton = (gcnew System::Windows::Forms::Button());
			this->trigonometryPanel = (gcnew System::Windows::Forms::Panel());
			this->defaultTrigFunctions = (gcnew System::Windows::Forms::Panel());
			this->moreOptionsButton = (gcnew System::Windows::Forms::Button());
			this->powe_xButton = (gcnew System::Windows::Forms::Button());
			this->logyButton = (gcnew System::Windows::Forms::Button());
			this->pow2_xButton = (gcnew System::Windows::Forms::Button());
			this->cbrtButton = (gcnew System::Windows::Forms::Button());
			this->cubeButton = (gcnew System::Windows::Forms::Button());
			this->yrtButton = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->funcPanel = (gcnew System::Windows::Forms::Panel());
			this->toGradButton = (gcnew System::Windows::Forms::Button());
			this->toRadButton = (gcnew System::Windows::Forms::Button());
			this->randomButton = (gcnew System::Windows::Forms::Button());
			this->ceilButton = (gcnew System::Windows::Forms::Button());
			this->floorButton = (gcnew System::Windows::Forms::Button());
			this->defaultOptionsPanel->SuspendLayout();
			this->trigonometryPanel->SuspendLayout();
			this->defaultTrigFunctions->SuspendLayout();
			this->funcPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// defaultOptionsPanel
			// 
			this->defaultOptionsPanel->Controls->Add(this->sqrButton);
			this->defaultOptionsPanel->Controls->Add(this->powx_yButton);
			this->defaultOptionsPanel->Controls->Add(this->pow10_xButton);
			this->defaultOptionsPanel->Controls->Add(this->log10Button);
			this->defaultOptionsPanel->Controls->Add(this->lnButton);
			this->defaultOptionsPanel->Controls->Add(this->sqrtButton);
			this->defaultOptionsPanel->Location = System::Drawing::Point(12, 165);
			this->defaultOptionsPanel->Margin = System::Windows::Forms::Padding(0);
			this->defaultOptionsPanel->Name = L"defaultOptionsPanel";
			this->defaultOptionsPanel->Size = System::Drawing::Size(50, 285);
			this->defaultOptionsPanel->TabIndex = 63;
			// 
			// sqrButton
			// 
			this->sqrButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sqrButton->Location = System::Drawing::Point(0, 0);
			this->sqrButton->Name = L"sqrButton";
			this->sqrButton->Size = System::Drawing::Size(49, 43);
			this->sqrButton->TabIndex = 35;
			this->sqrButton->Tag = L"0";
			this->sqrButton->Text = L"x²";
			this->sqrButton->UseVisualStyleBackColor = true;
			this->sqrButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// powx_yButton
			// 
			this->powx_yButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->powx_yButton->Location = System::Drawing::Point(0, 98);
			this->powx_yButton->Name = L"powx_yButton";
			this->powx_yButton->Size = System::Drawing::Size(49, 43);
			this->powx_yButton->TabIndex = 31;
			this->powx_yButton->Tag = L"0";
			this->powx_yButton->Text = L"xʸ";
			this->powx_yButton->UseVisualStyleBackColor = true;
			this->powx_yButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// pow10_xButton
			// 
			this->pow10_xButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pow10_xButton->Location = System::Drawing::Point(0, 147);
			this->pow10_xButton->Name = L"pow10_xButton";
			this->pow10_xButton->Size = System::Drawing::Size(49, 43);
			this->pow10_xButton->TabIndex = 32;
			this->pow10_xButton->Tag = L"2";
			this->pow10_xButton->Text = L"10ˣ";
			this->pow10_xButton->UseVisualStyleBackColor = true;
			this->pow10_xButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// log10Button
			// 
			this->log10Button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->log10Button->Location = System::Drawing::Point(0, 196);
			this->log10Button->Name = L"log10Button";
			this->log10Button->Size = System::Drawing::Size(49, 43);
			this->log10Button->TabIndex = 33;
			this->log10Button->Tag = L"3";
			this->log10Button->Text = L"log";
			this->log10Button->UseVisualStyleBackColor = true;
			this->log10Button->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// lnButton
			// 
			this->lnButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lnButton->Location = System::Drawing::Point(0, 245);
			this->lnButton->Name = L"lnButton";
			this->lnButton->Size = System::Drawing::Size(49, 43);
			this->lnButton->TabIndex = 34;
			this->lnButton->Tag = L"4";
			this->lnButton->Text = L"ln";
			this->lnButton->UseVisualStyleBackColor = true;
			this->lnButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// sqrtButton
			// 
			this->sqrtButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sqrtButton->Location = System::Drawing::Point(0, 49);
			this->sqrtButton->Name = L"sqrtButton";
			this->sqrtButton->Size = System::Drawing::Size(49, 43);
			this->sqrtButton->TabIndex = 37;
			this->sqrtButton->Tag = L"1";
			this->sqrtButton->Text = L"√x";
			this->sqrtButton->UseVisualStyleBackColor = true;
			this->sqrtButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(67, 263);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(49, 43);
			this->button1->TabIndex = 1;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button2
			// 
			this->button2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(122, 263);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(49, 43);
			this->button2->TabIndex = 2;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(177, 263);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(49, 43);
			this->button3->TabIndex = 3;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(67, 312);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(49, 43);
			this->button4->TabIndex = 4;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(122, 312);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(49, 43);
			this->button5->TabIndex = 5;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(177, 312);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(49, 43);
			this->button6->TabIndex = 6;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(67, 361);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(49, 43);
			this->button7->TabIndex = 7;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(122, 361);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(49, 43);
			this->button8->TabIndex = 8;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(177, 361);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(49, 43);
			this->button9->TabIndex = 9;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// button0
			// 
			this->button0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button0->Location = System::Drawing::Point(122, 410);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(49, 43);
			this->button0->TabIndex = 10;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = true;
			this->button0->Click += gcnew System::EventHandler(this, &MyForm::numberButton_Click);
			// 
			// negateButton
			// 
			this->negateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->negateButton->Location = System::Drawing::Point(67, 410);
			this->negateButton->Name = L"negateButton";
			this->negateButton->Size = System::Drawing::Size(49, 43);
			this->negateButton->TabIndex = 11;
			this->negateButton->Text = L"±";
			this->negateButton->UseVisualStyleBackColor = true;
			this->negateButton->Click += gcnew System::EventHandler(this, &MyForm::negateButton_Click);
			// 
			// decimalPointButton
			// 
			this->decimalPointButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->decimalPointButton->Location = System::Drawing::Point(177, 410);
			this->decimalPointButton->Name = L"decimalPointButton";
			this->decimalPointButton->Size = System::Drawing::Size(49, 43);
			this->decimalPointButton->TabIndex = 12;
			this->decimalPointButton->Text = L".";
			this->decimalPointButton->UseVisualStyleBackColor = true;
			this->decimalPointButton->Click += gcnew System::EventHandler(this, &MyForm::decimalPoint_Click);
			// 
			// multiplicationButton
			// 
			this->multiplicationButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->multiplicationButton->Location = System::Drawing::Point(232, 263);
			this->multiplicationButton->Name = L"multiplicationButton";
			this->multiplicationButton->Size = System::Drawing::Size(49, 43);
			this->multiplicationButton->TabIndex = 13;
			this->multiplicationButton->Tag = L"4";
			this->multiplicationButton->Text = L"x";
			this->multiplicationButton->UseVisualStyleBackColor = true;
			this->multiplicationButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// additionButton
			// 
			this->additionButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->additionButton->Location = System::Drawing::Point(231, 361);
			this->additionButton->Name = L"additionButton";
			this->additionButton->Size = System::Drawing::Size(49, 43);
			this->additionButton->TabIndex = 14;
			this->additionButton->Tag = L"6";
			this->additionButton->Text = L"+";
			this->additionButton->UseVisualStyleBackColor = true;
			this->additionButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// substractionButton
			// 
			this->substractionButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->substractionButton->Location = System::Drawing::Point(232, 312);
			this->substractionButton->Name = L"substractionButton";
			this->substractionButton->Size = System::Drawing::Size(49, 43);
			this->substractionButton->TabIndex = 15;
			this->substractionButton->Tag = L"5";
			this->substractionButton->Text = L"-";
			this->substractionButton->UseVisualStyleBackColor = true;
			this->substractionButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// resultButton
			// 
			this->resultButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultButton->Location = System::Drawing::Point(232, 410);
			this->resultButton->Name = L"resultButton";
			this->resultButton->Size = System::Drawing::Size(49, 43);
			this->resultButton->TabIndex = 16;
			this->resultButton->Text = L"=";
			this->resultButton->UseVisualStyleBackColor = true;
			this->resultButton->Click += gcnew System::EventHandler(this, &MyForm::resultButton_Click);
			// 
			// divisionButton
			// 
			this->divisionButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->divisionButton->Location = System::Drawing::Point(231, 214);
			this->divisionButton->Name = L"divisionButton";
			this->divisionButton->Size = System::Drawing::Size(49, 43);
			this->divisionButton->TabIndex = 17;
			this->divisionButton->Tag = L"3";
			this->divisionButton->Text = L"÷";
			this->divisionButton->UseVisualStyleBackColor = true;
			this->divisionButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// txtBox
			// 
			this->txtBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->txtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtBox->Location = System::Drawing::Point(12, 12);
			this->txtBox->Multiline = true;
			this->txtBox->Name = L"txtBox";
			this->txtBox->ReadOnly = true;
			this->txtBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->txtBox->Size = System::Drawing::Size(268, 64);
			this->txtBox->TabIndex = 18;
			this->txtBox->Text = L"\r\n0";
			this->txtBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->txtBox->TextChanged += gcnew System::EventHandler(this, &MyForm::txtBox_TextChanged);
			this->txtBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::keyPressed_Event);
			// 
			// clearButton
			// 
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearButton->Location = System::Drawing::Point(177, 116);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(49, 43);
			this->clearButton->TabIndex = 19;
			this->clearButton->Text = L"CE";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &MyForm::clearButton_Click);
			// 
			// showOperation
			// 
			this->showOperation->AutoSize = true;
			this->showOperation->BackColor = System::Drawing::SystemColors::ControlLight;
			this->showOperation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showOperation->Location = System::Drawing::Point(16, 16);
			this->showOperation->Margin = System::Windows::Forms::Padding(2);
			this->showOperation->Name = L"showOperation";
			this->showOperation->Size = System::Drawing::Size(0, 20);
			this->showOperation->TabIndex = 20;
			// 
			// eulerButton
			// 
			this->eulerButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eulerButton->Location = System::Drawing::Point(122, 116);
			this->eulerButton->Name = L"eulerButton";
			this->eulerButton->Size = System::Drawing::Size(49, 43);
			this->eulerButton->TabIndex = 21;
			this->eulerButton->Text = L"e";
			this->eulerButton->UseVisualStyleBackColor = true;
			this->eulerButton->Click += gcnew System::EventHandler(this, &MyForm::eulerNumberButton_Click);
			// 
			// backspaceButton
			// 
			this->backspaceButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->backspaceButton->Location = System::Drawing::Point(232, 116);
			this->backspaceButton->Name = L"backspaceButton";
			this->backspaceButton->Size = System::Drawing::Size(49, 43);
			this->backspaceButton->TabIndex = 22;
			this->backspaceButton->Text = L"⌫";
			this->backspaceButton->UseVisualStyleBackColor = true;
			this->backspaceButton->Click += gcnew System::EventHandler(this, &MyForm::backspaceKey_Click);
			// 
			// inverseButton
			// 
			this->inverseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inverseButton->Location = System::Drawing::Point(67, 165);
			this->inverseButton->Name = L"inverseButton";
			this->inverseButton->Size = System::Drawing::Size(49, 43);
			this->inverseButton->TabIndex = 26;
			this->inverseButton->Tag = L"5";
			this->inverseButton->Text = L"1/x";
			this->inverseButton->UseVisualStyleBackColor = true;
			this->inverseButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// absButton
			// 
			this->absButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->absButton->Location = System::Drawing::Point(122, 165);
			this->absButton->Name = L"absButton";
			this->absButton->Size = System::Drawing::Size(49, 43);
			this->absButton->TabIndex = 25;
			this->absButton->Tag = L"6";
			this->absButton->Text = L"|x|";
			this->absButton->UseVisualStyleBackColor = true;
			this->absButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// exponentButton
			// 
			this->exponentButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exponentButton->Location = System::Drawing::Point(177, 165);
			this->exponentButton->Name = L"exponentButton";
			this->exponentButton->Size = System::Drawing::Size(49, 43);
			this->exponentButton->TabIndex = 24;
			this->exponentButton->Tag = L"1";
			this->exponentButton->Text = L"exp";
			this->exponentButton->UseVisualStyleBackColor = true;
			this->exponentButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// moduloButton
			// 
			this->moduloButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->moduloButton->Location = System::Drawing::Point(232, 165);
			this->moduloButton->Name = L"moduloButton";
			this->moduloButton->Size = System::Drawing::Size(49, 43);
			this->moduloButton->TabIndex = 23;
			this->moduloButton->Tag = L"2";
			this->moduloButton->Text = L"mod";
			this->moduloButton->UseVisualStyleBackColor = true;
			this->moduloButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// piButton
			// 
			this->piButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->piButton->Location = System::Drawing::Point(67, 116);
			this->piButton->Name = L"piButton";
			this->piButton->Size = System::Drawing::Size(49, 43);
			this->piButton->TabIndex = 27;
			this->piButton->Text = L"𝜋";
			this->piButton->UseVisualStyleBackColor = true;
			this->piButton->Click += gcnew System::EventHandler(this, &MyForm::piButton_Click);
			// 
			// factorialButton
			// 
			this->factorialButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->factorialButton->Location = System::Drawing::Point(177, 214);
			this->factorialButton->Name = L"factorialButton";
			this->factorialButton->Size = System::Drawing::Size(49, 43);
			this->factorialButton->TabIndex = 30;
			this->factorialButton->Tag = L"7";
			this->factorialButton->Text = L"x!";
			this->factorialButton->UseVisualStyleBackColor = true;
			this->factorialButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// paranthesesCloseButton
			// 
			this->paranthesesCloseButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->paranthesesCloseButton->Location = System::Drawing::Point(122, 214);
			this->paranthesesCloseButton->Name = L"paranthesesCloseButton";
			this->paranthesesCloseButton->Size = System::Drawing::Size(49, 43);
			this->paranthesesCloseButton->TabIndex = 29;
			this->paranthesesCloseButton->Text = L")";
			this->paranthesesCloseButton->UseVisualStyleBackColor = true;
			// 
			// paranthesesOpenButton
			// 
			this->paranthesesOpenButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->paranthesesOpenButton->Location = System::Drawing::Point(67, 214);
			this->paranthesesOpenButton->Name = L"paranthesesOpenButton";
			this->paranthesesOpenButton->Size = System::Drawing::Size(49, 43);
			this->paranthesesOpenButton->TabIndex = 28;
			this->paranthesesOpenButton->Text = L"(";
			this->paranthesesOpenButton->UseVisualStyleBackColor = true;
			// 
			// trigButton
			// 
			this->trigButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->trigButton->Location = System::Drawing::Point(12, 82);
			this->trigButton->Name = L"trigButton";
			this->trigButton->Size = System::Drawing::Size(104, 29);
			this->trigButton->TabIndex = 36;
			this->trigButton->Text = L"trig";
			this->trigButton->UseVisualStyleBackColor = true;
			this->trigButton->Click += gcnew System::EventHandler(this, &MyForm::trigButton_Click);
			// 
			// invertTrigButton
			// 
			this->invertTrigButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->invertTrigButton->Location = System::Drawing::Point(171, 32);
			this->invertTrigButton->Name = L"invertTrigButton";
			this->invertTrigButton->Size = System::Drawing::Size(49, 43);
			this->invertTrigButton->TabIndex = 46;
			this->invertTrigButton->Text = L"Inv";
			this->invertTrigButton->UseVisualStyleBackColor = true;
			this->invertTrigButton->Click += gcnew System::EventHandler(this, &MyForm::InvertTrigButton_Click);
			// 
			// radiansButton
			// 
			this->radiansButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radiansButton->Location = System::Drawing::Point(232, 82);
			this->radiansButton->Name = L"radiansButton";
			this->radiansButton->Size = System::Drawing::Size(48, 28);
			this->radiansButton->TabIndex = 45;
			this->radiansButton->Text = L"rad";
			this->radiansButton->UseVisualStyleBackColor = true;
			this->radiansButton->Click += gcnew System::EventHandler(this, &MyForm::changeTrigUnitType_Click);
			// 
			// tanhButton
			// 
			this->tanhButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tanhButton->Location = System::Drawing::Point(110, 49);
			this->tanhButton->Name = L"tanhButton";
			this->tanhButton->Size = System::Drawing::Size(49, 43);
			this->tanhButton->TabIndex = 44;
			this->tanhButton->Tag = L"5";
			this->tanhButton->Text = L"tanh";
			this->tanhButton->UseVisualStyleBackColor = true;
			this->tanhButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// coshButton
			// 
			this->coshButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->coshButton->Location = System::Drawing::Point(55, 49);
			this->coshButton->Name = L"coshButton";
			this->coshButton->Size = System::Drawing::Size(49, 43);
			this->coshButton->TabIndex = 43;
			this->coshButton->Tag = L"4";
			this->coshButton->Text = L"cosh";
			this->coshButton->UseVisualStyleBackColor = true;
			this->coshButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// sinhButton
			// 
			this->sinhButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sinhButton->Location = System::Drawing::Point(0, 49);
			this->sinhButton->Name = L"sinhButton";
			this->sinhButton->Size = System::Drawing::Size(49, 43);
			this->sinhButton->TabIndex = 42;
			this->sinhButton->Tag = L"3";
			this->sinhButton->Text = L"sinh";
			this->sinhButton->UseVisualStyleBackColor = true;
			this->sinhButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// tanButton
			// 
			this->tanButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tanButton->Location = System::Drawing::Point(110, 0);
			this->tanButton->Name = L"tanButton";
			this->tanButton->Size = System::Drawing::Size(49, 43);
			this->tanButton->TabIndex = 41;
			this->tanButton->Tag = L"2";
			this->tanButton->Text = L"tan";
			this->tanButton->UseVisualStyleBackColor = true;
			this->tanButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// sinButton
			// 
			this->sinButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sinButton->Location = System::Drawing::Point(0, 0);
			this->sinButton->Name = L"sinButton";
			this->sinButton->Size = System::Drawing::Size(49, 43);
			this->sinButton->TabIndex = 40;
			this->sinButton->Tag = L"0";
			this->sinButton->Text = L"sin";
			this->sinButton->UseVisualStyleBackColor = true;
			this->sinButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// cosButton
			// 
			this->cosButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cosButton->Location = System::Drawing::Point(55, 0);
			this->cosButton->Name = L"cosButton";
			this->cosButton->Size = System::Drawing::Size(49, 43);
			this->cosButton->TabIndex = 39;
			this->cosButton->Tag = L"1";
			this->cosButton->Text = L"cos";
			this->cosButton->UseVisualStyleBackColor = true;
			this->cosButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// arcsinButton
			// 
			this->arcsinButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arcsinButton->Location = System::Drawing::Point(6, 7);
			this->arcsinButton->Name = L"arcsinButton";
			this->arcsinButton->Size = System::Drawing::Size(49, 43);
			this->arcsinButton->TabIndex = 48;
			this->arcsinButton->Tag = L"6";
			this->arcsinButton->Text = L"sin⁻¹";
			this->arcsinButton->UseVisualStyleBackColor = true;
			this->arcsinButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// arccosButton
			// 
			this->arccosButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arccosButton->Location = System::Drawing::Point(61, 7);
			this->arccosButton->Name = L"arccosButton";
			this->arccosButton->Size = System::Drawing::Size(49, 43);
			this->arccosButton->TabIndex = 47;
			this->arccosButton->Tag = L"7";
			this->arccosButton->Text = L"cos⁻¹";
			this->arccosButton->UseVisualStyleBackColor = true;
			this->arccosButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// arctanButton
			// 
			this->arctanButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arctanButton->Location = System::Drawing::Point(116, 7);
			this->arctanButton->Name = L"arctanButton";
			this->arctanButton->Size = System::Drawing::Size(49, 43);
			this->arctanButton->TabIndex = 49;
			this->arctanButton->Tag = L"8";
			this->arctanButton->Text = L"tan⁻¹";
			this->arctanButton->UseVisualStyleBackColor = true;
			this->arctanButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// arcsinhButton
			// 
			this->arcsinhButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arcsinhButton->Location = System::Drawing::Point(6, 57);
			this->arcsinhButton->Name = L"arcsinhButton";
			this->arcsinhButton->Size = System::Drawing::Size(49, 43);
			this->arcsinhButton->TabIndex = 50;
			this->arcsinhButton->Tag = L"9";
			this->arcsinhButton->Text = L"sinh⁻¹";
			this->arcsinhButton->UseVisualStyleBackColor = true;
			this->arcsinhButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// arccoshButton
			// 
			this->arccoshButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arccoshButton->Location = System::Drawing::Point(61, 57);
			this->arccoshButton->Name = L"arccoshButton";
			this->arccoshButton->Size = System::Drawing::Size(49, 43);
			this->arccoshButton->TabIndex = 51;
			this->arccoshButton->Tag = L"10";
			this->arccoshButton->Text = L"cosh⁻¹";
			this->arccoshButton->UseVisualStyleBackColor = true;
			this->arccoshButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// arctanhButton
			// 
			this->arctanhButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->arctanhButton->Location = System::Drawing::Point(116, 57);
			this->arctanhButton->Name = L"arctanhButton";
			this->arctanhButton->Size = System::Drawing::Size(49, 43);
			this->arctanhButton->TabIndex = 52;
			this->arctanhButton->Tag = L"11";
			this->arctanhButton->Text = L"tanh⁻¹";
			this->arctanhButton->UseVisualStyleBackColor = true;
			this->arctanhButton->Click += gcnew System::EventHandler(this, &MyForm::trigFunctions_Click);
			// 
			// gradesButton
			// 
			this->gradesButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gradesButton->Location = System::Drawing::Point(231, 82);
			this->gradesButton->Name = L"gradesButton";
			this->gradesButton->Size = System::Drawing::Size(50, 28);
			this->gradesButton->TabIndex = 54;
			this->gradesButton->Text = L"grad";
			this->gradesButton->UseVisualStyleBackColor = true;
			this->gradesButton->Click += gcnew System::EventHandler(this, &MyForm::changeTrigUnitType_Click);
			// 
			// trigonometryPanel
			// 
			this->trigonometryPanel->BackColor = System::Drawing::SystemColors::ControlDark;
			this->trigonometryPanel->Controls->Add(this->defaultTrigFunctions);
			this->trigonometryPanel->Controls->Add(this->arcsinButton);
			this->trigonometryPanel->Controls->Add(this->invertTrigButton);
			this->trigonometryPanel->Controls->Add(this->arccosButton);
			this->trigonometryPanel->Controls->Add(this->arctanButton);
			this->trigonometryPanel->Controls->Add(this->arcsinhButton);
			this->trigonometryPanel->Controls->Add(this->arccoshButton);
			this->trigonometryPanel->Controls->Add(this->arctanhButton);
			this->trigonometryPanel->Location = System::Drawing::Point(29, 109);
			this->trigonometryPanel->Name = L"trigonometryPanel";
			this->trigonometryPanel->Padding = System::Windows::Forms::Padding(2);
			this->trigonometryPanel->Size = System::Drawing::Size(226, 106);
			this->trigonometryPanel->TabIndex = 55;
			// 
			// defaultTrigFunctions
			// 
			this->defaultTrigFunctions->Controls->Add(this->tanButton);
			this->defaultTrigFunctions->Controls->Add(this->sinButton);
			this->defaultTrigFunctions->Controls->Add(this->tanhButton);
			this->defaultTrigFunctions->Controls->Add(this->cosButton);
			this->defaultTrigFunctions->Controls->Add(this->sinhButton);
			this->defaultTrigFunctions->Controls->Add(this->coshButton);
			this->defaultTrigFunctions->Location = System::Drawing::Point(6, 7);
			this->defaultTrigFunctions->Margin = System::Windows::Forms::Padding(0);
			this->defaultTrigFunctions->Name = L"defaultTrigFunctions";
			this->defaultTrigFunctions->Size = System::Drawing::Size(162, 96);
			this->defaultTrigFunctions->TabIndex = 64;
			// 
			// moreOptionsButton
			// 
			this->moreOptionsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->moreOptionsButton->Location = System::Drawing::Point(12, 116);
			this->moreOptionsButton->Name = L"moreOptionsButton";
			this->moreOptionsButton->Size = System::Drawing::Size(49, 43);
			this->moreOptionsButton->TabIndex = 56;
			this->moreOptionsButton->Text = L"2nd";
			this->moreOptionsButton->UseVisualStyleBackColor = true;
			this->moreOptionsButton->Click += gcnew System::EventHandler(this, &MyForm::otherOptionsButton_Click);
			// 
			// powe_xButton
			// 
			this->powe_xButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->powe_xButton->Location = System::Drawing::Point(12, 410);
			this->powe_xButton->Name = L"powe_xButton";
			this->powe_xButton->Size = System::Drawing::Size(49, 43);
			this->powe_xButton->TabIndex = 60;
			this->powe_xButton->Tag = L"11";
			this->powe_xButton->Text = L"eˣ";
			this->powe_xButton->UseVisualStyleBackColor = true;
			this->powe_xButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// logyButton
			// 
			this->logyButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logyButton->Location = System::Drawing::Point(12, 361);
			this->logyButton->Name = L"logyButton";
			this->logyButton->Size = System::Drawing::Size(49, 43);
			this->logyButton->TabIndex = 59;
			this->logyButton->Tag = L"8";
			this->logyButton->Text = L"logᵧx";
			this->logyButton->UseVisualStyleBackColor = true;
			this->logyButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// pow2_xButton
			// 
			this->pow2_xButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pow2_xButton->Location = System::Drawing::Point(12, 312);
			this->pow2_xButton->Name = L"pow2_xButton";
			this->pow2_xButton->Size = System::Drawing::Size(49, 43);
			this->pow2_xButton->TabIndex = 58;
			this->pow2_xButton->Tag = L"10";
			this->pow2_xButton->Text = L"2ˣ";
			this->pow2_xButton->UseVisualStyleBackColor = true;
			this->pow2_xButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// cbrtButton
			// 
			this->cbrtButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbrtButton->Location = System::Drawing::Point(12, 214);
			this->cbrtButton->Name = L"cbrtButton";
			this->cbrtButton->Size = System::Drawing::Size(49, 43);
			this->cbrtButton->TabIndex = 62;
			this->cbrtButton->Tag = L"9";
			this->cbrtButton->Text = L"∛x";
			this->cbrtButton->UseVisualStyleBackColor = true;
			this->cbrtButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// cubeButton
			// 
			this->cubeButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cubeButton->Location = System::Drawing::Point(12, 165);
			this->cubeButton->Name = L"cubeButton";
			this->cubeButton->Size = System::Drawing::Size(49, 43);
			this->cubeButton->TabIndex = 61;
			this->cubeButton->Tag = L"8";
			this->cubeButton->Text = L"x³";
			this->cubeButton->UseVisualStyleBackColor = true;
			this->cubeButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// yrtButton
			// 
			this->yrtButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yrtButton->Location = System::Drawing::Point(12, 262);
			this->yrtButton->Name = L"yrtButton";
			this->yrtButton->Size = System::Drawing::Size(49, 43);
			this->yrtButton->TabIndex = 57;
			this->yrtButton->Tag = L"7";
			this->yrtButton->Text = L"ʸ√x";
			this->yrtButton->UseVisualStyleBackColor = true;
			this->yrtButton->Click += gcnew System::EventHandler(this, &MyForm::multipleNumberOperators_Click);
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(122, 82);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(104, 29);
			this->button10->TabIndex = 64;
			this->button10->Text = L"func";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::funcButton_Click);
			// 
			// funcPanel
			// 
			this->funcPanel->BackColor = System::Drawing::SystemColors::ControlDark;
			this->funcPanel->Controls->Add(this->toGradButton);
			this->funcPanel->Controls->Add(this->toRadButton);
			this->funcPanel->Controls->Add(this->randomButton);
			this->funcPanel->Controls->Add(this->ceilButton);
			this->funcPanel->Controls->Add(this->floorButton);
			this->funcPanel->Location = System::Drawing::Point(41, 109);
			this->funcPanel->Name = L"funcPanel";
			this->funcPanel->Padding = System::Windows::Forms::Padding(2);
			this->funcPanel->Size = System::Drawing::Size(168, 99);
			this->funcPanel->TabIndex = 65;
			// 
			// toGradButton
			// 
			this->toGradButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toGradButton->Location = System::Drawing::Point(5, 50);
			this->toGradButton->Name = L"toGradButton";
			this->toGradButton->Size = System::Drawing::Size(77, 43);
			this->toGradButton->TabIndex = 69;
			this->toGradButton->Tag = L"14";
			this->toGradButton->Text = L"→grad";
			this->toGradButton->UseVisualStyleBackColor = true;
			this->toGradButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// toRadButton
			// 
			this->toRadButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->toRadButton->Location = System::Drawing::Point(86, 50);
			this->toRadButton->Name = L"toRadButton";
			this->toRadButton->Size = System::Drawing::Size(77, 43);
			this->toRadButton->TabIndex = 67;
			this->toRadButton->Tag = L"15";
			this->toRadButton->Text = L"→rad";
			this->toRadButton->UseVisualStyleBackColor = true;
			this->toRadButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// randomButton
			// 
			this->randomButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->randomButton->Location = System::Drawing::Point(115, 5);
			this->randomButton->Name = L"randomButton";
			this->randomButton->Size = System::Drawing::Size(49, 43);
			this->randomButton->TabIndex = 68;
			this->randomButton->Tag = L"0";
			this->randomButton->Text = L"rand";
			this->randomButton->UseVisualStyleBackColor = true;
			this->randomButton->Click += gcnew System::EventHandler(this, &MyForm::randButton_Click);
			// 
			// ceilButton
			// 
			this->ceilButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ceilButton->Location = System::Drawing::Point(60, 5);
			this->ceilButton->Name = L"ceilButton";
			this->ceilButton->Size = System::Drawing::Size(49, 43);
			this->ceilButton->TabIndex = 67;
			this->ceilButton->Tag = L"13";
			this->ceilButton->Text = L"ceil";
			this->ceilButton->UseVisualStyleBackColor = true;
			this->ceilButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// floorButton
			// 
			this->floorButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->floorButton->Location = System::Drawing::Point(5, 5);
			this->floorButton->Name = L"floorButton";
			this->floorButton->Size = System::Drawing::Size(49, 43);
			this->floorButton->TabIndex = 66;
			this->floorButton->Tag = L"12";
			this->floorButton->Text = L"floor";
			this->floorButton->UseVisualStyleBackColor = true;
			this->floorButton->Click += gcnew System::EventHandler(this, &MyForm::singleNumberOperators_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 459);
			this->Controls->Add(this->funcPanel);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->trigonometryPanel);
			this->Controls->Add(this->defaultOptionsPanel);
			this->Controls->Add(this->yrtButton);
			this->Controls->Add(this->cubeButton);
			this->Controls->Add(this->cbrtButton);
			this->Controls->Add(this->moreOptionsButton);
			this->Controls->Add(this->pow2_xButton);
			this->Controls->Add(this->logyButton);
			this->Controls->Add(this->gradesButton);
			this->Controls->Add(this->powe_xButton);
			this->Controls->Add(this->trigButton);
			this->Controls->Add(this->factorialButton);
			this->Controls->Add(this->paranthesesCloseButton);
			this->Controls->Add(this->paranthesesOpenButton);
			this->Controls->Add(this->piButton);
			this->Controls->Add(this->inverseButton);
			this->Controls->Add(this->absButton);
			this->Controls->Add(this->exponentButton);
			this->Controls->Add(this->moduloButton);
			this->Controls->Add(this->backspaceButton);
			this->Controls->Add(this->eulerButton);
			this->Controls->Add(this->showOperation);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->divisionButton);
			this->Controls->Add(this->resultButton);
			this->Controls->Add(this->substractionButton);
			this->Controls->Add(this->additionButton);
			this->Controls->Add(this->multiplicationButton);
			this->Controls->Add(this->decimalPointButton);
			this->Controls->Add(this->negateButton);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radiansButton);
			this->Controls->Add(this->txtBox);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"CalculatorApp";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->defaultOptionsPanel->ResumeLayout(false);
			this->trigonometryPanel->ResumeLayout(false);
			this->defaultTrigFunctions->ResumeLayout(false);
			this->funcPanel->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	static constexpr int NO_OPERATION = -1;
	double firstNum = 0, secondNum = 0, result = 0;
	Button^ operation = (gcnew System::Windows::Forms::Button());

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ActiveControl = txtBox;
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		operation->Tag = System::Convert::ToString(NO_OPERATION);
		operation->Text = "";
		trigonometryPanel->Hide();
		funcPanel->Hide();
	}

	private: System::Void reset() {
		txtBox->Text = L"\r\n0";
		firstNum = secondNum = result = 0;
		operation->Tag = System::Convert::ToString(NO_OPERATION);
		operation->Text = "";
		showOperation->Text = "";
	}

	private: System::Void keyPressed_Event(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		wchar_t lastInputChar = e->KeyChar;
		e->Handled = true;
		switch (lastInputChar) {
			case L'0':
				numberButton_Click(button0, e);
				break;
			case L'1':
				numberButton_Click(button1, e);
				break;
			case L'2':
				numberButton_Click(button2, e);
				break;
			case L'3':
				numberButton_Click(button3, e);
				break;
			case L'4':
				numberButton_Click(button4, e);
				break;
			case L'5':
				numberButton_Click(button5, e);
				break;
			case L'6':
				numberButton_Click(button6, e);
				break;
			case L'7':
				numberButton_Click(button7, e);
				break;
			case L'8':
				numberButton_Click(button8, e);
				break;
			case L'9':
				numberButton_Click(button9, e);
				break;
			case L'*':
			case L'x':
				multipleNumberOperators_Click(multiplicationButton, e);
				break;
			case L'/':
			case L':':
				multipleNumberOperators_Click(divisionButton, e);
				break;
			case L'+':
				multipleNumberOperators_Click(additionButton, e);
				break;
			case L'-':
				multipleNumberOperators_Click(substractionButton, e);
				break;
			case L'!':
				singleNumberOperators_Click(factorialButton, e);
				break;
			case L'%':
				multipleNumberOperators_Click(moduloButton, e);
				break;
			case L'^':
				multipleNumberOperators_Click(powx_yButton, e);
				break;
			case L'\r':
			case L'=':
				resultButton_Click(sender, e);
				break;
			case L'\b':
				backspaceKey_Click(sender, e);
				break;
			case L',':
			case L'.':
				decimalPoint_Click(sender, e);
				break;
			case L'c':
			case L'C':
				clearButton_Click(sender, e);
				break;
			case L'e':
				multipleNumberOperators_Click(exponentButton, e);
				break;
			case L'|':
				singleNumberOperators_Click(absButton, e);
				break;
		}
	}

	private: System::Void numberButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ digit = safe_cast<Button^>(sender);
		if (txtBox->Text == "\r\n0") {
			txtBox->Text = "\r\n" + digit->Text;
		}
		else if (txtBox->Text->EndsWith(".e+0")) {
			txtBox->Text = txtBox->Text->Remove(txtBox->Text->Length - 1);
			txtBox->Text += digit->Text;
		}
		else {
			txtBox->Text += digit->Text;
		}
		txtBox->Focus();
	}

	private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
		reset();
		txtBox->Focus();
	}

	private: System::Void decimalPoint_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!txtBox->Text->Contains(".")) {
			txtBox->Text += ".";
		}
		txtBox->Focus();
	}
	
	private: System::Void negateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtBox->Text->Contains("-")) {
			txtBox->Text = txtBox->Text->Remove(2, 1);
		}
		else {
			txtBox->Text = "\r\n-" + txtBox->Text->Remove(0, 2);
		}
		txtBox->Focus();
	}

	private: System::Void resultButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (System::Convert::ToInt32(operation->Tag) == NO_OPERATION) {
			return;
		}
		showOperation->Text = "";
		result = resultCalculation();
		operation->Text = "";
		operation->Tag = "-1";
		txtBox->Text = "\r\n" + System::Convert::ToString(result);
		firstNum = result;
		txtBox->Focus();
	}

	private: double resultCalculation() {
		secondNum = Double::Parse(txtBox->Text);
		return doubleNumberOperation[System::Convert::ToInt32(operation->Tag)](firstNum, secondNum);
	}

	private: System::Void backspaceKey_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txtBox->Text->Contains("+")) {
			if (txtBox->Text->Contains(".e+0")) {
				txtBox->Text = txtBox->Text->Remove(txtBox->Text->Length - 3);
				operation->Tag = "-1";
				operation->Text = "";
				return;
			}
			txtBox->Text = txtBox->Text->Remove(txtBox->Text->Length - 1);
			if (txtBox->Text->EndsWith("e+")) {
				txtBox->Text += "0";
			}
			return;
		}
		txtBox->Text = txtBox->Text->Remove(txtBox->Text->Length - 1);
		if (txtBox->Text == L"\r\n") {
			txtBox->Text = L"\r\n0";
		}
		txtBox->Focus();
	}
	
	private: System::Void singleNumberOperators_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ op = safe_cast<Button^>(sender);
		double currentNum = Double::Parse(txtBox->Text);
		currentNum = singleNumberOperation[System::Convert::ToInt32(op->Tag)](currentNum);
		txtBox->Text = "\r\n" + System::Convert::ToString(currentNum);
		funcPanel->Hide();
		txtBox->Focus();
	}

	private: System::Void multipleNumberOperators_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ op = safe_cast<Button^>(sender);
		const int POWX_Y = 0, EXP = 1, YROOT_X = 7, LOGY_X = 8;
		if (System::Convert::ToInt32(operation->Tag) == NO_OPERATION) {
			firstNum = Double::Parse(txtBox->Text);
		}
		else {
			firstNum = resultCalculation();
		}
		txtBox->Text = "\r\n0";
		operation->Tag = op->Tag;
		operation->Text = op->Text;
		switch (System::Convert::ToInt32(operation->Tag)) {
			case POWX_Y:
				showOperation->Text = System::Convert::ToString(firstNum) + "^";
				break;
			case EXP:
				txtBox->Text = "\r\n" + System::Convert::ToString(firstNum) + ".e+0";
				break;
			case YROOT_X:
				showOperation->Text = "ʸ√" + System::Convert::ToString(firstNum);
				break;
			case LOGY_X:
				showOperation->Text = "logᵧ" + System::Convert::ToString(firstNum);
				break;
			default:
				showOperation->Text = System::Convert::ToString(firstNum) + " " + operation->Text;
		}
		txtBox->Focus();
	}

	private: System::Void piButton_Click(System::Object^ sender, System::EventArgs^ e) {
		const double pi = 3.1415926535897932384626433;
		txtBox->Text = "\r\n" + System::Convert::ToString(pi);
		txtBox->Focus();
	}

	private: System::Void eulerNumberButton_Click(System::Object^ sender, System::EventArgs^ e) {
		const double eulerNumber = 2.7182818284590452353602874;
		txtBox->Text = "\r\n" + System::Convert::ToString(eulerNumber);
		txtBox->Focus();
	}

	private: System::Void randButton_Click(System::Object^ sender, System::EventArgs^ e) {
		double randomNumber = safe_cast<double>(rand()) / safe_cast<double>(RAND_MAX);
		txtBox->Text = "\r\n" + System::Convert::ToString(randomNumber);
		funcPanel->Hide();
		txtBox->Focus();
	}

	private: System::Void InvertTrigButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (defaultTrigFunctions->Visible) {
			defaultTrigFunctions->Hide();
		}
		else {
			defaultTrigFunctions->Show();
		}
		txtBox->Focus();
	}

	private: System::Void trigButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (trigonometryPanel->Visible) {
			trigonometryPanel->Hide();
		}
		else {
			trigonometryPanel->Show();
			funcPanel->Hide();
		}
		txtBox->Focus();
	}

	private: System::Void changeTrigUnitType_Click(System::Object^ sender, System::EventArgs^ e) {
		if (gradesButton->Visible) {
			gradesButton->Hide();
		}
		else {
			gradesButton->Show();
		}
		txtBox->Focus();
	}

	private: System::Void trigFunctions_Click(System::Object^ sender, System::EventArgs^ e) {
		Button^ trigType = safe_cast<Button^>(sender);
		double (*trigFunctPtr[])(double) = { sin, cos, tan, sinh, cosh, tanh, asin, acos, atan, asinh, acosh, atanh };
		double currentNumber = System::Double::Parse(txtBox->Text);
		if (gradesButton->Visible) {
			const double GradesPerRadian = 57.2957795;
			currentNumber /= GradesPerRadian;
		}
		currentNumber = (*trigFunctPtr[System::Convert::ToInt32(trigType->Tag)])(currentNumber);
		txtBox->Text = "\r\n" + System::Convert::ToString(currentNumber);
		trigonometryPanel->Hide();
		txtBox->Focus();
	}

	private: System::Void otherOptionsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (defaultOptionsPanel->Visible) {
			defaultOptionsPanel->Hide();
		}
		else {
			defaultOptionsPanel->Show();
		}
		txtBox->Focus();
	}
	private: System::Void funcButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (funcPanel->Visible) {
			funcPanel->Hide();
		}
		else {
			funcPanel->Show();
			trigonometryPanel->Hide();
		}
		txtBox->Focus();
	}

	private: System::Void txtBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if (txtBox->Text->Length > 32) {
			txtBox->Text = txtBox->Text->Remove(txtBox->Text->Length - 1);
		}
		else if (txtBox->Text->Length > 28) {
			if (txtBox->Font->Size == 11) {
				return;
			}
			txtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
		}
		else if (txtBox->Text->Length > 21) {
			if (txtBox->Font->Size == 12) {
				return;
			}
			txtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
		}
		else if (txtBox->Text->Length > 16) {
			if (txtBox->Font->Size == 16) {
				return;
			}
			txtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
		}
		else if (txtBox->Font->Size != 20) {
			txtBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
		}
	}
};
}
