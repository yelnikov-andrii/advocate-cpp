#pragma once
#include "UserManager.h"
#include "ClientManager.h"
#include "AddUser.h"
#include "EditUser.h"
#include "EditClient.h"
#include "CasesForm.h"
#include "AddClient.h"
#include "AddClientAdminForm.h"
#include "AddCaseAdmin.h"
#include "EditCase.h"

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
 
	public ref class AdminDashboard : public System::Windows::Forms::Form
    
	{
	public:
		AdminDashboard(System::String^ login)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->Text = "Адміністративна панель " + login;

			UserManager^ userManager = gcnew UserManager();
			List<User^>^ users = userManager->readUsersFromFile("users.txt");
			for (int i = 0; i < users->Count; i++) {
				if (users[i]->fullname->Trim() == "admin") {
					continue;
				}
				String^ fullname = users[i]->fullname;
				String^ role = users[i]->role;
				this->dataGridView1->Rows->Add(fullname, role);
			};

			ClientManager^ clientManager = gcnew ClientManager();
			List<Client^>^ clients = clientManager->readClientsFromFile(nullptr, "clients.txt");
			for (int i = 0; i < clients->Count; i++) {
				String^ id = clients[i]->id;
				String^ advocateFullname = clients[i]->advocateFullname;
				String^ fullname = clients[i]->fullname;
				String^ phone = clients[i]->phone;
				String^ email = clients[i]->email;
				this->dataGridView2->Rows->Add(id, advocateFullname, fullname, phone, email);
			}

			CasesManager^ casesManager = gcnew CasesManager();

			try {
				List<Case^>^ cases = casesManager->readAllCases("cases.txt");
				if (cases != nullptr) {
					for (int i = 0; i < cases->Count; i++) {
						String^ id = cases[i]->id->Trim();
						String^ advocateFullname = cases[i]->advocateFullname->Trim();
						String^ clientId = cases[i]->clientId->Trim();
						String^ title = cases[i]->title->Trim();
						String^ description = cases[i]->description->Trim();
						String^ status = cases[i]->status->Trim();
						String^ created = cases[i]->created->Trim();

						Client^ client = clientManager->getOne(clientId, "clients.txt");
						
						if (client) {
							String^ clientFullname = client->fullname->Trim();

							this->dataGridView3->Rows->Add(id, advocateFullname, clientFullname, title, description, status, created);
						}
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Помилка при завантаженні справ: " + ex->Message);
			}

			for (int i = 0; i < dataGridView3->RowCount; i++) {
				if (dataGridView3->Rows[i]->IsNewRow)
					continue;

				String^ status = dataGridView3->Rows[i]->Cells[5]->Value->ToString()->ToLower();

				if (status == "нова")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightBlue;
				else if (status == "в роботі")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Khaki;
				else if (status == "очікує клієнта")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightSalmon;
				else if (status == "призупинена")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGray;
				else if (status == "завершена")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGreen;
				else if (status == "відхилена")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Tomato;
				else if (status == "архівована")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::DarkGray;
			}


		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminDashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button8;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	public:
		void RefreshUserTable() { 
			this->dataGridView1->Rows->Clear();

			UserManager^ userManager = gcnew UserManager();
			List<User^>^ users = userManager->readUsersFromFile("users.txt");

			for (int i = 0; i < users->Count; i++) {
				if (users[i]->fullname->Trim() == "admin") {
					continue;
				}
				String^ fullname = users[i]->fullname;
				String^ role = users[i]->role;
				this->dataGridView1->Rows->Add(fullname, role);
			}
		};
	public:
		void RefreshClientsTable(String^ advocateFullname) {
			this->dataGridView2->Rows->Clear();

			ClientManager^ clientManager = gcnew ClientManager();
			List<Client^>^ clients = clientManager->readClientsFromFile(nullptr, "clients.txt");

			for (int i = 0; i < clients->Count; i++) {
				String^ id = clients[i]->id;
				String^ advocateFullname = clients[i]->advocateFullname;
				String^ fullname = clients[i]->fullname;
				String^ phone = clients[i]->phone;
				String^ email = clients[i]->email;
				this->dataGridView2->Rows->Add(id, advocateFullname, fullname, phone, email);
			}
		};
	public:
		void RefreshCasesTable() {
			this->dataGridView3->Rows->Clear();

			CasesManager^ casesManager = gcnew CasesManager();
			ClientManager^ clientManager = gcnew ClientManager();

			try {
				List<Case^>^ cases = casesManager->readAllCases("cases.txt");
				if (cases != nullptr) {
					for (int i = 0; i < cases->Count; i++) {
						String^ id = cases[i]->id;
						String^ advocateFullname = cases[i]->advocateFullname;
						String^ clientId = cases[i]->clientId;
						String^ title = cases[i]->title;
						String^ description = cases[i]->description;
						String^ status = cases[i]->status;
						String^ created = cases[i]->created;

						Client^ client = clientManager->getOne(clientId, "clients.txt");
						String^ clientFullname = client->fullname;

						this->dataGridView3->Rows->Add(id, advocateFullname, clientFullname, title, description, status, created);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Помилка при завантаженні справ: " + ex->Message);
			}

			for (int i = 0; i < dataGridView3->RowCount; i++) {
				if (dataGridView3->Rows[i]->IsNewRow)
					continue;

				String^ status = dataGridView3->Rows[i]->Cells[5]->Value->ToString()->ToLower();

				if (status == "нова")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightBlue;
				else if (status == "в роботі")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Khaki;
				else if (status == "очікує клієнта")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightSalmon;
				else if (status == "призупинена")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGray;
				else if (status == "завершена")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGreen;
				else if (status == "відхилена")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Tomato;
				else if (status == "архівована")
					dataGridView3->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::DarkGray;
			}
		};

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(54, 173);
			this->tabControl1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1744, 515);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 32);
			this->tabPage1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tabPage1->Size = System::Drawing::Size(1736, 479);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Адвокати";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(1026, 395);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(256, 65);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Видалити користувача";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminDashboard::button3_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(663, 395);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(246, 65);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Редагувати користувача";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminDashboard::button2_Click);
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(272, 395);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(232, 65);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Додати користувача";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminDashboard::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView1->Location = System::Drawing::Point(272, 29);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(1010, 340);
			this->dataGridView1->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Користувач";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 125;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Роль";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button7);
			this->tabPage2->Controls->Add(this->button6);
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Location = System::Drawing::Point(4, 32);
			this->tabPage2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->tabPage2->Size = System::Drawing::Size(1736, 479);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Клієнти";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Location = System::Drawing::Point(1081, 386);
			this->button7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(231, 55);
			this->button7->TabIndex = 4;
			this->button7->Text = L"Переглянути справи";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &AdminDashboard::button7_Click);
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(772, 385);
			this->button6->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(212, 55);
			this->button6->TabIndex = 3;
			this->button6->Text = L"Видалити клієнта";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &AdminDashboard::button6_Click);
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(440, 385);
			this->button5->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(234, 55);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Редагувати клієнта";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &AdminDashboard::button5_Click);
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(174, 386);
			this->button4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(205, 55);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Додати клієнта";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &AdminDashboard::button4_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn3,
					this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7
			});
			this->dataGridView2->Location = System::Drawing::Point(174, 57);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->Size = System::Drawing::Size(1138, 318);
			this->dataGridView2->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Адвокат";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 125;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"ПІБ";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 125;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Телефон";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 125;
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->HeaderText = L"Email";
			this->dataGridViewTextBoxColumn7->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			this->dataGridViewTextBoxColumn7->Width = 125;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button10);
			this->tabPage3->Controls->Add(this->button9);
			this->tabPage3->Controls->Add(this->button8);
			this->tabPage3->Controls->Add(this->dataGridView3);
			this->tabPage3->Location = System::Drawing::Point(4, 32);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->tabPage3->Size = System::Drawing::Size(1736, 479);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Справи";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Location = System::Drawing::Point(602, 350);
			this->button10->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(231, 55);
			this->button10->TabIndex = 3;
			this->button10->Text = L"Видалити справу";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &AdminDashboard::button10_Click);
			// 
			// button9
			// 
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Location = System::Drawing::Point(315, 350);
			this->button9->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(250, 55);
			this->button9->TabIndex = 2;
			this->button9->Text = L"Редагувати справу";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &AdminDashboard::button9_Click);
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Location = System::Drawing::Point(36, 350);
			this->button8->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(226, 55);
			this->button8->TabIndex = 1;
			this->button8->Text = L"Додати справу";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &AdminDashboard::button8_Click);
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			});
			this->dataGridView3->Location = System::Drawing::Point(36, 37);
			this->dataGridView3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->Size = System::Drawing::Size(1400, 251);
			this->dataGridView3->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Адвокат";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Клієнт";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Назва";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Опис";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			this->Column5->Width = 125;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Статус";
			this->Column6->MinimumWidth = 6;
			this->Column6->Name = L"Column6";
			this->Column6->Width = 125;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Дата створення";
			this->Column7->MinimumWidth = 6;
			this->Column7->Name = L"Column7";
			this->Column7->Width = 125;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(54, 113);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(340, 30);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &AdminDashboard::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(55, 90);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Пошук";
			// 
			// AdminDashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1852, 793);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->tabControl1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"AdminDashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Advocate::AddUser^ addUser = gcnew Advocate::AddUser(gcnew Advocate::AddUser::RefreshTableDelegate(this, &Advocate::AdminDashboard::RefreshUserTable));
	    addUser->Show();
	}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView1->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView1->Rows->Count) {
		selectedRow = dataGridView1->Rows[selectedIndex];

		String^ fullname = selectedRow->Cells[0]->Value->ToString();
		String^ role = selectedRow->Cells[1]->Value->ToString();

		UserManager^ userManager = gcnew UserManager();
		List<User^>^ users = userManager->readUsersFromFile("users.txt");
		User^ foundUser;

		for (int i = 0; i < users->Count; i++) {
			if (users[i]->fullname->Trim() == fullname->Trim()) {
				foundUser = users[i];
				break;
			}
		};


		Advocate::EditUser^ editUserForm = gcnew Advocate::EditUser(gcnew Advocate::EditUser::RefreshTableDelegate(this, &Advocate::AdminDashboard::RefreshUserTable));
		if (foundUser) {
			editUserForm->SetUserData(foundUser->fullname->Trim(), foundUser->password->Trim(), foundUser->role->Trim());
			editUserForm->ShowDialog();
		}
		
	}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView1->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView1->Rows->Count) {
		selectedRow = dataGridView1->Rows[selectedIndex];

		String^ fullname = selectedRow->Cells[0]->Value->ToString();
		String^ role = selectedRow->Cells[1]->Value->ToString();

		UserManager^ userManager = gcnew UserManager();
		List<User^>^ users = userManager->readUsersFromFile("users.txt");
		User^ foundUser;

		ClientManager^ clientManager = gcnew ClientManager(); 

		for (int i = 0; i < users->Count; i++) {
			if (users[i]->fullname == fullname) {
				foundUser = users[i];
				break;
			}
		};

		if (foundUser) {
			List<Client^>^ clients = clientManager->readClientsFromFile(foundUser->fullname->Trim(), "clients.txt");
			if (clients->Count > 0) {
				MessageBox::Show("Не можна видалити користувача, він має клієнтів");
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
			bool deleted = userManager->deleteUser(fullname, "users.txt");

			if (deleted) {
				MessageBox::Show("Користувача видалено.", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->RefreshUserTable();
			}
		}
	}
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Advocate::AddClientAdminForm^ addClientAdminForm = gcnew Advocate::AddClientAdminForm("", gcnew Advocate::AddClientAdminForm::RefreshTableDelegate(this, &Advocate::AdminDashboard::RefreshClientsTable));
	addClientAdminForm->Show();
}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView2->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView2->Rows->Count) {
		selectedRow = dataGridView2->Rows[selectedIndex];

		String^ id = selectedRow->Cells[0]->Value->ToString();
		String^ advocateFullname = selectedRow->Cells[1]->Value->ToString();
		String^ fullname = selectedRow->Cells[2]->Value->ToString();
		String^ phone = selectedRow->Cells[3]->Value->ToString();
		String^ email = selectedRow->Cells[4]->Value->ToString();

		ClientManager^ clientManager = gcnew ClientManager();
		Client^ foundClient = clientManager->getOne(id, "clients.txt");

		Advocate::EditClient^ editClientForm = gcnew Advocate::EditClient(advocateFullname, gcnew Advocate::EditClient::RefreshTableDelegate(this, &Advocate::AdminDashboard::RefreshClientsTable));
		if (foundClient) {
			editClientForm->SetData(foundClient->id, foundClient->fullname->Trim(), foundClient->phone->Trim(), foundClient->email->Trim());
			editClientForm->ShowDialog();
		}
	}
}

