#pragma once
#include <stdlib.h>
#include <ostream>
#include <iostream>

namespace windowsforms {

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

	/// <summ
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{

		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Label^  equal;
		private: System::Windows::Forms::Button^  button3;

		private: Double** elements;
		private: cli::array<TextBox^,2>^ boxElements;
		private: cli::array<TextBox^,1>^boxResultElements;
		private: Double* resultElements;
		private: Double* Variable;
		private: cli::array<Label^,1>^ labelVariable;


		private: int matrixSize;
		public:
		MyForm(void)
		{
			InitializeComponent();

			this->numericUpDown1->Minimum = 2;
			this->numericUpDown1->Maximum = (this->Height-100)/25;
			this->button1->Enabled = false;
			this->button2->Enabled = true;
			this->button3->Enabled = false;
		}

		protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	#pragma region initialize components
	void InitializeComponent(void)
	{
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->button3 = (gcnew System::Windows::Forms::Button());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Location = System::Drawing::Point(255, 25);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(75, 23);
		this->button1->TabIndex = 0;
		this->button1->Text = L"Solve System";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &MyForm::solveSystem);
		// 
		// numericUpDown1
		// 
		this->numericUpDown1->Location = System::Drawing::Point(20, 28);
		this->numericUpDown1->Name = L"numericUpDown1";
		this->numericUpDown1->Size = System::Drawing::Size(40, 20);
		this->numericUpDown1->TabIndex = 1;
		this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
		this->numericUpDown1->Click += gcnew System::EventHandler(this, &MyForm::changeDetected);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(12, 12);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(109, 13);
		this->label1->TabIndex = 2;
		this->label1->Text = L"Select the matrix size.";
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(66, 28);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(40, 20);
		this->button2->TabIndex = 4;
		this->button2->Text = L"Ok";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &MyForm::CreateMatrix);
		// 
		// button3
		// 
		this->button3->Location = System::Drawing::Point(143, 25);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(75, 23);
		this->button3->TabIndex = 5;
		this->button3->Text = L"Reset";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &MyForm::resetButton);
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(617, 427);
		this->Controls->Add(this->button3);
		this->Controls->Add(this->button2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->numericUpDown1);
		this->Controls->Add(this->button1);
		this->Name = L"MyForm";
		this->Text = L"MyForm";
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
	

	Double** matrix_alloc(int n){

		int i;
		Double **m =new Double*[n];

		for(i = 0; i <= n; i++){
			m[i] = new Double;
		}
		return m;
	}

	int changeRows(int index, Double** matrixA, int n){
		int row = 0;
		Double* buffer = new Double[n+1];

		for(int j = 0; j <= n;j ++){
			buffer[j] = matrixA[index][j];
		}
		for(int i=index; i<n;i++){
			if(matrixA[i][index] != 0){
				row = i;
				break;
			}
		}

		if(row == 0)
			return 0;

		for(int j = 0; j<=n;j++){
			matrixA[index][j] = matrixA[row][j];
			matrixA[row][j] = buffer[j];
		}

		delete buffer;
		
		return 1;
	}

	Double** gaussElimination(Double** m,Double *b,int n){

		Double** matrixA;
		Double aux;

		matrixA = new Double*[n];

		for(int i = 0;i <= n;i++){
			matrixA[i] = new Double;
		}

		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				matrixA[i][j] = m[i][j];
				std::cout << matrixA[i][j] << " ";
			}
			std::cout << std::endl;

		}
	
		for(int i = 0;i < n;i++){
			matrixA[i][n]= b[i];
		}

		Double mainPivo,auxPivo;
		int nullCollum = 0;
		//escalonamento simples, sem zero na diagonal principal
		for(int k = 0;k < n-1;k++){
			for(int i = k+1;i < n;i++){
				mainPivo = matrixA[k][k];
				auxPivo = matrixA[i][k];
				nullCollum = 0;
				for(int j = k;j <= n;j++){
					if(mainPivo == 0){
						if(!changeRows(k,matrixA,n)){
							//nullCollum = 1;
							break;
						}
						mainPivo = matrixA[k][k];
						auxPivo = matrixA[i][k];
					}
					if(j == k)
						matrixA[i][k] = 0;

					else if(auxPivo == 0)
						break;

					else{
						matrixA[i][j] = matrixA[k][j]*auxPivo - matrixA[i][j]*mainPivo;
					}
				}
				if(nullCollum)
					break;
			}
		}
		return matrixA;
	}

	int upper_triangular(Double **m, int n){
		int i,j;
		//check up for a triangular superior matrix
		for(i = 1;i < n;i ++){
			for(j = 0;j < i-1;j++){
				if(m[i][j] != 0)
					return 0;
			}
		}
		return 1;
	}

	int lower_triangular(Double **m, int n){
		int i,j;
		for(i = 0;i < n-1;i++){
			for(j = i+1;j < n;j ++){
				if(m[i][j] != 0)
					return 0;
			}

		}
		return 1;
	}

	int checkup_matrix(Double **m, int n){
		int i;
		for(i=0;i<n;i++){
			if(!m[i][i])
				return -1;
		}

		if(lower_triangular(m,n))
			return 1;
		else if(upper_triangular(m,n))
			return 2;
		else
			return 0;
	}

	Double* upper_triangular_system(Double **m,Double *b,int n){
		int i,j;
		Double *x = new Double[n],aux;


		for(i = n-1;i>=0;i--){
			aux=0;
			for(j=i + 1;j < n;j ++){
				aux += m[i][j] * x[j];
			}
			x[i] = (b[i] - aux)/m[i][i];
		}
		return x;
	}

	Double * lower_triangular_system(Double **m,Double *b,int n){
		int i,j;
		Double aux;
		Double *x = new Double[n];

		for(i=0;i<n;i++){
			aux = 0;
			for(j=i-1;j>=0;j--){
				aux+= m[i][j] * x[j];
			}
			x[i] = (b[i] - aux) / m[i][i];
		}
		return x;

	}

	int SPIorSI(Double **matrixA, int n){
		/*int product = 1;
		for(int i =0;i < n;i++){
			product*=matrixA[i][i];
		}

		if(product == 0)
			return 1;*/
		
		for(int i = 1;i < n; i++){
			if(matrixA[i][n] == 0 && matrixA[i][n-1] == 0)
				break;
			else if(matrixA[i][n] == 0 || matrixA[i][n-1] == 0)
				return 2;
		}
			
		int isZero;
		for(int i=0;i<n;i++){
			isZero = 1;
			if(matrixA[i][i] == 0){
				for(int j=i;j<=n;j++){
					if(matrixA[i][j] != 0){
						isZero = 0;
						break;
					}
				}
				if(isZero)
					return 1;// SPI
			}
		}

		return 0; // SPD
	}

	private: System::Void solveSystem(System::Object^  sender, System::EventArgs^  e) {
		
		int heightMargin = this->button2->Location.Y + this->button2->Height + 20;
		int widthMargin = this->numericUpDown1->Location.X;
		int matrixSize = (int)this->numericUpDown1->Value;
		elements = matrix_alloc(matrixSize);
		resultElements = new Double[matrixSize];

		int space = 5;
		int st = 0;
		Double **matrixA;

		Double value;
		for(int i = 0;i < matrixSize;i++){
			for(int j = 0;j < matrixSize;j++){
				Double::TryParse(boxElements[i,j]->Text,value);
				elements[i][j] = value;
			}
		}

		for(int i = 0;i < matrixSize;i++){
			Double::TryParse(boxResultElements[i]->Text,value);
			resultElements[i] = value;
		}
		
		matrixA = gaussElimination(elements,resultElements,matrixSize);

		for(int i =0;i < matrixSize;i ++){
			for(int j =0;j < matrixSize;j ++){
				this->boxElements[i,j]->Text = System::Convert::ToString(matrixA[i][j]);
			}	
		}
		for(int i = 0;i < matrixSize;i ++){
			this->boxResultElements[i]->Text = System::Convert::ToString(matrixA[i][matrixSize]);
		}
		
		st = SPIorSI(matrixA,matrixSize);
		st = 0;
		if(st == 0){
	
			for(int i=0;i < matrixSize; i++){
				for(int j=0;j < matrixSize;j++){
					elements[i][j] = matrixA[i][j];
				}
				resultElements[i] = matrixA[i][matrixSize];
			}

			int matrixType = checkup_matrix(elements,matrixSize);

			if(matrixType == 1)
				Variable = lower_triangular_system(elements,resultElements,matrixSize);
			else if (matrixType == 2)
				Variable = upper_triangular_system(elements,resultElements,matrixSize);			
			else
				MessageBox::Show(
			 "Invalid matrix!! You need to insert a triangular matrix", 
			 "Error!", MessageBoxButtons::OK);
			if(matrixType == 1 || matrixType == 2)
				for(int i =0;i<matrixSize;i++){
					std::cout << Variable[i] << std::endl;

					labelVariable[i]->Text = System::Convert::ToString(Variable[i]);
					labelVariable[i]->Visible = true;
			}
		}
		else if(st == 2)
			MessageBox::Show(
			 "System SI", 
			 "Error!", MessageBoxButtons::OK);
		else
			MessageBox::Show(
			 "System SPI", 
			 "Error!", MessageBoxButtons::OK);

		//for(int i = 0; i< matrixSize; i++)
		//	delete(matrixA[i]);
		//delete(matrixA);

	}

	private: System::Void CreateMatrix(System::Object^  sender, System::EventArgs^  e) {
		
		int matrixSize = (int)this->numericUpDown1->Value;
		int heightMargin = this->button2->Location.Y + this->button2->Height + 20;
		int widthMargin = this->numericUpDown1->Location.X;
		int textBoxHeight = 20;
		int textBoxWidth = 30;
		int labelWidth = 150;
		int labelHeight = 20;
		this->matrixSize = matrixSize;

		boxElements = gcnew cli::array<TextBox^,2>(matrixSize,matrixSize);
		boxResultElements = gcnew cli::array<TextBox^,1>(matrixSize);


		for(int i = 0;i < matrixSize;i++){
			for(int j = 0;j < matrixSize;j++){
				TextBox^ a = gcnew TextBox();
				a->Visible = true;
				a->Size = System::Drawing::Size(textBoxWidth, textBoxHeight);
				boxElements[i,j] = a;
				if(j == 0 && i == 0)
					a->Location = System::Drawing::Point(widthMargin,heightMargin);
				
				a->Location = System::Drawing::Point(widthMargin + j*a->Size.Width,heightMargin + i*a->Size.Height);
				this->Controls->Add(a);
			}	
		}
		for(int i=0;i<matrixSize;i++){
			TextBox^ a = gcnew TextBox();
			a->Visible = true;
			a->Size = System::Drawing::Size(textBoxWidth, textBoxHeight);
			boxResultElements[i] = a;
			a->Location = System::Drawing::Point(a->Width*matrixSize + widthMargin + a->Width*2,heightMargin + a->Height*i);
			this->Controls->Add(a);
		}
		equal = gcnew Label();//equal sign
		equal->Text = "=";
		equal->Font = gcnew System::Drawing::Font(equal->Font->FontFamily,30);
		equal->Size = System::Drawing::Size(50,50);
		

		labelVariable = gcnew array<Label^,1>(matrixSize);

		for(int i=0;i<matrixSize;i++){

			Label^ a = gcnew Label();
			a->Visible = false;
			a->Size = System::Drawing::Size(labelWidth,labelHeight);
			a->Location = System::Drawing::Point(boxResultElements[0]->Location.X + boxResultElements[0]->Width+5,heightMargin + labelHeight*i);
			labelVariable[i] = a;
			this->Controls->Add(a);

		}


		int differenceXY = boxResultElements[0]->Location.X - (widthMargin+matrixSize*textBoxWidth);
		
		int xLocation = widthMargin+textBoxWidth*matrixSize+differenceXY-equal->Width;
		int yLocation = boxResultElements[0]->Height*matrixSize/2 - equal->Height/2 + heightMargin;

		equal->Location = System::Drawing::Point(xLocation,yLocation);
		this->Controls->Add(equal);

		this->button1->Enabled = true;
		this->button3->Enabled = true;
		this->button2->Enabled = false;
	}

	private: System::Void resetButton(System::Object^  sender, System::EventArgs^  e) {
		
		this->button2->Enabled = true;
		this->button3->Enabled = false;
		this->button1->Enabled = false;

		for(int i = 0;i < matrixSize;i++){
			for(int j = 0;j < matrixSize;j++){
				delete(boxElements[i,j]);
			}
		}
		delete(equal);


		for(int i=0;i<matrixSize;i++){
			delete(boxResultElements[i]);
			delete(labelVariable[i]);
		}

	}

	private: System::Void changeDetected(System::Object^sender,System::EventArgs^e){
		this->numericUpDown1->Maximum = (this->Height-100)/25;
	}
};


}

