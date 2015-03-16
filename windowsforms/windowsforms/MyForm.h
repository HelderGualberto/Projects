#pragma once
#include <stdlib.h>
#include <ostream>

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

		private: System::Windows::Forms::Button^  button1;
		private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
		private: System::Windows::Forms::Label^  label1;
		private: System::Windows::Forms::Button^  button2;
		private: System::Windows::Forms::Label^  equal;
		private: System::Windows::Forms::Button^  button3;

		private: int** elements;
		private: cli::array<TextBox^,2>^ boxElements;
		private: cli::array<TextBox^,1>^boxResultElements;
		private: int* resultElements;
		private: float* unknowns;
		private: cli::array<Label^,1>^ labelUnknowns;
		
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
	
int** matrix_alloc(int n){

    int i;
    int **m =new int*[n];

    for(i = 0; i < n; i++){
        m[i] = new int;
    }
    return m;
}

int upper_triangular(int **m, int n){
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

int lower_triangular(int **m, int n){
    int i,j;
    for(i = 0;i < n-1;i++){
        for(j = i+1;j < n;j ++){
            if(m[i][j] != 0)
                return 0;
        }

    }
    return 1;
}

int checkup_matrix(int **m, int n){
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

float* upper_triangular_system(int **m,int *b,int n){
    int i,j;
	float *x = new float[n],aux;


    for(i = n-1;i>=0;i--){
        aux=0;
        for(j=i + 1;j < n;j ++){
            aux += (float)m[i][j] * (float)x[j];
        }
        x[i] = (float)(b[i] - aux)/(float)m[i][i];
    }
    return x;
}

float * lower_triangular_system(int **m,int *b,int n){
    int i,j;
    float aux;
    float *x = new float[n];

    for(i=0;i<n;i++){
        aux = 0;
        for(j=i-1;j>=0;j--){
            aux+= m[i][j] * x[j];
        }
        x[i] = (float)(b[i] - aux) / (float)m[i][i];
    }
    return x;

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
		this->button3->Name = L"Reset";
		this->button3->Size = System::Drawing::Size(75, 23);
		this->button3->TabIndex = 5;
		this->button3->Text = L"Reset";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
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


	void viadagem(){}

	private: System::Void solveSystem(System::Object^  sender, System::EventArgs^  e) {
		
		int heightMargin = this->button2->Location.Y + this->button2->Height + 20;
		int widthMargin = this->numericUpDown1->Location.X;
		int matrixSize = (int)this->numericUpDown1->Value;
		elements = matrix_alloc(matrixSize);
		resultElements = new int[matrixSize];

		int space = 5;

		int value;
		int % aout = value;
				
		for(int i = 0;i < matrixSize;i++){
			for(int j = 0;j < matrixSize;j++){
				Int32::TryParse(boxElements[i,j]->Text,value);
				elements[i][j] = value;
			}
		}

		for(int i = 0;i < matrixSize;i++){
			Int32::TryParse(boxResultElements[i]->Text,value);
			resultElements[i] = value;
		}
		
		int matrixType = checkup_matrix(elements,matrixSize);

		if(matrixType == 1)
			unknowns = lower_triangular_system(elements,resultElements,matrixSize);
		else if (matrixType == 2)
			unknowns = upper_triangular_system(elements,resultElements,matrixSize);			
		else
			MessageBox::Show(
         "Invalid matrix!! You need to insert a triangular matrix", 
		 "Error!", MessageBoxButtons::OK);
		if(matrixType == 1 || matrixType == 2)
			for(int i =0;i<matrixSize;i++){
				labelUnknowns[i]->Text = System::Convert::ToString(unknowns[i]);
				labelUnknowns[i]->Visible = true;
			}

		

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
		

		labelUnknowns = gcnew array<Label^,1>(matrixSize);

		for(int i=0;i<matrixSize;i++){

			Label^ a = gcnew Label();
			a->Visible = false;
			a->Size = System::Drawing::Size(labelWidth,labelHeight);
			a->Location = System::Drawing::Point(boxResultElements[0]->Location.X + boxResultElements[0]->Width+5,heightMargin + labelHeight*i);
			labelUnknowns[i] = a;
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

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		
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
			delete(labelUnknowns[i]);
		}

	}









};


}