private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView2->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView2->Rows->Count) {
		selectedRow = dataGridView2->Rows[selectedIndex];

		String^ id = selectedRow->Cells[0]->Value->ToString();
		String^ advocateFullname = selectedRow->Cells[1]->Value->ToString();
		String^ fullname = selectedRow->Cells[2]->Value->ToString();

		ClientManager^ clientManager = gcnew ClientManager();
		List<Client^>^ clients = clientManager->readClientsFromFile(advocateFullname, "clients.txt");
		Client^ foundClient;

		for (int i = 0; i < clients->Count; i++) {
			if (clients[i]->id == id) {
				foundClient = clients[i];
				break;
			}
		};

		CasesManager^ casesManager = gcnew CasesManager();

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

private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {

	if (dataGridView2->CurrentCell != nullptr) {
		int selectedIndex = dataGridView2->CurrentCell->RowIndex;
		DataGridViewRow^ selectedRow = dataGridView2->Rows[selectedIndex];

		if (selectedRow->Cells[0]->Value != nullptr &&
			selectedRow->Cells[0]->Value->ToString()->Trim() != "") {

			String^ clientId = selectedRow->Cells[0]->Value->ToString();
			Advocate::CasesForm^ casesForm = gcnew Advocate::CasesForm(clientId);

			casesForm->FormClosed += gcnew FormClosedEventHandler(this, &AdminDashboard::CasesFormClosed);
			casesForm->ShowDialog();
		}
		else {
			MessageBox::Show("Виберіть клієнта");
		}
	}
}

private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	Advocate::AddCaseAdmin^ addCaseAdminForm = gcnew Advocate::AddCaseAdmin(gcnew Advocate::AddCaseAdmin::RefreshTableDelegate(this, &Advocate::AdminDashboard::RefreshCasesTable));
	addCaseAdminForm->Show();
}

