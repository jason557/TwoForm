#pragma once
#include "Form2.h"

namespace TwoForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1^ instance;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::TextBox^  textBox1;
	public: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^ button2;
	public:
	public:
	private:
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
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(203, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(232, 47);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Sent to ChildForm";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(14, 145);
			this->textBox1->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(529, 30);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(12, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(203, 299);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(232, 47);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Reset ChildForm";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(663, 479);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"Form1";
			this->Text = L"Parent Form";
			this->TopMost = true;
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	public: Form2^ f2;
	public: Form1(void)
	{
		InitializeComponent();
		f2 = gcnew Form2();
		f2->sentDataEvent += gcnew Form2::sentData(this, &TwoForm::Form1::getdata); // Events have only 2 args
	}

	private: void getdata(System::Object^  sender, System::EventArgs^  e, String^ text) // From child form 1
	{
		this->label1->Text = text; // Here's where we display the message from the Form2
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->f2->label1->Text = textBox1->Text;
	}

	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) {
		f2->Show();
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		this->f2->label1->Text = textBox1->Text;
		if (this->textBox1->Text == "label1")
		{
			this->textBox1->Text = "";
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {		
		this->textBox1->Text = "";
		this->f2->label1->Text = "label1";
	}
};
}
