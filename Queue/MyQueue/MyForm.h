#pragma once
#include "../Queue/Queue.h"

namespace MyQueue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int MaxSize;
		int Size;
		double p;
		double q;
		int PopCount;
		int PushCount;
		TQueue <int>* pQueue;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rndm1;
		Pen^ BlackPen;
		Pen^ WhitePen;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox6;

	public:
		MyForm(void)
		{
			InitializeComponent();
			gr = CreateGraphics();
			rndm1 = gcnew Random();

			BlackPen = gcnew Pen(Color::DarkCyan);
			BlackPen->Width = 10.0F;
			WhitePen = gcnew Pen(SystemColors::InactiveBorder);
			WhitePen->Width = 11.0F;

			CenterX = 175;
			CenterY = 250;
			Width = Height = 200;

			PopCount = PushCount = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button1->Cursor = System::Windows::Forms::Cursors::Default;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::Olive;
			this->button1->Location = System::Drawing::Point(427, 44);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 36);
			this->button1->TabIndex = 8;
			this->button1->Text = L"СТАРТ";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe Script", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->label1->Location = System::Drawing::Point(0, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(263, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Максимальная длина очереди";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe Script", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->label2->Location = System::Drawing::Point(0, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(213, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Исходная длина очереди";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe Script", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->label3->Location = System::Drawing::Point(0, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(218, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Вероятность добавления";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe Script", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->label4->Location = System::Drawing::Point(0, 101);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(219, 25);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Вероятность извлечения";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe Script", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->label5->Location = System::Drawing::Point(0, 129);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(168, 25);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Добавлено в очередь";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe Script", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::Color::DarkGoldenrod;
			this->label6->Location = System::Drawing::Point(0, 157);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(181, 25);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Извлечено из очереди";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox1->ForeColor = System::Drawing::Color::DarkCyan;
			this->textBox1->Location = System::Drawing::Point(290, 11);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(100, 23);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox2->ForeColor = System::Drawing::Color::DarkCyan;
			this->textBox2->Location = System::Drawing::Point(290, 41);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(100, 23);
			this->textBox2->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox3->ForeColor = System::Drawing::Color::DarkCyan;
			this->textBox3->Location = System::Drawing::Point(290, 72);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox3->Size = System::Drawing::Size(100, 23);
			this->textBox3->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox4->ForeColor = System::Drawing::Color::DarkCyan;
			this->textBox4->Location = System::Drawing::Point(290, 103);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox4->Size = System::Drawing::Size(100, 23);
			this->textBox4->TabIndex = 10;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox5->ForeColor = System::Drawing::Color::DarkCyan;
			this->textBox5->Location = System::Drawing::Point(290, 131);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox5->Size = System::Drawing::Size(100, 23);
			this->textBox5->TabIndex = 11;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.25F));
			this->textBox6->ForeColor = System::Drawing::Color::DarkCyan;
			this->textBox6->Location = System::Drawing::Point(290, 159);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox6->Size = System::Drawing::Size(100, 23);
			this->textBox6->TabIndex = 12;
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::Olive;
			this->button2->Location = System::Drawing::Point(427, 118);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(80, 36);
			this->button2->TabIndex = 9;
			this->button2->Text = L"СТОП";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(567, 508);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MaxSize = Convert::ToInt32(textBox1->Text);
		Size = Convert::ToInt32(textBox2->Text);
		p = Convert::ToDouble(textBox3->Text);
		q = Convert::ToDouble(textBox4->Text);

		pQueue = new TQueue <int>(MaxSize);
		for (int i = 0; i < Size; i++)
		{
			pQueue->Push(i);
		}
		DrawQueue();
		timer1->Enabled = true;
	}
		   void DrawQueue()
		   {
			   int start = 360 * pQueue->GetHead() / pQueue->GetSize();
			   int finish = 360 * (pQueue->GetDataCount()) / pQueue->GetSize();
			   gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
		   }
		   void Clean()
		   {
			   int start = 360 * pQueue->GetHead() / pQueue->GetSize();
			   int finish = 360 * (pQueue->GetDataCount()) / pQueue->GetSize();
			   gr->DrawArc(WhitePen, CenterX, CenterY, Width, Height, 0, 360);
		   }
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		timer1->Enabled = false;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Clean();
		if (rndm1->NextDouble() < p)
		{
			if (Size < MaxSize)
			{
				pQueue->Push(1);
				Size++;
				PushCount++;
			}
		}
		if (rndm1->NextDouble() < q)
		{
			if (Size > 0)
			{
				pQueue->Pop();
				Size--;
				PopCount++;
			}
		}
		DrawQueue();
		textBox5->Text = Convert::ToString(PushCount);
		textBox6->Text = Convert::ToString(PopCount);
	}
	};
}