private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView3->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView3->Rows->Count) {
		selectedRow = dataGridView3->Rows[selectedIndex];

		String^ id = selectedRow->Cells[0]->Value->ToString()->Trim();

		CasesManager^ caseManager = gcnew CasesManager();
		Case^ foundCase = caseManager->getOne(id, "cases.txt");

		Advocate::EditCase^ editCaseForm = gcnew Advocate::EditCase(id, gcnew Advocate::EditCase::RefreshTableDelegate(this, &Advocate::AdminDashboard::RefreshCasesTable));
		if (foundCase) {
			editCaseForm->SetData(id);
			editCaseForm->ShowDialog();
		}
		else {
			MessageBox::Show("Не вдалося знайти справу", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView3->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView3->Rows->Count) {
		selectedRow = dataGridView3->Rows[selectedIndex];

		String^ id = selectedRow->Cells[0]->Value->ToString()->Trim();

		CasesManager^ casesManager = gcnew CasesManager();
		Case^ foundCase = casesManager->getOne(id, "cases.txt");

		if (foundCase == nullptr) {
			MessageBox::Show(
				"Справу не знайдено. Можливо, вона вже була видалена.",
				"Помилка",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Ви впевнені, що хочете видалити справу " + foundCase->title + "?",
			"Підтвердження видалення",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		if (result == System::Windows::Forms::DialogResult::Yes) {
			bool deleted = casesManager->deleteCase(id, "cases.txt");

			if (deleted) {
				MessageBox::Show("Справу видалено.", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->RefreshCasesTable();
			}
		}

	}
}

private: System::Void CasesFormClosed(System::Object^ sender, FormClosedEventArgs^ e) {
	this->RefreshCasesTable();
};

private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ query = textBox1->Text->Trim()->ToLower();

	for (int i = 0; i < dataGridView1->Rows->Count; i++) {
		DataGridViewRow^ row = dataGridView1->Rows[i];
		if (row->IsNewRow) continue;

		if (query == "") {
			row->Visible = true;
			continue;
		}

		String^ fullname = row->Cells[0]->Value != nullptr ? row->Cells[0]->Value->ToString()->ToLower() : "";
		String^ role = row->Cells[1]->Value != nullptr ? row->Cells[1]->Value->ToString()->ToLower() : "";
		row->Visible = fullname->Contains(query) || role->Contains(query);
	}

	for (int i = 0; i < dataGridView2->Rows->Count; i++) {
		DataGridViewRow^ row = dataGridView2->Rows[i];
		if (row->IsNewRow) continue;

		if (query == "") {
			row->Visible = true;
			continue;
		}

		bool match = false;
		for (int j = 0; j < dataGridView2->ColumnCount; j++) {
			String^ value = row->Cells[j]->Value != nullptr ? row->Cells[j]->Value->ToString()->ToLower() : "";
			if (value->Contains(query)) {
				match = true;
				break;
			}
		}
		row->Visible = match;
	}

	for (int i = 0; i < dataGridView3->Rows->Count; i++) {
		DataGridViewRow^ row = dataGridView3->Rows[i];
		if (row->IsNewRow) continue;

		if (query == "") {
			row->Visible = true;
			continue;
		}

		bool match = false;
		for (int j = 0; j < dataGridView3->ColumnCount; j++) {
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
