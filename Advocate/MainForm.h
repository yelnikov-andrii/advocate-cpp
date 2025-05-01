#pragma once
#include <fstream>
#include <vector>
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "AdminDashboard.h"
#include "AdvocateDashboard.h"
#include "UserManager.h"


namespace Advocate {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;



	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ fullnameBox;
	private: System::Windows::Forms::TextBox^ passwordBox;
	private: System::Windows::Forms::Label^ labelFullname;
	private: System::Windows::Forms::Label^ labelPassword;
	private: System::Windows::Forms::Button^ loginBtn;
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
			this->fullnameBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordBox = (gcnew System::Windows::Forms::TextBox());
			this->labelFullname = (gcnew System::Windows::Forms::Label());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// fullnameBox
			// 
			this->fullnameBox->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fullnameBox->Location = System::Drawing::Point(204, 169);
			this->fullnameBox->Name = L"fullnameBox";
			this->fullnameBox->Size = System::Drawing::Size(178, 21);
			this->fullnameBox->TabIndex = 0;
			this->fullnameBox->Text = L"Соул Гудман";
			// 
			// passwordBox
			// 
			this->passwordBox->Font = (gcnew System::Drawing::Font(L"Arial", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->passwordBox->Location = System::Drawing::Point(204, 224);
			this->passwordBox->Name = L"passwordBox";
			this->passwordBox->PasswordChar = '*';
			this->passwordBox->Size = System::Drawing::Size(178, 21);
			this->passwordBox->TabIndex = 1;
			this->passwordBox->Text = L"67890";
			// 
			// labelFullname
			// 
			this->labelFullname->AutoSize = true;
			this->labelFullname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelFullname->Location = System::Drawing::Point(201, 151);
			this->labelFullname->Name = L"labelFullname";
			this->labelFullname->Size = System::Drawing::Size(118, 15);
			this->labelFullname->TabIndex = 2;
			this->labelFullname->Text = L"Ім\'я та прізвище";
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelPassword->Location = System::Drawing::Point(201, 206);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(57, 15);
			this->labelPassword->TabIndex = 3;
			this->labelPassword->Text = L"Пароль";
			// 
			// loginBtn
			// 
			this->loginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->loginBtn->Location = System::Drawing::Point(204, 266);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(178, 39);
			this->loginBtn->TabIndex = 4;
			this->loginBtn->Text = L"Увійти";
			this->loginBtn->UseVisualStyleBackColor = true;
			this->loginBtn->Click += gcnew System::EventHandler(this, &MainForm::loginBtn_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(663, 504);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->labelPassword);
			this->Controls->Add(this->labelFullname);
			this->Controls->Add(this->passwordBox);
			this->Controls->Add(this->fullnameBox);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainForm";
			this->Text = L"Авторизація";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	using namespace msclr::interop;
	UserManager^ userManager = gcnew UserManager();

	System::String^ fullnameStr = this->fullnameBox->Text;
	System::String^ passwordStr = this->passwordBox->Text;

	if (String::IsNullOrEmpty(fullnameStr)
		|| String::IsNullOrEmpty(passwordStr)) {
		MessageBox::Show("Заповніть всі поля");
		return;
	}

	List<User^>^ usersFromFile = userManager->readUsersFromFile("users.txt");
	User^ foundUser = nullptr;
	bool userWasFound = false;

	for (int i = 0; i < usersFromFile->Count; i++) {
		String^ trimmedFullname = usersFromFile[i]->fullname->Trim()->ToLower();
		String^ trimmedInputFullname = fullnameStr->Trim()->ToLower();
		String^ trimmedPassword = usersFromFile[i]->password->Trim();
		String^ trimmedInputPassword = passwordStr->Trim();

		if (trimmedFullname == trimmedInputFullname 
            && trimmedPassword == trimmedInputPassword) {
			foundUser = usersFromFile[i];
			userWasFound = true;
			break;
		}
	}

	if (userWasFound && foundUser != nullptr) {
		if (foundUser->role->Trim() == "Адмін") {
			System::String^ loginName = foundUser->fullname->Trim();
			Advocate::AdminDashboard^ adminForm = gcnew Advocate::AdminDashboard(loginName);
			adminForm->Show();
		}
		else {
			String^ fullname = foundUser->fullname->Trim();
			Advocate::AdvocateDashboard^ advocateDashboard = gcnew Advocate::AdvocateDashboard(fullname);
			advocateDashboard->Show();
		}
	}
	else {
		MessageBox::Show("Невірний користувач або пароль");
	}
}
};
}
