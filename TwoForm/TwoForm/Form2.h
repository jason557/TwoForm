#pragma once


namespace TwoForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form2
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	private:
		
	public:
		Form2()
		{
			InitializeComponent();

			// save reference to main form
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^  textBox1;
	protected:

	protected:
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^ button2;
	public:
	private:

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(42, 138);
			this->textBox1->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(529, 30);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form2::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(210, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(199, 39);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Send to Mainform";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(38, 84);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(210, 271);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(199, 39);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Reset Mainform";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->ClientSize = System::Drawing::Size(663, 479);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Consolas", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 6, 5, 6);
			this->Name = L"Form2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ChildForm";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: delegate void sentData(System::Object^ sender, System::EventArgs^ e, String^ message); // Publish an event (with a text message) that others can subscribe to
	public: event sentData^ sentDataEvent;
	

	public: void issueEvent(System::Object^  sender, System::EventArgs^  e)	//This is where we publish the event to all subscribers
	{
		this->sentDataEvent(this, e, this->textBox1->Text); // Raise the event using the EventDelegate signature
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->issueEvent(sender, e);
		
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
		if (this->textBox1->Text != "")
		{
			this->issueEvent(sender, e);
		}

		if (this->textBox1->Text == "label1")
		{
			this->textBox1->Text = "";
		}

	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->textBox1->Text = "label1";
	  		
	}
};
}
