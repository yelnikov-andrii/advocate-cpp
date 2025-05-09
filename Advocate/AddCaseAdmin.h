#pragma once
#include "CasesManager.h"
#include "UserManager.h"
#include "ClientManager.h"

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
	public ref class AddCaseAdmin : public System::Windows::Forms::Form
	{
	public:
		delegate void RefreshTableDelegate();

		RefreshTableDelegate^ refreshDelegate;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	public:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label5;
	public: AddCaseAdmin(RefreshTableDelegate^ refreshFunc)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->refreshDelegate = refreshFunc;

			UserManager^ userManagerAdminSecond = gcnew UserManager();
			List<User^>^ users = userManagerAdminSecond->readUsersFromFile("users.txt");

			for (int i = 0; i < users->Count; i++) {
				if (users[i]->fullname->Trim() == "admin") {
					continue;
				}
				String^ fullname = users[i]->fullname;
				this->comboBox2->Items->Add(fullname);
			};
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddCaseAdmin()
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(474, 284);
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
			this->label1->Location = System::Drawing::Point(474, 259);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Заголовок";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(474, 366);
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
			this->label3->Location = System::Drawing::Point(474, 341);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Опис";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(475, 424);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Статус";
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(474, 524);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(273, 64);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Додати справу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AddCaseAdmin::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Нова", L"В роботі", L"Очікує клієнта", L"Призупинена",
					L"Завершена", L"Відхилена", L"Архівована"
			});
			this->comboBox1->Location = System::Drawing::Point(474, 200);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(271, 31);
			this->comboBox1->TabIndex = 11;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(474, 175);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 20);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Клієнт";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(474, 120);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(271, 31);
			this->comboBox2->TabIndex = 13;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &AddCaseAdmin::comboBox2_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(470, 95);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 20);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Адвокат";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Нова", L"В роботі", L"Очікує клієнта", L"Призупинена",
					L"Завершена", L"Відхилена", L"Архівована"
			});
			this->comboBox3->Location = System::Drawing::Point(476, 449);
			this->comboBox3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(271, 31);
			this->comboBox3->TabIndex = 15;
			// 
			// AddCaseAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1293, 817);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label2);
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
			this->Name = L"AddCaseAdmin";
			this->Text = L"Додати справу";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ title = this->textBox1->Text;
		System::String^ description = this->textBox3->Text;
		System::String^ status = this->comboBox3->SelectedItem->ToString();
		System::String^ selectedAdvocate = this->comboBox2->SelectedItem
			? this->comboBox2->SelectedItem->ToString()->Trim() : "";
		String^ selectedClient = comboBox1->SelectedItem->ToString();
		array<String^>^ parts = selectedClient->Split(gcnew array<wchar_t>{'|'}, 2);
		String^ clientId = parts[0]->Trim();

		MessageBox::Show(clientId);

		if (title == "" || description == "" || status == "") {
			MessageBox::Show("Заповніть всі поля", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else if (selectedAdvocate == "" || selectedClient == "") {
			MessageBox::Show("Виберіть адвоката та клієнта", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else {
			CasesManager^ casesManager = gcnew CasesManager();

			bool res = casesManager->addCase(selectedAdvocate, clientId, title, description, status, "cases.txt");

			if (res == true) {
				MessageBox::Show("Справу успішно додано!", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->textBox1->Clear();
				this->textBox3->Clear();
				this->refreshDelegate();
			}
			else {
				MessageBox::Show("Не вдалося відкрити файл для запису", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	comboBox1->Items->Clear();

	String^ selectedAdvocate = comboBox2->SelectedItem->ToString()->Trim();
	ClientManager^ clientManager = gcnew ClientManager();

	try {
		List<Client^>^ clients = clientManager->readClientsFromFile(selectedAdvocate, "clients.txt");
		if (clients != nullptr) {
			for (int i = 0; i < clients->Count; i++) {
				String^ id = clients[i]->id->Trim();
				String^ fullname = clients[i]->fullname->Trim();
				comboBox1->Items->Add(id + " | " + fullname);
			}
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Помилка при завантаженні клієнтів: " + ex->Message);
	}
}

};
}
