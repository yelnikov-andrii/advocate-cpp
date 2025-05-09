#pragma once
#include "CasesManager.h"
#include "ClientManager.h"
#include "AddCase.h"
#include "EditCase.h"

namespace Advocate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CasesForm
	/// </summary>
	public ref class CasesForm : public System::Windows::Forms::Form
	{
	public: String^ clientIdStr;
	public: String^ advocateFullname;
	public:
		CasesForm(String^ clientId)
		{
			InitializeComponent();
			this->clientIdStr = clientId;
			//
			//TODO: Add the constructor code here
			//
			CasesManager^ casesManager = gcnew CasesManager();
			ClientManager^ clientManager = gcnew ClientManager();

			Client^ client = clientManager->getOne(clientIdStr, "clients.txt");
			this->advocateFullname = client->advocateFullname->Trim();

			try {
				List<Case^>^ cases = casesManager->readClientCases(clientIdStr, "cases.txt");
				if (cases != nullptr) {
					for (int i = 0; i < cases->Count; i++) {
						String^ id = cases[i]->id;
						String^ advocateFullname = cases[i]->advocateFullname;
						String^ clientId = cases[i]->clientId;
						String^ title = cases[i]->title;
						String^ description = cases[i]->description;
						String^ status = cases[i]->status;
						String^ created = cases[i]->created;
						String^ clientFullname = client->fullname;
						this->dataGridView1->Rows->Add(id, advocateFullname, clientFullname, title, description, status, created);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Помилка при завантаженні справ: " + ex->Message);
			}

			for (int i = 0; i < dataGridView1->RowCount; i++) {
				if (dataGridView1->Rows[i]->IsNewRow)
					continue;

				String^ status = dataGridView1->Rows[i]->Cells[5]->Value->ToString()->ToLower();

				if (status == "нова")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightBlue;
				else if (status == "в роботі")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Khaki;
				else if (status == "очікує клієнта")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightSalmon;
				else if (status == "призупинена")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGray;
				else if (status == "завершена")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGreen;
				else if (status == "відхилена")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Tomato;
				else if (status == "архівована")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::DarkGray;
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CasesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::Button^ button3;
	public:
		void RefreshTable() {
			this->dataGridView1->Rows->Clear();

			CasesManager^ casesManager = gcnew CasesManager();
			ClientManager^ clientManager = gcnew ClientManager();

			try {
				List<Case^>^ cases = casesManager->readClientCases(clientIdStr, "cases.txt");
				if (cases != nullptr) {
					for (int i = 0; i < cases->Count; i++) {
						String^ id = cases[i]->id;
						String^ advocateFullname = cases[i]->advocateFullname;
						String^ clientId = cases[i]->clientId;
						String^ title = cases[i]->title;
						String^ description = cases[i]->description;
						String^ status = cases[i]->status;
						String^ created = cases[i]->created;

						Client^ client = clientManager->getOne(clientIdStr, "clients.txt");
						String^ clientFullname = client->fullname;

						this->dataGridView1->Rows->Add(id, advocateFullname, clientFullname, title, description, status, created);
					}
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Помилка при завантаженні справ: " + ex->Message);
			}

			for (int i = 0; i < dataGridView1->RowCount; i++) {
				if (dataGridView1->Rows[i]->IsNewRow)
					continue;

				String^ status = dataGridView1->Rows[i]->Cells[5]->Value->ToString()->ToLower();

				if (status == "нова")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightBlue;
				else if (status == "в роботі")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Khaki;
				else if (status == "очікує клієнта")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightSalmon;
				else if (status == "призупинена")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGray;
				else if (status == "завершена")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::LightGreen;
				else if (status == "відхилена")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::Tomato;
				else if (status == "архівована")
					dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::DarkGray;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7
			});
			this->dataGridView1->Location = System::Drawing::Point(33, 48);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->Size = System::Drawing::Size(1398, 354);
			this->dataGridView1->TabIndex = 0;
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
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(33, 446);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Додати справу";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CasesForm::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(226, 446);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(201, 51);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Редагувати справу";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CasesForm::button2_Click);
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(453, 446);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(180, 51);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Видалити справу";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &CasesForm::button3_Click);
			// 
			// CasesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 23);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1464, 596);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"CasesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Справи";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Advocate::AddCase^ addCase = gcnew Advocate::AddCase(advocateFullname, clientIdStr, gcnew Advocate::AddCase::RefreshTableDelegate(this, &Advocate::CasesForm::RefreshTable));
	addCase->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView1->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView1->Rows->Count) {
		selectedRow = dataGridView1->Rows[selectedIndex];

		if (selectedRow->Cells[0]->Value == nullptr) {
			MessageBox::Show("Справи відсутні", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ id = selectedRow->Cells[0]->Value->ToString()->Trim();

		if (String::IsNullOrEmpty(id)) {
			MessageBox::Show("Справи відсутні", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		CasesManager^ caseManager = gcnew CasesManager();
		Case^ foundCase = caseManager->getOne(id, "cases.txt");

		Advocate::EditCase^ editCaseForm = gcnew Advocate::EditCase(id, gcnew Advocate::EditCase::RefreshTableDelegate(this, &Advocate::CasesForm::RefreshTable));
		if (foundCase) {
			editCaseForm->SetData(id);
			editCaseForm->ShowDialog();
		} else {
			MessageBox::Show("Не вдалося знайти справу", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	int selectedIndex = dataGridView1->CurrentCell->RowIndex;
	DataGridViewRow^ selectedRow;

	if (selectedIndex >= 0 && selectedIndex < dataGridView1->Rows->Count) {
		selectedRow = dataGridView1->Rows[selectedIndex];

		if (selectedRow->Cells[0]->Value == nullptr) {
			MessageBox::Show("Справи відсутні", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ id = selectedRow->Cells[0]->Value->ToString()->Trim();

		if (String::IsNullOrEmpty(id)) {
			MessageBox::Show("Справи відсутні", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

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
				this->RefreshTable();
			}
		}

	}
}
};
}
