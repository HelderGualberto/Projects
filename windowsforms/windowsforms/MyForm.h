#pragma once
#include <stdlib.h>

namespace windowsforms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			this->numericUpDown1->Minimum = 2;
			this->numericUpDown1->Maximum = (this->Height-100)/25;
			

			//array<array<Double^>^>^ elements;
			//array<array<TextBox^>^>^ boxElements;
	
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;
	private: cli::array<int^,2>^ elements;
	private: cli::array<TextBox^,2>^ boxElements;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label3;
	protected: 


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.


		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(527, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Click Here";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::solveSystem);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(20, 51);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(40, 20);
			this->numericUpDown1->TabIndex = 1;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {2, 0, 0, 0});
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Select the matrix size.";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(173, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"The matrix must be a square matrix.";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(66, 51);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(40, 20);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Ok";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::CreateMatrix);
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(276, 51);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(52, 20);
			this->numericUpDown2->TabIndex = 5;
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDown2_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(373, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"label3";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(617, 427);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


	private: System::Void solveSystem(System::Object^  sender, System::EventArgs^  e) {
		int matrixSize = (int)this->numericUpDown1->Value;
		elements = gcnew cli::array<int^,2>(matrixSize,matrixSize);
		int value;
		int % aout = value;
				
		for(int i = 0;i < matrixSize;i++){
			for(int j = 0;j < matrixSize;j++){
				Int32::TryParse(boxElements[i,j]->Text,value);
				elements[i,j] = value;
			}
		}

		
	}

	private: System::Void CreateMatrix(System::Object^  sender, System::EventArgs^  e) {
		
		int matrixSize = (int)this->numericUpDown1->Value;
		int height = this->button2->Location.Y + this->button2->Height + 20;
		int width = this->numericUpDown1->Location.X;
		boxElements = gcnew cli::array<TextBox^,2>(matrixSize,matrixSize);

		for(int i = 0;i < matrixSize;i++){
			for(int j = 0;j < matrixSize;j++){
				TextBox^ a = gcnew TextBox();
				a->Visible = true;
				a->Size = System::Drawing::Size(30, 20);
				boxElements[i,j] = a;
				if(j == 0 && i == 0)
					a->Location = System::Drawing::Point(width,height);
				
				a->Location = System::Drawing::Point(width + j*a->Size.Width,height + i*a->Size.Height);
				this->Controls->Add(a);
			}	
		}

	}
	

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 int a = (int)this->numericUpDown2->Value;
			 
			 this->label3->Text = elements[a,a]->ToString();
}

};


}

