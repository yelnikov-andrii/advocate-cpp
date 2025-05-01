#pragma once
#include "ClientManager.h"
#include "Validator.h"

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
	public ref class AddClient : public System::Windows::Forms::Form
	{
	public:
		delegate void RefreshTableDelegate(String^ fullname);

		RefreshTableDelegate^ refreshDelegate;
		String^ advocateFullnameStr;
		AddClient(String^ advocateFullname, RefreshTableDelegate^ refreshFunc)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->advocateFullnameStr = advocateFullname;
			this->refreshDelegate = refreshFunc;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddClient()
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
	private: System::Windows::Forms::TextBox^ textBox4;
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
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(116, 99);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 21);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(113, 81);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Ім\'я та прізвище";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(116, 161);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(182, 21);
			this->textBox3->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(116, 146);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 15);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Телефон";
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox4->Location = System::Drawing::Point(116, 215);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(182, 21);
			this->textBox4->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(116, 200);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 15);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Email";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(116, 255);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(182, 36);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Створити користувача";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddClient::button1_Click);
			// 
			// AddClient
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(540, 339);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"AddClient";
			this->Text = L"Додати користувача";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ fullname = this->textBox1->Text;
		System::String^ phone = this->textBox3->Text;
		System::String^ email = this->textBox4->Text;


		if (fullname == "" || phone == "" || email == "") {
			MessageBox::Show("Заповніть всі поля", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else if (!Validator::IsValidPhone(phone)) {
			MessageBox::Show("Невірний формат номера телефону. Використовуйте +380XXXXXXXXX", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else if (!Validator::IsValidEmail(email)) {
			MessageBox::Show("Невірний формат електронної пошти", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			ClientManager^ clientManager = gcnew ClientManager();
			bool res = clientManager->addClient(advocateFullnameStr, fullname, phone, email, "clients.txt");

			if (res == true) {
				MessageBox::Show("Клієнта успішно додано!", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->textBox1->Clear();
				this->textBox3->Clear();
				this->textBox4->Clear();
				this->refreshDelegate(advocateFullnameStr);
			}
			else {
				MessageBox::Show("Не вдалося відкрити файл для запису", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	};
}
