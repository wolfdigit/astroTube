#pragma once
#include <math.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace astro2 {

	/// <summary>
	/// Form2 的摘要
	///
	/// 警告: 如果您變更這個類別的名稱，就必須變更與這個類別所依據之所有 .resx 檔案關聯的
	///          Managed 資源編譯器工具的 'Resource File Name' 屬性。
	///          否則，這些設計工具
	///          將無法與這個表單關聯的當地語系化資源
	///          正確互動。
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TrackBar^  RABar;
	private: System::Windows::Forms::TrackBar^  widthBar;



	private: System::Windows::Forms::Label^  RALabel;
	private: System::Windows::Forms::TrackBar^  decBBar;

	private: System::Windows::Forms::TrackBar^  decTBar;

	private: System::Windows::Forms::Label^  RARLabel;
	private: System::Windows::Forms::Label^  RALLabel;
	private: System::Windows::Forms::Label^  decTLabel;
	private: System::Windows::Forms::Label^  decBLabel;



	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;
		double AzCent, AzLeft, AzRight;
		double altTop, altBottom;
		static double pi = acos(-1.0);
		Graphics^ graph;
		Rectangle rect;
		static const double groupRadX=2*pi/32.0, groupRadY=pi/32.0;
		Int16 Mthres;
		
		ref class SAOheader {
		public:
			Int32 star0;
			Int32 star1;
			Int32 starn;
			Int32 stnum;
			Int32 mprop;
			Int32 nmag;
			Int32 nbent;
		};
		SAOheader saoHeader;
		ref class CatalogEnt : public IComparable {
		public:
			double sra0, sdec0;
			array<wchar_t> ^is;
			Int16 mag;
			double vi;
			double size;
			float xrpm, xdpm;
			int groupX, groupY;
			CatalogEnt() {
				is = gcnew array<wchar_t>(2);
			}
			System::Void calcVI() {
				double gamma = 0.6;
				double c1 = Math::Pow(100, -0/500.0*gamma);
				double c0 = Math::Pow(100, -1400/500.0*gamma);

				vi = Math::Pow(100,-mag/500.0);
				size = (Math::Pow(vi, gamma)-c0)/(c1-c0)*4+1;
			}
			System::Void draw(Form2 ^form) {
				form->drawStar(this->sra0/pi*180.0, this->sdec0/pi*180.0, size);
			}
			virtual int CompareTo(Object^ obj) {
				CatalogEnt^ b = safe_cast<CatalogEnt^>(obj);
				if (this->mag<=b->mag) {
					return -1;
				}
				else {
					return 1;
				}
			}
		};
		array<CatalogEnt^> ^catalog;
		ref class StarGroup {
		public: array<CatalogEnt^> ^stars;
			int n;
		public: StarGroup() {
				n=0;
				stars = gcnew array<CatalogEnt^>(8);
			}
		public: System::Void append(CatalogEnt^ star) {
					if (n>=stars->Length) {
						stars->Resize(stars, stars->Length*2);
					}
					stars[n++] = star;
			}
		public: System::Void sort() {
					Array::Sort( stars, 0, n );
				}
		};
		array<StarGroup^,2> ^starGroup;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->RABar = (gcnew System::Windows::Forms::TrackBar());
			this->widthBar = (gcnew System::Windows::Forms::TrackBar());
			this->RALabel = (gcnew System::Windows::Forms::Label());
			this->decBBar = (gcnew System::Windows::Forms::TrackBar());
			this->decTBar = (gcnew System::Windows::Forms::TrackBar());
			this->RARLabel = (gcnew System::Windows::Forms::Label());
			this->RALLabel = (gcnew System::Windows::Forms::Label());
			this->decTLabel = (gcnew System::Windows::Forms::Label());
			this->decBLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RABar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->widthBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->decBBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->decTBar))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 393);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form2::pictureBox1_Paint);
			// 
			// AzBar
			// 
			this->RABar->LargeChange = 15;
			this->RABar->Location = System::Drawing::Point(112, 411);
			this->RABar->Maximum = 360;
			this->RABar->Name = L"AzBar";
			this->RABar->Size = System::Drawing::Size(400, 45);
			this->RABar->SmallChange = 5;
			this->RABar->TabIndex = 1;
			this->RABar->TickFrequency = 15;
			this->RABar->Value = 180;
			this->RABar->ValueChanged += gcnew System::EventHandler(this, &Form2::updateAALabel);
			// 
			// widthBar
			// 
			this->widthBar->Location = System::Drawing::Point(512, 411);
			this->widthBar->Maximum = 180;
			this->widthBar->Minimum = 15;
			this->widthBar->Name = L"widthBar";
			this->widthBar->Size = System::Drawing::Size(100, 45);
			this->widthBar->TabIndex = 2;
			this->widthBar->TickFrequency = 15;
			this->widthBar->Value = 90;
			this->widthBar->ValueChanged += gcnew System::EventHandler(this, &Form2::updateAALabel);
			// 
			// AzLabel
			// 
			this->RALabel->AutoSize = true;
			this->RALabel->Location = System::Drawing::Point(301, 393);
			this->RALabel->Name = L"AzLabel";
			this->RALabel->Size = System::Drawing::Size(23, 12);
			this->RALabel->TabIndex = 3;
			this->RALabel->Text = L"180";
			this->RALabel->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// altBBar
			// 
			this->decBBar->Location = System::Drawing::Point(618, 212);
			this->decBBar->Maximum = 75;
			this->decBBar->Minimum = -90;
			this->decBBar->Name = L"altBBar";
			this->decBBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->decBBar->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->decBBar->Size = System::Drawing::Size(45, 193);
			this->decBBar->TabIndex = 4;
			this->decBBar->TickFrequency = 15;
			this->decBBar->ValueChanged += gcnew System::EventHandler(this, &Form2::updateAALabel);
			// 
			// altTBar
			// 
			this->decTBar->Location = System::Drawing::Point(618, 13);
			this->decTBar->Maximum = 90;
			this->decTBar->Minimum = -75;
			this->decTBar->Name = L"altTBar";
			this->decTBar->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->decTBar->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->decTBar->Size = System::Drawing::Size(45, 193);
			this->decTBar->TabIndex = 4;
			this->decTBar->TickFrequency = 15;
			this->decTBar->Value = 90;
			this->decTBar->ValueChanged += gcnew System::EventHandler(this, &Form2::updateAALabel);
			// 
			// AzRLabel
			// 
			this->RARLabel->AutoSize = true;
			this->RARLabel->Location = System::Drawing::Point(584, 393);
			this->RARLabel->Name = L"AzRLabel";
			this->RARLabel->Size = System::Drawing::Size(17, 12);
			this->RARLabel->TabIndex = 5;
			this->RARLabel->Text = L"90";
			this->RARLabel->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// AzLLabel
			// 
			this->RALLabel->AutoSize = true;
			this->RALLabel->Location = System::Drawing::Point(12, 393);
			this->RALLabel->Name = L"AzLLabel";
			this->RALLabel->Size = System::Drawing::Size(17, 12);
			this->RALLabel->TabIndex = 5;
			this->RALLabel->Text = L"90";
			this->RALLabel->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// altTLabel
			// 
			this->decTLabel->AutoSize = true;
			this->decTLabel->Location = System::Drawing::Point(595, 12);
			this->decTLabel->Name = L"altTLabel";
			this->decTLabel->Size = System::Drawing::Size(17, 12);
			this->decTLabel->TabIndex = 6;
			this->decTLabel->Text = L"90";
			this->decTLabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// altBLabel
			// 
			this->decBLabel->AutoSize = true;
			this->decBLabel->Location = System::Drawing::Point(595, 381);
			this->decBLabel->Name = L"altBLabel";
			this->decBLabel->Size = System::Drawing::Size(17, 12);
			this->decBLabel->TabIndex = 6;
			this->decBLabel->Text = L"90";
			this->decBLabel->TextAlign = System::Drawing::ContentAlignment::BottomRight;
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(661, 442);
			this->Controls->Add(this->decBLabel);
			this->Controls->Add(this->decTLabel);
			this->Controls->Add(this->RALLabel);
			this->Controls->Add(this->RARLabel);
			this->Controls->Add(this->decTBar);
			this->Controls->Add(this->decBBar);
			this->Controls->Add(this->RALabel);
			this->Controls->Add(this->widthBar);
			this->Controls->Add(this->RABar);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->RABar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->widthBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->decBBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->decTBar))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
				 RABar->Value++;
				 RABar->Value--;
				 loadSAO();
			 }
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				graph = e->Graphics;
				graph->Clear(Color::Black);
				rect = pictureBox1->ClientRectangle;

				drawGrid();
				drawStar();
			 }
	private: System::Void drawGrid() {
				 double x, y;
				 Pen^ bluePen = gcnew Pen(Color::Blue);
				 for (int i=0; i<=360; i+=15) {
					 System::Drawing::Point prev = System::Drawing::Point::Empty, curr;
					 for (double j=-75.0; j<=75.0; j+=1.0) {
						 x = windowX(i, j);
						 y = windowY(i, j);
						 if (Double::IsNaN(x)||Double::IsNaN(y)) {
							 curr = System::Drawing::Point::Empty;
							 continue;
						 }
						 prev = curr;
						 curr.X = rect.X+rect.Width*x;
						 curr.Y = rect.Y+rect.Height*y;
 						 if (!prev.IsEmpty) {
							graph->DrawLine(bluePen, prev, curr);
						}
					 }
				 }
				 
				 for (int i=-75; i<90; i+=15) {
					 System::Drawing::Point prev = System::Drawing::Point::Empty, curr;
					 for (double j=0; j<360; j+=1.0) {
						 x = windowX(j, i);
						 y = windowY(j, i);
						 if (Double::IsNaN(x)||Double::IsNaN(y)) {
							 continue;
						 }
						 prev = curr;
						 curr.X = rect.X+rect.Width*x;
						 curr.Y = rect.Y+rect.Height*y;
						 if (!prev.IsEmpty) {
							graph->DrawLine(bluePen, prev, curr);
						}
					 }
				 }
			 }
	private: System::Boolean groupInView(int idx, int idy) {
				 double ra, dec;
				 double dX=groupRadX/pi*180, dY=groupRadY/pi*180;
				 //x = windowX(ra, dec);
				 //y = windowY(ra, dec);
				 //catalog[i]->groupX = (int)(catalog[i]->sra0/groupRadX);
				 //catalog[i]->groupY = (int)((catalog[i]->sdec0+pi/2)/groupRadY);
				 ra  = (idx*groupRadX)/pi*180;
				 dec = (idy*groupRadY-pi/2)/pi*180;
				 if (!Double::IsNaN(windowX(ra, dec))&&!Double::IsNaN(windowY(ra, dec))) {
					 return true;
				 }
				 if (!Double::IsNaN(windowX(ra+dX, dec))&&!Double::IsNaN(windowY(ra+dX, dec))) {
					 return true;
				 }
				 if (!Double::IsNaN(windowX(ra, dec+dY))&&!Double::IsNaN(windowY(ra, dec+dY))) {
					 return true;
				 }
				 if (!Double::IsNaN(windowX(ra+dX, dec+dY))&&!Double::IsNaN(windowY(ra+dX, dec+dY))) {
					 return true;
				 }
				 return false;
			 }
	private: System::Void drawStar() {
				for (int i=0; i<(int)(2*pi/groupRadX); i++) {
					for (int j=0; j<(int)(pi/groupRadY); j++) {
						if (!groupInView(i,j)) {
							continue;
						}
						for (int k=0; k<starGroup[i,j]->n; k++) {
							if (starGroup[i,j]->stars[k]->mag>Mthres) {
								break;
							}
							starGroup[i,j]->stars[k]->draw(this);
						}
					}
				}
				//for (int i=0; i<saoHeader.starn; i++) {
					//if (catalog[i]->mag<800) {
						//catalog[i]->draw(this);
					//}
				//}
			 }

	private: System::Void drawStar(double ra, double dec, int size) {
				Pen^ whitePen = gcnew Pen(Color::White);
				double x, y;
				x = windowX(ra, dec);
				y = windowY(ra, dec);
				if (!Double::IsNaN(x)&&!Double::IsNaN(y)) {
					graph->DrawEllipse(whitePen, rect.X+rect.Width*x, rect.Y+rect.Height*y, size, size);
				}
			 }
	private: System::Void updateAALabel(System::Object^  sender, System::EventArgs^  e) {
				 AzCent = RABar->Value;
				 RALabel->Text = AzCent.ToString();
				 AzLeft = AzCent - widthBar->Value;
				 RALLabel->Text = AzLeft.ToString();
				 AzRight = AzCent + widthBar->Value;
				 RARLabel->Text = AzRight.ToString();
				 altBottom = decBBar->Value;
				 decBLabel->Text = altBottom.ToString();
				 decTBar->Minimum = altBottom + 15;
				 altTop = decTBar->Value;
				 decTLabel->Text = altTop.ToString();
				 decBBar->Maximum = altTop - 15;
				 pictureBox1->Refresh();
				 // view area = r^2 * (theta2-theta1) * (sin(phi2)-sin(phi1))
				 Mthres = 680-(Int16)(500.0/2.0*Math::Log10((AzRight-AzLeft)*(sin(altTop/180.0*pi)-sin(altBottom/180.0*pi))/360.0/(1-sin(10.0/180.0*pi))));
			 }
	private: double windowX(double az, double alt) {
				 double delta = (az - AzCent) / (AzRight - AzCent);
				 //double x = delta * cos(alt/180.0*pi) / cos(altBottom/180.0*pi);
				 double x = delta * cos(alt/180.0*pi);
				 if (x>1 || x<-1) {
					 return System::Double::NaN;
				 }
				 return 0.5 + x/2;
			 }
	private: double windowY(double az, double alt) {
				 double y = (alt - altBottom) / (altTop - altBottom);
				 if (y>1||y<0) {
					 return System::Double::NaN;
				 }
				 return 1.0 - y;
			 }
	private: System::Void loadSAO() {
				 starGroup = gcnew array<StarGroup^,2>((int)(2*pi/groupRadX), (int)(pi/groupRadY));
				 for (int i=0; i<(int)(2*pi/groupRadX); i++) {
					 for (int j=0; j<(int)(pi/groupRadY); j++) {
						 starGroup[i,j] = gcnew StarGroup();
					 }
				 }
				 System::IO::BinaryReader reader = System::IO::File::Open("SAO.pc", System::IO::FileMode::Open);
				 reader.BaseStream->Seek(8, System::IO::SeekOrigin::Begin);
				 saoHeader.starn = reader.ReadInt32();
				 catalog = gcnew array<CatalogEnt^>(saoHeader.starn);
				 reader.BaseStream->Seek(28, System::IO::SeekOrigin::Begin);
				 for (int i=0; i<saoHeader.starn; i++) {
					 catalog[i] = gcnew CatalogEnt();
					 catalog[i]->sra0 = reader.ReadDouble();
					 catalog[i]->sdec0 = reader.ReadDouble();
					 catalog[i]->is = reader.ReadChars(2);
					 catalog[i]->mag = reader.ReadInt16();
					 catalog[i]->calcVI();
					 catalog[i]->xrpm = reader.ReadSingle();
					 catalog[i]->xdpm = reader.ReadSingle();
					 catalog[i]->groupX = (int)(catalog[i]->sra0/groupRadX);
					 catalog[i]->groupY = (int)((catalog[i]->sdec0+pi/2)/groupRadY);
					 starGroup[catalog[i]->groupX, catalog[i]->groupY]->append(catalog[i]);
				 }
				 for (int i=0; i<(int)(2*pi/groupRadX); i++) {
					 for (int j=0; j<(int)(pi/groupRadY); j++) {
						 starGroup[i,j]->sort();
					 }
				 }

			 }
	};

}
