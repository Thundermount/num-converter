#pragma once
#include <iostream>
#include <bitset>
#include <msclr\marshal_cppstd.h>
#include "Number.h"
namespace Table {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:








	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"из";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(283, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(15, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"в";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(33, 107);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(158, 22);
			this->textBox1->TabIndex = 10;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(286, 107);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(158, 22);
			this->textBox2->TabIndex = 11;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(148, 146);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 47);
			this->button1->TabIndex = 12;
			this->button1->Text = L"преобразовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"двоична€", L"восьмерична€", L"дес€тирична€",
					L"шестнадцатерична€"
			});
			this->comboBox1->Location = System::Drawing::Point(33, 55);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(158, 24);
			this->comboBox1->TabIndex = 14;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"двоична€", L"восьмерична€", L"дес€тирична€",
					L"шестнадцатерична€"
			});
			this->comboBox2->Location = System::Drawing::Point(286, 55);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(158, 24);
			this->comboBox2->TabIndex = 15;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(476, 216);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Number^ n;
	String^ in = textBox1->Text;
	if (comboBox1->SelectedIndex == 0) {
		n = gcnew Number(in, false);
		if (comboBox2->SelectedIndex == 0) {
			textBox2->Text = in;
		}
		if (comboBox2->SelectedIndex == 1) {
			n->BinarytoDec();
			n->DectoOct();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 2) {
			n->BinarytoDec();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 3) {
			n->BinarytoDec();
			n->DectoHex();
			textBox2->Text = n->GetNumber();
		}
	}
	if (comboBox1->SelectedIndex == 1) {
		n = gcnew Number(in, false);
		if (comboBox2->SelectedIndex == 0) {
			n->OcttoDec();
			n->DectoBinary();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 1) {
			textBox2->Text = in;
		}
		if (comboBox2->SelectedIndex == 2) {
			n->OcttoDec();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 3) {
			n->OcttoDec();
			n->DectoHex();
			textBox2->Text = n->GetNumber();
		}
	}
	if (comboBox1->SelectedIndex == 2) {
		n = gcnew Number(in, false);
		if (comboBox2->SelectedIndex == 0) {
			n->DectoBinary();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 1) {
			n->DectoOct();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 2) {
			textBox2->Text = in;
		}
		if (comboBox2->SelectedIndex == 3) {
			n->DectoHex();
			textBox2->Text = n->GetNumber();
		}
	}
	if (comboBox1->SelectedIndex == 3) {
		n = gcnew Number(in, true);
		if (comboBox2->SelectedIndex == 0) {
			n->HextoDec();
			n->DectoBinary();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 1) {
			n->HextoDec();
			n->DectoOct();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 2) {
			n->HextoDec();
			textBox2->Text = n->GetNumber();
		}
		if (comboBox2->SelectedIndex == 3) {
			textBox2->Text = in;
		}
	}
	
}
};
}
