#pragma once
#include "AddClient.h"
#include "EditClient.h"
#include "ClientManager.h"
#include "CasesForm.h"

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

	public ref class AdvocateDashboard : public System::Windows::Forms::Form
	{
	public:
		String^ advocateFullname;
	public:
		AdvocateDashboard(System::String^ fullname)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			advocateFullname = fullname;
			this->Text = "Адміністративна панель " + fullname;

			ClientManager^ clientManager = gcnew ClientManager();

			try {
				List<Client^>^ clients = clientManager->readClientsFromFile(fullname, "clients.txt");
				if (clients != nullptr) {
					for (int i = 0; i < clients->Count; i++) {
						String^ id = clients[i]->id;
						String^ advocateFullname = clients[i]->advocateFullname;
						String^ fullname = clients[i]->fullname;
						String^ phone = clients[i]->phone;
						String^ email = clients[i]->email;
						this->dataGridView1->Rows->Add(id, advocateFullname, fullname, phone, email);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Помилка при завантаженні клієнтів: " + ex->Message);
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdvocateDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button1;
	public:
		void RefreshClientsTable(String^ advocateFullname) {
			this->dataGridView1->Rows->Clear();

			ClientManager^ clientManager = gcnew ClientManager();
			List<Client^>^ clients = clientManager->readClientsFromFile(advocateFullname, "clients.txt");

			for (int i = 0; i < clients->Count; i++) {
				String^ id = clients[i]->id;
				String^ advocateFullname = clients[i]->advocateFullname;
				String^ fullname = clients[i]->fullname;
				String^ phone = clients[i]->phone;
				String^ email = clients[i]->email;
				this->dataGridView1->Rows->Add(id, advocateFullname, fullname, phone, email);
			}
		};

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Location = System::Drawing::Point(118, 150);
			this->tabControl1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1051, 515);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 32);
			this->tabPage1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tabPage1->Size = System::Drawing::Size(1043, 479);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Клієнти";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(744, 382);
			this->button4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(224, 51);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Переглянути справи";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &AdvocateDashboard::button4_Click);
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(500, 382);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(218, 51);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Видалити клієнта";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdvocateDashboard::button3_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(236, 382);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(208, 51);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Редагувати клієнта";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdvocateDashboard::button2_Click);
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(24, 382);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Додати клієнта";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdvocateDashboard::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 27);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(944, 324);
			this->dataGridView1->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 125;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Адвокат";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"ПІБ";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Телефон";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 125;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Email";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 125;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(124, 83);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(356, 30);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &AdvocateDashboard::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(120, 46);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Пошук";
			// 
			// AdvocateDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1352, 748);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"AdvocateDashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Advocate::AddClient^ addClient = gcnew Advocate::AddClient(advocateFullname, gcnew Advocate::AddClient::RefreshTableDelegate(this, &Advocate::AdvocateDashboard::RefreshClientsTable));
	addClient->Show();
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView1->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView1->Rows->Count) {
		selectedRow = dataGridView1->Rows[selectedIndex];

		String^ id = selectedRow->Cells[0]->Value->ToString();
		String^ advocateFullname = selectedRow->Cells[1]->Value->ToString();
		String^ fullname = selectedRow->Cells[2]->Value->ToString();
		String^ phone = selectedRow->Cells[3]->Value->ToString();
		String^ email = selectedRow->Cells[4]->Value->ToString();

		ClientManager^ clientManager = gcnew ClientManager();
		Client^ foundClient = clientManager->getOne(id, "clients.txt");

		Advocate::EditClient^ editClientForm = gcnew Advocate::EditClient(advocateFullname, gcnew Advocate::EditClient::RefreshTableDelegate(this, &Advocate::AdvocateDashboard::RefreshClientsTable));
		if (foundClient) {
			editClientForm->SetData(foundClient->id, foundClient->fullname->Trim(), foundClient->phone->Trim(), foundClient->email->Trim());
			editClientForm->ShowDialog();
		}
	}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView1->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView1->Rows->Count) {
		selectedRow = dataGridView1->Rows[selectedIndex];

		String^ id = selectedRow->Cells[0]->Value->ToString();
		String^ fullname = selectedRow->Cells[2]->Value->ToString();

		ClientManager^ clientManager = gcnew ClientManager();
		List<Client^>^ clients = clientManager->readClientsFromFile(advocateFullname, "clients.txt");
		Client^ foundClient;

		CasesManager^ casesManager = gcnew CasesManager();

		for (int i = 0; i < clients->Count; i++) {
			if (clients[i]->id == id) {
				foundClient = clients[i];
				break;
			}
		};

		if (foundClient) {
			List<Case^>^ cases = casesManager->readClientCases(foundClient->id, "cases.txt");

			if (cases->Count > 0) {
				MessageBox::Show("Не можна видалити клієнта, він має справи");
				return;
			}
		}

		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Ви впевнені, що хочете видалити користувача " + fullname + "?",
			"Підтвердження видалення",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			bool deleted = clientManager->deleteClient(id->Trim(), "clients.txt");

			if (deleted) {
				MessageBox::Show("Користувача видалено.", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->RefreshClientsTable(advocateFullname);
			}
		}

	}
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView1->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;
	selectedRow = dataGridView1->Rows[selectedIndex];

	if (dataGridView1->CurrentCell != nullptr) {
		int selectedIndex = dataGridView1->CurrentCell->RowIndex;
		DataGridViewRow^ selectedRow = dataGridView1->Rows[selectedIndex];

		if (selectedRow->Cells[0]->Value != nullptr &&
			selectedRow->Cells[0]->Value->ToString()->Trim() != "") {

			String^ clientId = selectedRow->Cells[0]->Value->ToString();
			Advocate::CasesForm^ casesForm = gcnew Advocate::CasesForm(clientId);
			casesForm->ShowDialog();
		}
		else {
			MessageBox::Show("Виберіть клієнта");
		}
	}
}

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ query = textBox1->Text->Trim()->ToLower();

	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		DataGridViewRow^ row = dataGridView1->Rows[i];
		if (row->IsNewRow) continue;

		if (query == "") {
			row->Visible = true;
			continue;
		}

		bool match = false;
		for (int j = 0; j < dataGridView1->ColumnCount; j++) {
			String^ value = row->Cells[j]->Value != nullptr ? row->Cells[j]->Value->ToString()->ToLower() : "";
			if (value->Contains(query)) {
				match = true;
				break;
			}
		}
		row->Visible = match;
	}
}
};
}
