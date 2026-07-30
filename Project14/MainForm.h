#pragma once
#include <Windows.h>
#include "CeasarChiper.h"
#include "AtbashCipher.h"
#include "VigenèreCipher.h"
#include "SimpleSubstitutionCipher.h"
#include "ColumnarTranspositionCipher.h"
#include "SimpleXORCipher.h"
#include "RailFenceCipher.h"
#include <msclr/marshal_cppstd.h>
 // For ShellExecute

namespace Project14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			// Wire up cipher button events
			this->btnCaesarCipher->Click += gcnew System::EventHandler(this, &MainForm::btnCaesarCipher_Click);
			this->btnAtbashCipher->Click += gcnew System::EventHandler(this, &MainForm::btnAtbashCipher_Click);
			this->btnVigenereCipher->Click += gcnew System::EventHandler(this, &MainForm::btnVigenereCipher_Click);
			this->btnSimpleSubsitiutionCipher->Click += gcnew System::EventHandler(this, &MainForm::btnSimpleSubsitiutionCipher_Click);
			this->btnColumanrTransposition->Click += gcnew System::EventHandler(this, &MainForm::btnColumanrTransposition_Click);
			this->btnSimpleXorCipher->Click += gcnew System::EventHandler(this, &MainForm::btnSimpleXorCipher_Click);
			this->btnRailFenceCipher->Click += gcnew System::EventHandler(this, &MainForm::btnRailFenceCipher_Click);
			this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::undoToolStripMenuItem_Click);
			this->redoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::redoToolStripMenuItem_Click);
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::copyToolStripMenuItem_Click);
			this->cutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::cutToolStripMenuItem_Click);
			this->documentationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::documentationToolStripMenuItem_Click);
			this->ToolStripMenuAbout->Click += gcnew System::EventHandler(this, &MainForm::aboutMystiCryptToolStripMenuItem_Click);

			// Add event handlers for button hover effect
			this->btnEncrypt->MouseEnter += gcnew System::EventHandler(this, &MainForm::btnEncrypt_MouseEnter);
			this->btnEncrypt->MouseLeave += gcnew System::EventHandler(this, &MainForm::btnEncrypt_MouseLeave);
			this->btnDecrypt->MouseEnter += gcnew System::EventHandler(this, &MainForm::btnDecrypt_MouseEnter);
			this->btnDecrypt->MouseLeave += gcnew System::EventHandler(this, &MainForm::btnDecrypt_MouseLeave);
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		// Menu
		System::Windows::Forms::MenuStrip^ menuStripFile;
		System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ newToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;

		System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ undoToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ redoToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ copyToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ pasteToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ cutToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ documentationToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ ToolStripMenuAbout;
		System::Windows::Forms::Button^ btnCaesarCipher;
		System::Windows::Forms::Button^ btnAtbashCipher;
		System::Windows::Forms::Button^ btnVigenereCipher;
		System::Windows::Forms::Button^ btnSimpleSubsitiutionCipher;
		System::Windows::Forms::Button^ btnColumanrTransposition;
		System::Windows::Forms::Button^ btnSimpleXorCipher;

		System::Windows::Forms::GroupBox^ groupBoxCaesar;
		System::Windows::Forms::TextBox^ txtShift;
		System::Windows::Forms::Label^ lblShift;
		System::Windows::Forms::Button^ btnEncrypt;
		System::Windows::Forms::TextBox^ txtOutput;
		System::Windows::Forms::Label^ lblOutput;
		System::Windows::Forms::TextBox^ txtInput;
		System::Windows::Forms::Label^ lblInput;
		System::Windows::Forms::Button^ btnDecrypt;

		System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Button^ btnRailFenceCipher;


		// Track current cipher
		System::String^ currentCipher;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStripFile = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->documentationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ToolStripMenuAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnCaesarCipher = (gcnew System::Windows::Forms::Button());
			this->btnAtbashCipher = (gcnew System::Windows::Forms::Button());
			this->btnVigenereCipher = (gcnew System::Windows::Forms::Button());
			this->btnSimpleSubsitiutionCipher = (gcnew System::Windows::Forms::Button());
			this->btnColumanrTransposition = (gcnew System::Windows::Forms::Button());
			this->btnSimpleXorCipher = (gcnew System::Windows::Forms::Button());
			this->groupBoxCaesar = (gcnew System::Windows::Forms::GroupBox());
			this->btnDecrypt = (gcnew System::Windows::Forms::Button());
			this->btnEncrypt = (gcnew System::Windows::Forms::Button());
			this->txtOutput = (gcnew System::Windows::Forms::TextBox());
			this->lblOutput = (gcnew System::Windows::Forms::Label());
			this->txtInput = (gcnew System::Windows::Forms::TextBox());
			this->lblInput = (gcnew System::Windows::Forms::Label());
			this->txtShift = (gcnew System::Windows::Forms::TextBox());
			this->lblShift = (gcnew System::Windows::Forms::Label());
			this->btnRailFenceCipher = (gcnew System::Windows::Forms::Button());
			this->menuStripFile->SuspendLayout();
			this->groupBoxCaesar->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStripFile
			// 
			this->menuStripFile->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStripFile->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStripFile->Location = System::Drawing::Point(0, 0);
			this->menuStripFile->Name = L"menuStripFile";
			this->menuStripFile->Size = System::Drawing::Size(670, 28);
			this->menuStripFile->TabIndex = 0;
			this->menuStripFile->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->saveToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::saveToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->undoToolStripMenuItem,
					this->redoToolStripMenuItem, this->copyToolStripMenuItem, this->pasteToolStripMenuItem, this->cutToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(49, 24);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->undoToolStripMenuItem->Text = L"Undo";
			this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::undoToolStripMenuItem_Click);
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->redoToolStripMenuItem->Text = L"Redo";
			this->redoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::redoToolStripMenuItem_Click);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::copyToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->pasteToolStripMenuItem->Text = L"Paste";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::pasteToolStripMenuItem_Click);
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->cutToolStripMenuItem->Text = L"Cut";
			this->cutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::cutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->documentationToolStripMenuItem,
					this->ToolStripMenuAbout
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// documentationToolStripMenuItem
			// 
			this->documentationToolStripMenuItem->Name = L"documentationToolStripMenuItem";
			this->documentationToolStripMenuItem->Size = System::Drawing::Size(207, 26);
			this->documentationToolStripMenuItem->Text = L"Documentation";
			// 
			// ToolStripMenuAbout
			// 
			this->ToolStripMenuAbout->Name = L"ToolStripMenuAbout";
			this->ToolStripMenuAbout->Size = System::Drawing::Size(207, 26);
			this->ToolStripMenuAbout->Text = L"About MystiCrypt";
			// 
			// btnCaesarCipher
			// 
			this->btnCaesarCipher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCaesarCipher->Location = System::Drawing::Point(24, 59);
			this->btnCaesarCipher->Name = L"btnCaesarCipher";
			this->btnCaesarCipher->Size = System::Drawing::Size(114, 45);
			this->btnCaesarCipher->TabIndex = 2;
			this->btnCaesarCipher->Text = L"Caesar Cipher";
			this->btnCaesarCipher->UseVisualStyleBackColor = true;
			// 
			// btnAtbashCipher
			// 
			this->btnAtbashCipher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAtbashCipher->Location = System::Drawing::Point(24, 123);
			this->btnAtbashCipher->Name = L"btnAtbashCipher";
			this->btnAtbashCipher->Size = System::Drawing::Size(114, 45);
			this->btnAtbashCipher->TabIndex = 3;
			this->btnAtbashCipher->Text = L"Atbash Cipher";
			this->btnAtbashCipher->UseVisualStyleBackColor = true;
			// 
			// btnVigenereCipher
			// 
			this->btnVigenereCipher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVigenereCipher->Location = System::Drawing::Point(24, 189);
			this->btnVigenereCipher->Name = L"btnVigenereCipher";
			this->btnVigenereCipher->Size = System::Drawing::Size(114, 45);
			this->btnVigenereCipher->TabIndex = 4;
			this->btnVigenereCipher->Text = L"Vigenère Cipher";
			this->btnVigenereCipher->UseVisualStyleBackColor = true;
			// 
			// btnSimpleSubsitiutionCipher
			// 
			this->btnSimpleSubsitiutionCipher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSimpleSubsitiutionCipher->Location = System::Drawing::Point(24, 253);
			this->btnSimpleSubsitiutionCipher->Name = L"btnSimpleSubsitiutionCipher";
			this->btnSimpleSubsitiutionCipher->Size = System::Drawing::Size(114, 45);
			this->btnSimpleSubsitiutionCipher->TabIndex = 5;
			this->btnSimpleSubsitiutionCipher->Text = L"Simple Substitution Cipher";
			this->btnSimpleSubsitiutionCipher->UseVisualStyleBackColor = true;
			// 
			// btnColumanrTransposition
			// 
			this->btnColumanrTransposition->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnColumanrTransposition->Location = System::Drawing::Point(24, 318);
			this->btnColumanrTransposition->Name = L"btnColumanrTransposition";
			this->btnColumanrTransposition->Size = System::Drawing::Size(114, 45);
			this->btnColumanrTransposition->TabIndex = 6;
			this->btnColumanrTransposition->Text = L"Columnar Transposition Cipher";
			this->btnColumanrTransposition->UseVisualStyleBackColor = true;
			// 
			// btnSimpleXorCipher
			// 
			this->btnSimpleXorCipher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSimpleXorCipher->Location = System::Drawing::Point(24, 383);
			this->btnSimpleXorCipher->Name = L"btnSimpleXorCipher";
			this->btnSimpleXorCipher->Size = System::Drawing::Size(114, 45);
			this->btnSimpleXorCipher->TabIndex = 7;
			this->btnSimpleXorCipher->Text = L"Simple XOR Cipher";
			this->btnSimpleXorCipher->UseVisualStyleBackColor = true;
			// 
			// groupBoxCaesar
			// 
			this->groupBoxCaesar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBoxCaesar->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->groupBoxCaesar->Controls->Add(this->btnDecrypt);
			this->groupBoxCaesar->Controls->Add(this->btnEncrypt);
			this->groupBoxCaesar->Controls->Add(this->txtOutput);
			this->groupBoxCaesar->Controls->Add(this->lblOutput);
			this->groupBoxCaesar->Controls->Add(this->txtInput);
			this->groupBoxCaesar->Controls->Add(this->lblInput);
			this->groupBoxCaesar->Controls->Add(this->txtShift);
			this->groupBoxCaesar->Controls->Add(this->lblShift);
			this->groupBoxCaesar->Location = System::Drawing::Point(209, 59);
			this->groupBoxCaesar->Name = L"groupBoxCaesar";
			this->groupBoxCaesar->Size = System::Drawing::Size(421, 443);
			this->groupBoxCaesar->TabIndex = 8;
			this->groupBoxCaesar->TabStop = false;
			this->groupBoxCaesar->Text = L"Select Cipher";
			this->groupBoxCaesar->Enter += gcnew System::EventHandler(this, &MainForm::groupBoxCaesar_Enter);
			// 
			// btnDecrypt
			// 
			this->btnDecrypt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDecrypt->Location = System::Drawing::Point(290, 402);
			this->btnDecrypt->Name = L"btnDecrypt";
			this->btnDecrypt->Size = System::Drawing::Size(109, 35);
			this->btnDecrypt->TabIndex = 7;
			this->btnDecrypt->Text = L"Decrypt";
			this->btnDecrypt->UseVisualStyleBackColor = true;
			this->btnDecrypt->Click += gcnew System::EventHandler(this, &MainForm::btnDecrypt_Click);
			// 
			// btnEncrypt
			// 
			this->btnEncrypt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEncrypt->Location = System::Drawing::Point(23, 402);
			this->btnEncrypt->Name = L"btnEncrypt";
			this->btnEncrypt->Size = System::Drawing::Size(109, 35);
			this->btnEncrypt->TabIndex = 6;
			this->btnEncrypt->Text = L"Encrypt";
			this->btnEncrypt->UseVisualStyleBackColor = true;
			this->btnEncrypt->Click += gcnew System::EventHandler(this, &MainForm::btnEncrypt_Click);
			// 
			// txtOutput
			// 
			this->txtOutput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtOutput->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->txtOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtOutput->Location = System::Drawing::Point(23, 277);
			this->txtOutput->Multiline = true;
			this->txtOutput->Name = L"txtOutput";
			this->txtOutput->Size = System::Drawing::Size(376, 88);
			this->txtOutput->TabIndex = 5;
			// 
			// lblOutput
			// 
			this->lblOutput->AutoSize = true;
			this->lblOutput->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblOutput->Location = System::Drawing::Point(19, 247);
			this->lblOutput->Name = L"lblOutput";
			this->lblOutput->Size = System::Drawing::Size(68, 23);
			this->lblOutput->TabIndex = 4;
			this->lblOutput->Text = L"Output";
			// 
			// txtInput
			// 
			this->txtInput->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtInput->BackColor = System::Drawing::SystemColors::ControlDark;
			this->txtInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtInput->Location = System::Drawing::Point(23, 137);
			this->txtInput->Multiline = true;
			this->txtInput->Name = L"txtInput";
			this->txtInput->Size = System::Drawing::Size(376, 88);
			this->txtInput->TabIndex = 3;
			// 
			// lblInput
			// 
			this->lblInput->AutoSize = true;
			this->lblInput->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInput->Location = System::Drawing::Point(19, 109);
			this->lblInput->Name = L"lblInput";
			this->lblInput->Size = System::Drawing::Size(91, 23);
			this->lblInput->TabIndex = 2;
			this->lblInput->Text = L"Input Text";
			// 
			// txtShift
			// 
			this->txtShift->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtShift->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->txtShift->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtShift->Location = System::Drawing::Point(23, 54);
			this->txtShift->Multiline = true;
			this->txtShift->Name = L"txtShift";
			this->txtShift->Size = System::Drawing::Size(376, 49);
			this->txtShift->TabIndex = 1;
			// 
			// lblShift
			// 
			this->lblShift->AutoSize = true;
			this->lblShift->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblShift->Location = System::Drawing::Point(19, 28);
			this->lblShift->Name = L"lblShift";
			this->lblShift->Size = System::Drawing::Size(44, 23);
			this->lblShift->TabIndex = 0;
			this->lblShift->Text = L"Key ";
			// 
			// btnRailFenceCipher
			// 
			this->btnRailFenceCipher->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRailFenceCipher->Location = System::Drawing::Point(24, 448);
			this->btnRailFenceCipher->Name = L"btnRailFenceCipher";
			this->btnRailFenceCipher->Size = System::Drawing::Size(114, 45);
			this->btnRailFenceCipher->TabIndex = 9;
			this->btnRailFenceCipher->Text = L"Rail Fence Cipher";
			this->btnRailFenceCipher->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(670, 542);
			this->Controls->Add(this->btnRailFenceCipher);
			this->Controls->Add(this->groupBoxCaesar);
			this->Controls->Add(this->btnSimpleXorCipher);
			this->Controls->Add(this->btnColumanrTransposition);
			this->Controls->Add(this->btnSimpleSubsitiutionCipher);
			this->Controls->Add(this->btnVigenereCipher);
			this->Controls->Add(this->btnAtbashCipher);
			this->Controls->Add(this->btnCaesarCipher);
			this->Controls->Add(this->menuStripFile);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStripFile;
			this->Name = L"MainForm";
			this->Text = L"MystiCrypt";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStripFile->ResumeLayout(false);
			this->menuStripFile->PerformLayout();
			this->groupBoxCaesar->ResumeLayout(false);
			this->groupBoxCaesar->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	//  Cipher Button Click Handlers
	private: System::Void btnCaesarCipher_Click(System::Object^ sender, System::EventArgs^ e) {
		currentCipher = "Caesar";
		groupBoxCaesar->Text = "Selected Cipher: Caesar";
		lblShift->Text = "Shift (0-25):";
		txtShift->Enabled = true;
		lblShift->Visible = true;      // Show key components
		txtShift->Visible = true;
		txtShift->Clear();
		txtInput->Clear();
		txtOutput->Clear();
	}
	private: System::Void btnAtbashCipher_Click(System::Object^ sender, System::EventArgs^ e) {
		currentCipher = "Atbash";
		groupBoxCaesar->Text = "Selected Cipher: Atbash";
		// Hide key components for Atbash cipher
		lblShift->Visible = false;
		txtShift->Visible = false;
		txtShift->Enabled = false;
		txtShift->Clear();
		txtInput->Clear();
		txtOutput->Clear();
	}
	private: System::Void btnVigenereCipher_Click(System::Object^ sender, System::EventArgs^ e) {
		currentCipher = "Vigenere";
		groupBoxCaesar->Text = "Selected Cipher: Vigenère";
		lblShift->Text = "Keyword:";
		txtShift->Enabled = true;
		lblShift->Visible = true;      // Show key components
		txtShift->Visible = true;
		txtShift->Clear();
		txtInput->Clear();
		txtOutput->Clear();
	}
	private: System::Void btnSimpleSubsitiutionCipher_Click(System::Object^ sender, System::EventArgs^ e) {
		currentCipher = "Substitution";
		groupBoxCaesar->Text = "Selected Cipher: Simple Substitution";
		lblShift->Text = "Key (26 letters):";
		txtShift->Enabled = true;
		lblShift->Visible = true;      // Show key components
		txtShift->Visible = true;
		txtShift->Clear();
		txtInput->Clear();
		txtOutput->Clear();
	}
	private: System::Void btnColumanrTransposition_Click(System::Object^ sender, System::EventArgs^ e) {
		currentCipher = "Columnar";
		groupBoxCaesar->Text = "Selected Cipher: Columnar Transposition";
		lblShift->Text = "Key (word or numbers):";
		txtShift->Enabled = true;
		lblShift->Visible = true;      // Show key components
		txtShift->Visible = true;
		txtShift->Clear();
		txtInput->Clear();
		txtOutput->Clear();
	}
	private: System::Void btnSimpleXorCipher_Click(System::Object^ sender, System::EventArgs^ e) {
		currentCipher = "XOR";
		groupBoxCaesar->Text = "Selected Cipher: Simple XOR";
		lblShift->Text = "Key (string):";
		txtShift->Enabled = true;
		lblShift->Visible = true;      // Show key components
		txtShift->Visible = true;
		txtShift->Clear();
		txtInput->Clear();
		txtOutput->Clear();
	}
	private: System::Void btnRailFenceCipher_Click(System::Object^ sender, System::EventArgs^ e) {
		currentCipher = "RailFence";
		groupBoxCaesar->Text = "Selected Cipher: Rail Fence";
		lblShift->Visible = false;
		txtShift->Visible = false;
		txtShift->Enabled = false;
		txtShift->Clear();
		txtInput->Clear();
		txtOutput->Clear();
	}

	//  Encrypt Button Handler 
	private: System::Void btnEncrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		System::String^ input = txtInput->Text;
		System::String^ keyStr = txtShift->Text;
		std::string in = context.marshal_as<std::string>(input);
		std::string key = context.marshal_as<std::string>(keyStr);
		System::String^ output = "";

		if (currentCipher == "Caesar") {
			int shift = 0;
			if (!Int32::TryParse(keyStr, shift)) {
				MessageBox::Show("Please enter a valid integer for the shift value.");
				return;
			}
			output = gcnew System::String(CaesarCipher::Encrypt(in, shift).c_str());
		}
		else if (currentCipher == "Atbash") {
			output = gcnew System::String(AtbashCipher::Encrypt(in).c_str());
		}
		else if (currentCipher == "Vigenere") {
			if (keyStr->Length == 0) {
				MessageBox::Show("Please enter a keyword for Vigenère cipher.");
				return;
			}
			output = gcnew System::String(VigenereCipher::Encrypt(in, key).c_str());
		}
		else if (currentCipher == "Substitution") {
			if (keyStr->Length != 26) {
				MessageBox::Show("Key must be 26 letters for Simple Substitution.");
				return;
			}
			output = gcnew System::String(SimpleSubstitutionCipher::Encrypt(in, key).c_str());
		}
		else if (currentCipher == "Columnar") {
			if (keyStr->Length == 0) {
				MessageBox::Show("Please enter a key for Columnar Transposition.");
				return;
			}
			output = gcnew System::String(ColumnarTranspositionCipher::Encrypt(in, key).c_str());
		}
        else if (currentCipher == "XOR") {
            if (keyStr->Length == 0) {
                MessageBox::Show("Please enter a key for XOR cipher.");
                return;
            }
            char xorKey = key[0]; // Use the first character as the key
            output = gcnew System::String(SimpleXORCipher::Encrypt(in, xorKey).c_str());
        }
		else if (currentCipher == "RailFence") {
			output = RailFenceCipher::Encrypt(input);
		}
		else {
			MessageBox::Show("Please select a cipher.");
			return;
		}
		txtOutput->Text = output;
	}

	// Decrypt Button Handler	
	private: System::Void btnDecrypt_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
		System::String^ input = txtInput->Text;
		System::String^ keyStr = txtShift->Text;
		std::string in = context.marshal_as<std::string>(input);
		std::string key = context.marshal_as<std::string>(keyStr);
		System::String^ output = "";

		if (currentCipher == "Caesar") {
			int shift = 0;
			if (!Int32::TryParse(keyStr, shift)) {
				MessageBox::Show("Please enter a valid integer for the shift value.");
				return;
			}
			output = gcnew System::String(CaesarCipher::Decrypt(in, shift).c_str());
		}
		else if (currentCipher == "Atbash") {
			output = gcnew System::String(AtbashCipher::Decrypt(in).c_str());
		}
		else if (currentCipher == "Vigenere") {
			if (keyStr->Length == 0) {
				MessageBox::Show("Please enter a keyword for Vigenère cipher.");
				return;
			}
			output = gcnew System::String(VigenereCipher::Decrypt(in, key).c_str());
		}
		else if (currentCipher == "Substitution") {
			if (keyStr->Length != 26) {
				MessageBox::Show("Key must be 26 letters for Simple Substitution.");
				return;
			}
			output = gcnew System::String(SimpleSubstitutionCipher::Decrypt(in, key).c_str());
		}
		else if (currentCipher == "Columnar") {
			if (keyStr->Length == 0) {
				MessageBox::Show("Please enter a key for Columnar Transposition.");
				return;
			}
			output = gcnew System::String(ColumnarTranspositionCipher::Decrypt(in, key).c_str());
		}
		else if (currentCipher == "XOR") {
			if (keyStr->Length == 0) {
				MessageBox::Show("Please enter a key for XOR cipher.");
				return;
			}
            char xorKey = key[0];
			output = gcnew System::String(SimpleXORCipher::Decrypt(in, xorKey).c_str());
		}
		else if (currentCipher == "RailFence") {
			output = RailFenceCipher::Decrypt(input);
		}
		else {
			MessageBox::Show("Please select a cipher.");
			return;
		}
		txtOutput->Text = output;
	}

	// File Menu Handlers (unchanged) 
	private: System::Void newToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!String::IsNullOrEmpty(txtInput->Text) || !String::IsNullOrEmpty(txtOutput->Text)) {
			System::Windows::Forms::DialogResult result = MessageBox::Show(
				"Clear all data? Unsaved changes will be lost.", "New Document",
				MessageBoxButtons::YesNo, MessageBoxIcon::Warning
			);
			if (result == System::Windows::Forms::DialogResult::No)
				return;
		}
		txtInput->Clear();
		txtOutput->Clear();
		txtShift->Clear();      
	}
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ ofd = gcnew OpenFileDialog();
		ofd->Filter = "Text Files (*.txt)|*.txt|MystiCrypt Section (*.mcrypt)|*.mcrypt|All Files (*.*)|*.*";
		ofd->Title = "Open Cipher Section";
		ofd->DefaultExt = "txt"; // Set default extension to .txt
		ofd->FilterIndex = 1;    // Ensure .txt is selected by default
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				array<System::String^>^ lines = System::IO::File::ReadAllLines(ofd->FileName, System::Text::Encoding::UTF8);
				if (lines->Length >= 4) {
					currentCipher = lines[0];
					txtShift->Text = lines[1];
					txtInput->Text = lines[2];
					txtOutput->Text = lines[3];
					groupBoxCaesar->Text = "Selected Cipher: " + currentCipher;
				} else {
					// Fallback: treat as plain text input
					txtInput->Text = System::IO::File::ReadAllText(ofd->FileName, System::Text::Encoding::UTF8);
					txtOutput->Clear();
					txtShift->Clear();
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error opening file: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
    private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
        SaveFileDialog^ sfd = gcnew SaveFileDialog();
        sfd->Filter = "Text Files (*.txt)|*.txt|MystiCrypt Section (*.mcrypt)|*.mcrypt|All Files (*.*)|*.*";
        sfd->Title = "Save Cipher Section";
        sfd->DefaultExt = "txt"; // Set default extension to .txt
        sfd->AddExtension = true;
        sfd->FilterIndex = 1;    // Ensure .txt is selected by default
        if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            if (System::IO::File::Exists(sfd->FileName)) {
                auto result = MessageBox::Show(
                    "File already exists. Overwrite?", "Confirm Overwrite",
                    MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
                if (result != System::Windows::Forms::DialogResult::Yes)
                    return;
            }
            try {
                System::String^ data = currentCipher + "\n" + txtShift->Text + "\n" + txtInput->Text + "\n" + txtOutput->Text;
                System::IO::File::WriteAllText(sfd->FileName, data, System::Text::Encoding::UTF8);
                MessageBox::Show("Section saved successfully.", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error saving file: " + ex->Message,
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    }
	private: System::Void exportToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ sfd = gcnew SaveFileDialog();
		sfd->Filter = "Text Files (*.txt)|*.txt|CSV Files (*.csv)|*.csv|Word Document (*.docx)|*.docx|All Files (*.*)|*.*";
		sfd->Title = "Export File";
		if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				String^ outputData = txtOutput->Text;
				String^ ext = System::IO::Path::GetExtension(sfd->FileName)->ToLower();
				if (ext == ".csv") {
					outputData = outputData->Replace(" ", ",");
				}
				System::IO::File::WriteAllText(sfd->FileName, outputData, System::Text::Encoding::UTF8);
				MessageBox::Show("Export successful.", "Export",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error exporting file: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult result = MessageBox::Show(
			"Are you sure you want to exit?", "Exit",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question
		);
		if (result == System::Windows::Forms::DialogResult::Yes) {
			Application::Exit();
		}
	}

	//  Edit Menu Handlers 

	// Helper: Get the currently focused TextBox (txtInput or txtOutput)
	private: System::Windows::Forms::TextBox^ GetFocusedTextBox() {
		if (txtInput->Focused) return txtInput;
		if (txtOutput->Focused) return txtOutput;
		if (txtShift->Focused) return txtShift;
		return nullptr;
	}

	// Undo
	private: System::Void undoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		auto tb = GetFocusedTextBox();
		if (tb != nullptr && tb->CanUndo) {
			tb->Undo();
		}
	}

	// Redo
	private: System::Void redoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::MessageBox::Show("Redo is not supported.");
	}

	// Copy
	private: System::Void copyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		auto tb = GetFocusedTextBox();
		if (tb != nullptr && tb->SelectionLength > 0) {
			tb->Copy();
		}
	}

	// Paste
	private: System::Void pasteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		auto tb = GetFocusedTextBox();
		if (tb != nullptr && System::Windows::Forms::Clipboard::ContainsText()) {
			tb->Paste();
		}
	}

	// Cut
	private: System::Void cutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		auto tb = GetFocusedTextBox();
		if (tb != nullptr && tb->SelectionLength > 0) {
			tb->Cut();
		}
	}
	private: System::Void groupBoxCaesar_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void documentationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ pdfPath = "MystiCrypt_Documentation.pdf";
		try {
			System::Diagnostics::Process^ proc = gcnew System::Diagnostics::Process();
			proc->StartInfo->FileName = pdfPath;
			proc->StartInfo->UseShellExecute = true;
			proc->Start();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Could not open documentation PDF.\n" + ex->Message,
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void aboutMystiCryptToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(
			"MystiCrypt v1.0\nA Text Encryption & Decryption Suite\nCreated by Chavindu Pahasara",
			"About MystiCrypt",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
	}

	//  Button Hover Event Handlers
	private: System::Void btnEncrypt_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		btnEncrypt->BackColor = System::Drawing::Color::Blue;
		btnEncrypt->ForeColor = System::Drawing::Color::White;
	}
	private: System::Void btnEncrypt_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		btnEncrypt->BackColor = System::Drawing::Color::White;
		btnEncrypt->ForeColor = System::Drawing::Color::Black;
	}
	private: System::Void btnDecrypt_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		btnDecrypt->BackColor = System::Drawing::Color::Blue;
		btnDecrypt->ForeColor = System::Drawing::Color::White;
	}
	private: System::Void btnDecrypt_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		btnDecrypt->BackColor = System::Drawing::Color::White;
		btnDecrypt->ForeColor = System::Drawing::Color::Black;
	}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
