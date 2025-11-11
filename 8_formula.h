#pragma once
#include <Math.h>
#include <cmath>
namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Form1
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
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
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::TextBox^ textBox3;

    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::TextBox^ textBox4;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label6;
    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(65, 79);
            this->textBox1->Margin = System::Windows::Forms::Padding(4);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(132, 22);
            this->textBox1->TabIndex = 0;
            this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(16, 82);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(18, 16);
            this->label1->TabIndex = 1;
            this->label1->Text = L"X:";
            this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(16, 114);
            this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(37, 16);
            this->label2->TabIndex = 3;
            this->label2->Text = L"A от:";
            this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(65, 111);
            this->textBox2->Margin = System::Windows::Forms::Padding(4);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(132, 22);
            this->textBox2->TabIndex = 2;
            this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(16, 146);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(38, 16);
            this->label3->TabIndex = 5;
            this->label3->Text = L"A до:";
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(65, 143);
            this->textBox3->Margin = System::Windows::Forms::Padding(4);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(132, 22);
            this->textBox3->TabIndex = 4;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(16, 178);
            this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(45, 16);
            this->label4->TabIndex = 8;
            this->label4->Text = L"A шаг:";
            this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
            // 
            // textBox4
            // 
            this->textBox4->Location = System::Drawing::Point(65, 175);
            this->textBox4->Margin = System::Windows::Forms::Padding(4);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(132, 22);
            this->textBox4->TabIndex = 7;
            this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
            // 
            // button1
            // 
            this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
            this->button1->Location = System::Drawing::Point(15, 236);
            this->button1->Margin = System::Windows::Forms::Padding(4);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(301, 52);
            this->button1->TabIndex = 9;
            this->button1->Text = L"Рассчитать";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->label5->ForeColor = System::Drawing::Color::Crimson;
            this->label5->Location = System::Drawing::Point(16, 212);
            this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(0, 20);
            this->label5->TabIndex = 10;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
            this->label6->Location = System::Drawing::Point(28, 23);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(254, 39);
            this->label6->TabIndex = 11;
            this->label6->Text = L"T=sin(x)^3 +x*a";
            this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(337, 299);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->textBox4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->textBox1);
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            this->ResumeLayout(false);
            this->PerformLayout();

        }


#pragma endregion
  private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {}
  private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
  private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
  private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {}
  private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
  private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {}
  private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
  private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
  {

      double X, A_MIN, A_MAX, A_SHAG, T, A;
      X = System::Convert::ToDouble(textBox1->Text);
      A_MIN = System::Convert::ToDouble(textBox2->Text);
      A_MAX = System::Convert::ToDouble(textBox3->Text);
      A_SHAG = System::Convert::ToDouble(textBox4->Text);
      System::String^ S = gcnew String("");

      for (A = A_MIN; A <= A_MAX; A = A + A_SHAG) {
          T = Math::Pow(Math::Sin(X), 3) + X * A;

          S = S + "T=" + System::Convert::ToString(T) + "\tA=" + System::Convert::ToString(A) + "\r\n";
      }
      MessageBox::Show(S, "result");


  }

  private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
  }
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
