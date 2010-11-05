#pragma once
#include <math.h>
#include "Form2.h"

namespace astro2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
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
			form2 = gcnew Form2();
			form2->Show(this);
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
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	protected: 

	private: Form2 ^form2;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  latitudeBox;
	private: System::Windows::Forms::TextBox^  longtitudeBox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  JDBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  LSTBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  RABox1;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  decBox1;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  AzBox1;
	private: System::Windows::Forms::TextBox^  altBox1;


	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  RABox2;
	private: System::Windows::Forms::TextBox^  decBox2;


	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  AzBox2;
	private: System::Windows::Forms::TextBox^  altBox2;


	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		double LST;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->latitudeBox = (gcnew System::Windows::Forms::TextBox());
			this->longtitudeBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->JDBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->LSTBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->RABox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->decBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->AzBox1 = (gcnew System::Windows::Forms::TextBox());
			this->altBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->RABox2 = (gcnew System::Windows::Forms::TextBox());
			this->decBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->AzBox2 = (gcnew System::Windows::Forms::TextBox());
			this->altBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"yyyy/MM/dd HH:mm:ss";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(158, 5);
			this->dateTimePicker1->MaxDate = System::DateTime(9998, 10, 26, 0, 0, 0, 0);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->ShowUpDown = true;
			this->dateTimePicker1->Size = System::Drawing::Size(129, 22);
			this->dateTimePicker1->TabIndex = 0;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &Form1::dateTimePicker1_ValueChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 250;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(140, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"observer\'s local time:";
			// 
			// latitudeBox
			// 
			this->latitudeBox->Location = System::Drawing::Point(158, 39);
			this->latitudeBox->Name = L"latitudeBox";
			this->latitudeBox->Size = System::Drawing::Size(60, 22);
			this->latitudeBox->TabIndex = 2;
			this->latitudeBox->Text = L"25.016564";
			this->latitudeBox->TextChanged += gcnew System::EventHandler(this, &Form1::latitudeBox_TextChanged);
			// 
			// longtitudeBox
			// 
			this->longtitudeBox->Location = System::Drawing::Point(263, 39);
			this->longtitudeBox->Name = L"longtitudeBox";
			this->longtitudeBox->Size = System::Drawing::Size(80, 22);
			this->longtitudeBox->TabIndex = 3;
			this->longtitudeBox->Text = L"121.544362";
			this->longtitudeBox->TextChanged += gcnew System::EventHandler(this, &Form1::longtitudeBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label2->Location = System::Drawing::Point(12, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(129, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"observer\'s location:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(224, 39);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"N";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(349, 39);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"E";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(334, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 22);
			this->button1->TabIndex = 6;
			this->button1->Text = L"walk/stop";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(292, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(36, 21);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Now";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// JDBox
			// 
			this->JDBox->Location = System::Drawing::Point(97, 72);
			this->JDBox->Name = L"JDBox";
			this->JDBox->Size = System::Drawing::Size(99, 22);
			this->JDBox->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label5->Location = System::Drawing::Point(12, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Julian Day:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label6->Location = System::Drawing::Point(223, 72);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(38, 16);
			this->label6->TabIndex = 5;
			this->label6->Text = L"LST:";
			// 
			// LSTBox
			// 
			this->LSTBox->Location = System::Drawing::Point(267, 72);
			this->LSTBox->Name = L"LSTBox";
			this->LSTBox->Size = System::Drawing::Size(99, 22);
			this->LSTBox->TabIndex = 8;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label7->Location = System::Drawing::Point(14, 114);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(33, 16);
			this->label7->TabIndex = 5;
			this->label7->Text = L"RA:";
			// 
			// RABox1
			// 
			this->RABox1->Location = System::Drawing::Point(44, 114);
			this->RABox1->Name = L"RABox1";
			this->RABox1->Size = System::Drawing::Size(60, 22);
			this->RABox1->TabIndex = 8;
			this->RABox1->Text = L"0.000";
			this->RABox1->TextChanged += gcnew System::EventHandler(this, &Form1::RABox1_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label8->Location = System::Drawing::Point(103, 114);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(34, 16);
			this->label8->TabIndex = 5;
			this->label8->Text = L"dec:";
			// 
			// decBox1
			// 
			this->decBox1->Location = System::Drawing::Point(133, 114);
			this->decBox1->Name = L"decBox1";
			this->decBox1->Size = System::Drawing::Size(60, 22);
			this->decBox1->TabIndex = 8;
			this->decBox1->Text = L"0.000";
			this->decBox1->TextChanged += gcnew System::EventHandler(this, &Form1::decBox1_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label9->Location = System::Drawing::Point(219, 114);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(30, 16);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Az:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label10->Location = System::Drawing::Point(309, 114);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(27, 16);
			this->label10->TabIndex = 5;
			this->label10->Text = L"alt:";
			// 
			// AzBox1
			// 
			this->AzBox1->Location = System::Drawing::Point(246, 114);
			this->AzBox1->Name = L"AzBox1";
			this->AzBox1->Size = System::Drawing::Size(60, 22);
			this->AzBox1->TabIndex = 8;
			// 
			// altBox1
			// 
			this->altBox1->Location = System::Drawing::Point(335, 114);
			this->altBox1->Name = L"altBox1";
			this->altBox1->Size = System::Drawing::Size(60, 22);
			this->altBox1->TabIndex = 8;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(199, 117);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(15, 12);
			this->label11->TabIndex = 9;
			this->label11->Text = L"->";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label12->Location = System::Drawing::Point(216, 142);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(33, 16);
			this->label12->TabIndex = 5;
			this->label12->Text = L"RA:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label13->Location = System::Drawing::Point(305, 142);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(34, 16);
			this->label13->TabIndex = 5;
			this->label13->Text = L"dec:";
			// 
			// RABox2
			// 
			this->RABox2->Location = System::Drawing::Point(246, 142);
			this->RABox2->Name = L"RABox2";
			this->RABox2->Size = System::Drawing::Size(60, 22);
			this->RABox2->TabIndex = 8;
			// 
			// decBox2
			// 
			this->decBox2->Location = System::Drawing::Point(335, 142);
			this->decBox2->Name = L"decBox2";
			this->decBox2->Size = System::Drawing::Size(60, 22);
			this->decBox2->TabIndex = 8;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(199, 146);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(15, 12);
			this->label14->TabIndex = 9;
			this->label14->Text = L"->";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label15->Location = System::Drawing::Point(17, 143);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(30, 16);
			this->label15->TabIndex = 5;
			this->label15->Text = L"Az:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label16->Location = System::Drawing::Point(107, 143);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(27, 16);
			this->label16->TabIndex = 5;
			this->label16->Text = L"alt:";
			// 
			// AzBox2
			// 
			this->AzBox2->Location = System::Drawing::Point(44, 143);
			this->AzBox2->Name = L"AzBox2";
			this->AzBox2->Size = System::Drawing::Size(60, 22);
			this->AzBox2->TabIndex = 8;
			this->AzBox2->Text = L"0.000";
			this->AzBox2->TextChanged += gcnew System::EventHandler(this, &Form1::AzBox2_TextChanged);
			// 
			// altBox2
			// 
			this->altBox2->Location = System::Drawing::Point(133, 142);
			this->altBox2->Name = L"altBox2";
			this->altBox2->Size = System::Drawing::Size(60, 22);
			this->altBox2->TabIndex = 8;
			this->altBox2->Text = L"0.000";
			this->altBox2->TextChanged += gcnew System::EventHandler(this, &Form1::altBox2_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(404, 275);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->altBox2);
			this->Controls->Add(this->altBox1);
			this->Controls->Add(this->decBox2);
			this->Controls->Add(this->decBox1);
			this->Controls->Add(this->AzBox2);
			this->Controls->Add(this->AzBox1);
			this->Controls->Add(this->RABox2);
			this->Controls->Add(this->RABox1);
			this->Controls->Add(this->LSTBox);
			this->Controls->Add(this->JDBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->longtitudeBox);
			this->Controls->Add(this->latitudeBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
				 dateTimePicker1->Value = dateTimePicker1->Value.AddMilliseconds(timer1->Interval);
				 
			 }
	private: System::Void dateTimePicker1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
				calculateLST();
				calculateCoordinate();
			 }
	private: System::Void calculateLST() {
				System::DateTime UT = dateTimePicker1->Value.ToUniversalTime();
				int y = UT.Year;
				int m = UT.Month;
				int d = UT.Day;
				if (m<3) {
				 y = y - 1;
				 m = m + 12;
				}
				int B=0;
				if (y>1582 || y==1582&&m>10 || y==1582&&m==10&&d>=15) {
					B = 2 - y/100 + y/100/4;
				}
				int C=0;
				if (y<0) {
					C = floor(365.25*y-0.75);
				}
				else {
					C = floor(365.25*y);
				}
				int D = floor(30.6001*(m+1));
				double JD0 = B+C+D+d+1720994.5;
				double decimalHour = (UT.Second/60.0 + UT.Minute)/60.0 + UT.Hour;
				double JD = JD0 + decimalHour/24.0;
				JDBox->Text = JD.ToString();

				double T = (JD0-2451545.0)/36525.0;
				double T0 = fmod(6.697374558 + 2400.051336*T + 0.000025862*T*T, 24.0);
				double GST = fmod(fmod(decimalHour*1.002737909 + T0, 24.0)+24.0, 24.0);
				try {
					LST = fmod(GST + System::Convert::ToDouble(longtitudeBox->Text)/15.0 + 24.0, 24.0);
				}
				catch (System::Exception^) {
					LST = fmod(GST + System::Convert::ToDouble("0")/15.0 + 24.0, 24.0);
				}
				LSTBox->Text = LST.ToString();
			}

	private: System::Void calculateCoordinate() {
				double pi = acos(-1.0);
				double latitude;
				try {
					latitude = System::Convert::ToDouble(latitudeBox->Text);
				}
				catch (System::Exception^) {
					latitude = 0.0;
				}
				latitude = latitude/180.0*pi;
				double HA1;
				try {
					HA1 = fmod(LST - System::Convert::ToDouble(RABox1->Text) + 24.0, 24.0) * 15.0;
				}
				catch (System::Exception^) {
					HA1 = fmod(LST - 0.0 + 24.0, 24.0) * 15.0;
				}
				HA1 = HA1/180.0*pi;
				double dec1;
				try {
					dec1 = System::Convert::ToDouble(decBox1->Text);
				}
				catch (System::Exception^) {
					dec1 = 0.0;
				}
				dec1 = dec1/180.0*pi;
				double alt1 = asin(sin(dec1)*sin(latitude) + cos(dec1)*cos(latitude)*cos(HA1));
				altBox1->Text = (alt1/pi*180.0).ToString();

				double Az1 = acos( (sin(dec1)-sin(latitude)*sin(alt1)) / (cos(latitude)*cos(alt1)) );
				if (sin(HA1)>=0.0) {
					Az1 = 2*pi-Az1;
				}
				AzBox1->Text = (Az1/pi*180.0).ToString();

				double Az2;
				try {
					Az2 = System::Convert::ToDouble(AzBox2->Text);
				}
				catch (System::Exception^) {
					Az2 = 0.0;
				}
				Az2 = Az2/180.0*pi;
				double alt2;
				try {
					alt2 = System::Convert::ToDouble(altBox2->Text);
				}
				catch (System::Exception^) {
					alt2 = 0.0;
				}
				alt2 = alt2/180.0*pi;
				double dec2 = asin(sin(alt2)*sin(latitude) + cos(alt2)*cos(latitude)*cos(Az2));
				decBox2->Text = (dec2/pi*180.0).ToString();
				//double HA2 = acos( (sin(alt2)-sin(latitude)*sin(dec2)) / (cos(latitude)*cos(dec2)) );
				double eps = 0.000000000000001;
				double tmp = (sin(alt2)-sin(latitude)*sin(dec2)) / (cos(latitude)*cos(dec2));
				if (tmp<-1.0) {
					tmp += eps;
				}
				if (tmp>1.0) {
					tmp -= eps;
				}
				double HA2 = acos(tmp);
				if (sin(Az2)>=0.0) {
					HA2 = 2*pi-HA2;
				}
				RABox2->Text = fmod(LST - HA2/pi*12 + 24.0, 24.0).ToString();
				//RABox2->Text = acos((sin(alt2)-sin(latitude)*sin(dec2)) / (cos(latitude)*cos(dec2))).ToString();
				//RABox2->Text = HA2.ToString();
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if (timer1->Enabled) {
					 timer1->Enabled = false;
				 }
				 else {
					 timer1->Enabled = true;
				 }
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
					 dateTimePicker1->Value = System::DateTime::Now;
		 }
private: System::Void latitudeBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 calculateCoordinate();
		 }
private: System::Void longtitudeBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				calculateLST();
				calculateCoordinate();
		 }
private: System::Void RABox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				calculateCoordinate();
		 }
private: System::Void decBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				calculateCoordinate();
		 }
private: System::Void AzBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				calculateCoordinate();
		 }
private: System::Void altBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				calculateCoordinate();
		 }
};
}

