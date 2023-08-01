#pragma once
#include "CClient.h"

namespace UIClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		CClient mClient;
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxChat;
	private: System::Windows::Forms::TextBox^ txtBoxMessage;
	private: System::Windows::Forms::Button^ btnSend;
	private: System::Windows::Forms::Label^ lblStatus;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::Button^ btnDisconnect;


	protected:

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
			this->txtBoxChat = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->btnDisconnect = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxChat
			// 
			this->txtBoxChat->Location = System::Drawing::Point(8, 8);
			this->txtBoxChat->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtBoxChat->Multiline = true;
			this->txtBoxChat->Name = L"txtBoxChat";
			this->txtBoxChat->ReadOnly = true;
			this->txtBoxChat->Size = System::Drawing::Size(599, 165);
			this->txtBoxChat->TabIndex = 0;
			// 
			// txtBoxMessage
			// 
			this->txtBoxMessage->Location = System::Drawing::Point(8, 183);
			this->txtBoxMessage->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtBoxMessage->Multiline = true;
			this->txtBoxMessage->Name = L"txtBoxMessage";
			this->txtBoxMessage->Size = System::Drawing::Size(599, 70);
			this->txtBoxMessage->TabIndex = 1;
			// 
			// btnSend
			// 
			this->btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSend->Location = System::Drawing::Point(499, 255);
			this->btnSend->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(107, 36);
			this->btnSend->TabIndex = 2;
			this->btnSend->Text = L"Send";
			this->btnSend->UseVisualStyleBackColor = true;
			this->btnSend->Click += gcnew System::EventHandler(this, &MyForm::btnSend_Click);
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->ForeColor = System::Drawing::Color::Red;
			this->lblStatus->Location = System::Drawing::Point(14, 266);
			this->lblStatus->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(73, 13);
			this->lblStatus->TabIndex = 3;
			this->lblStatus->Text = L"Disconnected";
			// 
			// btnDisconnect
			// 
			this->btnDisconnect->Location = System::Drawing::Point(401, 255);
			this->btnDisconnect->Name = L"btnDisconnect";
			this->btnDisconnect->Size = System::Drawing::Size(93, 35);
			this->btnDisconnect->TabIndex = 4;
			this->btnDisconnect->Text = L"DISCONNECT";
			this->btnDisconnect->UseVisualStyleBackColor = true;
			this->btnDisconnect->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 298);
			this->Controls->Add(this->btnDisconnect);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtBoxMessage);
			this->Controls->Add(this->txtBoxChat);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
		mClient.sendMessage(txtBoxMessage->Text);
		txtBoxChat->Text += "You: " + txtBoxMessage->Text + "\n";
		txtBoxMessage->Text = "";

	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	if (mClient.connectClient()) {
		lblStatus->Text = "Connected";
		lblStatus->ForeColor = System::Drawing::Color::Green;
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	mClient.disconnect();
	
}
};
}
