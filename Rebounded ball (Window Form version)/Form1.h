#pragma once

namespace s1003352_Program7_VS2013 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 設計工具所需的變數。
		int mouseX;
		int rectWidth;
		int ballX, ballY;
		int ballMoveX, ballMoveY;
		int timeCnt;
	private: System::Windows::Forms::Timer^  ballTimer;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Timer^  timeTimer;
	private: System::Windows::Forms::Label^  label2;
	private: System::ComponentModel::IContainer^  components;
		#define LEFTMARGIN 10
		#define RIGHTMARGIN 310
		#define TOPMARGIN 30
		#define BOTTOMMARGIN 330
		#define BALLWIDTH 20
		#define BALLHEIGHT 20
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ballTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timeTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// ballTimer
			// 
			this->ballTimer->Enabled = true;
			this->ballTimer->Tick += gcnew System::EventHandler(this, &Form1::ballTimer_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(50, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 12);
			this->label1->TabIndex = 0;
			// 
			// timeTimer
			// 
			this->timeTimer->Enabled = true;
			this->timeTimer->Interval = 1000;
			this->timeTimer->Tick += gcnew System::EventHandler(this, &Form1::timeTimer_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 341);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 12);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(324, 362);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Rebounded Ball";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 Graphics^ graph = this->CreateGraphics();
				 Pen^ pen = gcnew Pen(Color::Red, 3);
				 graph->DrawRectangle(pen, LEFTMARGIN, TOPMARGIN, RIGHTMARGIN-LEFTMARGIN, BOTTOMMARGIN-TOPMARGIN);

				 // draw rect
				 SolidBrush^ rectBrush = gcnew SolidBrush(Color::Red);
				 graph->FillRectangle(rectBrush, mouseX-rectWidth/2, 330, rectWidth, 20);

				 // draw ball
				 SolidBrush^ ballBrush = gcnew SolidBrush(Color::Red);
				 graph->FillEllipse(ballBrush, ballX-BALLWIDTH/2, ballY-BALLHEIGHT/2, BALLWIDTH, BALLHEIGHT);

				 // show the time
				 String^ strTime = "Time: ";
				 strTime = String::Concat(strTime, System::Convert::ToString(timeCnt));
				 label2->Text = strTime;
			 }
	private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if (e->X < LEFTMARGIN+rectWidth/2) mouseX = LEFTMARGIN+rectWidth/2;
				 else if (e->X > RIGHTMARGIN-rectWidth/2) mouseX = RIGHTMARGIN-rectWidth/2;
				 else mouseX = e->X;
				 Invalidate();
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 mouseX = RIGHTMARGIN-LEFTMARGIN/2;
				 rectWidth = 50;

				 ballX = (RIGHTMARGIN-LEFTMARGIN)/2;
				 ballY = TOPMARGIN+BALLHEIGHT/2;

				 ballMoveX = 5;
				 ballMoveY = 10;
			 }
	private: System::Void ballTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
				 // left wall
				 if (ballX+ballMoveX-BALLWIDTH/2 < LEFTMARGIN) {
					 ballX = LEFTMARGIN+BALLWIDTH/2;
					 ballMoveX *= -1; // reverse
				 }
			     // right wall
				 if (ballX+ballMoveX+BALLWIDTH/2 > RIGHTMARGIN) {
					 ballX = RIGHTMARGIN-BALLWIDTH/2;
					 ballMoveX *= -1; // reverse
				 }
				 // top wall
				 if (ballY+ballMoveY-BALLHEIGHT/2 < TOPMARGIN) {
					 ballY = TOPMARGIN+BALLHEIGHT/2;
					 ballMoveY *= -1; // reverse
				 }
				 // bottom wall
				 if (ballY+ballMoveY+BALLHEIGHT/2 > BOTTOMMARGIN) {
					 if (ballX < mouseX-rectWidth/2 || ballX > mouseX+rectWidth/2) {
						 ballTimer->Enabled = false;
						 timeTimer->Enabled = false;
					 }
					 ballY = BOTTOMMARGIN-BALLHEIGHT/2;
					 ballMoveY *= -1; // reverse
				 }
				 Invalidate();
				 ballX += ballMoveX;
				 ballY += ballMoveY;
			 }
	private: System::Void timeTimer_Tick(System::Object^  sender, System::EventArgs^  e) {
				 timeCnt++;
				 if (timeCnt%5 == 0)
					 ballMoveY = ballMoveY > 0 ? ballMoveY+3 : ballMoveY-3;
			 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

