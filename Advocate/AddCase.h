#pragma once
#include "CasesManager.h"

namespace Advocate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class AddCase : public System::Windows::Forms::Form
	{
	public:
		delegate void RefreshTableDelegate();


		RefreshTableDelegate^ refreshDelegate;
		String^ advocateFullnameStr;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	public:
		String^ clientId;
		AddCase(String^ advocateFullname, String^ clientIdStr, RefreshTableDelegate^ refreshFunc)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->refreshDelegate = refreshFunc;
			this->clientId = clientIdStr;
			this->advocateFullnameStr = advocateFullname;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddCase()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(174, 175);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(271, 27);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(170, 143);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"���������";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(174, 259);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(271, 27);
			this->textBox3->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(170, 234);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"����";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(170, 318);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"������";
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(174, 411);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(273, 64);
			this->button1->TabIndex = 10;
			this->button1->Text = L"������ ������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddCase::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"����", L"� �����", L"����� �볺���", L"�����������",
					L"���������", L"³�������", L"����������"
			});
			this->comboBox1->Location = System::Drawing::Point(174, 343);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(271, 31);
			this->comboBox1->TabIndex = 11;
			// 
			// AddCase
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(810, 600);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"AddCase";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������ �����������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		


#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ title = this->textBox1->Text;
		System::String^ description = this->textBox3->Text;
		System::String^ status = this->comboBox1->Text;


		if (title == "" || description == "" || status == "") {
			MessageBox::Show("�������� �� ����", "�������", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			CasesManager^ casesManager = gcnew CasesManager();
			bool res = casesManager->addCase(advocateFullnameStr, clientId, title, description, status, "cases.txt");

			if (res == true) {
				MessageBox::Show("������ ������ ������!", "����", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->textBox1->Clear();
				this->textBox3->Clear();
				this->refreshDelegate();
				
			}
			else {
				MessageBox::Show("�� ������� ������� ���� ��� ������", "�������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
};
}
