#pragma once

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

















	protected: 

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;
		double AzCent, AzLeft, AzRight;
		double altCent, altTop, altBottom;
		double viewWidth;
		static double pi = acos(-1.0);
		Graphics^ graph;
		Rectangle rect;
		static const double groupRadX=2*pi/32.0, groupRadY=pi/32.0;
		static const double drawSize = 5.0;
		Int16 Mthres;
        static Pen^ gridPen = gcnew Pen(Color::Blue);
		static Brush^ starOBrush = gcnew SolidBrush(Color::PaleTurquoise);
		static Brush^ starBBrush = gcnew SolidBrush(Color::PaleTurquoise);
		static Brush^ starABrush = gcnew SolidBrush(Color::White);
		static Brush^ starFBrush = gcnew SolidBrush(Color::Yellow);
		static Brush^ starGBrush = gcnew SolidBrush(Color::Orange);
		static Brush^ starKBrush = gcnew SolidBrush(Color::Tomato);
		static Brush^ starMBrush = gcnew SolidBrush(Color::Tomato);

		
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
			float xrpm, xdpm;
			int groupX, groupY;
			double physicalDiameter, size;
			CatalogEnt() {
				is = gcnew array<wchar_t>(2);
			}
			System::Void calcVI() {
				double gamma = 0.5;
				double c1 = Math::Pow(100, -0/500.0/2.0*gamma);
				double c0 = Math::Pow(100, -1400/500.0/2.0*gamma);

				vi = Math::Pow(100,-mag/500.0);
				physicalDiameter = Math::Sqrt(vi);
				size = (Math::Pow(physicalDiameter, gamma)-c0)/(c1-c0)*30+1;
			}
			System::Void draw(Form2 ^form) {
				form->drawStar(this->sra0/pi*180.0, this->sdec0/pi*180.0, size, this->is[0]);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(784, 562);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form2::pictureBox1_MouseMove);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form2::pictureBox1_Paint);
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form2";
			this->Text = L"Form2";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			this->SizeChanged += gcnew System::EventHandler(this, &Form2::Form2_SizeChanged);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e) {
				 AzCent = 180.0;
				 altCent = 0.0;
				 viewWidth = 90.0;
				 loadSAO();
				 updateViewDelta(0.0, 0.0, 0.0);
			 }
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::HighQuality;
				 e->Graphics->InterpolationMode = Drawing2D::InterpolationMode::HighQualityBicubic;
				// e->Graphics->PageScale = 30.0F;
				graph = e->Graphics;
				graph->Clear(Color::Black);
				rect = pictureBox1->ClientRectangle;
				rect.Width *= drawSize;
				rect.Height *= drawSize;

				e->Graphics->ScaleTransform(1.0/drawSize,1.0/drawSize);
				drawGrid();
				// e->Graphics->PageScale = 1.0F;
				drawStar();
			 }
	private: System::Void drawGrid() {
				 double x, y;
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
							graph->DrawLine(gridPen, prev, curr);
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
							graph->DrawLine(gridPen, prev, curr);
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
			 }

	private: System::Void drawStar(double ra, double dec, int size, wchar_t is) {
				Brush^ brush=starABrush;
				//if (ra<AzLeft) {
				//	ra += 360.0;
				//}
				//if (ra>AzRight) {
				//	ra -= 360.0;
				//}
				double x, y;
				x = windowX(ra, dec);
				y = windowY(ra, dec);
				if (!Double::IsNaN(x)&&!Double::IsNaN(y)) {
					if (is=='O') brush = starOBrush;
					if (is=='B') brush = starBBrush;
					if (is=='A') brush = starABrush;
					if (is=='F') brush = starFBrush;
					if (is=='G') brush = starGBrush;
					if (is=='K') brush = starKBrush;
					if (is=='M') brush = starMBrush;
					graph->FillEllipse(brush, rect.X+rect.Width*x-size/2.0, rect.Y+rect.Height*y-size/2.0, size, size);
				}
			 }
	private: System::Void updateLabel() {
				 String^ title = gcnew String("View: (");
				 title += Math::Round(AzRight).ToString() + " ~ " +  Math::Round(AzCent).ToString() + " ~ " + Math::Round(AzLeft).ToString();
				 title += ", ";
				 title += Math::Round(altBottom).ToString() + " ~ " +  Math::Round(altCent).ToString() + " ~ "  + Math::Round(altTop).ToString();
				 title += ")";
				 this->Text = title;
			 }
	private: System::Void updateViewDelta(double dXCent, double dYCent, double dWidth) {
				 static const double AzCentMin = 0, AzCentMax = 360;
				 static const double altCentMin = -90, altCentMax = 90;
				 static const double viewWidthMin = 15, viewWidthMax = 180;
				 static const double moveSpeed=1/180.0;
				 {
					 double newValue = AzCent + dXCent*viewWidth*moveSpeed;
					 /*
					 if (AzCentMin<=newValue&&newValue<=AzCentMax) {
						 AzCent = newValue;
					 }
					 */
					 if (newValue>360.0) {
						 newValue -= 360.0;
					 }
					 if (newValue<0.0) {
						 newValue += 360.0;
					 }
					 AzCent = newValue;
				 }
				 {
					 double newValue = altCent + dYCent*viewWidth*moveSpeed;
					 if (altCentMin<=newValue&&newValue<=altCentMax) {
						 altCent = newValue;
					 }
				 }
				 {
					 double newValue = viewWidth + dWidth;
					 if (viewWidthMin<=newValue&&newValue<=viewWidthMax) {
						 viewWidth = newValue;
					 }
				 }
				 AzLeft = AzCent - viewWidth;
				 AzRight = AzCent + viewWidth;
				 altBottom = altCent - viewWidth/pictureBox1->ClientRectangle.Width*pictureBox1->ClientRectangle.Height;
				 altTop = altCent + viewWidth/pictureBox1->ClientRectangle.Width*pictureBox1->ClientRectangle.Height;
				 // view area = r^2 * (theta2-theta1) * (sin(phi2)-sin(phi1))
				 double pivotArea = (2*pi-0) * (sin(90.0/180.0*pi)-sin(10.0/180.0*pi));
				 double tmpPhi1=altBottom, tmpPhi2=altTop;
				 if (tmpPhi1<-90) tmpPhi1 = -90;
				 if (tmpPhi2>90) tmpPhi2 = 90;
				 double myArea = (AzRight/180.0*pi-AzLeft/180.0*pi) * (sin(tmpPhi2/180.0*pi)-sin(tmpPhi1/180.0*pi));
				 Mthres = 600-(Int16)(500*Math::Log10(myArea/pivotArea)/2.0);

				 updateLabel();
				 pictureBox1->Refresh();
			 }
	private: double windowX(double az, double alt) {
				 double delta = (az - AzCent);
				 if (delta>180.0) delta -= 360.0;
				 if (delta<-180.0) delta += 360.0;
				 delta = delta / viewWidth;
				 //double x = delta * cos(alt/180.0*pi) / cos(altBottom/180.0*pi);
				 double x = delta * Math::Cos(alt/180.0*pi);
				 if (x>1 || x<-1) {
					 return System::Double::NaN;
				 }
				 return 0.5 - x/2;
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
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 static Point prev, cur;
			 if (e->Button==::MouseButtons::None) {
				 cur = Point::Empty;
			 }
			 else {
				 cur = e->Location;
			 }
			 if (!prev.IsEmpty) {
				 if (e->Button==::MouseButtons::Left) {
					 updateViewDelta(cur.X-prev.X, cur.Y-prev.Y, 0.0);
				 }
				 if (e->Button==::MouseButtons::Right) {
					 updateViewDelta(0.0, 0.0, cur.Y-prev.Y);
				 }
			 }
			 prev = cur;
		 }
private: System::Void Form2_SizeChanged(System::Object^  sender, System::EventArgs^  e) {
			 pictureBox1->Size = this->ClientRectangle.Size;
			 updateViewDelta(0.0, 0.0, 0.0);
			 updateLabel();
		 }
};

}
