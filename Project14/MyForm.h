#pragma once
#include "MainForm.h"
#include <Windows.h>

namespace Project14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			// Form properties 
			this->ClientSize = System::Drawing::Size(600, 500);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->BackColor = Color::Black;
			this->Opacity = 0.0;

			// Timers
			timerFadeIn = gcnew Timer();
			timerFadeIn->Interval = 20;
			timerFadeIn->Tick += gcnew EventHandler(this, &MyForm::timerFadeIn_Tick);

			timerLoading = gcnew Timer();
			timerLoading->Interval = 400;
			timerLoading->Tick += gcnew EventHandler(this, &MyForm::timerLoading_Tick);

			timerTypewriter = gcnew Timer();
			timerTypewriter->Interval = 35;
			timerTypewriter->Tick += gcnew EventHandler(this, &MyForm::timerTypewriter_Tick);

			// Start timers 
			timerFadeIn->Start();
			timerLoading->Start();
			timerTypewriter->Start();

			// Typewriter setup 
			fullWelcomeText = L"Welcome to MystiCrypt! Encrypt and decrypt your Messages.";
			typewriterIndex = 0;
			lblWelcome->Text = "";

			// Double-buffering for smooth gradient 
			this->SetStyle(ControlStyles::AllPaintingInWmPaint | ControlStyles::UserPaint | ControlStyles::OptimizedDoubleBuffer, true);
			this->UpdateStyles();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container ^components;



		System::Windows::Forms::Label^ lblWelcome;
		System::Windows::Forms::Button^ ButtonLoading;
		System::Windows::Forms::LinkLabel^ linkLabelSupportUs;
		System::Windows::Forms::Label^ lblFutter;

		// Timers
		Timer^ timerFadeIn;
		Timer^ timerLoading;
		Timer^ timerTypewriter;

		// Animation state
		int loadingDotCount = 0;
		String^ loadingBaseText = L"Loading";
		String^ fullWelcomeText;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ tbSlogan;

		   int typewriterIndex = 0;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->ButtonLoading = (gcnew System::Windows::Forms::Button());
			this->linkLabelSupportUs = (gcnew System::Windows::Forms::LinkLabel());
			this->lblFutter = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tbSlogan = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblWelcome->Location = System::Drawing::Point(80, 210);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(0, 25);
			this->lblWelcome->TabIndex = 3;
			// 
			// ButtonLoading
			// 
			this->ButtonLoading->Cursor = System::Windows::Forms::Cursors::Default;
			this->ButtonLoading->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ButtonLoading->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ButtonLoading->Location = System::Drawing::Point(238, 282);
			this->ButtonLoading->Name = L"ButtonLoading";
			this->ButtonLoading->Size = System::Drawing::Size(122, 35);
			this->ButtonLoading->TabIndex = 4;
			this->ButtonLoading->Text = L"Loading";
			this->ButtonLoading->UseVisualStyleBackColor = true;
			this->ButtonLoading->Click += gcnew System::EventHandler(this, &MyForm::ButtonLoading_Click);
			// 
			// linkLabelSupportUs
			// 
			this->linkLabelSupportUs->AutoSize = true;
			this->linkLabelSupportUs->Location = System::Drawing::Point(261, 366);
			this->linkLabelSupportUs->Name = L"linkLabelSupportUs";
			this->linkLabelSupportUs->Size = System::Drawing::Size(76, 16);
			this->linkLabelSupportUs->TabIndex = 5;
			this->linkLabelSupportUs->TabStop = true;
			this->linkLabelSupportUs->Text = L"Support US";
			this->linkLabelSupportUs->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabelSupport_LinkClicked);
			// 
			// lblFutter
			// 
			this->lblFutter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblFutter->AutoSize = true;
			this->lblFutter->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFutter->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->lblFutter->Location = System::Drawing::Point(187, 457);
			this->lblFutter->Name = L"lblFutter";
			this->lblFutter->Size = System::Drawing::Size(225, 17);
			this->lblFutter->TabIndex = 6;
			this->lblFutter->Text = L"All Right Reserved By MystiCrypt.com";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(48, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(164, 157);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// tbSlogan
			// 
			this->tbSlogan->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->tbSlogan->ForeColor = System::Drawing::Color::Black;
			this->tbSlogan->Location = System::Drawing::Point(200, 85);
			this->tbSlogan->Name = L"tbSlogan";
			this->tbSlogan->Size = System::Drawing::Size(270, 44);
			this->tbSlogan->TabIndex = 8;
			this->tbSlogan->Text = L"Where Secrets Stay Secrets. ";
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(600, 500);
			this->Controls->Add(this->tbSlogan);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->lblFutter);
			this->Controls->Add(this->linkLabelSupportUs);
			this->Controls->Add(this->ButtonLoading);
			this->Controls->Add(this->lblWelcome);
			this->ForeColor = System::Drawing::SystemColors::MenuBar;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"MystiCrypt";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//  Fade 
	private: System::Void timerFadeIn_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (this->Opacity < 1.0) {
			this->Opacity += 0.04;
		}
		else {
			this->Opacity = 1.0;
			timerFadeIn->Stop();
		}
	}

	// Loading button animation 
	private: System::Void timerLoading_Tick(System::Object^ sender, System::EventArgs^ e) {
		loadingDotCount = (loadingDotCount + 1) % 4;
		String^ dots = gcnew String('.', loadingDotCount);
		ButtonLoading->Text = loadingBaseText + dots;
	}

	//  Typewriter effect for welcome text
	private: System::Void timerTypewriter_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (typewriterIndex < fullWelcomeText->Length) {
			lblWelcome->Text = fullWelcomeText->Substring(0, typewriterIndex + 1);
			typewriterIndex++;
		}
		else {
			timerTypewriter->Stop();
		}
	}

	//  Gradient background in Paint event
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// Gradient background
		System::Drawing::Drawing2D::LinearGradientBrush^ brush =
			gcnew System::Drawing::Drawing2D::LinearGradientBrush(
				this->ClientRectangle,
				Color::FromArgb(255, 10, 20, 80), // DarkBlue
				Color::Black,
				System::Drawing::Drawing2D::LinearGradientMode::Vertical);
		e->Graphics->FillRectangle(brush, this->ClientRectangle);
		delete brush;

		// text effect for "MystiCrypt"
		System::Drawing::Font^ glowFont = gcnew System::Drawing::Font(L"Segoe UI", 32, System::Drawing::FontStyle::Bold);
		System::Drawing::Point glowPos = System::Drawing::Point(200, 25);
		System::String^ text = L"MystiCrypt";
		for (int i = 8; i >= 1; --i) {
			System::Drawing::SolidBrush^ glowBrush = gcnew System::Drawing::SolidBrush(
				System::Drawing::Color::FromArgb(30, 0, 120, 255));
			e->Graphics->DrawString(text, glowFont, glowBrush,
				glowPos.X - i, glowPos.Y - i);
			e->Graphics->DrawString(text, glowFont, glowBrush,
				glowPos.X + i, glowPos.Y + i);
			e->Graphics->DrawString(text, glowFont, glowBrush,
				glowPos.X - i, glowPos.Y + i);
			e->Graphics->DrawString(text, glowFont, glowBrush,
				glowPos.X + i, glowPos.Y - i);
			delete glowBrush;
		}
		System::Drawing::SolidBrush^ whiteBrush = gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
		e->Graphics->DrawString(text, glowFont, whiteBrush, glowPos);
		delete whiteBrush;
		delete glowFont;
	}

	// Support US link opens mysticrypt.com 
	private: System::Void linkLabelSupport_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		System::Diagnostics::Process::Start("https://mysticrypt.com");
	}

	//	Loading button click		
	private: System::Void ButtonLoading_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		MainForm^ mainForm = gcnew MainForm();
		mainForm->ShowDialog();
		this->Close();
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
};
}
